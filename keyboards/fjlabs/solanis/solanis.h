/*
Copyright 2022 <felix@fjlaboratories.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

/*
 * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┐
 * │00 ││01 │02 │03 │04 ││05 │06 │07 │08 ││09 │0A │0B │0C ││0D │ F13 Row
 * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┘
 * ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 * │00 │   │02 │03 │04 │05 │ │06 │07 │08 │09 │ │0A │0B │0C │0D │ │0E │0F │0G │
 * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐   ┌───────┐
 * │10 │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D │3E │ │1E │1F │1G │   │1D     │ 2u Backspace
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤   └───────┘
 * │20   │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C │2D   │ │2E │2F │2G │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
 * │30    │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │3D      │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤     ┌───┐       ┌──────────┐
 * │40      │41 │42 │43 │44 │45 │46 │47 │48 │49 │4A │4C    │4D │     │4F │       │4C        │ 2.75u RShift
 * ├────┬───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬────┬┴───┤ ┌───┼───┼───┐   └──────────┘
 * │50  │51  │52  │54      │55  │58        │59  │5A  │5B  │5D  │ │5E │5F │5G │
 * └────┴────┴────┴────────┴────┴──────────┴────┴────┴────┴────┘ └───┴───┴───┘
 * ┌────┬────┬────┬────────────────────────┬────┬────┬────┬────┐
 * │50  │51  │52  │55                      │59  │5A  │5B  │5D  │ Standard Bottom Row
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
 * ┌─────┬───┬─────┬───────────────────────────┬─────┬───┬─────┐
 * │50   │51 │52   │55                         │5A   │5B │5D   │ Tsangan/WKL
 * └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
 * ┌─────┬───┬─────┬───────────┬───┬───────────┬─────┬───┬─────┐
 * │50   │51 │52   │54         │55 │58         │5A   │5B │5D   │ Tsangan/WKL with Split Spacebar
 * └─────┴───┴─────┴───────────┴───┴───────────┴─────┴───┴─────┘
 */

/* === All used matrix spots populated === */
#define LAYOUT_all( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D,        K0E, K0F, K0G, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K3E,   K1E, K1F, K1G, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,        K2E, K2F, K2G, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D,                       \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A,      K4C, K4D,             K4F,      \
    K50, K51, K52,      K54, K55,           K58, K59, K5A, K5B,      K5D,        K5E, K5F, K5G  \
) { \
    { K00, K01,   K02, K03,   K04,   K05, K06,   K07,   K08,   K09, K0A, K0B,   K0C,   K0D,   K0E,   K0F,   K0G   }, \
    { K10, K11,   K12, K13,   K14,   K15, K16,   K17,   K18,   K19, K1A, K1B,   K1C,   K1D,   K1E,   K1F,   K1G   }, \
    { K20, K21,   K22, K23,   K24,   K25, K26,   K27,   K28,   K29, K2A, K2B,   K2C,   K2D,   K2E,   K2F,   K2G   }, \
    { K30, K31,   K32, K33,   K34,   K35, K36,   K37,   K38,   K39, K3A, K3B,   KC_NO, K3D,   K3E,   KC_NO, KC_NO }, \
    { K40, K41,   K42, K43,   K44,   K45, K46,   K47,   K48,   K49, K4A, KC_NO, K4C,   K4D,   KC_NO, K4F,   KC_NO }, \
    { K50, K51,   K52, KC_NO, K54,   K55, KC_NO, KC_NO, K58,   K59, K5A, K5B,   KC_NO, K5D,   K5E,   K5F,   K5G   } \
}
