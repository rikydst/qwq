#include QMK_KEYBOARD_H


/* DZ60RGB ANSI Hot-swap */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi(             /* Colemak */
        KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,            KC_EQL,        KC_BSPC,
        KC_TAB,       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_LBRC,       KC_RBRC,        KC_BSLS,
        LT(3, KC_CAPS), KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,                       KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                       RSFT_T(KC_UP),
        KC_LCTL,    KC_LGUI, KC_LALT,                     LT(2, KC_SPC),               KC_RALT, RGUI_T(KC_LEFT), MT(KC_MENU, KC_DOWN),    RCTL_T(KC_RGHT)
    ),
    [1] = LAYOUT_60_ansi(             /* Qwerty */
        KC_GESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,            KC_EQL,       KC_BSPC,
        KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,         KC_RBRC,      KC_BSLS,
        LT(3, KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                      KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                      RSFT_T(KC_UP),
        KC_LCTL,    KC_LGUI, KC_LALT,                     LT(2, KC_SPC),               KC_RALT, RGUI_T(KC_LEFT), MT(KC_MENU, KC_DOWN),   RCTL_T(KC_RGHT)
    ),
    [2] = LAYOUT_60_ansi(             /* SpaceFn */
        KC_GRAVE,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,     KC_TRNS,
        KC_PSCR,     KC_NO,     KC_PGUP,  KC_NO,    KC_NO,    KC_NO,    KC_PMNS,  KC_PPLS,  KC_P7,    KC_P8,    KC_P9,    KC_LPRN,  KC_RPRN,   KC_NLCK,
        KC_PAUS,       KC_HOME,    KC_PGDN,  KC_END,   KC_NO,    KC_NO,    KC_PSLS,  KC_PAST,  KC_P4,    KC_P5,    KC_P6,    KC_PEQL,          KC_MPLY,
        KC_TRNS,          KC_NO,      KC_NO,    KC_SPC,   KC_SPC,   KC_INS,   KC_DEL,   KC_P0,    KC_P1,    KC_P2,    KC_P3,                   KC_VOLU,
        KC_TRNS,     KC_TRNS,    KC_TRNS,                            KC_TRNS,                            KC_PDOT,       KC_MPRV,    KC_VOLD,    KC_MNXT
    ),
    [3] = LAYOUT_60_ansi(             /* CapsFn */
        C(S(KC_ESC)), RESET,   DEBUG,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,     KC_NO,
        KC_NO,        RGB_HUI,   RGB_SAI,   RGB_VAI,  RGB_SPI,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,
        KC_TRNS,        RGB_HUD,   RGB_SAD,   RGB_VAD,   RGB_SPD,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,       EEP_RST,
        KC_NO,            RGB_RMOD,  RGB_TOG,   RGB_MOD,     KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                KC_NO,
        DF(1),     DF(0),     KC_NO,                            KC_NO,                       KC_NO,      KC_NO,      KC_NO,      KC_NO
    )
};
