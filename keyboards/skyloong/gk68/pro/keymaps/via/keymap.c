// Copyright 2021 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_names {
    _WIN,
    _MAC,
    _WIN_INDEX,
    _MAC_INDEX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_all(
         KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,            KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,    KC_INS,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,            KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,         KC_SCLN,     KC_QUOT,              KC_ENT,   KC_PGUP,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,         KC_SLSH,               KC_RSFT,     KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,                KC_SPC,               KC_SPC,  KC_RALT,  MO(_WIN_INDEX),      KC_APP,  KC_LEFT,   KC_DOWN,  KC_RIGHT
    ),

     [_MAC] = LAYOUT_all(
         KC_ESC,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,            KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,    KC_INS,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,            KC_P,     KC_LBRC,  KC_RBRC,   KC_BSLS,    KC_DEL,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,         KC_SCLN,     KC_QUOT,              KC_ENT,   KC_PGUP,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,         KC_SLSH,               KC_RSFT,     KC_UP,   KC_PGDN,
        KC_LCTL,  KC_LALT,  KC_LGUI,             KC_SPC,                KC_SPC,               KC_SPC,  KC_RGUI,  MO(_MAC_INDEX),     KC_RALT,  KC_LEFT,   KC_DOWN,  KC_RIGHT
    ),

    [_WIN_INDEX] =  LAYOUT_all(
         KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,       KC_F6,    KC_F7,      KC_F8,    KC_F9,          KC_F10,      KC_F11,   KC_F12,    KC_DEL,   KC_MUTE,
        _______,  _______,    TO(0),    TO(1),  _______,  _______,     _______,  _______,    _______,  _______,         _______,    RGB_RMOD,  RGB_MOD,   RGB_TOG,   KC_MPLY,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,         _______,     _______,             _______,   KC_HOME,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,         _______,               _______,   RGB_VAI,    KC_END,
        _______,  _______,  _______,            _______,               _______,              _______,  KC_RALT,         _______,      KC_APP,  RGB_SPD,   RGB_VAD,   RGB_SPI
    ),

    [_MAC_INDEX] = LAYOUT_all(
        KC_GRV ,   KC_F14,   KC_F15, C(KC_UP),  G(KC_D), G(KC_SPC),  LSG(KC_4),  KC_MPRV,    KC_MPLY,  KC_MNXT,         KC_MUTE,     KC_VOLD,  KC_VOLU,    KC_DEL,   KC_MUTE,
        _______,  _______,    TO(0),    TO(1),  _______,  _______,     _______,  _______,    _______,  _______,         _______,    RGB_RMOD,  RGB_MOD,   RGB_TOG,   KC_MPLY,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,         _______,     _______,             _______,   KC_HOME,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,    _______,  _______,         _______,               _______,   RGB_VAI,    KC_END,
        _______,  KC_LALT,  KC_LGUI,            _______,               _______,              _______,  KC_RGUI,         _______,     KC_RALT,  RGB_SPD,   RGB_VAD,   RGB_SPI
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_WIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_MAC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_WIN_INDEX] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_HUD, RGB_HUI)},
    [_MAC_INDEX] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RGB_HUD, RGB_HUI)}
};
#endif

