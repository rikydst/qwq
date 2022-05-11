// Copyright 2021 Ryan Skidmore (@ryanskidmore, rskeys@ryanskidmore.co.uk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

#define LAYOUT_fullsize_iso( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,       K014, K015, K016, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, K118, K119, K120, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, K218, K219, K220, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312,                         K317, K318, K319, \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411,       K413,       K415,       K417, K418, K419, K420, \
	K500,       K502, K503,             K506,                   K510, K511, K512, K513, K514, K515, K516, K517,       K519 \
) { \
    { K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  KC_NO, K014,  K015,  K016,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116,  K117,  K118,  K119,  K120,  KC_NO, KC_NO, KC_NO }, \
    { K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216,  K217,  K218,  K219,  K220,  KC_NO, KC_NO, KC_NO }, \
    { K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  KC_NO, KC_NO, KC_NO, KC_NO, K317,  K318,  K319,  KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  K411,  KC_NO, K413,  KC_NO, K415,  KC_NO, K417,  K418,  K419,  K420,  KC_NO, KC_NO, KC_NO }, \
    { K500,  KC_NO, K502,  K503,  KC_NO, KC_NO, K506,  KC_NO, KC_NO, KC_NO, K510,  K511,  K512,  K513,  K514,  K515,  K516,  K517,  KC_NO, K519,  KC_NO, KC_NO, KC_NO, KC_NO }  \
}
