#pragma once

#include <stdio.h>

#include "..\XboxTLS\XboxTLS.h"
#include "picohttpparser.h"

// Defines for library end users
#define XHTTPS_DEBUG
#define XHTTPS_USER_AGENT_SIZE 32

// Autodetects whitespaces at the beginning of the HTTP stream
#define XHTTPS_WHITESPACE_AUTODETECT 1

enum XHTTPS_Error {
	XHTTPS_OK = 0,
	XHTTPS_XNET_STARTUP_FAILED,
	XHTTPS_WSA_STARTUP_FAILED,
	XHTTPS_CONTEXT_CREATION_FAILED,
	XHTTPS_USER_AGENT_MALLOC_FAILED,
	XHTTPS_FAILED_ADDING_TRUST_ANCHOR,
	XHTTPS_FAILED_DNS_RESOLUTION,
	XHTTPS_FAILED_DNS_LOOKUP,
	XHTTPS_CONNECT_TO_HOST_FAILED,
	XHTTPS_INVALID_HTTP_RESPONSE
};

typedef struct XHTTPS_Response {
	int minor_version;
	int status;
	const char* msg;
	size_t msg_len;

	// Size of 100 recommended by picohttpparser.
	// Need to look into HTTP spec to see if there's a limit.
	// Even if there's none, 100 is plenty and is kept from an
	// overrun by the parser.
	size_t num_headers;
	struct phr_header headers[100];
} XHTTPS_Response;

void XHTTPS_Debug(char* text);
XHTTPS_Error XHTTPS_Setup(void);
XHTTPS_Error XHTTPS_Add_EC_TA(const unsigned char* dn, size_t dn_len,
			      const unsigned char* q, size_t q_len,
			      XboxTLSCurve curve_id);
XHTTPS_Error XHTTPS_Add_RSA_TA(const unsigned char* dn, size_t dn_len,
			       const unsigned char* n, size_t n_len,
			       const unsigned char* e, size_t e_len);
XHTTPS_Error XHTTPS_GET(char* host, char* path, char* out, long outSize,
			XHTTPS_Response* resp);
void XHTTPS_SetUserAgent(char* userAgent);
void XHTTPS_Exit(void);