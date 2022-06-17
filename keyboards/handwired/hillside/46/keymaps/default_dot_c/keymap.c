// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _SYM,
    _NUM,
    _ADJUST,
};

#define xxxxxxx KC_NO

#define LY_SYM MO(_SYM)
#define LY_NUM MO(_NUM)
#define LY_ADJ MO(_ADJUST)
#define ALT_GR OSM(MOD_RALT)
#define OSM_SFT OSM(MOD_LSFT)
#define PLY_PAU  KC_MEDIA_PLAY_PAUSE


#define UNDO LCTL(KC_Z)
#define CUT  LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Y)
// (For OS X, you'll want to change these editing keys to LGUI(KC_Z) etc.)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,                       CAPSWRD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                                         KC_LGUI, KC_LALT, LY_SYM , OSM_SFT,    LY_NUM , KC_SPC , KC_LALT, KC_RGUI
    ),
    [_SYM] = LAYOUT(
     KC_HOME, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     KC_END,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_INS,                                         KC_LBRC, KC_RBRC, KC_MINS, KC_EQL , KC_BSLS, _______, 
     _______, xxxxxxx, KC_VOLD, KC_MUTE, KC_VOLU, KC_MPLY, ALT_GR ,                      KC_APP , KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_PIPE, KC_RCTL,
                                         _______, _______, _______, _______,    LY_ADJ , _______, _______, _______ 
    ),
    [_NUM] = LAYOUT(
     CUT    , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
     COPY   , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, PASTE,                                          UNDO   , KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, _______, 
     _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5,   KC_PGUP,                      KC_PGDN, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_RCTL,
                                         _______, _______, LY_ADJ , _______,    _______, _______, _______, _______
    ),
    [_ADJUST] = LAYOUT(
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, AG_SWAP, CG_SWAP,                                        xxxxxxx, KC_F11 , KC_F12 , KC_PSCR, xxxxxxx, EE_CLR,
     xxxxxxx, xxxxxxx, KC_BRID, KC_BRIU, AG_NORM, CG_NORM,                                        RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, xxxxxxx, xxxxxxx, 
     xxxxxxx, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, xxxxxxx, xxxxxxx,                     RGB_TOG, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, xxxxxxx, QK_BOOT,
                                         xxxxxxx, xxxxxxx, xxxxxxx, _______,    _______, xxxxxxx, xxxxxxx, xxxxxxx
    ),
};

//  Template:
//    [_INDEX] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
//                                         _______, _______, _______, _______,    _______, _______, _______, _______
//    ),
