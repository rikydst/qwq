/* Copyright 2015-2017 Jack Humbert
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

#define _______ KC_TRNS

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FN
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |Hyper | Alt  | GUI  |Lower | Func |Space |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
      KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
      KC_LCTL, KC_HYPR, KC_LALT, KC_LGUI, LOWER,   MO(_FN), KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |Hyper | Alt  | GUI  |Lower | Func |Space |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_HYPR, KC_LALT, KC_LGUI, LOWER,   MO(_FN), KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | PGDN | PGUP | Home | End  | Mute |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Play |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN,    KC_PGUP,    KC_HOME, KC_END , KC_MUTE,
    _______, _______, _______, _______, _______, _______, KC_MPLY, _______,    KC_MPRV,    KC_VOLD, KC_VOLU, KC_MNXT
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | PGDN | PGUP | Home | End  | Mute |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Play |      | Next | Vol- | Vol+ | Play |
   * `-----------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PGDN, KC_PGUP, KC_HOME, KC_END , KC_MUTE,
    _______, _______, _______, _______, _______, _______, KC_MPLY, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
  ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |RESET |      |      |      |      |      |      |Qwerty|Colemk|      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
    RESET,  _______, _______, _______, _______, _______, _______, QWERTY,  DVORAK, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Func
   * ,-----------------------------------------------------------------------------------.
   * |      |      |      |  £   | PSCR |      |      |      |  Up  |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |Reset |      |      |      |      |      |      | Left | Down |Right |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |DVORAK|QWERTY|
   * `-----------------------------------------------------------------------------------'
   */
  [_FN] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______,    KC_PSCR, _______, _______, _______, KC_UP,    _______, _______, _______,
    RESET  , _______, _______, _______,    _______, _______, _______, KC_LEFT, KC_DOWN,  KC_RGHT, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
  }
  return true;
}
