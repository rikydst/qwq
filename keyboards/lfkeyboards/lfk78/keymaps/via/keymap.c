/* Copyright 2021 Matt Bautista (@nayoshi)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap VANILLA: (Base Layer) Default Layer
     * ,---------.  ,------------------------------------------------------------.  ,---------.
     * | F1 | F2 |  |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backspa|  | Ins|PgUp|
     * |---------|  |------------------------------------------------------------|  |---------|
     * | F3 | F4 |  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     \|  | Del|PgDn|
     * |---------|  |------------------------------------------------------------|  `---------'
     * | F5 | F6 |  |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return |
     * |---------|  |------------------------------------------------------------|  ,----.
     * | F7 | F8 |  |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift      |  | Up |
     * |---------|  |-------------------------------------------------------------------------.
     * | F9 | F10|  |Ctrl|Win |Alt |      Space            |Alt |Ctrl|Func |    |Lft| Dn |Rig |
     * `---------'  `------------------------------------------------------'    `-------------'
     */

    [0] = LAYOUT(
        KC_F1,   KC_F2,   QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,   KC_BSPC,          KC_INS,  KC_PGUP,
        KC_F3,   KC_F4,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,  KC_BSLS,          KC_DEL,  KC_PGDN,
        KC_F5,   KC_F6,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,           KC_ENT,
        KC_F7,   KC_F8,   KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,          KC_UP,
        KC_F9,   KC_F10,  KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RCTL, MO(1),          KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,                KC_TRNS, KC_HOME,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_END,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,          TG(2),          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_ENT,                             KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DOWN, BL_UP,   BL_TOGG,          RGB_TOG, RGB_VAI,
        KC_TRNS, KC_TRNS, MU_NEXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          RGB_MOD, RGB_VAD,
        KC_TRNS, KC_TRNS, AU_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          QK_BOOT,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MU_TOGG, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          RGB_HUI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,          RGB_SAD, RGB_HUD, RGB_SAI
    ),
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_DOWN, BL_UP,   BL_TOGG,          RGB_TOG, RGB_VAI,
        KC_TRNS, KC_TRNS, MU_NEXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          RGB_MOD, RGB_VAD,
        KC_TRNS, KC_TRNS, AU_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          QK_BOOT,
        KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MU_TOGG, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          RGB_HUI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS,          RGB_SAD, RGB_HUD, RGB_SAI
    )
};

void matrix_init_user(void) {
    // This keymap only has a single base layer, so reset the default if needed
    if (eeconfig_read_default_layer() > 1) {
        eeconfig_update_default_layer(1);
        default_layer_set(1);
    }
}
