#pragma once

#include "slice.h"

#include "quantum.h"
//////////////////////////////////////////////////////////////////////////////
// When only use Slice Rev0.
//////////////////////////////////////////////////////////////////////////////
/*
 * ,------------------------------------------------   ----------------------------------------------.
 * | L00 | L01 | L02 | L03 | L04 | L05 | L06 | L07 |   | R07 | R06 | R05 | R04 | R03 | R02 |   R01   |
 * |---------------------------------------------------------------------------------------------------+
 * | L10 |   L11  | L12 | L13 | L14 | L15 | L16 |   | R17 | R16 | R15 | R14 | R13 | R12 | R11 |   R31  |
 * |----------------------------------------------  ---------------------------------------------------+
 * | L20 |   L21   | L22 | L23 | L24 | L25 | L26 |   | R27 | R26 | R25 | R24 | R23 | R22 |     R21     |
 * |---------------------------------------------------------------------------------------------------+
 * | L30 |    L31     | L32 | L33 | L34 | L35 | L36 |   | R37 | R36 | R35 | R34 | R33 |      R32       |
 * |-------------------------------------------------   -----------------------------------------------'
 *           | L40 |  L41  |  L42  | L43 | L44L45L46 |    |  R47  |    R46   |  R45  | R44 | R43 |
 *           |----------------------------------------   ----------------------------------------'
 */
#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07,      R01, R02, R03, R04, R05, R06, R07, \
    L10, L11, L12, L13, L14, L15, L16,      R10, R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25, L26,           R21, R22, R23, R24, R25, R26, R27, \
    L30, L31, L32, L33, L34, L35, L36,                R32, R33, R34, R35, R36, R37, \
    L40, L41, L42, L43, L44, L45, L46,                     R43, R44, R45, R46, R47 \
  ) \
  { \
	{ R01,   R02,   R03,   R04,   R05,   R06,   R07,   KC_NO }, \
	{ R10,   R11,   R12,   R13,   R14,   R15,   R16,   R17 }, \
	{ R21,   R22,   R23,   R24,   R25,   R26,   R27,   KC_NO }, \
	{ R32,   R33,   R34,   R35,   R36,   R37,   KC_NO, KC_NO, }, \
    { R43,   R44,   R45,   R46,   R47,   KC_NO, KC_NO, KC_NO },  \
    { KC_NO, L46,   L45,   L44,   L43,   L42,   L41,   L40 }, \
    { KC_NO, L36,   L35,   L34,   L33,   L32,   L31,   L31 }, \
    { KC_NO, L26,   L25,   L24,   L23,   L22,   L21,   L20 }, \
    { KC_NO, L16,   L15,   L14,   L13,   L12,   L11,   L10 }, \
    { L07,	 L06,	L05,   L04,   L03,	 L02,	L01,   L00 }, \