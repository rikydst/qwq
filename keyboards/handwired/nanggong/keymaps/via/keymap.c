// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ Cap │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │Enter│
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │Shift│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ↑  │ Del │
     * ├─────┴┬────┴──┬──┴────┬┴─────┴─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┤
     * │ ctrl │  Win  │  Alt  │  FN  │   Space   │Prt s│  \  │Bck S│  ←  │  ↓  │  →  │
     * └──────┴───────┴───────┴──────┴───────────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [0] = LAYOUT(
     //,--------------------------------------------------------------------------------------------------------------------.
          KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, 
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
		  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------| 
		 KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT, 
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------| 
		 KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_UP,  KC_DEL, 
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------| 
		   KC_LCTL,   KC_LGUI,   KC_LALT,      MO(1),           KC_SPC, KC_BSPC, KC_BSLS, KC_BSPC, KC_LEFT, KC_DOWN,  KC_RGHT
     //'----------+----------+----------+-----------+-----------------+--------+--------+--------+--------+--------+--------' 
    ),

    [1] = LAYOUT(
     //,--------------------------------------------------------------------------------------------------------------------.
         KC_TILD,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, KC_MSTP,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
           _______,   _______,   _______,    _______,          _______,   MO(2), _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
     //'----------+----------+----------+-----------+-----------------+--------+--------+--------+--------+--------+--------' 
    ),

    [2] = LAYOUT(
     //,--------------------------------------------------------------------------------------------------------------------.
         QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
         RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
         RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
         _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|  
           _______,   _______,   _______,    _______,          _______, _______, _______, _______, _______, _______, _______
     //'----------+----------+----------+-----------+-----------------+--------+--------+--------+--------+--------+--------' 
    )
};