// SPDX-License-Identifier: MIT
/*
* XHTTPS - a simple HTTP(S) library for Xbox 360
* based on XboxTLS (https://github.com/JakobRangel/XboxTLS)
*
* This library is released under the MIT license.
*
* Thanks and regards go out to:
*  - Jakob Rangel (https://github.com/JakobRangel) for XboxTLS
*  - Clément Dreptin (https://github.com/ClementDreptin) for helping bugfix
*  - Kazuho Oku, Tokuhiro Matsuno, Daisuke Murase, Shigeo Mitsunari for picohttpparser
*/

#include <xtl.h>
#include "XHTTPS.h"
#include "..\XboxTLS\XboxTLS.h"

// For simplicity's sake we declare an internal context instead of passing it around
XboxTLSContext* int_ctx;
static char* UserAgent;

void XHTTPS_Debug(char* text)
{
#ifdef XHTTPS_DEBUG
	printf("XHTTPS_DEBUG: %s", text);
#endif
}

/**
 * @brief Resolves a domain name to an IPv4 address string.
 * 
 * @param domain The hostname to resolve (e.g., "example.com").
 * @param resolvedIP Output buffer to store the resolved IP address.
 * @param ipBufferSize Size of the resolvedIP buffer.
 * @return true if resolution succeeded, false otherwise.
 */
XHTTPS_Error XHTTPS_ResolveDNS(const char* domain, char* resolvedIP, int ipBufferSize)
{
	XNDNS* pxndns = nullptr;
	if (XNetDnsLookup(domain, nullptr, &pxndns) != 0)
		return XHTTPS_FAILED_DNS_RESOLUTION;

	// Wait up to ~5 seconds for DNS resolution
	for (int i = 0; i < 50 && pxndns->iStatus == WSAEINPROGRESS; ++i)
		Sleep(100);

	if (pxndns->iStatus != 0 || pxndns->cina == 0) {
		XNetDnsRelease(pxndns);
		return XHTTPS_FAILED_DNS_LOOKUP;
	}

	XNetInAddrToString(pxndns->aina[0], resolvedIP, ipBufferSize);
	XNetDnsRelease(pxndns);
	return XHTTPS_OK;
}

XHTTPS_Error XHTTPS_Add_EC_TA(const unsigned char* dn, size_t dn_len,
	const unsigned char* q, size_t q_len,
	XboxTLSCurve curve_id)
{
	if(!XboxTLS_AddTrustAnchor_EC(int_ctx, dn, dn_len, q, q_len, curve_id))
		return XHTTPS_FAILED_ADDING_TRUST_ANCHOR;

	return XHTTPS_OK;
}

XHTTPS_Error XHTTPS_Add_RSA_TA(const unsigned char* dn, size_t dn_len,
	const unsigned char* n, size_t n_len,
	const unsigned char* e, size_t e_len)
{
	if(!XboxTLS_AddTrustAnchor_RSA(int_ctx, dn, dn_len, n, n_len, e, e_len))
		return XHTTPS_FAILED_ADDING_TRUST_ANCHOR;

	return XHTTPS_OK;
}

// Converts hex string to size_t (todo: check for more efficient method)
size_t XHTTPS_Hex_To_Size(const char *hex, size_t max_len) 
{
	size_t val = 0;
	size_t i = 0;
	while (i < max_len && hex[i]) {
		char c = hex[i++];
		if (c >= '0' && c <= '9') val = (val << 4) + (c - '0');
		else if (c >= 'A' && c <= 'F') val = (val << 4) + (c - 'A' + 10);
		else if (c >= 'a' && c <= 'f') val = (val << 4) + (c - 'a' + 10);
		else break;
	}

	return val;
}

size_t XHTTPS_Get_Message_Offset(char *response)
{
	return abs(response - strstr(response, "\r\n\r\n")) + 3;
}

int XHTTPS_Get_Next_Chunk_Size(char* chunkData, size_t *chunkLen)
{
	// <chunk>\n<size in hex>\n<chunk>
	int chunkSize = 0;
	sscanf(chunkData, "%x", &chunkSize);

	// Advance offset to after the CRLF
	const char *crlf = strstr(chunkData, "\r\n");
	if (!crlf) return -1;

	*chunkLen = (crlf - chunkData) + 2; // include \r\n
	return chunkSize;
}

char* XHTTPS_Dechunk(char *message, size_t messageLen) 
{
	size_t readOffset = 0;
	size_t writeOffset = 0;
	char *dechunked = (char *)malloc(messageLen);
	if (!dechunked) return NULL;

	while (readOffset < messageLen) {
		size_t localOffset = 0;
		int chunkSize = XHTTPS_Get_Next_Chunk_Size(message + readOffset, &localOffset);
		if (chunkSize < 0) {
			free(dechunked);
			return NULL;
		}

		if (chunkSize == 0)
			break; // end of chunks

		readOffset += localOffset;

		if (readOffset + chunkSize > (size_t)messageLen) {
			free(dechunked);
			return NULL; // not enough data
		}

		memcpy(dechunked + writeOffset, message + readOffset, chunkSize);
		readOffset += chunkSize;

		// Skip trailing CRLF after chunk data
		if (message[readOffset] == '\r' && message[readOffset + 1] == '\n') {
			readOffset += 2;
		} else {
			free(dechunked);
			return NULL; // malformed chunk
		}

		writeOffset += chunkSize;
	}

	dechunked[writeOffset] = '\0';

	return dechunked;
}

XHTTPS_Error XHTTPS_GET(char* host, char* path, char* out, long outSize,
	XHTTPS_Response* resp)
{
	char ip[64] = { 0 };
	char request[512];
	char* dechunked;
	int r;
	int bufLen = 0; // input variable for for loop

	XHTTPS_Error err;

	// Resolve DNS
	err = XHTTPS_ResolveDNS(host, ip, sizeof(ip));
	if(err != XHTTPS_OK)
		return err;

	// Connect to host
	if (!XboxTLS_Connect(int_ctx, ip, host, 443)) {
		XboxTLS_Free(int_ctx);
		return XHTTPS_CONNECT_TO_HOST_FAILED;
	}

	XHTTPS_Debug("Connected to host!\n");

	sprintf(request,
		"GET %s HTTP/1.1\r\n"
		"Host: %s\r\n"
		"User-Agent: %s\r\n"
		"Accept: */*\r\n"
		"Connection: close\r\n\r\n", path, host, UserAgent);
	XboxTLS_Write(int_ctx, request, (int)strlen(request));

	// Read the response from the socket
	while ((r = XboxTLS_Read(int_ctx, out + bufLen, outSize - bufLen - 1)) > 0) {
		bufLen += r;
		out[bufLen] = '\0';
	}

	// See comment in XHTTPS.h about header numbers
	resp->num_headers = 100;

	r = phr_parse_response(out, outSize, &resp->minor_version, &resp->status, &resp->msg, &resp->msg_len, resp->headers, &resp->num_headers, 0);

	if (r > 0)
		XHTTPS_Debug("Finished parsing HTTP headers.\n");
	else
		return XHTTPS_INVALID_HTTP_RESPONSE;

	/*
	 * Now we need to check Transfer-Encoding. Mainly because
	 * we will most likely receive chunked responses and will
	 * need to check if what we got is correct with the chunk
	 * sizes. TODO: Maybe will be more efficient to do it while
	 * reading from the socket?
	 */
	for (size_t i = 0; i < resp->num_headers; i++)
	{
		if (strncmp(resp->headers[i].name, "Transfer-Encoding", resp->headers[i].name_len))
		{
			if (strncmp(resp->headers[i].value, "chunked", resp->headers[i].value_len))
			{
				XHTTPS_Debug("Found chunked HTTP transfer encoding. Dechunking.\n");
				dechunked = XHTTPS_Dechunk(out + XHTTPS_Get_Message_Offset(out), outSize);
				out = dechunked;
				free(dechunked);

				break;
			}
			else
				break;
		}

		i++;
	}

	return XHTTPS_OK;
}

void XHTTPS_SetUserAgent(char* userAgent)
{
	memcpy_s(UserAgent, sizeof(char) * XHTTPS_USER_AGENT_SIZE, userAgent, sizeof(char) * XHTTPS_USER_AGENT_SIZE);
}

XHTTPS_Error XHTTPS_Setup(void)
{
	XNetStartupParams xnsp = { 0 };
	WSADATA wsadata;

	xnsp.cfgSizeOfStruct = sizeof(xnsp);
	xnsp.cfgFlags = XNET_STARTUP_BYPASS_SECURITY;

	if (XNetStartup(&xnsp) != 0)
		return XHTTPS_XNET_STARTUP_FAILED;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		return XHTTPS_WSA_STARTUP_FAILED;

	// XboxTLS Recommends this
	Sleep(3000);

	int_ctx = (XboxTLSContext*)malloc(sizeof(XboxTLSContext));

	if (int_ctx == NULL)
		return XHTTPS_CONTEXT_CREATION_FAILED;

	UserAgent = (char*)malloc(sizeof(char) * XHTTPS_USER_AGENT_SIZE);

	// Default UserAgent, can be replaced with XHTTPS_SetUserAgent
	UserAgent = "Xbox360/1.0";

	if (UserAgent == NULL)
		return XHTTPS_USER_AGENT_MALLOC_FAILED;

	if (!XboxTLS_CreateContext(int_ctx, "dummy"))
		return XHTTPS_CONTEXT_CREATION_FAILED;

	XHTTPS_Debug("XHTTPS ready.\n");

	return XHTTPS_OK;
}

void XHTTPS_Exit(void)
{
	if(int_ctx != nullptr)
		XboxTLS_Free(int_ctx);

	WSACleanup();
}