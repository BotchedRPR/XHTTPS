#pragma once

#include <stdio.h>

// TODO: Why does this not get found by VC++ directories?
#include "..\..\External\XboxTLS\XboxTLS.h"
#include "..\..\External\picohttpparser\picohttpparser.h"

// Defines for library end users
#define XHTTPS_DEBUG

// Sizes, constants, etc.
#define XHTTPS_MAX_ADDITIONAL_HEADERS 16
#define XHTTPS_IO_BUFFER_SIZE ((8 * 1024) + XHTTPS_MAX_ADDITIONAL_HEADERS * sizeof(XHTTPS_Header))
#define XHTTPS_USER_AGENT_SIZE 32

// Autodetects whitespaces at the beginning of the HTTP stream
#define XHTTPS_WHITESPACE_AUTODETECT 1

#define XHTTPS_IF_IN_BETWEEN(obj, s, e)	if (obj >= s && obj <= e)

enum XHTTPS_Error {
	XHTTPS_OK = 0,
	XHTTPS_XNET_STARTUP_FAILED,
	XHTTPS_WSA_STARTUP_FAILED,
	XHTTPS_CONTEXT_CREATION_FAILED,
	XHTTPS_USER_AGENT_MALLOC_FAILED,
	XHTTPS_HEADER_MALLOC_FAILED,
	XHTTPS_FAILED_ADDING_TRUST_ANCHOR,
	XHTTPS_MESSAGE_MALLOC_FAILED,
	XHTTPS_FAILED_DNS_RESOLUTION,
	XHTTPS_FAILED_DNS_LOOKUP,
	XHTTPS_INVALID_REQUEST,
	XHTTPS_TOO_LITTLE_HEADERS,
	XHTTPS_TOO_MANY_HEADERS,
	XHTTPS_CONNECT_TO_HOST_FAILED,
	XHTTPS_INVALID_HTTP_RESPONSE,
	XHTTPS_OUT_OF_MEMORY,
};

typedef struct XHTTPS_Header {
	char* name;
	char* value;
} XHTTPS_Header;

enum XHTTPS_Request_Type {
	GET = 0,
	POST,
};

typedef struct XHTTPS_Context {
	XboxTLSContext* int_ctx;
	XHTTPS_Error engine_err;
	char* UserAgent;

	XHTTPS_Header headers[XHTTPS_MAX_ADDITIONAL_HEADERS];
	size_t num_headers;
} XHTTPS_Context;

typedef struct XHTTPS_Response {
	int minor_version;
	int status;
	char* msg;
	char* body;
	size_t msg_len;

	// Size of 100 recommended by picohttpparser.
	// Need to look into HTTP spec to see if there's a limit.
	// Even if there's none, 100 is plenty and is kept from an
	// overrun by the parser.
	size_t num_headers;
	struct phr_header headers[100];
} XHTTPS_Response;

XHTTPS_Context* XHTTPS_Setup(void);
XHTTPS_Response* XHTTPS_GET(XHTTPS_Context* ctx, char* host, char* path);
XHTTPS_Error XHTTPS_AddHeader(XHTTPS_Context* ctx, XHTTPS_Header header);
XHTTPS_Error XHTTPS_RemoveHeader(XHTTPS_Context* ctx, int index);
void XHTTPS_SetUserAgent(XHTTPS_Context* ctx, char* targetUserAgent);
void XHTTPS_Exit(XHTTPS_Context* ctx);