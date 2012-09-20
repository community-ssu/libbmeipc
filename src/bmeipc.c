/**
   @file bmeipc.c

   @brief BME IPC function interface
   <p>
   Copyright (C) 2010 Nokia Corporation.

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

static int bme_fds[2] = {-1, -1};

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
  bmeipc_header hdr = {
    .sync = BMEIPC_SYNCWORD,
    .size = bytes,
  };

  struct iovec iov[2] = {
    {.iov_base = &hdr,.iov_len = sizeof hdr}
    ,
    {.iov_base = (void *)msg,.iov_len = bytes},
  };

  int tot = sizeof hdr + bytes;
  int ret = writev(fd, iov, 2);

  if (ret == -1)
  {
    log_warn_F("[fd=%d]: write ERROR: %s\n", fd, strerror(errno));
  }
  else if (ret != tot)
  {
    log_warn_F("[fd=%d]: write ERROR: %d/%d bytes\n", fd, ret, tot);
    // set errno to something meaningful
    errno = ECOMM;
    ret = -1;
  }
  else
  {
    ret = bytes;
  }

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
  int ret;

  if ((ret = bme_header_read(fd)) <= 0)
  {
    return ret;                 // ERR or EOF
  }
  if (bytes < ret)
  {
    log_warn_F("[fd=%d]: read packet: got %d, expected max %d bytes\n",
               fd, ret, bytes);
    // set errno to something meaningful
    errno = EBADMSG;
    return -1;
  }
  if (bytes > ret)
  {
    bytes = ret;
  }
  if ((ret = bme_bytes_read(fd, msg, bytes)) != bytes)
  {
    log_warn_F("[fd=%d]: read packet: got %d/%d bytes\n", fd, ret, bytes);

    if (ret != -1)
    {
      // set errno to something meaningful
      errno = EBADMSG;
    }
    return -1;
  }

  return ret;
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
  bmeipc_msg_t gm = { BME_SYSMSG_GETPID, 0 };
  bmeipc_pid_t reply;

  if (bme_send_get_reply(&gm, sizeof(gm), &reply, sizeof(reply), NULL) < 0)
    return -1;
  else
    return reply.pid;
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
