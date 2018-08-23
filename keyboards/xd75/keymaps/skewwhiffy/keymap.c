/* Copyright 2017 Kenny Hung
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "xd75.h"
#include "keymap_uk.h"

#define _______ KC_TRNS

// Layer shorthand
#define _CM 0 // Colemak
#define _DV 1 // Dvorak
#define _QW 2 // QWERTY
#define _NBL 3 // Numbers left
#define _NBR 4 // Numbers right
#define _SYL 5 // Symbols left
#define _SYR 6 // Symbols right
#define _NAV 7 // Navigation

// Layer buttons
#define _Z_SFT SFT_T(UK_Z)
#define _SCLSH SFT_T(UK_SCLN)
#define _SLSH SFT_T(UK_SLSH)
#define _X_NB LT(_NBL, UK_X)
#define _Q_NB LT(_NBL, UK_Q)
#define _DOT_NB LT(_NBR, UK_DOT)
#define _V_NB LT(_NBR, UK_V)
#define __NBL LT(_NBL, _______)
#define __NBR LT(_NBR, _______)
#define _C_SY LT(_SYL, UK_C)
#define _J_SY LT(_SYL, UK_J)
#define _W_SY LT(_SYR, UK_W)
#define _COM_SY LT(_SYR, UK_COMM)
#define __SYL LT(_SYL, _______)
#define __SYR LT(_SYR, _______)
#define _B_NAV LT(_NAV, UK_B)
#define _X_NAV LT(_NAV, UK_X)
#define _K_NAV LT(_NAV, UK_K)
#define _N_NAV LT(_NAV, UK_N)
#define __NAV LT(_NAV, _______)
#define __NAV LT(_NAV, _______)

// Custom hotkeys
#define _TERM LCTL(UK_QUOT) // Hotkey for Cmder or iTerm
#define _S_TAB S(UK_TAB)
#define _C_LEFT LCTL(UK_LEFT)
#define _C_RGHT LCTL(UK_RGHT)
#define _A_LEFT LALT(UK_LEFT)
#define _A_RGHT LALT(UK_RGHT)

enum custom_keycodes {
  IJ_OMN = SAFE_RANGE // IntelliJ Omnibox
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak _CM
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | Q      | W      | F      | P      | G      |        |        |        |        |        | J      | L      | U      | Y      | ;      |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | A      | R      | S      | T      | D      |        |        |        |        |        | H      | N      | E      | I      | O      |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | Z      | X      | C      | V      | B      |        |        |        |        |        | K      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL |        | NAV    |        |        |        |        |        | NAV    |        | SYMBOL | FUNC   | SHIFT  |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | LSHIFT | LCTRL  | LALT   | LGUI   | SPACE  | ENT    |        |        |        | DEL    | BKSPC  | RGUI   | RALT   | RCTRL  | RSHIFT |
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 */
 [_CM] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { UK_Q,    UK_W,    UK_F,    UK_P,    UK_G,    _______, _______, _______, _______, _______, UK_J,    UK_L,    UK_U,    UK_Y,    UK_SCLN },
  { UK_A,    UK_R,    UK_S,    UK_T,    UK_D,    _______, _______, _______, _______, _______, UK_H,    UK_N,    UK_E,    UK_I,    UK_O    },
  { _Z_SFT,  _X_NB,   _C_SY,   UK_V,    _B_NAV,  _______, _______, _______, _______, _______, _K_NAV,  UK_M,    _COM_SY, _DOT_NB, _SLSH   },
  { UK_LSFT, UK_LCTL, UK_LALT, UK_LGUI, UK_SPC,  UK_ENT,  _______, _______, _______, UK_DEL,  UK_BSPC, UK_RGUI, UK_RALT, UK_RCTL, UK_RSFT }
 },

/* DVORAK _DV
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | '      | ,      | .      | P      | Y      |        |        |        |        |        | F      | G      | C      | R      | L      |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | A      | O      | E      | U      | I      |        |        |        |        |        | D      | H      | T      | N      | S      |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | ;      | Q      | J      | K      | X      |        |        |        |        |        | B      | M      | W      | V      | Z      |
 * | SHIFT  | NUMBER | SYMBOL |        | NAV    |        |        |        |        |        | NAV    |        | SYMBOL | FUNC   | SHIFT  |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 */
 [_DV] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { UK_QUOT, UK_COMM, UK_DOT,  UK_P,    UK_Y,    _______, _______, _______, _______, _______, UK_F,    UK_G,    UK_C,    UK_R,    UK_L    },
  { UK_A,    UK_O,    UK_E,    UK_U,    UK_I,    _______, _______, _______, _______, _______, UK_D,    UK_H,    UK_T,    UK_N,    UK_S    },
  { _SCLSH,  _Q_NB,   _J_SY,   UK_K,    _X_NAV,  _______, _______, _______, _______, _______, _B_NAV,  UK_M,    _W_SY,   _V_NB,   _Z_SFT  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
 },

/* QWERTY _QW
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | Q      | W      | E      | R      | T      |        |        |        |        |        | Y      | U      | I      | O      | P      |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | A      | S      | D      | F      | G      |        |        |        |        |        | H      | J      | K      | L      | ;      |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | Z      | X      | C      | V      | B      |        |        |        |        |        | N      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL |        | NAV    |        |        |        |        |        | NAV    |        | SYMBOL | FUNC   | SHIFT  |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------------------------------------------------------------------------------------------------------------------------------------|
 * | LSHIFT | LCTRL  | LALT   | LGUI   | SPACE  | ENT    |        |        |        | DEL    | BKSPC  | RGUI   | RALT   | RCTRL  | RSHIFT |
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 */
 [_QW] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,    _______, _______, _______, _______, _______, UK_Y,    UK_U,    UK_I,    UK_O,    UK_P    },
  { UK_A,    UK_S,    UK_D,    UK_F,    UK_G,    _______, _______, _______, _______, _______, UK_H,    UK_J,    UK_K,    UK_L,    UK_SCLN },
  { _Z_SFT,  _X_NB,   _C_SY,   UK_V,    _B_NAV,  _______, _______, _______, _______, _______, _N_NAV,  UK_M,    _COM_SY, _DOT_NB, _SLSH   },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
 },

/* Numbers _NB
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | F7     | F8     | F9     | F10    |        |        |        |        |        |        | 7      | 8      | 9      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F4     | F5     | F6     | F11    |        |        |        |        |        |        | 4      | 5      | 6      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | F1     | F2     | F3     | F12    |        |        |        |        |        | 0      | 1      | 2      | 3      | .      |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_NBL] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, UK_F7,   UK_F8,   UK_F9,   UK_F10,  _______, _______, _______, _______, _______, _______, UK_7,    UK_8,    UK_9,    _______ },
  { _______, UK_F4,   UK_F5,   UK_F6,   UK_F11,  _______, _______, _______, _______, _______, _______, UK_4,    UK_5,    UK_6,    _______ },
  { _______, __NBL,   UK_F2,   UK_F3,   UK_F12,  _______, _______, _______, _______, _______, UK_0,    UK_1,    UK_2,    UK_3,    UK_DOT  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
 },
 [_NBR] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { _______, UK_F7,   UK_F8,   UK_F9,   UK_F10,  _______, _______, _______, _______, _______, _______, UK_7,    UK_8,    UK_9,    _______ },
  { _______, UK_F4,   UK_F5,   UK_F6,   UK_F11,  _______, _______, _______, _______, _______, _______, UK_4,    UK_5,    UK_6,    _______ },
  { _______, UK_F1,   UK_F2,   UK_F3,   UK_F12,  _______, _______, _______, _______, _______, UK_0,    UK_1,    UK_2,    __NBR,   UK_DOT  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
 },

/* Symbols _SY
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | !      | £      | _      | -      | ~      |        |        |        |        |        | \      | {      | }      | /      | #      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | $      | %      | +      | =      |        |        |        |        |        |        | "      | (      | )      | '      | @      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ^      | &      | *      | |      |        |        |        |        |        |        | <      | [      | ]      | >      | `      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_SYL] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { UK_EXLM, UK_PND,  UK_UNDS, UK_MINS, UK_TILD, _______, _______, _______, _______, _______, UK_BSLS, UK_LCBR, UK_RCBR, UK_SLSH, UK_HASH },
  { UK_DLR,  UK_PERC, UK_PLUS, UK_EQL,  _______, _______, _______, _______, _______, _______, UK_DQUO, UK_LPRN, UK_RPRN, UK_QUOT, UK_AT   },
  { UK_CIRC, UK_AMPR, __SYL,   UK_PIPE, _______, _______, _______, _______, _______, _______, UK_LABK, UK_LBRC, UK_RBRC, UK_RABK, UK_GRV  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
 },
 [_SYR] = {
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { UK_EXLM, UK_PND,  UK_UNDS, UK_MINS, UK_TILD, _______, _______, _______, _______, _______, UK_BSLS, UK_LCBR, UK_RCBR, UK_SLSH, UK_HASH },
  { UK_DLR,  UK_PERC, UK_PLUS, UK_EQL,  _______, _______, _______, _______, _______, _______, UK_DQUO, UK_LPRN, UK_RPRN, UK_QUOT, UK_AT   },
  { UK_CIRC, UK_AMPR, UK_ASTR, UK_PIPE, _______, _______, _______, _______, _______, _______, UK_LABK, UK_LBRC, __SYR,   UK_RABK, UK_GRV  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
 },
/*
 * Navigation
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | RESET  | COLEMA | DVORAK | QWERTY |        | RGB_TG |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Esc    | Ctrl L | Up     | Ctrl R |        | RGB HD | RGB HI |        |        |        |        | PtSn   | ScLk   | Pause  |        |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Tab    | Left   | Down   | Right  |        | RGB SD | RGB SI |        |        |        |        | Insert | Home   | PgUp   | Term   |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ShTab  | Alt L  | Shift  | Alt R  |        | RGB VD | RGB VI |        |        |        |        | ScLk   | End    | PgDn   |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        | RGB RMD| RGB MD |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
 [_NAV] = {
  { RESET,   DF(_CM), DF(_DV), DF(_QW), _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
  { UK_ESC,  _C_LEFT, UK_UP  , _C_RGHT, _______, RGB_HUD, RGB_HUI, _______, _______, _______, _______, UK_PSCR, UK_SLCK, UK_PAUS, _______ },
  { UK_TAB,  UK_LEFT, UK_DOWN, UK_RGHT, _______, RGB_SAD, RGB_SAI, _______, _______, _______, _______, UK_INS,  UK_HOME, UK_PGUP, _TERM   },
  { _S_TAB,  _A_LEFT, IJ_OMN,  _A_RGHT, __NAV,   RGB_VAD, RGB_VAI, _______, _______, _______, __NAV,   UK_SLCK, UK_END,  UK_PGDN, _______ },
  { _______, _______, _______, _______, _______, RGB_RMOD,RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______ }
 },
};

const uint16_t PROGMEM fn_actions[] = {

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case IJ_OMN:
        SEND_STRING(SS_TAP(X_LSHIFT)SS_TAP(X_LSHIFT));
        return false;
    }
  }
  return true;
}


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
