/* Copyright 2024 Lrfoster03
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

enum custom_keycodes {
    KC_P00 = QK_KB_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base -> XT:Num:Nav:Alphas:Nav:Num:Xt*/ 
        KC_F1,  KC_F2,     KC_PPLS,  KC_P7, KC_P8, KC_P9,          KC_INS,  KC_HOME, KC_PGUP,          KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,                KC_INS,  KC_HOME, KC_PGUP,          KC_P7,   KC_P8,   KC_P9,   KC_PPLS,     KC_F1,  KC_F2,
        KC_F3,  KC_F4,     KC_PMNS,  KC_P4, KC_P5, KC_P6,          KC_DEL,  KC_END,  KC_PGDN,          KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                          KC_DEL,  KC_END,  KC_PGDN,          KC_P4,   KC_P5,   KC_P6,   KC_PPLS,     KC_F3,  KC_F4,
        KC_F5,  KC_F6,     KC_PMNS,  KC_P1, KC_P2, KC_P3,          KC_SPC,  KC_UP,   KC_SPC,           KC_LSFT, KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),                  KC_SPC,  KC_UP, KC_SPC,             KC_P1,   KC_P2,   KC_P3,   KC_PMNS,     KC_F5,  KC_F6,
        KC_F7,  KC_F8,     KC_PENT,  KC_PDOT, KC_P00, KC_P0,       KC_LEFT, KC_DOWN, KC_RIGHT,         KC_LCTL, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RCTL,                                                                               KC_LEFT, KC_DOWN, KC_RIGHT,         KC_P0,   KC_P00,  KC_PDOT, KC_PENT,     KC_F7,  KC_F8
    ), 

    [1] = LAYOUT( /* MO(1) */ 
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS,  KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                                                                                                        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS
    ),

    [2] = LAYOUT( /* MO(2) */ 
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS,  KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS,  KC_TRNS, KC_TRNS,         KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                                                                                                        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_P00:
                tap_code(KC_P0);
                tap_code(KC_P0);
                return false;
        }
    }
    return true;
}
