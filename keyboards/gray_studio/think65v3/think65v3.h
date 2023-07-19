// Copyright 2023 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D,           \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3D,      k3E,      \
    k40, k41, k42,                     k47,           k4A, k4B,      k4D, k4E, k4F  \
) \
{ \
    { k00, k01,   k02,   k03, k04,   k05, k06,   k07, k08, k09,   k0A, k0B, k0C,   k0D, k0E,   k0F }, \
    { k10, KC_NO, k12,   k13, k14,   k15, k16,   k17, k18, k19,   k1A, k1B, k1C,   k1D, k1E,   k1F }, \
    { k20, KC_NO, k22,   k23, k24,   k25, k26,   k27, k28, k29,   k2A, k2B, k2C,   k2D, KC_NO, KC_NO }, \
    { k30, k31,   k32,   k33, k34,   k35, k36,   k37, k38, k39,   k3A, k3B, KC_NO, k3D, k3E,   KC_NO }, \
    { k40, k41,   K42, KC_NO,   KC_NO,KC_NO,KC_NO, k47,KC_NO, KC_NO,k4A, k4B, KC_NO, k4D, k4E,   k4F }, \
}

#define LAYOUT_65_blocker( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D,      k0F, \
    k10,      k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, \
    k20,      k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D,           \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3D,      k3E,      \
    k40, k41, k42,                     k47,           k4A, k4B,      k4D, k4E, k4F  \
) \
{ \
    { k00, k01,   k02,   k03, k04,   k05,   k06,   k07, k08,   k09,   k0A, k0B, k0C,   k0D,   KC_NO, k0F }, \
    { k10, KC_NO, k12,   k13, k14,   k15,   k16,   k17, k18,   k19,   k1A, k1B, k1C,   k1D,   k1E,   k1F }, \
    { k20, KC_NO, k22,   k23, k24,   k25,   k26,   k27, k28,   k29,   k2A, k2B, k2C,   k2D,   KC_NO, KC_NO }, \
    { k30, KC_NO, k32,   k33, k34,   k35,   k36,   k37, k38,   k39,   k3A, k3B, KC_NO, k3D,   k3E,   KC_NO }, \
    { k40, k41,   k42, KC_NO, KC_NO, KC_NO, KC_NO, k47, KC_NO, KC_NO, k4A, k4B, KC_NO, k4D,   k4E,   k4F }, \
}

#define LAYOUT_65_iso_blocker( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C,    K0D,   K0F,   \
    K10,   K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,         K1F,   \
    K20,    K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K1E, K2D,          \
    K30,  K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3D,     K3E,        \
    K40,  K41,  K42,                    K47,           K4A,  K4B,     K4D, K4E, K4F    \
) { \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   KC_NO, K0F   }, \
    { K10,   KC_NO, K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F   }, \
    { K20,   KC_NO, K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   K2C,   K2D,   KC_NO, KC_NO }, \
    { K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   KC_NO, K3D,   K3E,   KC_NO }, \
    { K40,   K41,   K42, KC_NO,   KC_NO, KC_NO, KC_NO, K47,   KC_NO, KC_NO, K4A,   K4B,   KC_NO, K4D,   K4E,   K4F   }, \
}
