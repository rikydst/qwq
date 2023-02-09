// Copyright 2022 Y&R-Biu (@jiaxin96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "quantum.h"

#define LAYOUT( \
    K000,       K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, \
    K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
    K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, \
    K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,                         \
    K400,       K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K413, K414,             \
    K500, K501, K502,                   K506,                   K510, K511, K512, K513, K514, K515, K516  \
    )\
    { \
    { K000,  KC_NO, K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015,  K016 }, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116 }, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216 }, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K400,  KC_NO, K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  KC_NO, K413,  K414,  KC_NO, KC_NO }, \
    { K500,  K501,  K502,  KC_NO, KC_NO, KC_NO, K506,  KC_NO, KC_NO, KC_NO, K510,  K511,  K512,  K513,  K514,  K515,  K516 }  \
}

enum keyboard_keycodes {
#ifdef VIA_ENABLE
    LOCK_GUI = USER00,
#else
    LOCK_GUI = SAFE_RANGE,
#endif
    TOG_MACOS_KEYMAP,
    KC_MISSION_CONTROL,
    KC_LAUNCHPAD,
#ifdef VIA_ENABLE
    NEW_SAFE_RANGE = SAFE_RANGE  // Important!
#else
    NEW_SAFE_RANGE   // Important!
#endif
};

#define KC_LG    LOCK_GUI
#define KC_MACOS TOG_MACOS_KEYMAP
#define KC_MCTL  KC_MISSION_CONTROL
#define KC_LPAD  KC_LAUNCHPAD
