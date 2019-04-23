/* Copyright 2018 Josh Hinnebusch

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

  [0] = LAYOUT_tkl_ansi_wkl(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,     KC_F11,     KC_F12,                  KC_PSCR, KC_SLCK, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,                 KC_INS,  KC_HOME, KC_PGUP,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,                 KC_DEL,  KC_END,  KC_PGDN,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,                KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,                                                  KC_UP,
    KC_LCTL, KC_LALT,                   KC_SPC,                                      MO(1),             KC_RCTL,                                         KC_LEFT, KC_DOWN, KC_RGHT),

  [1] = LAYOUT_tkl_ansi_wkl(
    KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,     RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,               BL_TOGG, BL_DEC,  BL_INC,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,               KC_TRNS, KC_TRNS, KC_VOLU,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,               KC_MPLY, KC_MNXT, KC_VOLD,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_TRNS, 
    KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS,          KC_TRNS,                                          KC_TRNS, KC_TRNS, KC_TRNS ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_init_ports(void) {
  setPinOutput(D5);
  setPinOutput(E6);
}

void led_set_user(uint8_t usb_led) {

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    DDRD |= (1 << 5); PORTD &= ~(1 << 5);
  } else {
    DDRD &= ~(1 << 5); PORTD &= ~(1 << 5);
  }

  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    DDRE |= (1 << 6); PORTE &= ~(1 << 6);
  } else {
    DDRE &= ~(1 << 6); PORTE &= ~(1 << 6);
  }

}
