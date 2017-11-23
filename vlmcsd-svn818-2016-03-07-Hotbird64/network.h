#ifndef INCLUDED_NETWORK_H
#define INCLUDED_NETWORK_H

#ifndef CONFIG
#define CONFIG "config.h"
#endif // CONFIG
#include CONFIG

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "types.h"



int_fast8_t sendrecv(SOCKET sock, BYTE *data, int len, int_fast8_t do_send);

#define _recv(s, d, l)  sendrecv(s, (BYTE *)d, l,  0)
#define _send(s, d, l)  sendrecv(s, (BYTE *)d, l, !0)

#ifndef NO_SOCKETS

void closeAllListeningSockets();
BOOL addListeningSocket(const char *const addr);
__pure int_fast8_t checkProtocolStack(const int addressfamily);

#endif // NO_SOCKETS

int runServer();
SOCKET connectToAddress(const char *const addr, const int AddressFamily, int_fast8_t showHostName);
int_fast8_t isDisconnected(const SOCKET s);

#endif // INCLUDED_NETWORK_H
