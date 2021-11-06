#pragma once

#include "quantum.h"

void _idb_60_caps_led_on(void);
void _idb_60_fn_led_on(void);
void _idb_60_caps_led_off(void);
void _idb_60_fn_led_off(void);

#define _idb_60_esc_led_on() _idb_60_fn_led_on()
#define _idb_60_esc_led_off() _idb_60_fn_led_off()

#define XXX KC_NO

/*
 *              ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐      ┌───────┐
 *              │00 │10 │01 │11 │02 │12 │03 │13 │04 │14 │05 │15 │06 │16 │07 │      │16     │ 2u Backspace
 *              ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤      └─┬─────┤
 *              │20   │30 │21 │31 │22 │32 │23 │33 │24 │34 │25 │35 │26 │36   │        │     │
 *  2.25u       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤     ┌──┴┐56  │ ISO Enter
 *  LShift      │40    │50 │41 │51 │42 │52 │43 │53 │44 │54 │45 │55 │56      │     │36 │    │
 * ┌────────┐   ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤   ┌─┴───┴────┤
 * │60      │   │60  │70 │61 │71 │62 │72 │63 │73 │64 │74 │65 │75 │66    │76 │   │66        │ 2.75u RShift
 * └────────┘   ├────┴┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬───┬─┴───┤   └──────────┘
 *              │80   │90 │81   │93                         │95   │86 │96   │
 *              └─────┴───┴─────┴───────────────────────────┴─────┴───┴─────┘
 *              ┌─────┬───┬─────┬───────────────────────────┬─────┬───┬─────┐
 *              │80   │   │81   │93                         │95   │   │96   │ WKL
 *              └─────┘   └─────┴───────────────────────────┴─────┘   └─────┘
 *                    ┌───┬─────┬───────────────────────────┬─────┬───┐
 *                    │90 │81   │93                         │95   │86 │ MX HHKB
 *                    └───┴─────┴───────────────────────────┴─────┴───┘
 *                    ┌───┬─────┬───────────────────────┬─────┬───┐
 *                    │90 │81   │93                     │95   │86 │ True HHKB
 *                    └───┴─────┴───────────────────────┴─────┴───┘
 */


#define LAYOUT_all( \
        K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, K07, \
        K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36, \
        K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55,      K56, \
        K60, K70, K61, K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76, \
        K80, K90, K81,                     K93,                K95, K86, K96 \
) { \
        { K00, K01, K02, K03, K04, K05, K06, K07 }, \
        { K10, K11, K12, K13, K14, K15, K16, XXX }, \
        { K20, K21, K22, K23, K24, K25, K26, XXX }, \
        { K30, K31, K32, K33, K34, K35, K36, XXX }, \
        { K40, K41, K42, K43, K44, K45, XXX, XXX }, \
        { K50, K51, K52, K53, K54, K55, K56, XXX }, \
        { K60, K61, K62, K63, K64, K65, K66, XXX }, \
        { K70, K71, K72, K73, K74, K75, K76, XXX }, \
        { K80, K81, XXX, XXX, XXX, XXX, K86, XXX }, \
        { K90, XXX, XXX, K93, XXX, K95, K96, XXX } \
}

#define LAYOUT_60_ansi_tsangan( \
        K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, \
        K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36, \
        K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55,      K56, \
        K60,      K61, K71, K62, K72, K63, K73, K64, K74, K65, K75,      K66, \
        K80, K90, K81,                     K93,                K95, K86, K96 \
) { \
        { K00, K01, K02, K03, K04, K05, K06, XXX }, \
        { K10, K11, K12, K13, K14, K15, K16, XXX }, \
        { K20, K21, K22, K23, K24, K25, K26, XXX }, \
        { K30, K31, K32, K33, K34, K35, K36, XXX }, \
        { K40, K41, K42, K43, K44, K45, XXX, XXX }, \
        { K50, K51, K52, K53, K54, K55, K56, XXX }, \
        { K60, K61, K62, K63, K64, K65, K66, XXX }, \
        { XXX, K71, K72, K73, K74, K75, XXX, XXX }, \
        { K80, K81, XXX, XXX, XXX, XXX, K86, XXX }, \
        { K90, XXX, XXX, K93, XXX, K95, K96, XXX } \
}

#define LAYOUT_60_tsangan_hhkb( \
        K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, K07, \
        K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36, \
        K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55,      K56, \
        K60,      K61, K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76, \
        K80, K90, K81,                     K93,                K95, K86, K96 \
) { \
        { K00, K01, K02, K03, K04, K05, K06, K07 }, \
        { K10, K11, K12, K13, K14, K15, K16, XXX }, \
        { K20, K21, K22, K23, K24, K25, K26, XXX }, \
        { K30, K31, K32, K33, K34, K35, K36, XXX }, \
        { K40, K41, K42, K43, K44, K45, XXX, XXX }, \
        { K50, K51, K52, K53, K54, K55, K56, XXX }, \
        { K60, K61, K62, K63, K64, K65, K66, XXX }, \
        { XXX, K71, K72, K73, K74, K75, K76, XXX }, \
        { K80, K81, XXX, XXX, XXX, XXX, K86, XXX }, \
        { K90, XXX, XXX, K93, XXX, K95, K96, XXX } \
}

#define LAYOUT_60_ansi_wkl_split_rshift( \
        K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, \
        K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26, K36, \
        K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55,      K56, \
        K60,      K61, K71, K62, K72, K63, K73, K64, K74, K65, K75, K66, K76, \
        K80,      K81,                     K93,                K95,      K96 \
) { \
        { K00, K01, K02, K03, K04, K05, K06, XXX }, \
        { K10, K11, K12, K13, K14, K15, K16, XXX }, \
        { K20, K21, K22, K23, K24, K25, K26, XXX }, \
        { K30, K31, K32, K33, K34, K35, K36, XXX }, \
        { K40, K41, K42, K43, K44, K45, XXX, XXX }, \
        { K50, K51, K52, K53, K54, K55, K56, XXX }, \
        { K60, K61, K62, K63, K64, K65, K66, XXX }, \
        { XXX, K71, K72, K73, K74, K75, K76, XXX }, \
        { K80, K81, XXX, XXX, XXX, XXX, XXX, XXX }, \
        { XXX, XXX, XXX, K93, XXX, K95, K96, XXX } \
}

#define LAYOUT_60_iso_tsangan( \
        K00, K10, K01, K11, K02, K12, K03, K13, K04, K14, K05, K15, K06, K16, \
        K20, K30, K21, K31, K22, K32, K23, K33, K24, K34, K25, K35, K26,      \
        K40, K50, K41, K51, K42, K52, K43, K53, K44, K54, K45, K55, K36, K56, \
        K60, K70, K61, K71, K62, K72, K63, K73, K64, K74, K65, K75,      K66, \
        K80, K90, K81,                     K93,                K95, K86, K96 \
) { \
        { K00, K01, K02, K03, K04, K05, K06, XXX }, \
        { K10, K11, K12, K13, K14, K15, K16, XXX }, \
        { K20, K21, K22, K23, K24, K25, K26, XXX }, \
        { K30, K31, K32, K33, K34, K35, K36, XXX }, \
        { K40, K41, K42, K43, K44, K45, XXX, XXX }, \
        { K50, K51, K52, K53, K54, K55, K56, XXX }, \
        { K60, K61, K62, K63, K64, K65, K66, XXX }, \
        { K70, K71, K72, K73, K74, K75, XXX, XXX }, \
        { K80, K81, XXX, XXX, XXX, XXX, K86, XXX }, \
        { K90, XXX, XXX, K93, XXX, K95, K96, XXX } \
}
