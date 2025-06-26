# XHTTPS

XHTTPS is an early, non-production-ready Xbox 360 HTTPS library.
It supports basic GET requests using XboxTLS for TLS1.2 encryption. 


# Install guide

XHTTPS is provided alongside a Demo utility. To test the library, follow these steps:

 1. Clone the repo, and place XboxTLS alongside the XHTTPS and XHTTPS_Demo folders.
 2. Open the demo project in Visual Studio 2010 (with the Xbox 360 SDK installed)
 3. All dependencies should be sorted out. If not, manually add project references (right click XHTTPS_Demo, XHTTPS, **Add -> Reference** and select XHTTPS for XHTTPS_Demo and XboxTLS for XHTTPS.
 4. Build and run using Release_LTCG configuration.
 5. You should have a connection :)

TODO: Write more tutorials

# Generating TAs

XboxTLS (and, as such XHTTPS) requires to provide TAs for the domains you wish to load in your client application.
This is easily accomplished using the BearSSL `brssl` command. First of all, download the certificates (using OpenSSL, or your favorite web browser. 
For example, on Firefox:


### Step 1: Open Certificate Details
![Step 1](https://github.com/user-attachments/assets/38241404-2e2a-4223-86ba-c6977c247451)

- Click the **More information** button.

---

### Step 2: View the Certificate
![Step 2](https://github.com/user-attachments/assets/a6c1b426-c88a-40e7-ab3c-6e3d6b0150d4)

- Click the **View Certificate** button.

---

### Step 3: Select the Website Certificate
![Step 3](https://github.com/user-attachments/assets/51457553-5b3e-47da-92b2-1a65b17d3937)

- Switch to the **Website certificate** tab (e.g., `google.com`).

---

### Step 4: Download Certificates
![Step 4](https://github.com/user-attachments/assets/5ae30533-2928-4936-8bd5-783a3e34b644)

- Click **Download** to save the website certificate.
- Then, click the **Root Certificate** in the top bar (e.g., `GTS Root R4`) and download it as well.

Now let's convert all of these certificates to a BearSSL-compatible array. On a Linux system (or WSL)
```bash
[igor@DESKTOP-IAGBS4H ~]$ brssl ta /mnt/c/Users/bochen/Downloads/www-google-com.pem /mnt/c/Users/bochen/Downloads/www-google-com\(1\).pem
Reading file '/mnt/c/Users/bochen/Downloads/www-google-com.pem': 1 trust anchor
Reading file '/mnt/c/Users/bochen/Downloads/www-google-com(1).pem': 1 trust anchor

<certificate data>

static const br_x509_trust_anchor TAs[2] = {
        {
                { (unsigned char *)TA0_DN, sizeof TA0_DN },
                0,
                {
                        BR_KEYTYPE_EC,
                        { .ec = {
                                BR_EC_secp256r1,
                                (unsigned char *)TA0_EC_Q, sizeof TA0_EC_Q,
                        } }
                }
        },
        {
                { (unsigned char *)TA1_DN, sizeof TA1_DN },
                BR_X509_TA_CA,
                {
                        BR_KEYTYPE_EC,
                        { .ec = {
                                BR_EC_secp384r1,
                                (unsigned char *)TA1_EC_Q, sizeof TA1_EC_Q,
                        } }
                }
        }
};

#define TAs_NUM   2
```
Now we know that it uses two EC type certificates. One using a secp256r1 curve and one with a secp384r1 curve.
After adding in the arrays to the application, you can add them into the trust store using XHTTPS_Add_EC_TA (or XHTTPS_Add_RSA_TA if you have a RSA TA), as such:
```c
	// Add TAs
	ret_xhttps = XHTTPS_Add_EC_TA(TA0_DN, sizeof(TA0_DN), TA0_EC_Q, sizeof(TA0_EC_Q), XboxTLS_Curve_secp256r1);
	if (ret_xhttps != XHTTPS_OK)
		printf("Could not add 1st TA. XHTTPS returned: %i\n", ret_xhttps);

	ret_xhttps = XHTTPS_Add_EC_TA(TA1_DN, sizeof(TA1_DN), TA1_EC_Q, sizeof(TA1_EC_Q), XboxTLS_Curve_secp384r1);
	if (ret_xhttps != XHTTPS_OK)
		printf("Could not add 2nd TA. XHTTPS returned: %i\n", ret_xhttps);
```

After this, you should have two TAs which will allow HTTPS communication. Easy, huh? :)

# Notice
This library is anything but stable currently. Please refrain from using it in production. PRs are very welcome :)
