/* Copyright 2019 imchipwood
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

#define _BASE 0
#define _SUB  1

#define TAPPING_TOGGLE 2

// Tap Dance Declarations
enum {
    TD_PLUS_MINUS = 0,
    TD_MUL_DIV,
};

// Tap Dance actions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PLUS_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_KP_PLUS, KC_KP_MINUS),
    [TD_MUL_DIV]    = ACTION_TAP_DANCE_DOUBLE(KC_KP_ASTERISK, KC_KP_SLASH),
};

#define KC_TD_PLUS_MINUS TD(TD_PLUS_MINUS)
#define KC_TD_MUL_DIV    TD(TD_MUL_DIV)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
        BASE LAYER
   /-----------------------------------------------------`
   |             |    7    |    8    |    9    |  Bkspc  |
   |             |---------|---------|---------|---------|
   |             |    4    |    5    |    6    |   Esc   |
   |             |---------|---------|---------|---------|
   |             |    1    |    2    |    3    |   Tab   |
   |-------------|---------|---------|---------|---------|
   | Left mouse  | TT(SUB) |    0    |    .    |  Enter  |
   \-----------------------------------------------------'
  */
  [_BASE] = LAYOUT(
                   KC_7,      KC_8,    KC_9,     KC_BSPC, 
                   KC_4,      KC_5,    KC_6,     KC_ESC, 
                   KC_1,      KC_2,    KC_3,     KC_TAB, 
    KC_BTN1,       TT(_SUB),  KC_0,    KC_DOT,   KC_ENTER
  ),
  /*
        SUB LAYER
   /-----------------------------------------------------`
   |             |         |         |         |  Reset  |
   |             |---------|---------|---------|---------|
   |             |         |         |         |   + -   |
   |             |---------|---------|---------|---------|
   |             |         |         |         |   * /   |
   |-------------|---------|---------|---------|---------|
   |    LOCK     |         |         |         |    =    |
   \-----------------------------------------------------'
  */
  [_SUB] = LAYOUT(
                 _______,     _______,     _______,      RESET, 
                 _______,     _______,     _______,      KC_TD_PLUS_MINUS, 
                 _______,     _______,     _______,      KC_TD_MUL_DIV, 
    KC_LOCK,     _______,     _______,     _______,      KC_EQUAL
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
/*
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
*/
  return true;
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable = true;
  //debug_matrix = true;
  //debug_keyboard = true;
  //debug_mouse = true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}


void encoder_update_user(uint8_t index, bool clockwise) {
  // put your custom code here
  // change "return false;" to "return true;" if you do anything 
  // returning false will cause it to use the default
  if (index == 0) {
    if (layer_state && 0x1) {
      // sub layer - move mouse left/right
      if (clockwise) {
        tap_code(KC_MS_R);
      } else {
        tap_code(KC_MS_L);
      }
    } else {
      // main layer - volume control
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    }
  }
}
