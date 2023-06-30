// Copyright 2020 Christian Eiden, cykedev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

// layers, ordering is important!
enum layers {
    _BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base layer
  * ,--------------------------------------------------------------------------------------------------.
  * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  Backspace  | `    |
  * |-------------------------------------------------------------------------------------------+------+
  * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \     | Del  |
  * |-------------------------------------------------------------------------------------------+------+
  * | MO(_FN2) |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |     Enter    | PgUp |
  * |-------------------------------------------------------------------------------------------+------+
  * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Shift    | Up  | PgDn |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * | LCtrl | LAlt | LGUI |               Space                 | RGUI | RAlt |   | Left  | Dn  | Rght |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
	[_BASE] = LAYOUT_65_ansi_blocker(
		KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,           KC_MINS,   KC_EQL,    KC_BSPC,   KC_GRV,
		KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,           KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_DEL,
		MO(_FN1),  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,        KC_QUOT,              KC_ENT,    KC_PGUP,
		KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,        KC_RSFT,              KC_UP,     KC_PGDN,
		KC_LCTL,   KC_LALT,   KC_LGUI,                         KC_SPC,                                     KC_RGUI,   OSM(MOD_RALT),             KC_LEFT,   KC_DOWN,   KC_RGHT
		),

  /* FN 1 layer
  * ,--------------------------------------------------------------------------------------------------.
  * |     |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |             | Mute |
  * |-------------------------------------------------------------------------------------------+------+
  * |        |     |     |     |     |     |     |     |     |     |     | Br - |Br +|          | Ins  |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |     |     |     |     |     | Lft | Dwn | Up  | Rgt |     |     |              | Home |
  * |-------------------------------------------------------------------------------------------+------+
  * | MO(_FN2)   |     |     |     |     |     |     |     |     |     |     |            | V + | End  |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |       |      |      |                                     |      |      |   | Prev  | V - | Next |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
	[_FN1] = LAYOUT_65_ansi_blocker(
		_______,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,   KC_F11,    KC_F12,    _______,   KC_MUTE,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_BRID,   KC_BRIU,   _______,   KC_INS,
		_______,   _______,   _______,   _______,   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______,   _______,              _______,   KC_HOME,
		MO(_FN2),  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              KC_VOLU,   KC_END,
		_______,   _______,   _______,                         _______,                                    _______,   _______,              KC_MRWD,   KC_VOLD,   KC_MFFD
		),

	/* FN 2 layer
  * ,--------------------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |     Reset   | EEPR |
  * |-------------------------------------------------------------------------------------------+------+
  * |        |     |     |     |     |     |     |     |     |     |     | Mo- | Mo+ |          |Solid |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |     |     |     |     |     |     |     |     |     | Sp- | Sp+ |              |  V + |
  * |-------------------------------------------------------------------------------------------+------+
  * |            |     |     |     |     |     |     |     |     |     |     |            | S + |  V - |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |       |      |      |             Backlight               |      |      |   |  H -  | S - |  H + |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
	[_FN2] = LAYOUT_65_ansi_blocker(
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   QK_BOOT,   EE_CLR,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   RGB_RMOD,  RGB_MOD,   _______,   RGB_M_P,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   RGB_SPD,   RGB_SPI,              _______,   RGB_VAI,
		_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              RGB_SAI,   RGB_VAD,
		_______,   _______,   _______,                         RGB_TOG,                                    _______,   _______,              RGB_HUD,   RGB_SAD,   RGB_HUI
    ),

  /* FN 3 layer
  * ,--------------------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |             |      |
  * |-------------------------------------------------------------------------------------------+------+
  * |        |     |     |     |     |     |     |     |     |     |     |     |     |          |      |
  * |-------------------------------------------------------------------------------------------+------+
  * |          |     |     |     |     |     |     |     |     |     |     |     |              |      |
  * |-------------------------------------------------------------------------------------------+------+
  * |            |     |     |     |     |     |     |     |     |     |     |            |     |      |
  * +-------------------------------------------------------------------------┬---┬-------------+------+
  * |       |      |      |                                     |      |      |   |       |     |      |
  * `-------------------------------------------------------------------------┘   └-------------+------´
  */
  [_FN3] = LAYOUT_65_ansi_blocker(
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,
    _______,   _______,   _______,                         _______,                                    _______,   _______,              _______,   _______,   _______
    )
};
