#include "dz60.h"
#include "action_layer.h"

const uint16_t PROGMEM keymaps[][5][15] = {
/* Layer 0 (Basically an HHKB MacOS layout)
* ,-----------------------------------------------------------------------------------------.
* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Bkspc   |
* |-----------------------------------------------------------------------------------------+
* | GUI     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |  Shift   | Fn |
* |-----------------------------------------------------------------------------------------+
* | Caps  | alt  | Ctrl |                    Space               |   GUI   |  Alt  |  Ctrl  |
* `-----------------------------------------------------------------------------------------'
*/

LAYOUT(	
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(1),
		KC_CAPS, KC_LALT, KC_LCTL, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, KC_RGUI, KC_RALT, KC_RCTL),

// layer 1
LAYOUT(KC_GRV, KC_F14, KC_F15, KC_TRNS, KC_TRNS, BL_DEC, BL_INC, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_DEL,
       TO(2), RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_UP, KC_NO, RESET,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_LEFT, KC_RIGHT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, BL_DEC, BL_TOGG, BL_INC, BL_STEP, KC_TRNS, KC_MRWD, KC_MPLY, KC_MFFD, KC_DOWN, KC_TRNS, KC_TRNS,
       KC_CAPS, KC_LALT, KC_LCTL, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RGUI, KC_RGUI, KC_RALT, KC_RCTL),
/* Layer 0 (Basically an HHKB MacOS layout)
* ,-----------------------------------------------------------------------------------------.
* | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  ~  |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  | Bkspc   |
* |-----------------------------------------------------------------------------------------+
* | Crtl     |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   /   |  Shift   | Fn |
* |-----------------------------------------------------------------------------------------+
* | Caps  | gui  | Alt  |                    Space               |   alt   |  GUI  |  Ctrl  |
* `-----------------------------------------------------------------------------------------'
*/

// layer 2
LAYOUT( KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPACE,
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
  KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(3),
	KC_CAPS, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RALT, KC_RGUI, KC_RCTL),

    // layer 3
    LAYOUT(
           KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_MINS, KC_EQL, KC_TRNS, KC_TRNS,
           TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, RESET,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_RIGHT, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS, KC_TRNS,
					 KC_CAPS, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RALT, KC_RGUI, KC_RCTL,)


};

uint16_t custom_lt_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
    // Other declarations would go here, separated by commas, if you have them
};
