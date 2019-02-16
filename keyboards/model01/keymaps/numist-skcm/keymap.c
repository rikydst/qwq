/* Copyright 2018 James Laird-Wah
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

/* layer constants */
enum {
  DEF = 0,
  NUM,
  FUN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEF] = LAYOUT(
  RESET  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , MO(NUM),
  KC_GRV , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LBRC,    KC_RBRC, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_EQL ,
  KC_PGUP, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_TAB ,    KC_ENT , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
  KC_PGDN, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ESC ,    KC_BSLS, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_MINS,
                                         KC_LCTL,                                 KC_RCTL,
                                            KC_LALT,                           KC_SPC ,
                                               KC_LGUI,                     KC_RSFT,
                                                  KC_LSFT,               KC_BSPC,
                                      MO(FUN),                                        MO(FUN)
  ),
[NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, KC_7   , KC_8   , KC_9   , KC_PMNS, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_4   , KC_5   , KC_6   , KC_PPLS, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_1   , KC_2   , KC_3   , KC_PEQL, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, KC_0   , KC_DOT , KC_PAST, KC_PSLS, KC_PENT,
                                         _______,                                 _______,
                                            _______,                           _______,
                                               _______,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  ),
[FUN] = LAYOUT(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  KC_TAB , _______, KC_MS_U, _______, KC_BTN3, _______, RGB_TOG,    KC_MPRV, KC_MNXT, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_F12 ,
  KC_HOME, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______, _______,    KC_MPLY, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
  KC_END , KC_PSCR, KC_INS , _______, KC_BTN2, _______, _______,    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_BSLS, KC_PIPE,
                                         _______,                                 _______,
                                            _______,                           KC_ENT ,
                                               _______,                     _______,
                                                  _______,               KC_DEL ,
                                      _______,                                        _______
  )
};

/* template for new layouts:
LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                                         _______,                                 _______,
                                            _______,                           _______,
                                               _______,                     _______,
                                                  _______,               _______,
                                      _______,                                        _______
  )
*/

/* vim: set ts=2 sw=2 et: */
