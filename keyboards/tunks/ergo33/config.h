#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xA0A1
#define DEVICE_VER      0x0001
#define MANUFACTURER    kulmajaba
#define PRODUCT         Ergo33
#define DESCRIPTION     QMK keyboard firmware for Ergo33

#define MATRIX_ROWS 5
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
*/
#define MATRIX_ROW_PINS { F0, F1, B5, B4, D7 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, C7, C6, B6 }

#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Underglow + top RGB configuration */
#define RGB_DI_PIN D4

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define ENCODERS_PAD_A { D5 }
#define ENCODERS_PAD_B { D3 }

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* Bootmagic Lite key configuration */
// #define BOOTMAGIC_LITE_ROW 0
// #define BOOTMAGIC_LITE_COLUMN 0
