#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_minila(
        KC_ESC,  KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRAVE, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT, KC_UP,   KC_DEL,
        KC_LCTL, KC_LGUI, KC_LALT,  MO(1),                              KC_SPC,  MO(2),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [1] = LAYOUT_minila(
        QK_BOOT, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, RGB_TOG,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,
        _______, RGB_MOD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_RMOD, _______, BL_DOWN, BL_TOGG, BL_UP,   _______, _______, _______, _______, _______, _______, KC_VOLU, _______,
        _______, _______,  _______, _______,                            _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_MPLY 
    ),

    [2] = LAYOUT_minila(
        _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        _______, RGB_TOG,  RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______, _______,
        _______, RGB_MOD,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_RMOD, _______, BL_DOWN, BL_TOGG, BL_UP,   _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______,  _______, _______,                            _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END 
    ),
};
