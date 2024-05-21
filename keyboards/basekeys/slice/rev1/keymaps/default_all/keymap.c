/* Copyright 2020 2Moons
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

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _FN,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_all(
  //,------------------------------------------------------------------------|   |--------------------------------------------------------------------------------------.
       KC_ESC, KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_BSPC, KC_BSPC,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX,   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,   KC_RBRC,   KC_BSLS,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX, KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,               KC_ENT,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX,     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RSFT,   KC_RSFT,  KC_RSFT,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX,           KC_LCTL, KC_LALT, KC_LALT,  KC_SPC,  KC_SPC,  KC_SPC,      KC_SPC,  KC_SPC,                            KC_RALT,              KC_RCTL,  MO(_FN)
  //`------------------------------------------------------------------------|   |--------------------------------------------------------------------------------------'
  ),

  [_FN] = LAYOUT_all(
  //,------------------------------------------------------------------------|   |--------------------------------------------------------------------------------------.
       KC_ESC,TG(_ADJUST), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,    KC_INS, KC_BSPC,    KC_DEL,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      _______,           _______, _______, _______, _______, _______, _______,     _______, KC_PSCR, KC_SCRL, KC_PAUSE,  KC_UP, _______,   _______,   _______,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      _______,           _______, _______, _______, _______, _______, _______,     _______, KC_HOME, KC_PGUP, KC_LEFT,KC_RIGHT, _______,              _______,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      _______,           _______, _______, _______, _______, _______, _______,     _______,  KC_END, KC_PGDN, KC_DOWN, _______, _______,   _______,   _______,   _______,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      _______,           _______, _______, _______, _______, _______, _______,     _______, _______,                            _______,              _______,   _______
  //`------------------------------------------------------------------------|   |--------------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT_all( /* Base */
  //,------------------------------------------------------------------------|   |--------------------------------------------------------------------------------------.
    XXXXXXX,TG(_ADJUST), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,    QK_BOOT,  XXXXXXX,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
     XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
  //|------------------+--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+----------+----------+----------|
      XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,                            XXXXXXX,              XXXXXXX,   XXXXXXX
  //`------------------------------------------------------------------------|   |--------------------------------------------------------------------------------------'
  )
};

