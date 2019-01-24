/* Copyright 2019 Yonatan Zunger
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
#include "eeconfig.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MAGIC = SAFE_RANGE,
};

enum layers_keymap {
  _QWERTY = 0,
  _FUNCTION,

  _MAGIC,
  _SHIFTMAGIC,
};

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define H(x) UC(0x##x)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ |Del|Brk |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Hypr|
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Win |        Space          |Alt| FN |||||Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_QWERTY] = LAYOUT(
  GRAVE_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRAVE, KC_BRK,  \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          MAGIC,   \
  KC_LCTL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP, \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                          KC_RALT, MO(_FUNCTION),             KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap Fn Layer. Blank keys are deliberately NO, not TRNS.
   * ,----------------------------------------------------------------.
   * |Rst |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|F13|PSc|PAUS|
   * |----------------------------------------------------------------|
   * |Debug|   |   |   |   |   |   |   |   |   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |Ctrl   |   |Vo+|   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |Shift   |REV|Vo-|FWD|   |   |   |   |   |   |   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Win |                       |Alt|    |||||MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FUNCTION] = LAYOUT(
   RESET,   KC_F1,   KC_F2,       KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10, KC_F11, KC_F12, KC_F13, KC_PSCR,  KC_MPLY, \
   DEBUG,   KC_NO,   KC_NO,       KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,            _______,   \
   _______, KC_NO,   KC__VOLUP,   KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO,          KC_NO,            KC_NO,   \
   _______, KC_MRWD, KC__VOLDOWN, KC_MFFD, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,                  KC_BTN1, KC_MS_U, KC_BTN2, \
   _______, _______, _______,                      KC_NO,                          _______, _______,                KC_MS_L, KC_MS_D, KC_MS_R),

  /* Mathematical lower layer. Blank keys are TRNS.
   * Note that escape turns into grave here. This doesn't just generalize GRAVE_ESC; it means that
   * magic+esc is a way to create backticks without a dedicated key.
   * ,----------------------------------------------------------------.
   * | `  | ¹| ² | ³ | ⁴ | ⁵ | ⁶ | ⁷ | ⁸ | ⁹ | ⁰ | ⁻ | ⁺ | ⊕ | ≠ |    |
   * |----------------------------------------------------------------|
   * |     | ± | ω | ε | ρ | τ | θ | υ | ι | ο | π | ∃ | ∀ |     |    |
   * |----------------------------------------------------------------|
   * |       | α | σ | δ | φ | γ | η | ∅ | κ | λ | ∨ | ∧ |       |    |
   * |----------------------------------------------------------------|
   * |        | ζ | ξ | χ | ψ | β | ν | μ | ≲ | ≳ | ∈ |      | ↑ | ↔  |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |    ||||| ← | ↓ | →  |
   * `----------------------------------------------------------------'
  */
[_MAGIC] = LAYOUT(
 KC_GRV,  H(00b9), H(00b2), H(00b3), H(2074), H(2075), H(2076), H(2077), H(2078), H(2079), H(2070), H(207b), H(207a), H(2295), H(2260), _______, \
 _______, H(00b1), H(03c9), H(03b5), H(03c1), H(03c4), H(03b8), H(03c5), H(03b9), H(03bf), H(03c0), H(2203), H(2200), _______,          _______, \
 _______, H(03b1), H(03c3), H(03b4), H(03c6), H(03b3), H(03b7), H(2205), H(03ba), H(03bb), H(2228), H(2227),          _______,          _______, \
 _______, H(03b6), H(03be), H(03c7), H(03c8), H(03b2), H(03bd), H(03bc), H(2272), H(2273), H(2208),                   _______, H(2191), H(2194), \
 _______, _______, _______,                   _______,                            _______, _______,                   H(2190), H(2193), H(2192)),

  /* Mathematical upper layer. Blank keys are TRNS.
   * ,----------------------------------------------------------------.
   * | `  | ₁| ₂ | ₃ | ₄ | ₅ | ₆ | ₇ | ₈ | ₉ | ₀ | ₋ | ₊ | ⊗ | ≈ |    |
   * |----------------------------------------------------------------|
   * |     | ∓ | Ω | Ε | Ρ | Τ | Θ | Υ | Ι | Ο | Π | ∄ | ∞ |     |    |
   * |----------------------------------------------------------------|
   * |       | Α | Σ | Δ | Φ | Γ | Η | ¬ | Κ | Λ | ∪ | ∩ |       |    |
   * |----------------------------------------------------------------|
   * |        | Ζ | Ξ | Χ | Ψ | Β | Ν | Μ | ⊆ | ⊇ | ∉ |      | ⇑ | ⇔  |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |    ||||| ⇐ | ⇓ | ⇒  |
   * `----------------------------------------------------------------'
  */
[_SHIFTMAGIC] = LAYOUT(
 KC_GRV,  H(2081), H(2082), H(2083), H(2084), H(2085), H(2086), H(2087), H(2088), H(2089), H(2080), H(208b), H(208a), H(2297), H(2248), _______, \
 _______, H(2213), H(03a9), H(0395), H(03a1), H(03a4), H(0398), H(03a5), H(0399), H(039f), H(03a0), H(2204), H(221e), _______,          _______, \
 _______, H(0391), H(03a3), H(0394), H(03a6), H(0393), H(0397), H(00ac), H(039a), H(039b), H(222a), H(2229),          _______,          _______, \
 _______, H(0396), H(039e), H(03a7), H(03a8), H(0392), H(039d), H(039c), H(2286), H(2287), H(2209),                   _______, H(21d1), H(21d4), \
 _______, _______, _______,                   _______,                            _______, _______,                   H(21d0), H(21d3), H(21d2)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // We want magic to move us to layer _MAGIC, and shift+magic to move us to layer _SHIFTMAGIC. We
  // can't do this with MO's because they get confused about the various orders in which keys can be
  // pressed and released, so let's do it carefully and in code instead.
  static bool shifted = false;
  static bool magic = false;

  if (keycode == KC_LSHIFT || keycode == KC_RSHIFT) {
    shifted = record->event.pressed;
  } else if (keycode == MAGIC) {
    magic = record->event.pressed;
  }

  if (magic && shifted) {
    layer_off(_MAGIC);
    layer_on(_SHIFTMAGIC);
  } else if (magic) {
    layer_on(_MAGIC);
    layer_off(_SHIFTMAGIC);
  } else {
    layer_off(_MAGIC);
    layer_off(_SHIFTMAGIC);
  }
  return true;
}

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

void matrix_init_user(void) {
  if (!eeconfig_is_enabled()) {
    eeconfig_init();
  }
}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
