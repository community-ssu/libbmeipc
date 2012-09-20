ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS = -Wall -fPIC -I@top_srcdir@/include

bmeincludedir = @includedir@/bme
pkgconfigdir = @libdir@/pkgconfig

lib_LTLIBRARIES = libbmeipc.la

libbmeipc_la_SOURCES = src/bmeipc.c
libbmeipc_la_LDFLAGS = -version-info $(BMEIPC_LT_VERSION) -Wl,--version-script,@top_srcdir@/libbmeipc.ver

bmeinclude_HEADERS = include/bme_extmsg.h \
                     include/bmeipc.h \
                     include/bme_isa_def.h \
                     include/bmeisa.h \
                     include/bmemsg.h \
                     include/client_ipc.h \
                     include/em_isi.h

pkgconfig_DATA = bmeipc.pc
