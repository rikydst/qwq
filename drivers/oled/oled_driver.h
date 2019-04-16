/*
Copyright 2019 Ryan Caltabiano <https://github.com/XScorpion2>

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

#include <stdint.h>
#include <stdbool.h>


#if defined(OLED_DISPLAY_CUSTOM)
  // Expected user to implement the necessary defines
#elif defined(OLED_DISPLAY_128X64)
  // Double height 128x64
  #define OLED_DISPLAY_WIDTH 128
  #define OLED_DISPLAY_HEIGHT 64
  #define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH) // 1024 (compile time mathed)
  #define OLED_BLOCK_TYPE uint16_t
  #define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8) // 16 (compile time mathed)
  #define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT) // 64 (compile time mathed)

  // For 90 degree rotation, we map our internal matrix to oled matrix using fixed arrays
  // The OLED writes to it's memory horizontally, starting top left, but our memory starts bottom left in this mode
  #define OLED_SOURCE_MAP { 0, 8, 16, 24, 32, 40, 48, 56 }
  #define OLED_TARGET_MAP { 56, 48, 40, 32, 24, 16, 8, 0 }
  // If OLED_BLOCK_TYPE is uint8_t, these tables would look like:
  // #define OLED_SOURCE_MAP { 0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120 }
  // #define OLED_TARGET_MAP { 56, 120, 48, 112, 40, 104, 32, 96, 24, 88, 16, 80, 8, 72, 0, 64 }
#else // defined(OLED_DISPLAY_128X64)
  // Default 128x32
  #define OLED_DISPLAY_WIDTH 128
  #define OLED_DISPLAY_HEIGHT 32
  #define OLED_MATRIX_SIZE (OLED_DISPLAY_HEIGHT / 8 * OLED_DISPLAY_WIDTH) // 512 (compile time mathed)
  #define OLED_BLOCK_TYPE uint8_t // Type to use for segmenting the oled display for smart rendering, use unsigned types only
  #define OLED_BLOCK_COUNT (sizeof(OLED_BLOCK_TYPE) * 8) // 8 (compile time mathed)
  #define OLED_BLOCK_SIZE (OLED_MATRIX_SIZE / OLED_BLOCK_COUNT) // 128 (compile time mathed)

  // For 90 degree rotation, we map our internal matrix to oled matrix using fixed arrays
  // The OLED writes to it's memory horizontally, starting top left, but our memory starts bottom left in this mode
  #define OLED_SOURCE_MAP { 0, 8, 16, 24, 32, 40, 48, 56 }
  #define OLED_TARGET_MAP { 48, 32, 16, 0, 56, 40, 24, 8 }
#endif // defined(OLED_DISPLAY_CUSTOM)

// Address to use for tthe i2d oled communication
#if !defined(OLED_DISPLAY_ADDRESS)
  #define OLED_DISPLAY_ADDRESS 0x3C
#endif

// Custom font file to use
#if !defined(OLED_FONT_H)
  #define OLED_FONT_H "glcdfont.c"
#endif
// unsigned char value of the first character in the font file
#if !defined(OLED_FONT_START)
  #define OLED_FONT_START 0
#endif
// unsigned char value of the last character in the font file
#if !defined(OLED_FONT_END)
  #define OLED_FONT_END 224
#endif
// Font render width
#if !defined(OLED_FONT_WIDTH)
  #define OLED_FONT_WIDTH 6
#endif
// Font render height
#if !defined(OLED_FONT_HEIGHT)
  #define OLED_FONT_HEIGHT 8
#endif

#define OLED_ROTATION_0 0x00
#define OLED_ROTATION_90 0x01
#define OLED_ROTATION_180 0x02
#define OLED_ROTATION_270 0x03

// Initialize the oled display, rotating the rendered output based on the define passed in.
// Returns true if the OLED was initialized successfully
bool oled_init(uint8_t rotation);

// Called at the start of oled_init, weak function overridable by the user
// rotation - the value passed into oled_init
// Return new uint8_t if you want to override default rotation
uint8_t oled_init_user(uint8_t rotation);

// Clears the display buffer, resets cursor position to 0, and sets the buffer to dirty for rendering
void oled_clear(void);

// Renders the dirty chunks of the buffer to oled display
void oled_render(void);

// Moves cursor to character position indicated by column and line, wraps if out of bounds
// Max column denoted by 'oled_max_chars()' and max lines by 'oled_max_lines()' functions
void oled_set_cursor(uint8_t col, uint8_t line);

// Advances the cursor to the next page, writing ' ' if true
// Wraps to the begining when out of bounds
void oled_advance_page(bool clearPageRemainder);

// Moves the cursor forward 1 character length
// Advance page if there is not enough room for the next character
// Wraps to the begining when out of bounds
void oled_advance_char(void);

// Writes a single character to the buffer at current cursor position
// Advances the cursor while writing, inverts the pixels if true
// Main handler that writes character data to the display buffer
void oled_write_char(const char data, bool invert);

// Writes a string to the buffer at current cursor position
// Advances the cursor while writing, inverts the pixels if true
void oled_write(const char *data, bool invert);

// Writes a string to the buffer at current cursor position
// Advances the cursor while writing, inverts the pixels if true
// Advances the cursor to the next page, wiring ' ' to the remainder of the current page
void oled_write_ln(const char *data, bool invert);

#if defined(__AVR__)
// Writes a PROGMEM string to the buffer at current cursor position
// Advances the cursor while writing, inverts the pixels if true
// Remapped to call 'void oled_write(const char *data, bool invert);' on ARM
void oled_write_P(const char *data, bool invert);

// Writes a PROGMEM string to the buffer at current cursor position
// Advances the cursor while writing, inverts the pixels if true
// Advances the cursor to the next page, wiring ' ' to the remainder of the current page
// Remapped to call 'void oled_write_ln(const char *data, bool invert);' on ARM
void oled_write_ln_P(const char *data, bool invert);
#else
  // Writes a string to the buffer at current cursor position
  // Advances the cursor while writing, inverts the pixels if true
  #define oled_write_P(data, invert) oled_write(data, invert)

  // Writes a string to the buffer at current cursor position
  // Advances the cursor while writing, inverts the pixels if true
  // Advances the cursor to the next page, wiring ' ' to the remainder of the current page
  #define oled_write_ln_P(data, invert) oled_write(data, invert)
#endif // defined(__AVR__)

// Can be used to manually turn on the screen if it is off
// Returns true if the screen was on or turns on
bool oled_on(void);

// Can be used to manually turn off the screen if it is on
// Returns true if the screen was off or turns off
bool oled_off(void);

// Basically it's oled_render, but with timeout management and oled_task_user calling!
void oled_task(void);

// Called at the start of oled_task, weak function overridable by the user
void oled_task_user(void);

// Scrolls the entire display right
// Returns true if the screen was scrolling or starts scrolling
// NOTE: display contents cannot be changed while scrolling
bool oled_scroll_right(void);

// Scrolls the entire display left
// Returns true if the screen was scrolling or starts scrolling
// NOTE: display contents cannot be changed while scrolling
bool oled_scroll_left(void);

// Turns off display scrolling
// Returns true if the screen was not scrolling or stops scrolling
bool oled_scroll_off(void);

// Returns the maximum number of characters that will fit on a line
uint8_t oled_max_chars(void);

// Returns the maximum number of lines that will fit on the oled
uint8_t oled_max_lines(void);
