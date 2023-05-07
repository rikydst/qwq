/*
Copyright 2023 QMK

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _SYS,
    _BLANK
};

#define LT_1BSP LT(1, KC_BSPC)
#define LT_2SPC LT(2, KC_SPC)
#define MH_DEL  MEH_T(KC_DEL)
#define HY_ENT  HYPR_T(KC_ENT)
#define CA_PGDN LCA_T(KC_PGDN)
#define CAG_END LCAG_T(KC_END)
#define AG_PGUP LAG_T(KC_PGUP)
#define CG_HOME MT(MOD_LGUI | MOD_LCTL, KC_HOME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_dactylk(
        KC_ESC,     KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                            KC_6,    KC_7,    KC_8,   KC_9,    KC_0, KC_GRV,
        KC_TAB,     KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,   KC_O,    KC_P, KC_BSLS,
        KC_CAP,     KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,   KC_L, LT_SCLN, KC_QUOT,
        KC_LSFT,    KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                                            KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                 KC_MINS, KC_EQL, KC_LBRC, KC_RBRC,                                                           KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT,
                                                             KC_LCTL, KC_LALT,     KC_RGUI, KC_RCTL,
                                                                      CG_HOME,     AG_PGUP,
                                                    LT_1BSP,  MH_DEL, CAG_END,     CA_PGDN,  HY_ENT, LT_2SPC
    ),
    [_NAV] = LAYOUT_dactylk(
        _______, _______, _______, _______, _______, _______,                                         _______,  KC_NUM, KC_PEQL, KC_PSLS, KC_PAST, _______,
        _______, _______, _______, _______, _______, _______,                                         _______,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, _______,
        _______, QK_BOOT, _______, _______, KC_SLEP, _______,                                         _______,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, _______,
        _______, _______, _______, _______, _______, _______,                                         _______,   KC_P1,   KC_P2,   KC_P3, KC_PENT, _______,
                 _______, _______, _______, _______,                                                           _______, _______, KC_PDOT, KC_PENT, 
                                                              _______, _______,     _______,   KC_P0,
                                                                       _______,     _______,
                                                     _______, _______, _______,     _______, _______,   MO(3)
    ),
    [_SYS] = LAYOUT_dactylk(
        KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                           KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  QK_F12,
        _______, KC_VOLU, KC_WBAK, KC_MS_U, KC_WFWD, KC_WH_U,                                         _______,   KC_NO,   KC_NO,  KC_NO,   KC_NO, _______,
        _______, KC_MUTE, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                         _______, KC_PSCR, KC_PAUS, KC_INS, KC_SCRL, _______,
        _______, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,                                         _______,   KC_NO,   KC_NO,  KC_NO,   KC_NO, _______,
                 _______, _______, _______, _______,                                                           _______, _______,  KC_NO,   KC_NO, 
                                                              _______, _______,     _______, _______,
                                                                       _______,     _______,
                                                     KC_BTN1, KC_BTN2, _______,     _______, _______, _______

    ),
    [_BLANK] = LAYOUT_dactylk(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
               KC_NO, KC_NO, KC_NO, KC_NO,                                                 KC_NO, KC_NO, KC_NO, KC_NO,
                                                  KC_NO, KC_NO,       KC_NO, KC_NO,
                                                         KC_NO,       KC_NO,
                                           KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO,  
    )
};
