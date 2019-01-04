#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _RAISE,
  _LOWER
};

enum keycodes {
  QWERTY = SAFE_RANGE,
  RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_INSERT,    \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,  KC_DEL,  \
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,            KC_PGUP,    \
      KC_LSFT,          KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, KC_UP,    KC_PGDN,      \
      KC_LCTL, KC_LGUI, KC_LALT,                          KC_SPC,                 MO(_RAISE), MO(_LOWER),        KC_LEFT, KC_DOWN,  KC_RIGHT),

  [_RAISE] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,   KC_PSCR,    \
      KC_TRNS, KC_NO,   KC_UP,   KC_NO,   RGB_TOG,RGB_VAI,RGB_HUI,RGB_SAI,KC_INS, RESET,   KC_PSCR, KC_SLCK,  KC_PAUS, KC_BSLS,  KC_SLCK, \
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,RGB_MOD,RGB_VAD,RGB_HUD,RGB_SAD,KC_NO,  KC_NO,   KC_F14,  KC_F15,   KC_INS,            KC_HOME,   \
      KC_LSFT,          KC_MPRV, KC_MPLY, KC_MNXT,KC_NO,  BL_TOGG,  KC_NO,  KC_MUTE,KC_VOLD, KC_VOLU, KC_NO,    KC_RSFT, RGB_MODE_FORWARD,  KC_END,       \
      KC_LCTL, KC_LGUI, KC_LALT,                          RESET,                KC_RALT, KC_TRNS,           KC_HOME, BL_STEP, KC_END),

  [_LOWER] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_DEL,   KC_PSCR,    \
      KC_TRNS, KC_NO,   KC_UP,   KC_NO,   RGB_TOG,RGB_VAI,RGB_HUI,RGB_SAI,KC_INS, RESET,   KC_PSCR, KC_SLCK,  KC_PAUS, KC_BSLS,  KC_SLCK, \
      KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,RGB_MOD,RGB_VAD,RGB_HUD,RGB_SAD,KC_NO,  KC_NO,   KC_F14,  KC_F15,   RGB_TOG,            KC_HOME,   \
      KC_LSFT,          KC_MPRV, KC_MPLY, KC_MNXT,KC_NO,  BL_TOGG,  KC_NO,  KC_MUTE,KC_VOLD, KC_VOLU, KC_NO,    KC_RSFT, RGB_VAI,  KC_END,       \
      KC_LCTL, KC_LGUI, KC_LALT,                          RESET,                KC_RALT, KC_TRNS,           RGB_RMOD, RGB_VAD, RGB_MOD)
};

