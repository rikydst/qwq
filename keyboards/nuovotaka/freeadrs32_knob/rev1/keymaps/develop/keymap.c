// SPDX-FileCopyrightText: 2024 Takahiro Natsume ( @nuovotaka )
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

#include "print.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        //,------+--------+--------+--------+--------+-------+--------+--------+--------.
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
                KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
        KC_1, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
        KC_1, KC_LALT, KC_Z, KC_X, KC_C, KC_V, MO(1), KC_M, KC_ENT
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
    ),
    [1] = LAYOUT(
        //,------+--------+--------+--------+--------+-------+--------+--------+--------.
        S(KC_ESC), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8),
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
                S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I),
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
        S(KC_1), KC_LSFT, S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J),
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
        S(KC_1), KC_LALT, S(KC_Z), S(KC_X), S(KC_C), S(KC_V), _______, S(KC_M), KC_ENT
        //|------+--------+--------+--------+--------+-------+--------+--------+--------|
    )
};

// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(KC_PAGE_UP, KC_PAGE_DOWN), // Encoder 1
        ENCODER_CCW_CW(KC_UP, KC_DOWN),           // Encoder 2
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)         // Encoder 3
    },
    [1] = {
        ENCODER_CCW_CW(KC_PAGE_UP, KC_PAGE_DOWN), // Encoder 1
        ENCODER_CCW_CW(KC_UP, KC_DOWN),           // Encoder 2
        ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)         // Encoder 3
    }};
#endif

void keyboard_post_init_user(void)
{
#ifdef CONSOLE_ENABLE
    debug_enable = true;
#endif
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  return true;
}