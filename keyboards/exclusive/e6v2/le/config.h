/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* QMK E6-V2 PCB default pin-out */
#define MATRIX_ROW_PINS { B0, B1, B2, B3, B4 }
#define MATRIX_COL_PINS { B5, D0, D1, D2, D3, D4, D5, D6, D7, C6, C7, F4, F5, F6, F7 }

#define RGB_DI_PIN E6
#ifdef RGB_DI_PIN
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 12
#define RGBLIGHT_SAT_STEP 12
#define RGBLIGHT_VAL_STEP 12
#endif

#define BACKLIGHT_PIN B6
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 2
#define BACKLIGHT_BREAHTING
#endif

#define DIODE_DIRECTION COL2ROW
