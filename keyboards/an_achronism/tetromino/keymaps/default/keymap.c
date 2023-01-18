/*
Copyright 2022 an_achronism (@an-achronism)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Del│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Tab| Q │ W │ E | R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Bsp│
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │UK#│Rtn|
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Sft│ ↑ │App|
     * ├───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │Esc│Ctl│Alt│GUI│L_1│Spc│L_2|GUI│Alt│Ctl|UK\│ ← │ ↓ │ → │
     * └───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_5x14(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP, RSFT_T(KC_APP),
        KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, MO(1),   KC_SPC,  MO(2),   KC_RGUI, KC_RALT, KC_RCTL, KC_NUBS, KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_ortho_5x14(
        KC_BRID, KC_BRIU, _______, _______, _______, _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PEQL, _______, _______, _______, KC_PWR,
        _______, _______, KC_UP,   _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PAUS, KC_ESC,  _______, KC_SLEP,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______, KC_CALC,
        KC_CAPS, _______, _______, _______, _______, KC_PAUS, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______, KC_CAPS, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, _______, _______, _______, _______, _______, _______
    ),
    [2] = LAYOUT_ortho_5x14(
        _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MSTP,
        _______, KC_F4,   KC_F3,   KC_F2,   KC_F1,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, C(KC_BRK), KC_ESC, _______, _______,
        _______, KC_F8,   KC_F7,   KC_F6,   KC_F5,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MPRV, KC_MNXT, KC_MPLY,
        KC_CAPS, KC_F12,  KC_F11,  KC_F10,  KC_F9,  C(KC_BRK),_______, _______, _______, _______, _______, KC_CAPS, _______, KC_PSCR,
        _______, _______, _______, _______, MO(3),   _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [3] = LAYOUT_ortho_5x14(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};
