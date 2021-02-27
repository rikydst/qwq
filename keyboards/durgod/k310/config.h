/* Copyright 2021 kuenhlee, Don Kjer, Tyler Tidman
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xD60D
#define PRODUCT_ID      0x3100
#define DEVICE_VER      0x0001
#define MANUFACTURER    Hoksi Technology
#define PRODUCT         DURGOD Taurus K310 (QMK)

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 16

#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5, A6, A7 }
#define MATRIX_COL_PINS { C4, C5, B0, B1, B2, B10, B11, B12, B13, B14, B15, C6, C7, C10, C11, C12 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION ROW2COL

// Dynamic EEPROM
// Something sensible or else VIA may crash
// Users may enable more if they wish
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR  4095

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
// #define USB_POLLING_INTERVAL_MS 1

/* Bootmagic Lite key configuration */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#define BOOTMAGIC_LITE_ROW                 0
#define BOOTMAGIC_LITE_COLUMN              0

/* LED indicator pins */
#define LED_NUM_LOCK_PIN    C8
#define LED_CAPS_LOCK_PIN   C9
#define LED_SCROLL_LOCK_PIN A8
#define LED_WIN_LOCK_PIN    A9
#define LED_MR_LOCK_PIN     A10
#define LED_PIN_ON_STATE    0

/* Original hardware "reset" button on pin D2 */
