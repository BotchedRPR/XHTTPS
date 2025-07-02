// SPDX-License-Identifier: MIT
/*
 * XHTTPS - a simple HTTP(S) library for Xbox 360
 * based on XboxTLS (https://github.com/JakobRangel/XboxTLS)
 *
 * This library is released under the MIT license.
 *
 * Thanks and regards go out to:
 *  - Jakob Rangel (https://github.com/JakobRangel) for XboxTLS
 *  - Cl�ment Dreptin (https://github.com/ClementDreptin) for helping bugfix
 *  - Kazuho Oku, Tokuhiro Matsuno, Daisuke Murase, Shigeo Mitsunari for picohttpparser
 */

#include <iostream>
#include <xtl.h>

#include "snprintf.h"
#include "XboxTLS.h"
#include "XHTTPS.h"
#include "XHTTPS_Roots.h"

/*
 * TODO:
 *
 * - document all functions
 * - POST requests
 * - dynamically add headers in
 */

void XHTTPS_Debug(char* text)
{
#ifdef XHTTPS_DEBUG
	std::cout << "[XHTTPS_DEBUG]: " << text;
#endif
}

static inline XHTTPS_Response* XHTTPS_MakeError(XHTTPS_Error err)
{
	XHTTPS_Response* r = new XHTTPS_Response;
	r->msg = nullptr;
	r->body = nullptr;
	return r;
}

static inline XHTTPS_Context* XHTTPS_MakeContextError(XHTTPS_Context* ctx,
						      XHTTPS_Error err)
{
	ctx->engine_err = err;
	return ctx;
}

/**
 * @brief Resolves a domain name to an IPv4 address string.
 *
 * @param domain The hostname to resolve (e.g., "example.com").
 * @param resolvedIP Output buffer to store the resolved IP address.
 * @param ipBufferSize Size of the resolvedIP buffer.
 * @return true if resolution succeeded, false otherwise.
 */
XHTTPS_Error XHTTPS_ResolveDNS(const char* domain, char* resolvedIP,
			       int ipBufferSize)
{
	XNDNS* pxndns = nullptr;
	if (XNetDnsLookup(domain, nullptr, &pxndns) != 0)
		return XHTTPS_FAILED_DNS_RESOLUTION;

	// Wait up to ~5 seconds for DNS resolution
	for (int i = 0; i < 50 && pxndns->iStatus == WSAEINPROGRESS; ++i)
		Sleep(100);

	if (pxndns->iStatus != 0 || pxndns->cina == 0)
	{
		XNetDnsRelease(pxndns);
		return XHTTPS_FAILED_DNS_LOOKUP;
	}

	XNetInAddrToString(pxndns->aina[0], resolvedIP, ipBufferSize);
	XNetDnsRelease(pxndns);
	return XHTTPS_OK;
}

size_t XHTTPS_Get_Message_Offset(char* response)
{
	char* msg_start = strstr(response, "\r\n\r\n");
	if (!msg_start)
		return 0;
	return (msg_start - response) + 4;
}

int XHTTPS_Get_Next_Chunk_Size(char* chunkData, size_t* chunkLen)
{
	// <chunk>\n<size in hex>\n<chunk>
	int chunkSize = 0;
	sscanf(chunkData, "%x", &chunkSize);

	// Advance offset to after the CRLF
	const char* crlf = strstr(chunkData, "\r\n");
	if (!crlf)
		return -1;

	*chunkLen = (crlf - chunkData) + 2; // include \r\n
	return chunkSize;
}

char* XHTTPS_Dechunk(char* message, size_t messageLen)
{
	size_t readOffset = 0;
	size_t writeOffset = 0;

	char* dechunked = new char[messageLen];
	if (!dechunked)
		return NULL;

	while (readOffset < messageLen)
	{
		size_t localOffset = 0;
		int chunkSize = XHTTPS_Get_Next_Chunk_Size(message + readOffset,
							   &localOffset);
		if (chunkSize < 0)
		{
			delete[] dechunked;
			return NULL;
		}

		std::cout << "CHUNK: Size 0x" << std::hex << chunkSize << "\n";

		if (chunkSize == 0)
			break; // end of chunks

		readOffset += localOffset;

		if (readOffset + chunkSize > (size_t)messageLen)
		{
			delete[] dechunked;
			return NULL; // not enough data
		}

		memcpy(dechunked + writeOffset, message + readOffset,
		       chunkSize);
		readOffset += chunkSize;

		// Skip trailing CRLF after chunk data
		if (message[readOffset] == '\r' &&
		    message[readOffset + 1] == '\n')
		{
			readOffset += 2;
		}
		else
		{
			delete[] dechunked;
			return NULL; // malformed chunk
		}

		writeOffset += chunkSize;
	}

	dechunked[writeOffset] = '\0';

	return dechunked;
}

XHTTPS_Error XHTTPS_Parse_HTTP_Response(XHTTPS_Context* ctx,
					XHTTPS_Response* resp)
{
	int r = 0;
	char* dechunked;

	// See comment in XHTTPS.h about header numbers
	resp->num_headers = 100;

	r = phr_parse_response(resp->msg, resp->msg_len, &resp->minor_version,
			       &resp->status, (const char**)&resp->msg,
			       &resp->msg_len, resp->headers,
			       &resp->num_headers, 0);

	if (r > 0)
		XHTTPS_Debug("Finished parsing HTTP headers.\n");
	else
		return XHTTPS_INVALID_HTTP_RESPONSE;

	// Let's check the HTTP status code so that we don't waste our time.
	// On success check if we're chunked and if we're downloading a file.
	// On redirect - redirect.
	// On failure - pass to user and get out.
	XHTTPS_IF_IN_BETWEEN(resp->status, 200, 226)
	{
		// success - do nothing... boo
	}
	else XHTTPS_IF_IN_BETWEEN(resp->status, 300, 308)
	{
		XHTTPS_Debug("STUB: Need to redirect!\n");
		return XHTTPS_OK;
	}
	else
	{
		// handle everything else as errors
		return XHTTPS_INVALID_HTTP_RESPONSE;
	}

	/*
	 * Now we need to check Transfer-Encoding. Mainly because
	 * we will most likely receive chunked responses and will
	 * need to check if what we got is correct with the chunk
	 * sizes. TODO: Maybe will be more efficient to do it while
	 * reading from the socket?
	 */
	for (size_t i = 0; i < resp->num_headers; i++)
	{
		if (strncmp(resp->headers[i].name, "Transfer-Encoding",
			    resp->headers[i].name_len) == 0)
		{
			if (strncmp(resp->headers[i].value, "chunked",
				    resp->headers[i].value_len) == 0)
			{
				XHTTPS_Debug(
					"Found chunked HTTP transfer encoding. Dechunking.\n");

				size_t msgOffset =
					XHTTPS_Get_Message_Offset(resp->msg);

				resp->body = resp->msg + msgOffset;

				// We can't trust msg_len to not overrun
				dechunked = XHTTPS_Dechunk(resp->body,
							   strlen(resp->body));
				if (dechunked == NULL)
					return XHTTPS_INVALID_HTTP_RESPONSE;

				break;
			}
			else
				break;
		}
	}

	return XHTTPS_OK;
}

XHTTPS_Error XHTTPS_Connect(XHTTPS_Context* ctx, char* host)
{
	char ip[64] = { 0 };
	XHTTPS_Error err;

	// Resolve DNS
	err = XHTTPS_ResolveDNS(host, ip, sizeof(ip));
	if (err != XHTTPS_OK)
		return XHTTPS_FAILED_DNS_RESOLUTION;

	// Connect to host
	if (!XboxTLS_Connect(ctx->int_ctx, ip, host, 443))
		return XHTTPS_CONNECT_TO_HOST_FAILED;

	XHTTPS_Debug("Connected to host!\n");

	return XHTTPS_OK;
}

XHTTPS_Error XHTTPS_Make_Request(XHTTPS_Context* ctx, char* request, char* host,
				 char* path, XHTTPS_Request_Type type,
				 XHTTPS_Header* headers, size_t num_headers)
{
	int offset = 0;

	if (type != GET)
	{
		std::cout << "STUB: Only GET requests are supported.\n";
		return XHTTPS_INVALID_REQUEST;
	}

	offset += snprintf(request, XHTTPS_IO_BUFFER_SIZE,
			   "GET %s HTTP/1.1\r\n"
			   "Host: %s\r\n"
			   "User-Agent: %s\r\n"
			   "Accept: */*\r\n"
			   "Connection: close\r\n",
			   path, host, ctx->UserAgent);

	// We don't need to add additional headers if there are none
	if (!headers || num_headers == 0)
		goto end_request;

	for (size_t i = 0; i < num_headers; i++)
	{
		offset += snprintf(request + offset,
				   XHTTPS_IO_BUFFER_SIZE - offset, "%s: %s\r\n",
				   headers[i].name, headers[i].value);

		if (offset >= XHTTPS_IO_BUFFER_SIZE)
			return XHTTPS_TOO_MANY_HEADERS;
	}

end_request:
	if (offset + 2 >=
	    XHTTPS_IO_BUFFER_SIZE) // check for overrunning with the final \r\n
		return XHTTPS_TOO_MANY_HEADERS;

	offset += snprintf(request + offset, XHTTPS_IO_BUFFER_SIZE - offset,
			   "\r\n");

	return XHTTPS_OK;
}

// ---------- Public API (TODO: Document)

XHTTPS_Context* XHTTPS_Setup(void)
{
	// First of all let's allocate the context pointer
	XHTTPS_Context* ctx = new XHTTPS_Context;

	if (!ctx)
		return nullptr;

	// Now startup XNET and WSA
	XNetStartupParams xnsp = { 0 };
	WSADATA wsadata;

	xnsp.cfgSizeOfStruct = sizeof(xnsp);
	xnsp.cfgFlags = XNET_STARTUP_BYPASS_SECURITY;

	if (XNetStartup(&xnsp) != 0)
		return XHTTPS_MakeContextError(ctx, XHTTPS_XNET_STARTUP_FAILED);

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		return XHTTPS_MakeContextError(ctx, XHTTPS_WSA_STARTUP_FAILED);

	// XboxTLS Recommends this
	Sleep(3000);

	ctx->int_ctx = new XboxTLSContext;

	if (ctx->int_ctx == NULL)
		return XHTTPS_MakeContextError(ctx,
					       XHTTPS_CONTEXT_CREATION_FAILED);

	ctx->UserAgent = new char[XHTTPS_USER_AGENT_SIZE];

	if (ctx->UserAgent == NULL)
		return XHTTPS_MakeContextError(ctx,
					       XHTTPS_USER_AGENT_MALLOC_FAILED);

	// Default UserAgent, can be replaced with XHTTPS_SetUserAgent
	strncpy(ctx->UserAgent, "Xbox360/1.0",
		XHTTPS_USER_AGENT_SIZE * sizeof(char));

	if (!XboxTLS_CreateContext(ctx->int_ctx, "dummy"))
		return XHTTPS_MakeContextError(ctx,
					       XHTTPS_CONTEXT_CREATION_FAILED);

	// Add some common root CAs. Don't fail on error.
	XHTTPS_AddTAs(ctx->int_ctx);

	XHTTPS_Debug("XHTTPS ready.\n");

	return ctx;
}

XHTTPS_Response* XHTTPS_GET(XHTTPS_Context* ctx, char* host, char* path)
{
	char request[XHTTPS_IO_BUFFER_SIZE];
	char* newBuf;
	int r;
	int bufLen = 0; // input variable for for loop
	XHTTPS_Error err;
	XHTTPS_Response* resp = new XHTTPS_Response;

	if (!resp)
		return nullptr;

	resp->msg_len = XHTTPS_IO_BUFFER_SIZE;
	resp->msg = (char*)malloc(resp->msg_len);

	if (!resp->msg)
		return XHTTPS_MakeError(XHTTPS_MESSAGE_MALLOC_FAILED);

	err = XHTTPS_Connect(ctx, host);
	if (err != XHTTPS_OK)
	{
		free(resp->msg);
		return XHTTPS_MakeError(err);
	}

	err = XHTTPS_Make_Request(ctx, request, host, path, GET, ctx->headers,
				  ctx->num_headers);
	if (err != XHTTPS_OK)
	{
		free(resp->msg);
		return XHTTPS_MakeError(err);
	}

	XboxTLS_Write(ctx->int_ctx, request, (int)strlen(request));

	// Read the response from the socket
	// Here we need to be careful and realloc the buffer every XHTTPS_IO_BUFFER_SIZE bytes read
	while ((r = XboxTLS_Read(ctx->int_ctx, resp->msg + bufLen,
				 resp->msg_len - bufLen - 1)) > 0)
	{
		bufLen += r;

		// Check capacity of the output buffer
		if (resp->msg_len - bufLen <= 1)
		{
			resp->msg_len += XHTTPS_IO_BUFFER_SIZE;
			newBuf = (char*)realloc(resp->msg, resp->msg_len);

			if (!newBuf)
				return XHTTPS_MakeError(XHTTPS_OUT_OF_MEMORY);

			resp->msg = newBuf;
		}
	}

	r = XHTTPS_Parse_HTTP_Response(ctx, resp);
	if (r != 0)
	{
		XHTTPS_Exit(ctx);
		return XHTTPS_MakeError((XHTTPS_Error)r);
	}

	return resp;
}

XHTTPS_Error XHTTPS_AddHeader(XHTTPS_Context* ctx, XHTTPS_Header header)
{
	if (ctx->num_headers == XHTTPS_MAX_ADDITIONAL_HEADERS)
		return XHTTPS_TOO_MANY_HEADERS;

	ctx->headers[ctx->num_headers] = header;
	ctx->num_headers++;

	return XHTTPS_OK;
}

XHTTPS_Error XHTTPS_RemoveHeader(XHTTPS_Context* ctx)
{
	if (ctx->num_headers == 0)
		return XHTTPS_TOO_LITTLE_HEADERS;

	ctx->num_headers--;

	return XHTTPS_OK;
}

void XHTTPS_SetUserAgent(XHTTPS_Context* ctx, char* targetUserAgent)
{
	if (!ctx->UserAgent || !targetUserAgent)
		return;

	memcpy_s(ctx->UserAgent, sizeof(char) * XHTTPS_USER_AGENT_SIZE,
		 targetUserAgent, sizeof(char) * XHTTPS_USER_AGENT_SIZE);
}

void XHTTPS_Exit(XHTTPS_Context* ctx)
{
	if (ctx->int_ctx != nullptr || !ctx)
		XboxTLS_Free(ctx->int_ctx);

	delete[] ctx->UserAgent;
	delete ctx;

	WSACleanup();
}
