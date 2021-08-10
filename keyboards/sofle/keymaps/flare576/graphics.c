/* Copyright 2021 Flare576 <flare576@gmail.com>
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
#include QMK_KEYBOARD_H
#include "enums.h"
int current_wpm = -1; // Enable screen-on at startup
bool isJumping = false;
bool showedJump = true;

#ifdef MAIN_BOARD
static void render_logos(void){}

// START Luna vars
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_SIZE 96 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint8_t current_frame = 0;

bool isSneaking = false;
static void render_luna(int LUNA_X, int LUNA_Y) {

    static const char PROGMEM sit[2][ANIM_SIZE] = {
        // 'sit1', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        // 'sit2', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    static const char PROGMEM walk[2][ANIM_SIZE] = {
        // 'walk1', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        // 'walk2', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM run[2][ANIM_SIZE] = {
        // 'run1', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        // 'run2', 32x22px
        {
            0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    static const char PROGMEM sneak[2][ANIM_SIZE] = {
        // 'sneak1', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
            0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
            0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        },

        // 'sneak2', 32x22px
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
            0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
            0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    // animation state
    void animation_phase(void) {

        if (isJumping || !showedJump) {

            // clear
            oled_set_cursor(LUNA_X,LUNA_Y +2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X,LUNA_Y -1);

            showedJump = true;
        } else {

            // clear
            oled_set_cursor(LUNA_X,LUNA_Y -1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X,LUNA_Y);
        }

        current_frame = (current_frame + 1) % 2;

        if(isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if(current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if(current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    // animation timer
    if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animation_phase();
    }

}
// END Luna vars


static void main_board(void) {
    int layer = get_highest_layer(layer_state);
    isSneaking = false;
    // Print current mode
    oled_write_ln_P(PSTR("Flare"), false);
    oled_write_ln_P(PSTR("Sofle"), false);
    if (layer == _FF14) {
        static char os_logo[8*16] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xf0, 0x00, 0xf0, 0xc0, 0xe0, 0x80, 0x00, 0x02,
            0x0c, 0x2e, 0xfc, 0xfc, 0xfc, 0xfc, 0x78, 0x78, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x3f, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8,
            0xf8, 0xf8, 0xf1, 0xff, 0xff, 0xff, 0xf8, 0xf0, 0xf0, 0xb0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x7b, 0xdf, 0x1f, 0x3f, 0x3f,
            0x1f, 0x1f, 0x3f, 0x5f, 0x9f, 0x8f, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x06, 0x07, 0x0f, 0x1c, 0x74,
            0x0c, 0x0d, 0x09, 0x09, 0x11, 0x01, 0x03, 0x03, 0x07, 0x05, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        oled_write_raw(os_logo, 8*16);
    } else if (keymap_config.swap_lalt_lgui) {
        static char os_logo[8*16] = {
            0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0xf8,
            0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfe, 0xfe, 0xfe, 0x00,
            0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
            0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0xfe,
            0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00,
            0x00, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x00, 0x1f,
            0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x00
        };
        oled_write_raw(os_logo, 8*16);
    } else {
        static char os_logo[8*16] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0xe0, 0x78, 0x7c, 0x7e, 0x3e, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe,
            0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0x0e, 0x0c, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f,
            0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00
        };
        oled_write_raw(os_logo, 8*16);
    }
    oled_set_cursor(0, 9);

    switch (layer) {
        case _BASE:
            oled_write_ln_P(PSTR("ALL"), false);
            oled_write_P(PSTR(" YOUR"), false);
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _MOUS:
            isSneaking = true;
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case _SYMS:
            oled_write_ln_P(PSTR("@$*&#"), false);
            break;
        case _FF14:
            oled_write_ln_P(PSTR("FFXIV"), false);
            break;
        case _ESDF:
            oled_write_ln_P(PSTR("ESDF "), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    if (layer != _BASE) {
        oled_write_P(PSTR("\n"), false);
    }

    // Don't re-write if not in use
    if (current_wpm > 0) {
        render_luna(0,13);
    }
}
#else
static void main_board(void){}

#define LINE_LENGTH 32
#define MARQUEE_FRAME_DURATION 200 // how long each frame lasts in ms
#define MARQUEE_LINES 20
#define MARQUEE_BITS (MARQUEE_LINES * LINE_LENGTH)
uint32_t marquee_timer = 0;
uint32_t marquee_frame = 0;


static void render_logos(void) {
    static const char logos[MARQUEE_BITS] = {
        // Docker start
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70,
        0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x80, 0x80, 0xb0, 0xb0, 0xb0, 0x80, 0xb7, 0xb7, 0xb7, 0x80, 0xb7, 0xb7, 0xb7, 0x80, 0xb7,
        0xb7, 0xb7, 0x80, 0xb0, 0xb0, 0xb0, 0x80, 0x80, 0xfe, 0xfe, 0xfc, 0xf0, 0xf0, 0xf0, 0x70, 0x00,
        0x03, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03,
        0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        // Docker End

        // Python Start
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x7e, 0x66, 0x66, 0x67, 0x7f, 0x7f, 0x7f,
        0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xf0, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f,
        0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x9f, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf0,
        0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf9, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x0f,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff,
        0xfe, 0xfe, 0xfe, 0xe6, 0x66, 0x66, 0x7e, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        // Python End

        // JS Start
        0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf8, 0x78, 0x7c, 0x3c, 0x1e, 0x9f,
        0x9e, 0x1e, 0x3c, 0x3c, 0x78, 0xf8, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x03, 0x01, 0xf1, 0xf8, 0xfc, 0xfc, 0x06, 0x06, 0xff, 0x0f,
        0x0f, 0x67, 0x67, 0xe6, 0xcc, 0x8c, 0xf8, 0xf9, 0x01, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x1f, 0x3f, 0x3f, 0x3f, 0x00, 0x80, 0xff, 0xe3,
        0xe2, 0xce, 0xce, 0x4c, 0x64, 0x20, 0x11, 0x9f, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x3c, 0x3c, 0x78, 0x79,
        0xf9, 0x78, 0x3c, 0x3c, 0x1e, 0x1f, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
        // JS End

        // QMK Start
        0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf0, 0xf0, 0xf8, 0xf8, 0xf0, 0xf0, 0xf8,
        0xf8, 0xf0, 0xf0, 0xf8, 0xf8, 0xf0, 0xf0, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00,
        0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x99, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf1, 0xf3, 0xe3, 0xe7, 0x00,
        0x00, 0xe7, 0xe3, 0xf3, 0xf1, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0x99, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f,
        0x1f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x00, 0x00, 0x00, 0x00,
        // QMK End

        // Brew Start
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe7, 0xff, 0xfe, 0xfc, 0xf8, 0xfe,
        0xe4, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe7, 0x43, 0x41, 0x41, 0x4b, 0xcf, 0x87, 0x87, 0x8f,
        0x87, 0x03, 0x03, 0xc3, 0x47, 0xe7, 0xa4, 0xb8, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x02, 0x02, 0x03, 0x00, 0xfe, 0x02, 0x02, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
        0x80, 0x80, 0x80, 0xc0, 0x40, 0x7b, 0x0a, 0x0a, 0x0b, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            // Brew End
    };

    void marquee_phase(void) {
        marquee_frame = ( marquee_frame + 1 ) % MARQUEE_LINES;
        int start = marquee_frame * LINE_LENGTH;
        char output[MARQUEE_BITS] = {};
        for(int i = 0; i < MARQUEE_BITS; i++) {
            int current = ( i + start ) % MARQUEE_BITS;
            output[i] = logos[current];
        }
        oled_write_raw(output, MARQUEE_BITS);
    }

    // animation timer
    if(timer_elapsed32(marquee_timer) > MARQUEE_FRAME_DURATION) {
        marquee_timer = timer_read32();
        marquee_phase();
    }
}
#endif

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    // Prevent blank screen on startup
    if (current_wpm == -1) {
        set_current_wpm(10);
    }
    current_wpm = get_current_wpm();
    if (is_keyboard_master()) {
        // can't gate main_board on wpm; won't get mode changes that don't trigger wpm
        main_board();
    } else if (current_wpm > 0) {
        render_logos();
    }
}
