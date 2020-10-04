#include QMK_KEYBOARD_H
#include "keymap_jp.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
  _QWERTY = 0,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  RGB_RST = SAFE_RANGE
};

enum tapdances{
  TD_ESMS = 0,
  TD_ESAR,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESMS] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _MOUSE),
  [TD_ESAR] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESC, _QWERTY),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TD(TD_ESMS),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_PSCR,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_ZKHK,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0, JP_MINS,  JP_EQL, KC_BSPC, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, JP_LBRC, JP_RBRC, JP_BSLS, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, JP_MINS, JP_QUOT,           KC_ENT, KC_PGDN,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,          KC_RSFT,   KC_UP,  KC_END,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      KC_ZKHK, KC_LGUI,ALT_T(KC_MHEN),LT(_LOWER,KC_ENT),KC_BSPC, KC_DEL,LT(_RAISE,KC_SPC),   ALT_T(KC_HENK),  KC_APP, KC_LEFT, KC_DOWN,KC_RIGHT
  //`-----------------------------------------------------|   |--------------------------------------------------------------------------------'
  ),

  [_MOUSE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
  TD(TD_ESAR), _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, LCTL(KC_W),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,          _______, LCTL(LSFT(KC_T)),
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______,          KC_BTN1, KC_MS_U, KC_BTN2,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______,          _______, _______,     _______, _______,          _______, _______,          KC_MS_L, KC_MS_D, KC_MS_R
  //`-----------------------------------------------------|   |--------------------------------------------------------------------------------'
  ),

  [_LOWER] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
       KC_ESC, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      JP_QUOT, JP_EXLM, JP_QUES, JP_LBRC, JP_RBRC, JP_TILD,       KC_P6,   KC_P7,   KC_P8,   KC_P9, JP_ASTR, JP_SLSH, _______, _______, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
LCTL_T(JP_QUOT),JP_HASH, JP_DQT, JP_LPRN, JP_RPRN,   JP_AT,     XXXXXXX,   KC_P4,   KC_P5,   KC_P6, JP_MINS,  JP_EQL,          _______,  KC_END,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
SFT_T(JP_CIRC),JP_PERC, JP_AMPR, JP_SCLN, JP_COLN, JP_PIPE,       KC_P0,   KC_P1,   KC_P2,   KC_P3, JP_PLUS,          _______,   KC_UP, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______,       MO(_LOWER), _______,     _______,MO(_RAISE),        _______, _______,          KC_LEFT, KC_DOWN,KC_RIGHT
  //`-----------------------------------------------------|   |--------------------------------------------------------------------------------'
  ),

  [_RAISE] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, KC_PGUP, XXXXXXX, _______, _______, KC_HOME,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
LCTL_T(KC_F11),XXXXXXX,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT, XXXXXXX, XXXXXXX,          _______,  KC_END,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
SFT_T(KC_F12),   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN,          _______,   KC_UP, KC_PGUP,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______,          _______, _______,     _______, _______,          _______, _______,          KC_LEFT, KC_DOWN,KC_RIGHT
  //`-----------------------------------------------------|   |--------------------------------------------------------------------------------'
  ),

  [_ADJUST] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD,          RGB_SAI, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      _______, _______, _______,          _______, _______,     _______, _______,          _______, _______,          XXXXXXX, XXXXXXX, XXXXXXX
  //`-----------------------------------------------------|   |--------------------------------------------------------------------------------'
  )
};

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#ifdef RGBLIGHT_ENABLE
        case RGB_RST:
            if (record->event.pressed) {
                uint8_t mode = rgblight_get_mode();
                eeconfig_update_rgblight_default();
                rgblight_enable();
                rgblight_mode(mode);
             }
             break;
#endif
    }
    return true;
}
