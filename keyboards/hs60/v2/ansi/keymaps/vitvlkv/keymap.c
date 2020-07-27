/* Copyright 2018 vitvlkv
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

// To compile firmware:
// `qmk compile -kb hs60/v2/ansi -km vitvlkv`

// To flash firmware:
// plug in keyboard
// press hardware 'reset' button (on the PCB)
// execute command: `qmk flash -kb hs60/v2/ansi -km vitvlkv`
#include QMK_KEYBOARD_H

//This is the ANSI version of the PCB

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_60_ansi( /* Base */
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,\
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,\
    MO(2),    KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,\
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_GRV,\
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(1),    MO(2),    MO(3)),

[1] = LAYOUT_60_ansi( /* Fn */
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,\
    _______,  KC_PGUP,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  KC_PSCR,  KC_SLCK,  KC_PAUS,  _______,\
    _______,  KC_PGDN,  _______,  KC_HOME,  KC_END,   KC_DEL,   KC_BSPC,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_INS,   _______,            _______,\
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_RSFT,\
    _______,  _______,  _______,                                _______,                                _______,  _______,  KC_APP,   KC_RCTL),

[2] = LAYOUT_60_ansi( /* Mouse and volume */
    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,\
    _______,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_WH_U,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,\
    _______,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_WH_D,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,\
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,            _______,\
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

[3] = LAYOUT_60_ansi( /* RGB */
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,\
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,\
    _______,  _______,  _______,  _______,  S1_DEC,   S1_INC,   S2_DEC,   S2_INC,   _______,  _______,  _______,  _______,            _______,\
    _______,            EF_DEC,   EF_INC,   H1_DEC,   H1_INC,   H2_DEC,   H2_INC,   BR_DEC,   BR_INC,   ES_DEC,   ES_INC,             _______,\
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}
