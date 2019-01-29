
#include QMK_KEYBOARD_H
#include "keymap_slovenian.h"


#define CARON LT(3, SI_CIRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT( \
    KC_GESC,SI_1,   SI_2,   SI_3,   SI_4,   SI_5,   SI_6,   SI_7,   SI_8,   SI_9,   SI_0,   SI_QOT, SI_PLUS,XXXXXXX,KC_BSPC, \
    KC_TAB,         SI_Q,   SI_W,   SI_E,   SI_R,   SI_T,   SI_Z,   SI_U,   SI_I,   SI_O,   SI_P,   SI_GRV, SI_TILD,CARON,   \
    MO(2),          SI_A,   SI_S,   SI_D,   SI_F,   SI_G,   SI_H,   SI_J,   SI_K,   SI_L,   KC_SCLN,KC_QUOT,KC_ENT,          \
    KC_LSFT,XXXXXXX,SI_Y,   SI_X,   SI_C,   SI_V,   SI_B,   SI_N,   SI_M,   SI_COMM,SI_DOT, SI_MINS,        KC_RSFT,XXXXXXX, \
    KC_LCTL,KC_LGUI,        KC_LALT,KC_SPC,         KC_SPC,         KC_SPC,         KC_RALT,MO(3),  XXXXXXX,MO(1),  KC_F5    \
  ),

  [1] = LAYOUT( \
    KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,KC_DEL,  \
    _______,        RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______,_______,RESET,   \
    _______,        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,         \
    _______,_______,_______,_______,BL_DEC, BL_TOGG,BL_INC, BL_STEP,_______,_______,_______,_______,        _______,_______, \
    _______,_______,        _______,_______,        _______,        _______,        _______,_______,_______,_______,_______  \
  ),

  [2] = LAYOUT( \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
    _______,        KC_BSPC,KC_UP,  KC_DEL, _______,_______,_______,_______,_______,_______,_______,_______,KC_HOME, KC_END, \
    _______,        KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,_______,_______,_______,_______,_______,         \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,        _______,_______, \
    _______,_______,        _______,_______,        _______,        _______,        _______,_______,_______,_______,_______  \
  ),

  [3] = LAYOUT( \
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, \
    _______,        _______,_______,_______,_______,_______,SI_ZV,  _______,_______,_______,_______,_______,_______,_______, \
    _______,        _______,SI_SV,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,         \
    _______,_______,_______,_______,SI_CV,  _______,_______,_______,_______,_______,_______,_______,        _______,_______, \
    _______,_______,        _______,_______,        _______,        _______,        _______,_______,_______,_______,_______  \
  ),
};
