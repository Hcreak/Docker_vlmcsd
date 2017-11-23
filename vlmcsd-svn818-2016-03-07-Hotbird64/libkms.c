/*
 * libkms.c
 */

#ifndef CONFIG
#define CONFIG "config.h"
#endif // CONFIG
#include CONFIG

#define EXTERNAL dllexport

#define DLLVERSION 0x30000

#include "libkms.h"
#include "shared_globals.h"
#include "network.h"
#include "helpers.h"

#ifndef _WIN32
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#endif // WIN32

static int_fast8_t IsServerStarted = FALSE;


EXTERNC __declspec(EXTERNAL) DWORD __cdecl SendActivationRequest
(
	const char* const hostname,
	const int port,
	RESPONSE* baseResponse,
	const REQUEST* const baseRequest,
	RESPONSE_RESULT* result, BYTE *hwid
)
{
	return !0; // not yet implemented
}


EXTERNC __declspec(EXTERNAL) DWORD __cdecl StartKmsServer(const int port, RequestCallback_t requestCallback)
{
	char listenAddress[64];

	if (IsServerStarted) return !0;

#	ifdef _WIN32
#	ifndef USE_MSRPC
	// Windows Sockets must be initialized
	WSADATA wsadata;
	int error;

	if ((error = WSAStartup(0x0202, &wsadata)))
	{
		return error;
	}
#	endif // USE_MSRPC
#	endif // _WIN32

	CreateResponseBase = requestCallback;

	int maxsockets = 0;
	int_fast8_t haveIPv4 = FALSE;
	int_fast8_t haveIPv6 = FALSE;

	if (checkProtocolStack(AF_INET)) { haveIPv4 = TRUE; maxsockets++; }
	if (checkProtocolStack(AF_INET6)) { haveIPv6 = TRUE; maxsockets++; }

	if(!maxsockets) return !0;

	SocketList = (SOCKET*)vlmcsd_malloc(sizeof(SOCKET) * (size_t)maxsockets);
	numsockets = 0;

	if (haveIPv4)
	{
		snprintf(listenAddress, 64, "0.0.0.0:%u", (unsigned int)port);
		addListeningSocket(listenAddress);
	}

	if (haveIPv6)
	{
		snprintf(listenAddress, 64, "[::]:%u", (unsigned int)port);
		addListeningSocket(listenAddress);
	}

	if (!numsockets)
	{
		free(SocketList);
		return !0;
	}

	IsServerStarted = TRUE;

	runServer();

	IsServerStarted = FALSE;
	return 0;
}


EXTERNC __declspec(EXTERNAL) DWORD __cdecl StopKmsServer()
{
	if (!IsServerStarted) return !0;

	closeAllListeningSockets();
	if (SocketList) free(SocketList);
	return 0;
}


EXTERNC __declspec(EXTERNAL) int __cdecl GetLibKmsVersion()
{
	return DLLVERSION;
}

