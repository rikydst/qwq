#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE layer: Default Layer
   * ,--------------------------------------------------------------------------------------------------.
   * | `   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |  | Ins |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp  |  | Del |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * | Ctrl    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |--------------------------------------------------------------------------------------------+
   * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift       | Up  |
   * +--------------------------------------------------------------------------------------------+-----+
   * | Ctrl  | Gui   | Alt  |               Space                | Alt  | Gui  | Fn   | Left| Down|Right|
   * `--------------------------------------------------------------------------------------------------´
   */
  [0] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_INS,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL,
        KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,
        KC_LCTL,KC_LGUI,KC_LALT,          KC_SPC,                       KC_RALT,KC_RCTL,MO(1),      KC_LEFT,KC_DOWN,KC_RGHT
    ),
  /* FN layer
   * ,--------------------------------------------------------------------------------------------------.
   * | Esc| F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |            |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |        |     |     |     |     |     |     |     |PrtSc| Slck| Paus|     |     |        |  |     |
   * |-----------------------------------------------------------------------------------------+  +-----+
   * |         | Vol-| Vol+| Mute|Eject|     |     |     | Home| PgUp|     |     |             |
   * |--------------------------------------------------------------------------------------------+
   * |            | Prev| Play| Next|     |     |     |     | End | PgDn|     |             |     |
   * +--------------------------------------------------------------------------------------------+-----+
   * |       |       |      |                                    |      |      |      |     |     |     |
   * `--------------------------------------------------------------------------------------------------´
   */
  [1] = LAYOUT(
        KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,_______,_______,_______,     _______,
        _______,KC_VOLD,KC_VOLU,KC_MUTE,KC_EJCT,_______,_______,_______,KC_HOME,KC_PGUP,_______,_______,     _______,
        _______,KC_MPRV,KC_MPLY,KC_MNXT,_______,_______,_______,_______,KC_END, KC_PGDN,_______,_______,     _______,
        _______,_______,_______,                _______,                _______,_______,MO(1),       _______,_______,_______
    )
};

const uint16_t PROGMEM fn_actions[] = {
};
