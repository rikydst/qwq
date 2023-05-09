/* Copyright 2023 Pangorin <https://github.com/pangorin>
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

/* Bootmagic key */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Forcing to use NKRO instead 6KRO */
#define FORCE_NKRO

#ifdef RGB_MATRIX_ENABLE
    /* RGB Matrix config */
    #define RGB_DI_PIN B15
    #define RGB_MATRIX_LED_COUNT 84
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
    #define LED_CAPS_LOCK_PIN
#endif