/* Copyright 2023 Alex Rakowski (@agrski)
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

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _FUN,
    _KITTY,
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_Q,       KC_W,   KC_F,           KC_P,           KC_G,                   KC_J,           KC_L,           KC_U,   KC_Y,           KC_Z,
        KC_A,       KC_R,   LT(_NUM, KC_S), KC_T,           KC_D,                   KC_H,           KC_N,           KC_E,   LT(_SYM, KC_I), KC_O,
        TG(_NAV),   KC_X,   KC_C,           KC_V,           KC_TAB,                 KC_DEL,         KC_M,           KC_K,   KC_B,           TG(_FUN),
                                            CMD_T(KC_BSPC), SFT_T(KC_SPC),          CTL_T(KC_ENT),  ALT_T(KC_ESC),
    ),

    [_NUM] = LAYOUT(
            xxxxxxx,    xxxxxxx,    xxxxxxx,    xxxxxxx,            xxxxxxx,                xxxxxxx,            KC_7,           KC_8,       KC_9,    xxxxxxx,
            xxxxxxx,    _______,    KC_MINS,    KC_EQL,             xxxxxxx,                xxxxxxx,            KC_1,           KC_2,       KC_3,    KC_PERC,
            xxxxxxx,    xxxxxxx,    xxxxxxx,    KC_GRAVE,           xxxxxxx,                xxxxxxx,            KC_4,           KC_5,       KC_6,    xxxxxxx,
                                                CMD_T(KC_COMMA),    SFT_T(KC_DOT),          CTL_T(KC_QUOTE),    ALT_T(KC_0),
    ),

    [_SYM] = LAYOUT(
            KC_LABK,    KC_LBRC,    KC_RBRC,    KC_RABK,        xxxxxxx,                xxxxxxx,            xxxxxxx,        xxxxxxx,    xxxxxxx,    xxxxxxx,
            KC_CIRC,    KC_LPRN,    KC_RPRN,    KC_DLR,         KC_AT,                  xxxxxxx,            KC_TILDE,       KC_PIPE,    _______,    xxxxxxx,
            xxxxxxx,    KC_LCBR,    KC_RCBR,    KC_SCLN,        KC_AMPR,                xxxxxxx,            KC_EXLM,        xxxxxxx,    xxxxxxx,    xxxxxxx,
                                                CMD_T(KC_HASH), SFT_T(KC_ASTR),         CTL_T(KC_SLASH),    ALT_T(KC_BSLS),
    ),

    [_NAV] = LAYOUT(
        KC_MS_BTN3,     KC_MS_BTN2,     KC_UP,      KC_MS_BTN1, xxxxxxx,            xxxxxxx,    KC_MS_BTN1, KC_MS_U,    KC_MS_BTN2, KC_MS_BTN3,
        KC_ESC,         KC_LEFT,        KC_DOWN,    KC_RIGHT,   KC_WBAK,            KC_WFWD,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_ESC,
        _______,        KC_END,         KC_PGDN,    KC_PGUP,    KC_HOME,            KC_WH_L,    KC_WH_U,    KC_WH_D,    KC_WH_R,    _______,
                                                    KC_LCMD,    KC_LSFT,            KC_LCTL,    KC_LALT,
    ),

    [_FUN] = LAYOUT(
        xxxxxxx,    xxxxxxx,    xxxxxxx,    xxxxxxx,    xxxxxxx,                xxxxxxx,    BL_UP,  BL_TOGG,    BL_DOWN,    xxxxxxx,
        xxxxxxx,    KC_F1,      KC_F2,      KC_F3,      xxxxxxx,                xxxxxxx,    KC_F7,  KC_F8,      KC_F9,      xxxxxxx,
        _______,    KC_F4,      KC_F5,      KC_F6,      xxxxxxx,                xxxxxxx,    KC_F10, KC_F11,     KC_F12,     _______,
                                            KC_PASTE,   KC_COPY,                KC_VOLD,    KC_VOLU,
    ),

    [_KITTY] = LAYOUT(
        xxxxxxx,        xxxxxxx,        xxxxxxx,        xxxxxxx,        xxxxxxx,            xxxxxxx,    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        RCS(KC_COMMA),  S(KC_LEFT),     S(KC_RIGHT),    RCS(KC_DOT),    xxxxxxx,            xxxxxxx,    xxxxxxx, _______, xxxxxxx, xxxxxxx,
        RCS(KC_B),      RCS(KC_LEFT),   RCS(KC_RIGHT),  RCS(KC_F),      xxxxxxx,            xxxxxxx,    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                                        RCS(KC_DOWN),   S(KC_DOWN),         RCS(KC_L),  xxxxxxx,
    ),
}
