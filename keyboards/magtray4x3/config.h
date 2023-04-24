// Copyright 2023 Noah Beidelman (@noahbei)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* maybe need this
#define I2C1_OPMODE	OPMODE_I2C
#define I2C1_CLOCK_SPEED 100000
#define I2C1_DUTY_CYCLE	STD_DUTY_CYCLE
*/

#define OLED_TIMEOUT 180000
#define I2C1_SCL_PAL_MODE 1
#define I2C1_SDA_PAL_MODE 3

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
