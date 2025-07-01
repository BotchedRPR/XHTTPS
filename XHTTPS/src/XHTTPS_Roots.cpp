// SPDX-License-Identifier: MIT
/*
* XHTTPS - a simple HTTP(S) library for Xbox 360
* based on XboxTLS (https://github.com/JakobRangel/XboxTLS)
*
* This library is released under the MIT license.
*
* This file contains helper functions for adding hardcoded Root TAs.
*/

#include "XHTTPS.h"
#include "XHTTPS_Roots.h"

void XHTTPS_AddTAs(XboxTLSContext* ctx)
{
	// TA0 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA0_DN, sizeof TA0_DN,
		(const unsigned char*)TA0_RSA_N, sizeof TA0_RSA_N,
		(const unsigned char*)TA0_RSA_E, sizeof TA0_RSA_E);

	// TA1 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA1_DN, sizeof TA1_DN,
		(const unsigned char*)TA1_RSA_N, sizeof TA1_RSA_N,
		(const unsigned char*)TA1_RSA_E, sizeof TA1_RSA_E);

	// TA2 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA2_DN, sizeof TA2_DN,
		(const unsigned char*)TA2_EC_Q, sizeof TA2_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA3 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA3_DN, sizeof TA3_DN,
		(const unsigned char*)TA3_RSA_N, sizeof TA3_RSA_N,
		(const unsigned char*)TA3_RSA_E, sizeof TA3_RSA_E);

	// TA4 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA4_DN, sizeof TA4_DN,
		(const unsigned char*)TA4_RSA_N, sizeof TA4_RSA_N,
		(const unsigned char*)TA4_RSA_E, sizeof TA4_RSA_E);

	// TA5 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA5_DN, sizeof TA5_DN,
		(const unsigned char*)TA5_RSA_N, sizeof TA5_RSA_N,
		(const unsigned char*)TA5_RSA_E, sizeof TA5_RSA_E);

	// TA6 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA6_DN, sizeof TA6_DN,
		(const unsigned char*)TA6_RSA_N, sizeof TA6_RSA_N,
		(const unsigned char*)TA6_RSA_E, sizeof TA6_RSA_E);

	// TA7 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA7_DN, sizeof TA7_DN,
		(const unsigned char*)TA7_RSA_N, sizeof TA7_RSA_N,
		(const unsigned char*)TA7_RSA_E, sizeof TA7_RSA_E);

	// TA8 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA8_DN, sizeof TA8_DN,
		(const unsigned char*)TA8_EC_Q, sizeof TA8_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA9 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA9_DN, sizeof TA9_DN,
		(const unsigned char*)TA9_RSA_N, sizeof TA9_RSA_N,
		(const unsigned char*)TA9_RSA_E, sizeof TA9_RSA_E);

	// TA10 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA10_DN, sizeof TA10_DN,
		(const unsigned char*)TA10_RSA_N, sizeof TA10_RSA_N,
		(const unsigned char*)TA10_RSA_E, sizeof TA10_RSA_E);

	// TA11 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA11_DN, sizeof TA11_DN,
		(const unsigned char*)TA11_EC_Q, sizeof TA11_EC_Q,
		XboxTLS_Curve_secp256r1);

	// TA12 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA12_DN, sizeof TA12_DN,
		(const unsigned char*)TA12_EC_Q, sizeof TA12_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA13 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA13_DN, sizeof TA13_DN,
		(const unsigned char*)TA13_RSA_N, sizeof TA13_RSA_N,
		(const unsigned char*)TA13_RSA_E, sizeof TA13_RSA_E);

	// TA14 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA14_DN, sizeof TA14_DN,
		(const unsigned char*)TA14_EC_Q, sizeof TA14_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA15 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA15_DN, sizeof TA15_DN,
		(const unsigned char*)TA15_RSA_N, sizeof TA15_RSA_N,
		(const unsigned char*)TA15_RSA_E, sizeof TA15_RSA_E);

	// TA16 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA16_DN, sizeof TA16_DN,
		(const unsigned char*)TA16_RSA_N, sizeof TA16_RSA_N,
		(const unsigned char*)TA16_RSA_E, sizeof TA16_RSA_E);

	// TA17 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA17_DN, sizeof TA17_DN,
		(const unsigned char*)TA17_RSA_N, sizeof TA17_RSA_N,
		(const unsigned char*)TA17_RSA_E, sizeof TA17_RSA_E);

	// TA18 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA18_DN, sizeof TA18_DN,
		(const unsigned char*)TA18_EC_Q, sizeof TA18_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA19 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA19_DN, sizeof TA19_DN,
		(const unsigned char*)TA19_RSA_N, sizeof TA19_RSA_N,
		(const unsigned char*)TA19_RSA_E, sizeof TA19_RSA_E);

	// TA20 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA20_DN, sizeof TA20_DN,
		(const unsigned char*)TA20_RSA_N, sizeof TA20_RSA_N,
		(const unsigned char*)TA20_RSA_E, sizeof TA20_RSA_E);

	// TA21 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA21_DN, sizeof TA21_DN,
		(const unsigned char*)TA21_RSA_N, sizeof TA21_RSA_N,
		(const unsigned char*)TA21_RSA_E, sizeof TA21_RSA_E);

	// TA22 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA22_DN, sizeof TA22_DN,
		(const unsigned char*)TA22_RSA_N, sizeof TA22_RSA_N,
		(const unsigned char*)TA22_RSA_E, sizeof TA22_RSA_E);

	// TA23 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA23_DN, sizeof TA23_DN,
		(const unsigned char*)TA23_RSA_N, sizeof TA23_RSA_N,
		(const unsigned char*)TA23_RSA_E, sizeof TA23_RSA_E);

	// TA24 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA24_DN, sizeof TA24_DN,
		(const unsigned char*)TA24_EC_Q, sizeof TA24_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA25 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA25_DN, sizeof TA25_DN,
		(const unsigned char*)TA25_RSA_N, sizeof TA25_RSA_N,
		(const unsigned char*)TA25_RSA_E, sizeof TA25_RSA_E);

	// TA26 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA26_DN, sizeof TA26_DN,
		(const unsigned char*)TA26_EC_Q, sizeof TA26_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA27 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA27_DN, sizeof TA27_DN,
		(const unsigned char*)TA27_RSA_N, sizeof TA27_RSA_N,
		(const unsigned char*)TA27_RSA_E, sizeof TA27_RSA_E);

	// TA28 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA28_DN, sizeof TA28_DN,
		(const unsigned char*)TA28_RSA_N, sizeof TA28_RSA_N,
		(const unsigned char*)TA28_RSA_E, sizeof TA28_RSA_E);

	// TA29 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA29_DN, sizeof TA29_DN,
		(const unsigned char*)TA29_RSA_N, sizeof TA29_RSA_N,
		(const unsigned char*)TA29_RSA_E, sizeof TA29_RSA_E);

	// TA30 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA30_DN, sizeof TA30_DN,
		(const unsigned char*)TA30_EC_Q, sizeof TA30_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA31 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA31_DN, sizeof TA31_DN,
		(const unsigned char*)TA31_RSA_N, sizeof TA31_RSA_N,
		(const unsigned char*)TA31_RSA_E, sizeof TA31_RSA_E);

	// TA32 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA32_DN, sizeof TA32_DN,
		(const unsigned char*)TA32_RSA_N, sizeof TA32_RSA_N,
		(const unsigned char*)TA32_RSA_E, sizeof TA32_RSA_E);

	// TA33 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA33_DN, sizeof TA33_DN,
		(const unsigned char*)TA33_RSA_N, sizeof TA33_RSA_N,
		(const unsigned char*)TA33_RSA_E, sizeof TA33_RSA_E);

	// TA34 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA34_DN, sizeof TA34_DN,
		(const unsigned char*)TA34_EC_Q, sizeof TA34_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA35 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA35_DN, sizeof TA35_DN,
		(const unsigned char*)TA35_EC_Q, sizeof TA35_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA36 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA36_DN, sizeof TA36_DN,
		(const unsigned char*)TA36_RSA_N, sizeof TA36_RSA_N,
		(const unsigned char*)TA36_RSA_E, sizeof TA36_RSA_E);

	// TA37 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA37_DN, sizeof TA37_DN,
		(const unsigned char*)TA37_RSA_N, sizeof TA37_RSA_N,
		(const unsigned char*)TA37_RSA_E, sizeof TA37_RSA_E);

	// TA38 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA38_DN, sizeof TA38_DN,
		(const unsigned char*)TA38_EC_Q, sizeof TA38_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA39 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA39_DN, sizeof TA39_DN,
		(const unsigned char*)TA39_RSA_N, sizeof TA39_RSA_N,
		(const unsigned char*)TA39_RSA_E, sizeof TA39_RSA_E);

	// TA40 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA40_DN, sizeof TA40_DN,
		(const unsigned char*)TA40_EC_Q, sizeof TA40_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA41 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA41_DN, sizeof TA41_DN,
		(const unsigned char*)TA41_RSA_N, sizeof TA41_RSA_N,
		(const unsigned char*)TA41_RSA_E, sizeof TA41_RSA_E);

	// TA42 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA42_DN, sizeof TA42_DN,
		(const unsigned char*)TA42_RSA_N, sizeof TA42_RSA_N,
		(const unsigned char*)TA42_RSA_E, sizeof TA42_RSA_E);

	// TA43 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA43_DN, sizeof TA43_DN,
		(const unsigned char*)TA43_RSA_N, sizeof TA43_RSA_N,
		(const unsigned char*)TA43_RSA_E, sizeof TA43_RSA_E);

	// TA44 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA44_DN, sizeof TA44_DN,
		(const unsigned char*)TA44_RSA_N, sizeof TA44_RSA_N,
		(const unsigned char*)TA44_RSA_E, sizeof TA44_RSA_E);

	// TA45 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA45_DN, sizeof TA45_DN,
		(const unsigned char*)TA45_RSA_N, sizeof TA45_RSA_N,
		(const unsigned char*)TA45_RSA_E, sizeof TA45_RSA_E);

	// TA46 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA46_DN, sizeof TA46_DN,
		(const unsigned char*)TA46_EC_Q, sizeof TA46_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA47 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA47_DN, sizeof TA47_DN,
		(const unsigned char*)TA47_RSA_N, sizeof TA47_RSA_N,
		(const unsigned char*)TA47_RSA_E, sizeof TA47_RSA_E);

	// TA48 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA48_DN, sizeof TA48_DN,
		(const unsigned char*)TA48_RSA_N, sizeof TA48_RSA_N,
		(const unsigned char*)TA48_RSA_E, sizeof TA48_RSA_E);

	// TA49 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA49_DN, sizeof TA49_DN,
		(const unsigned char*)TA49_EC_Q, sizeof TA49_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA50 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA50_DN, sizeof TA50_DN,
		(const unsigned char*)TA50_RSA_N, sizeof TA50_RSA_N,
		(const unsigned char*)TA50_RSA_E, sizeof TA50_RSA_E);

	// TA51 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA51_DN, sizeof TA51_DN,
		(const unsigned char*)TA51_EC_Q, sizeof TA51_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA52 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA52_DN, sizeof TA52_DN,
		(const unsigned char*)TA52_RSA_N, sizeof TA52_RSA_N,
		(const unsigned char*)TA52_RSA_E, sizeof TA52_RSA_E);

	// TA53 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA53_DN, sizeof TA53_DN,
		(const unsigned char*)TA53_RSA_N, sizeof TA53_RSA_N,
		(const unsigned char*)TA53_RSA_E, sizeof TA53_RSA_E);

	// TA54 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA54_DN, sizeof TA54_DN,
		(const unsigned char*)TA54_RSA_N, sizeof TA54_RSA_N,
		(const unsigned char*)TA54_RSA_E, sizeof TA54_RSA_E);

	// TA55 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA55_DN, sizeof TA55_DN,
		(const unsigned char*)TA55_EC_Q, sizeof TA55_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA56 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA56_DN, sizeof TA56_DN,
		(const unsigned char*)TA56_RSA_N, sizeof TA56_RSA_N,
		(const unsigned char*)TA56_RSA_E, sizeof TA56_RSA_E);

	// TA57 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA57_DN, sizeof TA57_DN,
		(const unsigned char*)TA57_EC_Q, sizeof TA57_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA58 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA58_DN, sizeof TA58_DN,
		(const unsigned char*)TA58_RSA_N, sizeof TA58_RSA_N,
		(const unsigned char*)TA58_RSA_E, sizeof TA58_RSA_E);

	// TA59 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA59_DN, sizeof TA59_DN,
		(const unsigned char*)TA59_RSA_N, sizeof TA59_RSA_N,
		(const unsigned char*)TA59_RSA_E, sizeof TA59_RSA_E);

	// TA60 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA60_DN, sizeof TA60_DN,
		(const unsigned char*)TA60_RSA_N, sizeof TA60_RSA_N,
		(const unsigned char*)TA60_RSA_E, sizeof TA60_RSA_E);

	// TA61 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA61_DN, sizeof TA61_DN,
		(const unsigned char*)TA61_RSA_N, sizeof TA61_RSA_N,
		(const unsigned char*)TA61_RSA_E, sizeof TA61_RSA_E);

	// TA62 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA62_DN, sizeof TA62_DN,
		(const unsigned char*)TA62_EC_Q, sizeof TA62_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA63 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA63_DN, sizeof TA63_DN,
		(const unsigned char*)TA63_EC_Q, sizeof TA63_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA64 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA64_DN, sizeof TA64_DN,
		(const unsigned char*)TA64_EC_Q, sizeof TA64_EC_Q,
		XboxTLS_Curve_secp256r1);

	// TA65 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA65_DN, sizeof TA65_DN,
		(const unsigned char*)TA65_EC_Q, sizeof TA65_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA66 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA66_DN, sizeof TA66_DN,
		(const unsigned char*)TA66_RSA_N, sizeof TA66_RSA_N,
		(const unsigned char*)TA66_RSA_E, sizeof TA66_RSA_E);

	// TA67 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA67_DN, sizeof TA67_DN,
		(const unsigned char*)TA67_RSA_N, sizeof TA67_RSA_N,
		(const unsigned char*)TA67_RSA_E, sizeof TA67_RSA_E);

	// TA68 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA68_DN, sizeof TA68_DN,
		(const unsigned char*)TA68_EC_Q, sizeof TA68_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA69 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA69_DN, sizeof TA69_DN,
		(const unsigned char*)TA69_RSA_N, sizeof TA69_RSA_N,
		(const unsigned char*)TA69_RSA_E, sizeof TA69_RSA_E);

	// TA70 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA70_DN, sizeof TA70_DN,
		(const unsigned char*)TA70_RSA_N, sizeof TA70_RSA_N,
		(const unsigned char*)TA70_RSA_E, sizeof TA70_RSA_E);

	// TA71 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA71_DN, sizeof TA71_DN,
		(const unsigned char*)TA71_EC_Q, sizeof TA71_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA72 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA72_DN, sizeof TA72_DN,
		(const unsigned char*)TA72_RSA_N, sizeof TA72_RSA_N,
		(const unsigned char*)TA72_RSA_E, sizeof TA72_RSA_E);

	// TA73 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA73_DN, sizeof TA73_DN,
		(const unsigned char*)TA73_EC_Q, sizeof TA73_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA74 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA74_DN, sizeof TA74_DN,
		(const unsigned char*)TA74_RSA_N, sizeof TA74_RSA_N,
		(const unsigned char*)TA74_RSA_E, sizeof TA74_RSA_E);

	// TA75 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA75_DN, sizeof TA75_DN,
		(const unsigned char*)TA75_RSA_N, sizeof TA75_RSA_N,
		(const unsigned char*)TA75_RSA_E, sizeof TA75_RSA_E);

	// TA76 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA76_DN, sizeof TA76_DN,
		(const unsigned char*)TA76_RSA_N, sizeof TA76_RSA_N,
		(const unsigned char*)TA76_RSA_E, sizeof TA76_RSA_E);

	// TA77 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA77_DN, sizeof TA77_DN,
		(const unsigned char*)TA77_RSA_N, sizeof TA77_RSA_N,
		(const unsigned char*)TA77_RSA_E, sizeof TA77_RSA_E);

	// TA78 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA78_DN, sizeof TA78_DN,
		(const unsigned char*)TA78_EC_Q, sizeof TA78_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA79 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA79_DN, sizeof TA79_DN,
		(const unsigned char*)TA79_RSA_N, sizeof TA79_RSA_N,
		(const unsigned char*)TA79_RSA_E, sizeof TA79_RSA_E);

	// TA80 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA80_DN, sizeof TA80_DN,
		(const unsigned char*)TA80_RSA_N, sizeof TA80_RSA_N,
		(const unsigned char*)TA80_RSA_E, sizeof TA80_RSA_E);

	// TA81 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA81_DN, sizeof TA81_DN,
		(const unsigned char*)TA81_RSA_N, sizeof TA81_RSA_N,
		(const unsigned char*)TA81_RSA_E, sizeof TA81_RSA_E);

	// TA82 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA82_DN, sizeof TA82_DN,
		(const unsigned char*)TA82_RSA_N, sizeof TA82_RSA_N,
		(const unsigned char*)TA82_RSA_E, sizeof TA82_RSA_E);

	// TA83 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA83_DN, sizeof TA83_DN,
		(const unsigned char*)TA83_EC_Q, sizeof TA83_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA84 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA84_DN, sizeof TA84_DN,
		(const unsigned char*)TA84_RSA_N, sizeof TA84_RSA_N,
		(const unsigned char*)TA84_RSA_E, sizeof TA84_RSA_E);

	// TA85 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA85_DN, sizeof TA85_DN,
		(const unsigned char*)TA85_RSA_N, sizeof TA85_RSA_N,
		(const unsigned char*)TA85_RSA_E, sizeof TA85_RSA_E);

	// TA86 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA86_DN, sizeof TA86_DN,
		(const unsigned char*)TA86_RSA_N, sizeof TA86_RSA_N,
		(const unsigned char*)TA86_RSA_E, sizeof TA86_RSA_E);

	// TA87 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA87_DN, sizeof TA87_DN,
		(const unsigned char*)TA87_RSA_N, sizeof TA87_RSA_N,
		(const unsigned char*)TA87_RSA_E, sizeof TA87_RSA_E);

	// TA88 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA88_DN, sizeof TA88_DN,
		(const unsigned char*)TA88_EC_Q, sizeof TA88_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA89 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA89_DN, sizeof TA89_DN,
		(const unsigned char*)TA89_RSA_N, sizeof TA89_RSA_N,
		(const unsigned char*)TA89_RSA_E, sizeof TA89_RSA_E);

	// TA90 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA90_DN, sizeof TA90_DN,
		(const unsigned char*)TA90_RSA_N, sizeof TA90_RSA_N,
		(const unsigned char*)TA90_RSA_E, sizeof TA90_RSA_E);

	// TA91 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA91_DN, sizeof TA91_DN,
		(const unsigned char*)TA91_RSA_N, sizeof TA91_RSA_N,
		(const unsigned char*)TA91_RSA_E, sizeof TA91_RSA_E);

	// TA92 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA92_DN, sizeof TA92_DN,
		(const unsigned char*)TA92_RSA_N, sizeof TA92_RSA_N,
		(const unsigned char*)TA92_RSA_E, sizeof TA92_RSA_E);

	// TA93 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA93_DN, sizeof TA93_DN,
		(const unsigned char*)TA93_RSA_N, sizeof TA93_RSA_N,
		(const unsigned char*)TA93_RSA_E, sizeof TA93_RSA_E);

	// TA94 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA94_DN, sizeof TA94_DN,
		(const unsigned char*)TA94_EC_Q, sizeof TA94_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA95 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA95_DN, sizeof TA95_DN,
		(const unsigned char*)TA95_RSA_N, sizeof TA95_RSA_N,
		(const unsigned char*)TA95_RSA_E, sizeof TA95_RSA_E);

	// TA96 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA96_DN, sizeof TA96_DN,
		(const unsigned char*)TA96_EC_Q, sizeof TA96_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA97 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA97_DN, sizeof TA97_DN,
		(const unsigned char*)TA97_RSA_N, sizeof TA97_RSA_N,
		(const unsigned char*)TA97_RSA_E, sizeof TA97_RSA_E);

	// TA98 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA98_DN, sizeof TA98_DN,
		(const unsigned char*)TA98_EC_Q, sizeof TA98_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA99 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA99_DN, sizeof TA99_DN,
		(const unsigned char*)TA99_RSA_N, sizeof TA99_RSA_N,
		(const unsigned char*)TA99_RSA_E, sizeof TA99_RSA_E);

	// TA100 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA100_DN, sizeof TA100_DN,
		(const unsigned char*)TA100_RSA_N, sizeof TA100_RSA_N,
		(const unsigned char*)TA100_RSA_E, sizeof TA100_RSA_E);

	// TA101 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA101_DN, sizeof TA101_DN,
		(const unsigned char*)TA101_EC_Q, sizeof TA101_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA102 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA102_DN, sizeof TA102_DN,
		(const unsigned char*)TA102_RSA_N, sizeof TA102_RSA_N,
		(const unsigned char*)TA102_RSA_E, sizeof TA102_RSA_E);

	// TA103 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA103_DN, sizeof TA103_DN,
		(const unsigned char*)TA103_RSA_N, sizeof TA103_RSA_N,
		(const unsigned char*)TA103_RSA_E, sizeof TA103_RSA_E);

	// TA104 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA104_DN, sizeof TA104_DN,
		(const unsigned char*)TA104_RSA_N, sizeof TA104_RSA_N,
		(const unsigned char*)TA104_RSA_E, sizeof TA104_RSA_E);

	// TA105 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA105_DN, sizeof TA105_DN,
		(const unsigned char*)TA105_EC_Q, sizeof TA105_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA106 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA106_DN, sizeof TA106_DN,
		(const unsigned char*)TA106_RSA_N, sizeof TA106_RSA_N,
		(const unsigned char*)TA106_RSA_E, sizeof TA106_RSA_E);

	// TA107 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA107_DN, sizeof TA107_DN,
		(const unsigned char*)TA107_RSA_N, sizeof TA107_RSA_N,
		(const unsigned char*)TA107_RSA_E, sizeof TA107_RSA_E);

	// TA108 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA108_DN, sizeof TA108_DN,
		(const unsigned char*)TA108_EC_Q, sizeof TA108_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA109 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA109_DN, sizeof TA109_DN,
		(const unsigned char*)TA109_RSA_N, sizeof TA109_RSA_N,
		(const unsigned char*)TA109_RSA_E, sizeof TA109_RSA_E);

	// TA110 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA110_DN, sizeof TA110_DN,
		(const unsigned char*)TA110_RSA_N, sizeof TA110_RSA_N,
		(const unsigned char*)TA110_RSA_E, sizeof TA110_RSA_E);

	// TA111 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA111_DN, sizeof TA111_DN,
		(const unsigned char*)TA111_RSA_N, sizeof TA111_RSA_N,
		(const unsigned char*)TA111_RSA_E, sizeof TA111_RSA_E);

	// TA112 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA112_DN, sizeof TA112_DN,
		(const unsigned char*)TA112_RSA_N, sizeof TA112_RSA_N,
		(const unsigned char*)TA112_RSA_E, sizeof TA112_RSA_E);

	// TA113 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA113_DN, sizeof TA113_DN,
		(const unsigned char*)TA113_RSA_N, sizeof TA113_RSA_N,
		(const unsigned char*)TA113_RSA_E, sizeof TA113_RSA_E);

	// TA114 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA114_DN, sizeof TA114_DN,
		(const unsigned char*)TA114_RSA_N, sizeof TA114_RSA_N,
		(const unsigned char*)TA114_RSA_E, sizeof TA114_RSA_E);

	// TA115 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA115_DN, sizeof TA115_DN,
		(const unsigned char*)TA115_RSA_N, sizeof TA115_RSA_N,
		(const unsigned char*)TA115_RSA_E, sizeof TA115_RSA_E);

	// TA116 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA116_DN, sizeof TA116_DN,
		(const unsigned char*)TA116_RSA_N, sizeof TA116_RSA_N,
		(const unsigned char*)TA116_RSA_E, sizeof TA116_RSA_E);

	// TA117 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA117_DN, sizeof TA117_DN,
		(const unsigned char*)TA117_RSA_N, sizeof TA117_RSA_N,
		(const unsigned char*)TA117_RSA_E, sizeof TA117_RSA_E);

	// TA118 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA118_DN, sizeof TA118_DN,
		(const unsigned char*)TA118_RSA_N, sizeof TA118_RSA_N,
		(const unsigned char*)TA118_RSA_E, sizeof TA118_RSA_E);

	// TA119 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA119_DN, sizeof TA119_DN,
		(const unsigned char*)TA119_EC_Q, sizeof TA119_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA120 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA120_DN, sizeof TA120_DN,
		(const unsigned char*)TA120_RSA_N, sizeof TA120_RSA_N,
		(const unsigned char*)TA120_RSA_E, sizeof TA120_RSA_E);

	// TA121 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA121_DN, sizeof TA121_DN,
		(const unsigned char*)TA121_RSA_N, sizeof TA121_RSA_N,
		(const unsigned char*)TA121_RSA_E, sizeof TA121_RSA_E);

	// TA122 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA122_DN, sizeof TA122_DN,
		(const unsigned char*)TA122_RSA_N, sizeof TA122_RSA_N,
		(const unsigned char*)TA122_RSA_E, sizeof TA122_RSA_E);

	// TA123 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA123_DN, sizeof TA123_DN,
		(const unsigned char*)TA123_RSA_N, sizeof TA123_RSA_N,
		(const unsigned char*)TA123_RSA_E, sizeof TA123_RSA_E);

	// TA124 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA124_DN, sizeof TA124_DN,
		(const unsigned char*)TA124_EC_Q, sizeof TA124_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA125 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA125_DN, sizeof TA125_DN,
		(const unsigned char*)TA125_RSA_N, sizeof TA125_RSA_N,
		(const unsigned char*)TA125_RSA_E, sizeof TA125_RSA_E);

	// TA126 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA126_DN, sizeof TA126_DN,
		(const unsigned char*)TA126_EC_Q, sizeof TA126_EC_Q,
		XboxTLS_Curve_secp256r1);

	// TA127 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA127_DN, sizeof TA127_DN,
		(const unsigned char*)TA127_EC_Q, sizeof TA127_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA128 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA128_DN, sizeof TA128_DN,
		(const unsigned char*)TA128_RSA_N, sizeof TA128_RSA_N,
		(const unsigned char*)TA128_RSA_E, sizeof TA128_RSA_E);

	// TA129 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA129_DN, sizeof TA129_DN,
		(const unsigned char*)TA129_RSA_N, sizeof TA129_RSA_N,
		(const unsigned char*)TA129_RSA_E, sizeof TA129_RSA_E);

	// TA130 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA130_DN, sizeof TA130_DN,
		(const unsigned char*)TA130_RSA_N, sizeof TA130_RSA_N,
		(const unsigned char*)TA130_RSA_E, sizeof TA130_RSA_E);

	// TA131 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA131_DN, sizeof TA131_DN,
		(const unsigned char*)TA131_EC_Q, sizeof TA131_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA132 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA132_DN, sizeof TA132_DN,
		(const unsigned char*)TA132_RSA_N, sizeof TA132_RSA_N,
		(const unsigned char*)TA132_RSA_E, sizeof TA132_RSA_E);

	// TA133 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA133_DN, sizeof TA133_DN,
		(const unsigned char*)TA133_RSA_N, sizeof TA133_RSA_N,
		(const unsigned char*)TA133_RSA_E, sizeof TA133_RSA_E);

	// TA134 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA134_DN, sizeof TA134_DN,
		(const unsigned char*)TA134_RSA_N, sizeof TA134_RSA_N,
		(const unsigned char*)TA134_RSA_E, sizeof TA134_RSA_E);

	// TA135 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA135_DN, sizeof TA135_DN,
		(const unsigned char*)TA135_EC_Q, sizeof TA135_EC_Q,
		XboxTLS_Curve_secp256r1);

	// TA136 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA136_DN, sizeof TA136_DN,
		(const unsigned char*)TA136_EC_Q, sizeof TA136_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA137 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA137_DN, sizeof TA137_DN,
		(const unsigned char*)TA137_EC_Q, sizeof TA137_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA138 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA138_DN, sizeof TA138_DN,
		(const unsigned char*)TA138_RSA_N, sizeof TA138_RSA_N,
		(const unsigned char*)TA138_RSA_E, sizeof TA138_RSA_E);

	// TA139 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA139_DN, sizeof TA139_DN,
		(const unsigned char*)TA139_RSA_N, sizeof TA139_RSA_N,
		(const unsigned char*)TA139_RSA_E, sizeof TA139_RSA_E);

	// TA140 (EC)
	XboxTLS_AddTrustAnchor_EC(ctx,
		(const unsigned char*)TA140_DN, sizeof TA140_DN,
		(const unsigned char*)TA140_EC_Q, sizeof TA140_EC_Q,
		XboxTLS_Curve_secp384r1);

	// TA141 (RSA)
	XboxTLS_AddTrustAnchor_RSA(ctx,
		(const unsigned char*)TA141_DN, sizeof TA141_DN,
		(const unsigned char*)TA141_RSA_N, sizeof TA141_RSA_N,
		(const unsigned char*)TA141_RSA_E, sizeof TA141_RSA_E);
}