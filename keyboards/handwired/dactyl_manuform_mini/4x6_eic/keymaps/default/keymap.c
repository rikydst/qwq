// Copyright 2023 Duncan Sutherland (@dunk2k)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
};

#define RAISE TT(_RAISE)
#define LOWER TT(_LOWER)
#define RS_BSLS RSFT_T(KC_BSLS)
#define LC_SPC LCTL_T(KC_SPC)
#define RC_ENT RCTL_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_Q, KC_W,    KC_E,    KC_R,  KC_T,    KC_MINS,      KC_EQL,  KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_TAB,  KC_A, KC_S,    KC_D,    KC_F,  KC_G,    KC_LBRC,      KC_RBRC, KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X,    KC_C,    KC_V,  KC_B,                           KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, RS_BSLS,
                       KC_LEFT, KC_RGHT,                                                       KC_UP,   KC_DOWN,
                                         RAISE, LC_SPC,  KC_HOME,      KC_END,  RC_ENT, LOWER,
                                                KC_BSPC, KC_LALT,      KC_LGUI, KC_DEL
    ),

    [_LOWER] = LAYOUT(
        _______, _______, _______, _______, KC_PGUP, KC_VOLU, _______,      _______, KC_NUM,  KC_P7,   KC_P8, KC_P9,  _______, QK_BOOT,
        _______, KC_INS,  KC_PSCR, KC_PAUS, KC_SCRL, KC_MUTE, _______,      _______, KC_PAST, KC_P4,   KC_P5, KC_P6,  KC_PMNS, _______,
        _______, _______, _______, _______, KC_PGDN, KC_VOLD,                        KC_PSLS, KC_P1,   KC_P2, KC_P3,  KC_PPLS, _______,
                          _______, _______,                                                            KC_P0, KC_PDOT,
                                            _______, _______, _______,      _______, KC_PENT, _______,
                                                     _______, _______,      _______, _______
    ),

    [_RAISE] = LAYOUT(
        KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F2,
        _______, KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_LPRN,      KC_RPRN, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,                         KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_TILD, _______,
                         KC_MPRV, KC_MNXT,                                                            KC_MPLY, KC_MSTP,
                                           _______, _______, _______,      _______, _______, _______,
                                                    _______, _______,      _______, _______
    )
};
