/* Copyright 2024 CANARYTEAM <tuananhnguyen204@gmail.com>
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

#define I2C1_SDA_PIN GP20
#define I2C1_SCL_PIN GP21
#define I2C_DRIVER I2CD0

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define IS31FL3733_I2C_ADDRESS_1 IS31FL3733_I2C_ADDRESS_GND_GND

#define USB_SUSPEND_WAKEUP_DELAY 2000
