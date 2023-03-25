// Copyright 2023 alin m elena (@alinelena)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"

#ifdef UNICODEMAP_ENABLE
enum unicode_names { la = SAFE_RANGE, lA, lb, lB, lc, lC, ld, lD, le, lE, lf, lF, lg, lG, lh, lH, li, lI, lj, lJ, lk, lK, ll, lL, lm, lM, ln, lN, lo, lO, lp, lP, lq, lQ, lr, lR, ls, lS, lt, lT, lu, lU, lv, lV, lw, lW, lx, lX, ly, lY, lz, lZ, lc1, lC1, lp1, lP1, lq1, lQ1, ll1, lL1, lk1, lK1, lbo1, lbo2, lbc1, lbc2, ls1, ls2, ra, rA, ra1, rA1, rc, rC, ri, rI, rs, rS, rt, rT, ro, rO, ra2, rA2, ra3, rA3, rx, rX, rv, rV, rb, rB, rn, rN };
#endif

#ifdef OLED_ENABLE
void user_oled_magic(void);
void render_logo(void);
void clear_screen(void);
void init_timer(void);
#endif

#ifdef RGBLIGHT_ENABLE
void                             set_rgb_layers(layer_state_t);
const rgblight_segment_t* const* my_rgb(void);
void                             set_default_rgb_layers(layer_state_t);
void                             init_rgb_layers(void);
#endif
