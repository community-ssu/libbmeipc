/**
   @file bmeipc.c

   @brief BME IPC function interface
   <p>
   Copyright (C) 2010 Nokia Corporation.
   Copyright (C) 2012 Pali Rohár <pali.rohar@gmail.com>

   @author Markus Lehtonen <markus.lehtonen@nokia.com>
   @author Matti Halme <matti.halme@nokia.com>

   This file is part of libbme.

   Libbme is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Libbme is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with libbme. If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syslog.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/poll.h>
#include <stdarg.h>

#include <time.h>
#include <sys/time.h>
#include <stdint.h>

#include "bmeipc.h"
#include "bmemsg.h"
#include "em_isi.h"

static int bme_fds[2] = {-1, -1};

/**
 * BME packet header structure
 */
typedef struct
{
  int sync;                     // sync pattern for detecting broken packets
  int size;                     // size of actual packet data after the header
} bmeipc_header;

/**
 * Sync pattern for packet header
 */
#define BMEIPC_SYNCWORD 0x434e5953

/**
 * BME server code
 */
#define bme_fd bme_fds[1]

#define RX51_TEMP "/sys/class/power_supply/rx51-battery/temp"
#define BQ_TEMP "/sys/class/power_supply/bq27200-0/temp"

static uint16_t
read_temperature(void)
{
  int ret;
  FILE *fp = fopen(RX51_TEMP, "r");
  if (!fp)
    fp = fopen(BQ_TEMP, "r");
  if (!fp)
    return 0;
  if (fscanf(fp, "%d", &ret) != 1)
    ret = -2730;
  fclose(fp);
  return ret/10+273;
}

static void
call_bme_server(void)
{
  char buf[1024];
  int err = 0;
  int bytes = sizeof(buf);
  int ret;
  struct timeval tv;
  fd_set rfds;
  bmeipc_header hdr;

  FD_ZERO(&rfds);
  FD_SET(bme_fd, &rfds);
  tv.tv_sec = 5;
  tv.tv_usec = 0;

  ret = select(bme_fd+1, &rfds, NULL, NULL, &tv);
  if (ret <= 0)
    return;

  ret = read(bme_fd, &hdr, sizeof(hdr));
  if (ret <= 0 || ret != sizeof(hdr))
    return;

  if (hdr.sync != BMEIPC_SYNCWORD || hdr.size < 0 || bytes < hdr.size)
    return;

  if (bytes > hdr.size)
    bytes = hdr.size;

  if (read(bme_fd, buf, bytes) != bytes)
    return;

  if (((bmeipc_msg_t *)buf)->type == EM_BATTERY_INFO_REQ)
  {
    struct emsg_battery_info_reply reply = {0,};
    struct emsg_battery_info_req *req = (struct emsg_battery_info_req *)buf;

    if (req->flags & EM_BATTERY_TEMP) {
      reply.temp = read_temperature();
      if (reply.temp == 0)
        err = 1;
    }

#if 0
    syslog(LOG_INFO, "BME: flags: 0x%04X err: %d temp: %d kelvin",req->flags, err, reply.temp);
#endif

    hdr.sync = BMEIPC_SYNCWORD;

    hdr.size = sizeof(err);
    write(bme_fd, &hdr, sizeof(hdr));
    write(bme_fd, &err, sizeof(err));

    hdr.size = sizeof(reply);
    write(bme_fd, &hdr, sizeof(hdr));
    write(bme_fd, &reply, sizeof(reply));
  }
}

/**
 * BME client socket descriptor
 */
#define bme_sd bme_fds[0]

/**
 * Pointer to vsyslog() compatible logging function used by bmeipc.
 */
static void (*log_message_fn) (int, const char *, va_list) = vsyslog;

/**
 * Set function used for bmeipc logging.
 * 
 * Defaults to using vsyslog. Custom function should
 * have the same calling convention as vyslog, i.e.
 * 
 * void custom(int priority, const char *format, va_list ap);
 * 
 * Passing NULL is allowed and makes bmeipc totally silent.
 * 
 * @fn: pointer to function similar to vsyslog.
 */

void bme_set_logging_function(void (*fn)(int,const char *,va_list))
{
  log_message_fn = fn;
}

/**
 * Error diagnostics output
 * 
 * Note: The errno value will not be modified by this function.
 *
 * @level: syslog level constant (LOG_WARNING etc)
 * @fmt:   printf style format string
 * @...:   appropriate arguments for the format string
 */

static void log_message(int level, const char *fmt, ...)
  __attribute__ ((format(printf, 2, 3)));

static void
log_message(int level, const char *fmt, ...)
{
  if (log_message_fn != 0)
  {
    va_list va;
    va_start(va, fmt);
    log_message_fn(level, fmt, va);
    va_end(va);
  }
}

#define log_warn_F(FMT, ARG...)\
    log_message(LOG_WARNING, "%s: "FMT, __FUNCTION__, ## ARG)

#define log_error_F(FMT, ARG...)\
    log_message(LOG_ERR, "%s: "FMT, __FUNCTION__, ## ARG)

/**
 * Write a packet to the socket.
 *
 * @fd: socket descriptor
 * @msg: data address
 * @bytes: size of data to write
 *
 * @return number of bytes written, -1=Error
 */
int
bme_packet_write(int fd, const void *msg, int bytes)
{
  int ret;
  bmeipc_header hdr = {
    .sync = BMEIPC_SYNCWORD,
    .size = bytes,
  };

  ret = write(fd, &hdr, sizeof(hdr));
  if (ret <= 0)
    return ret;

  ret = write(fd, msg, bytes);
  call_bme_server();

  return ret;
}

/**
 * Read packet from socket
 *
 * @fd: socket descriptor
 * @msg: buffer address
 * @bytes: buffer size
 *
 * @return number of bytes read, -1=ERR, 0=EOF/out-of-sync
 */
int
bme_packet_read(int fd, void *msg, int bytes)
{
  struct timeval tv;
  bmeipc_header head;
  fd_set rfds;
  int ret;

  FD_ZERO(&rfds);
  FD_SET(fd, &rfds);
  tv.tv_sec = 5;
  tv.tv_usec = 0;

  ret = select(fd+1, &rfds, NULL, NULL, &tv);
  if (ret <= 0)
    return -1;

  ret = read(fd, &head, sizeof(head));
  if (ret <= 0)
    return ret;
  if (ret != sizeof(head))
    return 0;

  if (head.sync != BMEIPC_SYNCWORD || head.size < 0)
    return 0;

  if (bytes < head.size)
  {
    errno = EBADMSG;
    return -1;
  }

  if (bytes > head.size)
    bytes = head.size;

  return read(fd, msg, bytes);
}

static char global_cookie[255] = BME_SRV_COOKIE;

/**
 * Handle cookie handshake from accepting end (server/bme)
 * 
 * @fd: socket descriptor
 * @cookie: string that is expected
 * 
 * @return status value 0=Success, -1=Error
 */
int
bme_cookie_read(int fd, const char *cookie)
{
  if (strcmp(global_cookie, cookie))
    return -1;
  else
    return 0;
}

/**
 * Handle cookie handshake from connecting end (client/app)
 * 
 * @fd: socket descriptor
 * @cookie: string that is to be sent
 * 
 * @return status value 0=Success, -1=Error
 */

int
bme_cookie_write(int fd, const char *cookie)
{
  if (strlen(cookie) > sizeof(global_cookie)-1)
    return -1;
  strcpy(global_cookie, cookie);
  return 0;
}

/**
 * Connect to BME server.
 *
 * @return socket descriptor if successful, -1=Error
 */
int
bme_connect(void)
{
  /* Check that we are not already connected */
  if (bme_sd != -1)
  {
    // set errno to something meaningful
    errno = EALREADY;
    log_error_F("already connected\n");
    // return error without disconnecting
    return -1;
  }

  /* Create socket */
  if (socketpair(AF_UNIX, SOCK_STREAM, 0, bme_fds) == -1)
  {
    log_error_F("socket: %s\n", strerror(errno));
    return -1;
  }

  /* If we get here, the connection was succesfully established */
  return bme_sd;
}

/**
 * Send a message to the server and read reply.
 *
 * @smsg: address of a message to send
 * @sbytes: size of message to send
 * @rmsg: address of a reply buffer
 * @rbytes: size of reply buffer
 * @rbytes_act: actual size of reply got from the server
 *
 * @return status value, set by the server, or -1=Error
 */
int
bme_send_get_reply(const void *smsg, int sbytes,
                   void *rmsg, int rbytes, int *rbytes_act)
{
  int status, nb;

  if (bme_write(smsg, sbytes) != sbytes)
    return -1;

  if (bme_read(&status, sizeof(status)) == -1)
    return -1;

  if (status >= 0 && rmsg && rbytes)
  {
    nb = bme_read(rmsg, rbytes);
    if (nb == -1)
      return -1;
    if (rbytes_act)
      *rbytes_act = nb;
  }
  return status;
}

/**
 * Write a data packet to the server.
 *
 * @msg: data address
 * @bytes: size of data to write
 *
 * @return number of bytes written if successful, -1=Error
 */
int
bme_write(const void *msg, int bytes)
{
  if (bme_sd == -1)
  {
    // set errno to something meaningful
    errno = ENOTCONN;
    return -1;
  }
  return bme_packet_write(bme_sd, msg, bytes);
}

/**
 * Read a data packet from the server.
 *
 * @msg: buffer address
 * @bytes: buffer size
 *
 * @return number of bytes read if successful, -1=Error
 */
int
bme_read(void *msg, int bytes)
{
  if (bme_sd == -1)
  {
    // set errno to something meaningful
    errno = ENOTCONN;
    return -1;
  }
  return bme_packet_read(bme_sd, msg, bytes);
}

/**
 * Get a PID of the BME server.
 *
 * @return positive PID if successful, -1=Error
 */
int
bme_get_server_pid(void)
{
  /* Drivers are part of kernel, return lowest PID */
  return 1;
}

/**
 * Disconnect from BME server.
 */
void
bme_disconnect(void)
{
  if (bme_sd != -1)
  {
    close(bme_sd);
    bme_sd = -1;
  }
  if (bme_fd != -1)
  {
    close(bme_fd);
    bme_fd = -1;
  }
}
