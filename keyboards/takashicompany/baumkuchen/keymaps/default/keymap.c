// Copyright 2023 takashicompany (@takashicompany)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R,
        KC_A, KC_S, KC_D, KC_F,
        KC_Z, KC_X, KC_C, LT(1, KC_V), KC_B,
                                KC_NO, KC_NO
    ),
    [1] = LAYOUT(
        RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS
    )
};
