# XHTTPS

XHTTPS is an early, non-production-ready Xbox 360 HTTPS library.
It supports basic GET requests using XboxTLS for TLS1.2 encryption. 


# Install guide

XHTTPS is provided alongside a Demo utility. To test the library, follow these steps:

 1. Clone the repo, and place XboxTLS alongside the XHTTPS and XHTTPS_Demo folders.
 2. Open the demo project in Visual Studio 2010 (with the Xbox 360 SDK installed)
 3. All dependencies should be sorted out. If not, manually add project references (right click XHTTPS_Demo, XHTTPS, **Add -> Reference** and select XHTTPS for XHTTPS_Demo and XboxTLS for XHTTPS.
 4. Build and run using Release configuration.
 5. You should have a connection :)

TODO: Write more tutorials
TODO: Fix Debug config invalid sockets

# Notice
This library is anything but stable currently. Please refrain from using it in production. PRs are very welcome :)
