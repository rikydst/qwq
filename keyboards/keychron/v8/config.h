/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

/* If uses PH3 with a stronger pull resistor then the following definition should be included */
// #define MATRIX_UNSELECT_DRIVE_HIGH

/* RGB Matrix Driver Configuration */
#define SNLED27351_DRIVER_COUNT 2
#define SNLED27351_I2C_ADDRESS_1 SNLED27351_I2C_ADDRESS_VDDIO
#define SNLED27351_I2C_ADDRESS_2 SNLED27351_I2C_ADDRESS_GND

/* Increase I2C speed to 1000 KHz */
#define I2C1_TIMINGR_PRESC 0U
#define I2C1_TIMINGR_SCLDEL 3U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 15U
#define I2C1_TIMINGR_SCLL 51U

#define SNLED27351_PHASE_CHANNEL SNLED27351_MSKPHASE_9CHANNEL
#define SNLED27351_CURRENT_TUNE { 0xC4, 0xC4, 0x60, 0xC4, 0xC4, 0x60, 0xC4, 0xC4, 0x60, 0xC4, 0xC4, 0x60 }

/* DIP switch */
#define DIP_SWITCH_MATRIX_GRID  { {4, 4} }

/* Disable DIP switch in matrix data */
#define MATRIX_MASKED

/* Turn off effects when suspended */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* Encoder Configuration */
#ifdef ENCODER_ENABLE
    #define ENCODER_DEFAULT_POS 0x3
#endif

/* EEPROM Driver Configuration */
#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)
