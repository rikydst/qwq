// Copyright 2023 jonylee@hfd (@jonylee1986)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGB_TRIGGER_ON_KEYDOWN

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* SPI Config for spi flash*/
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4
#define SPI_MOSI_PAL_MODE 5

#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12

/* I2C Config for LED Driver */
#define SNLED27351_I2C_ADDRESS_1 SNLED27351_I2C_ADDRESS_GND
#define SNLED27351_I2C_ADDRESS_2 SNLED27351_I2C_ADDRESS_VDDIO
#define I2C1_SDA_PIN B7
#define I2C1_SCL_PIN B6
#define I2C1_SCL_PAL_MODE 4
#define I2C1_OPMODE OPMODE_I2C
#define I2C1_CLOCK_SPEED 400000 /* 400000 */

#define LED_MAC_OS_PIN B13
#define LED_WIN_LOCK_PIN B14
