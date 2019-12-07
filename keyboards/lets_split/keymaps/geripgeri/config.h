/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define USE_SERIAL

/* Select hand configuration */
#define MASTER_LEFT

#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_NUMERIC
#endif

// RGB lighting
#define RGBLIGHT_SLEEP
#undef RGBLED_NUM
#define RGBLED_NUM 24
#define RGBLIGHT_SLEEP

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

#define TAPPING_TERM 200
