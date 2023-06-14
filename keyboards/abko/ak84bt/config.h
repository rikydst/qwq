/* Copyright 2023 temp4gh
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

#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 0

#define VIA_EEPROM_CUSTOM_CONFIG_SIZE 32

#define SPI_DRIVER SPID2
#define SPI_SCK_PIN  B13
#define SPI_MOSI_PIN B15
#define SPI_MISO_PIN B14
#define SPI_SLAVE_CS B12

#define MATRIX_ROWS 6
#define MATRIX_COLS 16

#define DIODE_DIRECTION     COL2ROW
#define MATRIX_ROW_PINS     { A0, A1, A2, A3, A4, A5}
#define MATRIX_COL_PINS     { A6, A7, C4, C5, B0, B1, C6, C7, C8, C9, A8, A9, A10, A13, A14, A15}

#define DYNAMIC_KEYMAP_LAYER_COUNT 2  

#define DRIVER_ADDR_1 0b1010000
#define DRIVER_ADDR_2 0b1010011

#define DRIVER_COUNT 2
#define DRIVER_1_LED_TOTAL 45
#define DRIVER_2_LED_TOTAL 45

#define RGB_MATRIX_LED_COUNT (DRIVER_1_LED_TOTAL+DRIVER_2_LED_TOTAL)

#define EECONFIG_MAGIC_NUMBER   0x1234

#define INDICATOR_MAX_BRIGHTNESS 255
#ifdef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #undef INDICATOR_MAX_BRIGHTNESS
    #define INDICATOR_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS

#define    ENABLE_RGB_MATRIX_SOLID_COLOR              
#define    ENABLE_RGB_MATRIX_ALPHAS_MODS              
#define    ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN         
#define    ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT      
#define    ENABLE_RGB_MATRIX_BREATHING                
#define    ENABLE_RGB_MATRIX_BAND_SAT                 
#define    ENABLE_RGB_MATRIX_BAND_VAL                 
#define    ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL          
#define    ENABLE_RGB_MATRIX_CYCLE_ALL                
#define    ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT         
#define    ENABLE_RGB_MATRIX_CYCLE_UP_DOWN            
#define    ENABLE_RGB_MATRIX_HUE_WAVE                 
#define    ENABLE_RGB_MATRIX_PIXEL_FLOW               

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL
