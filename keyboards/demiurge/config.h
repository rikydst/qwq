
/*
Copyright 2021 ojthetiny

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

#include "config_common.h"


/* USB Device descriptor parameter */
#define VENDOR_ID       0x6F6A
#define PRODUCT_ID      0x6475
#define DEVICE_VER      0x0001    
#define PRODUCT         Demiurge

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 17

/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F4, F6, F7, C7 }
#define MATRIX_COL_PINS { E6, F5, C6, B6, B5, B4, D7, D6, D4, D5, D3, D2, D1, D0, B7, B3, B2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 1
#endif

#define RGB_DI_PIN F1
#ifdef RGB_DI_PIN
#define RGBLED_NUM 21
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LIMIT_VAL 153
#endif







/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
