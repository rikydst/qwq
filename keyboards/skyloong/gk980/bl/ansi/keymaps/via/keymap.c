// Copyright 2023 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_names {
    _WIN,
    _MAC,
    _WIN_INDEX,
    _MAC_INDEX
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN] =  LAYOUT_all(
         KC_ESC,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,     KC_F6,     KC_F7,    KC_F8,           KC_F9,    KC_F10,   KC_F11,       KC_F12,    KC_MUTE,   KC_DEL,  KC_PGUP, KC_PGDN,  KC_PSCR,
         KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,     KC_7,       KC_8,     KC_9,            KC_0,   KC_MINS,   KC_EQL,      KC_BSPC,               KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,       KC_I,     KC_O,            KC_P,   KC_LBRC,  KC_RBRC,      KC_BSLS,                KC_P7,    KC_P8,   KC_P9,  KC_PPLS,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,     KC_J,       KC_K,     KC_L,         KC_SCLN,   KC_QUOT,                 KC_ENT,                KC_P4,    KC_P5,   KC_P6,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,    KC_COMM,   KC_DOT,         KC_SLSH,                           KC_RSFT,      KC_UP,    KC_P1,    KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LGUI,  KC_LALT,             KC_SPC,   KC_SPC,                 KC_SPC,             KC_RALT,  MO(_WIN_INDEX),   KC_RCTL,                KC_LEFT,    KC_DOWN,  KC_RGHT,    KC_P0,  KC_PDOT
    ),

     [_MAC] = LAYOUT_all(
         KC_ESC,             KC_F14,   KC_F15, C(KC_UP),  G(KC_D),   G(KC_SPC), LAG(KC_EJCT),    KC_MPRV,  KC_MPLY,        KC_MNXT,   KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,   KC_DEL,  KC_PGUP, KC_PGDN,  KC_PSCR,
         KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,        KC_6,         KC_7,       KC_8,     KC_9,           KC_0,   KC_MINS,   KC_EQL,  KC_BSPC,               KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
         KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,         KC_U,       KC_I,     KC_O,           KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS,                KC_P7,    KC_P8,   KC_P9,  KC_PPLS,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,        KC_H,         KC_J,       KC_K,     KC_L,        KC_SCLN,   KC_QUOT,             KC_ENT,                KC_P4,    KC_P5,   KC_P6,
        KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,        KC_N,         KC_M,    KC_COMM,   KC_DOT,        KC_SLSH,                       KC_RSFT,      KC_UP,    KC_P1,    KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LALT,  KC_LGUI,             KC_SPC,   KC_SPC,                    KC_SPC,              KC_RCMD, MO(_MAC_INDEX),  KC_RALT,             KC_LEFT,    KC_DOWN,  KC_RGHT,    KC_P0,  KC_PDOT
    ),

    [_WIN_INDEX] = LAYOUT_all(
        _______,             KC_F14,   KC_F15, G(KC_TAB),  KC_WSCH,  G(C(KC_S)),   KC_SLEP,   KC_MPRV,  KC_MPLY,         KC_MNXT,   KC_MUTE,  KC_VOLD,     KC_VOLU,  G(KC_SPC),  KC_INS,  KC_HOME,  KC_END,  KC_PAUS,
        _______,  _______,  _______,  _______,   _______,  _______,    TO(_WIN),  TO(_MAC),   _______,  _______,         BL_TOGG,   BL_BRTG,  BL_BRTG,      KC_DEL,              KC_NUM,  KC_PSLS, KC_PAST,  KC_PMNS,
        _______,  _______,  _______,  _______,   _______,  _______,     _______,   _______,   _______,  _______,         _______,   _______,  _______,     _______,               KC_P7,    KC_P8,   KC_P9,  KC_PPLS,
        _______,  _______,  _______,  _______,   _______,  _______,     _______,   _______,   _______,  _______,         _______,   _______,               _______,               KC_P4,    KC_P5,   KC_P6,
        _______,  _______,  _______,  _______,   _______,  _______,     _______,   _______,   _______,  _______,         _______,                          _______,    BL_UP,     KC_P1,    KC_P2,   KC_P3,  KC_PENT,
        KC_LCTL,  KC_LGUI,  KC_LALT,             _______,  _______,                _______,             KC_RALT,  MO(_WIN_INDEX),    KC_APP,               KC_LEFT,  BL_DOWN,  KC_RGHT,    KC_P0,  KC_PDOT
    ),

    [_MAC_INDEX] = LAYOUT_all(
        _______,              KC_F1,    KC_F2,    KC_F3,    KC_F4,       KC_F5,     KC_F6,     KC_F7,    KC_F8,          KC_F9,     KC_F10,   KC_F11,   KC_F12,   G(KC_SPC),     KC_INS,  KC_HOME,  KC_END, KC_PAUS,
        _______,  _______,  _______,  _______,  _______,  _______,    TO(_WIN),  TO(_MAC),   _______,  _______,        BL_TOGG,    BL_BRTG,  BL_BRTG,   KC_DEL,                  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,   _______,  _______,        _______,    _______,  _______,  _______,                   KC_P7,    KC_P8,   KC_P9, KC_PPLS,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,   _______,  _______,        _______,    _______,            _______,                   KC_P4,    KC_P5,   KC_P6,
        _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,   _______,  _______,        _______,                        _______,       BL_UP,      KC_P1,    KC_P2,   KC_P3, KC_PENT,
        KC_LCTL,  KC_LALT,  KC_LGUI,            _______,  _______,                _______,             KC_RCMD, MO(_MAC_INDEX),    KC_RALT,            KC_LEFT,     BL_DOWN,    KC_RGHT,    KC_P0,  KC_PDOT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_WIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(BL_DOWN, BL_UP), ENCODER_CCW_CW(C(KC_WH_D), C(KC_WH_U)), ENCODER_CCW_CW(G(C(KC_LEFT)), G(C(KC_RGHT)))},
    [_MAC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_F14, KC_F15), ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(C(KC_UP), C(KC_DOWN))},
    [_WIN_INDEX] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(BL_DOWN, BL_UP), ENCODER_CCW_CW(C(KC_WH_D), C(KC_WH_U)), ENCODER_CCW_CW(G(C(KC_LEFT)), G(C(KC_RGHT)))},
    [_MAC_INDEX] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_F14, KC_F15), ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(C(KC_UP), C(KC_DOWN))}
};
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
    gpio_write_pin(MAC_PIN, layer_state_cmp(state, 1));
  return state;
}

