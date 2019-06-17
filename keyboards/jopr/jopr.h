#ifndef JOPR_H
#define JOPR_H

#include "quantum.h"

#define LAYOUT ( \
    MX_A0,  MX_B0, MX_C0, MX_D0, MX_E0,  MX_F0, MX_G0, MX_H0, MX_I0,  MX_J0, MX_A6, MX_B6, MX_C6,  MX_D6,  MX_E6, MX_F6, MX_G6, MX_H6, \
    MX_A1, MX_B1, MX_C1, MX_D1, MX_E1, MX_F1, MX_G1, MX_H1, MX_I1, MX_J1, MX_A7, MX_B7, MX_C7, MX_D7,      MX_E7, MX_F7, MX_G7, MX_H7, \
    MX_A2,   MX_B2, MX_C2, MX_D2, MX_E2, MX_F2, MX_G2, MX_H2, MX_I2, MX_J2, MX_A8, MX_B8, MX_C8, MX_D8,    MX_E8, MX_F8, MX_G8, MX_H8, \
    MX_A3,    MX_B3, MX_C3, MX_D3, MX_E3, MX_F3, MX_G3, MX_H3, MX_I3, MX_J3, MX_A9, MX_B9, MX_C9,          MX_E9, MX_F9, MX_G9,         MX_H9, MX_K1, MX_K0, \
	MX_A4,  MX_B4, MX_C4, MX_D4, MX_E4, MX_F4, MX_G4, MX_H4, MX_I4, MX_J4, MX_I9, MX_I8, MX_I7,            MX_I6, MX_J9, MX_J8, MX_J7,  MX_J6, MX_K3, MX_K2, \
    MX_A5,  MX_B5, MX_C5, MX_D5,                                          MX_J5,  MX_I5,  MX_K9,  MX_E5,   MX_K8,        MX_K7,         MX_K6, MX_K5, MX_K4 \
) { \
	{ MX_A0, MX_B0, MX_C0, MX_D0, MX_E0, MX_F0, MX_G0, MX_H0, MX_I0, MX_J0, MX_K0 }, \
	{ MX_A1, MX_B1, MX_C1, MX_D1, MX_E1, MX_F1, MX_G1, MX_H1, MX_I1, MX_J1, MX_K1 }, \
	{ MX_A2, MX_B2, MX_C2, MX_D2, MX_E2, MX_F2, MX_G2, MX_H2, MX_I2, MX_J2, MX_K2 }, \
	{ MX_A3, MX_B3, MX_C3, MX_D3, MX_E3, MX_F3, MX_G3, MX_H3, MX_I3, MX_J3, MX_K3 }, \
	{ MX_A4, MX_B4, MX_C4, MX_D4, MX_E4, MX_F4, MX_G4, MX_H4, MX_I4, MX_J4, MX_K4 }, \
	{ MX_A5, MX_B5, MX_C5, MX_D5, MX_E5, KC_NO, KC_NO, KC_NO, MX_I5, MX_J5, MX_K5 }, \
	{ MX_A6, MX_B6, MX_C6, MX_D6, MX_E6, MX_F6, MX_G6, MX_H6, MX_I6, MX_J6, MX_K6 }, \
	{ MX_A7, MX_B7, MX_C7, MX_D7, MX_E7, MX_F7, MX_G7, MX_H7, MX_I7, MX_J7, MX_K7 }, \
	{ MX_A8, MX_B8, MX_C8, MX_D8, MX_E8, MX_F8, MX_G8, MX_H8, MX_I8, MX_J8, MX_K8 }, \
	{ MX_A9, MX_B9, MX_C9, KC_NO, MX_E9, MX_F9, MX_G9, MX_H9, MX_I9, MX_J9, MX_K9 }  \
}

#endif