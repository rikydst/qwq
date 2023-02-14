/*
Copyright 2021 Jay Greco

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

/* NOTE: This config file is specific to RP2040 builds. */

#pragma once

/* Optional encoder pins */
#define ENCODERS_PAD_A { GP24 }
#define ENCODERS_PAD_B { GP25 }
#define TAP_CODE_DELAY 10

/* RP2040-specific defines*/
#define RP2040_FLASH_GENERIC_03H
#define I2C1_SDA_PIN GP26
#define I2C1_SCL_PIN GP27
#define I2C_DRIVER I2CD1
