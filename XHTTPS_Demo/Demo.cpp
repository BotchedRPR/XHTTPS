// SPDX-License-Identifier: MIT
// XHTTPS demo app

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string>
#include "..\XHTTPS\XHTTPS.h"

void _cdecl main()
{
	int ret_xhttps;
	char* output = (char*)malloc(XHTTPS_OUTPUT_BUFFER_SIZE);
	XHTTPS_Response *resp;

	ret_xhttps = XHTTPS_Setup();

	// This is optional
	XHTTPS_SetUserAgent("Xenon/2.0.17559.0");

	resp = XHTTPS_GET("consolemods.org", "/wiki/Main_Page");

	if (!resp)
		goto out;

	if (resp->engine_err != XHTTPS_OK)
	{
		std::cout << "XHTTPS Engine error " << resp->engine_err << "\n";
		free(resp);
		goto out;
	}

	for (int i = 0; i != resp->num_headers; ++i) {
		std::cout << std::string(resp->headers[i].name, resp->headers[i].name_len)
			<< ": "
			<< std::string(resp->headers[i].value, resp->headers[i].value_len)
			<< '\n';
	}

out:
	XHTTPS_Exit();
	return;
}