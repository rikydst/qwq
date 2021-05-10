/** @file oled.c
 *  @brief incluedes oled layout and some definintions.
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
 *
 * @author Aaron Walker (awwalker3@gmail.com) 2021
 *
 */

#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>
#include "awwalker.h"
#include "oled.h"

uint32_t pika_anim_timer = 0;
uint32_t pika_anim_sleep = 0;

uint32_t bongo_anim_timer = 0;
uint32_t bongo_anim_sleep = 0;

uint8_t pika_current_frame = 0;
uint8_t bongo_current_frame = 0;

bool is_deleting = false;

// Setup vars for WPM.
char wpm_str[20];

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Idea from SoundMaster but uses local images rather than glcdfont.
void render_layer_state(void) {
    static const char PROGMEM default_layer[] = {
        // 'pixil-frame-0(15)', 32x17px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xa8, 0xa8, 0xc4, 0xc4, 0x82, 0x82, 0x01,
        0x01, 0x82, 0x82, 0xc4, 0xc4, 0xa8, 0xa8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x2b, 0x2b, 0x47, 0x47, 0x8f, 0x8f, 0x1f,
        0x1f, 0x8f, 0x8f, 0x47, 0x47, 0x2b, 0x2b, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM raise_layer[] = {
        // 'pixil-frame-0(16)', 32x17px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xb8, 0xb8, 0x7c, 0x7c, 0xfe, 0xfe, 0xff,
        0xff, 0xfe, 0xfe, 0x7c, 0x7c, 0xb8, 0xb8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x2a, 0x2a, 0x44, 0x44, 0x88, 0x88, 0x11,
        0x11, 0x88, 0x88, 0x44, 0x44, 0x2a, 0x2a, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM lower_layer[] = {
        // 'pixil-frame-0(17)', 32x17px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0xa8, 0xa8, 0x44, 0x44, 0x82, 0x82, 0x01,
        0x01, 0x82, 0x82, 0x44, 0x44, 0xa8, 0xa8, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x3a, 0x3a, 0x7c, 0x7c, 0xf8, 0xf8, 0xf1,
        0xf1, 0xf8, 0xf8, 0x7c, 0x7c, 0x3a, 0x3a, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    if(layer_state_is(_LOWER)) {
        oled_write_raw_P(lower_layer, sizeof(lower_layer));
    } else if(layer_state_is(_RAISE)) {
        oled_write_raw_P(raise_layer, sizeof(raise_layer));
    } else {
        oled_write_raw_P(default_layer, sizeof(default_layer));
    }
}

// Idea from SoundMaster but uses local images rather than glcdfont.
// GUI + ALT mods.
void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_alt_off[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x02, 0x11, 0x29, 0xf1, 0x21, 0x21, 0x21, 0xf1, 0x29, 0x11,
        0x01, 0x01, 0x11, 0x11, 0x21, 0x41, 0x81, 0x01, 0x11, 0x11, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x22, 0x25, 0x23, 0x21, 0x21, 0x21, 0x23, 0x25, 0x22,
        0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x22, 0x22, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM gui_alt_on[] = {
        // 'pixil-frame-0(8)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xef, 0xd7, 0x0f, 0xdf, 0xdf, 0xdf, 0x0f, 0xd7, 0xef,
        0xff, 0xff, 0xef, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xef, 0xef, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3d, 0x3a, 0x3c, 0x3e, 0x3e, 0x3e, 0x3c, 0x3a, 0x3d,
        0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3d, 0x3d, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM gui_on_alt_off[] = {
        // 'pixil-frame-0(9)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xef, 0xd7, 0x0f, 0xdf, 0xdf, 0xdf, 0x0f, 0xd7, 0xef,
        0xff, 0x01, 0x11, 0x11, 0x21, 0x41, 0x81, 0x01, 0x11, 0x11, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3d, 0x3a, 0x3c, 0x3e, 0x3e, 0x3e, 0x3c, 0x3a, 0x3d,
        0x3f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x21, 0x22, 0x22, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM gui_off_alt_on[] = {
        // 'pixil-frame-0(7)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x02, 0x11, 0x29, 0xf1, 0x21, 0x21, 0x21, 0xf1, 0x29, 0x11,
        0x01, 0xff, 0xef, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xef, 0xef, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x22, 0x25, 0x23, 0x21, 0x21, 0x21, 0x23, 0x25, 0x22,
        0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3d, 0x3d, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00
    };


    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_raw_P(gui_alt_on, sizeof(gui_alt_on));
    } else if(modifiers & MOD_MASK_GUI) {
        oled_write_raw_P(gui_on_alt_off, sizeof(gui_on_alt_off));
    } else if(modifiers & MOD_MASK_ALT) {
        oled_write_raw_P(gui_off_alt_on, sizeof(gui_off_alt_on));
    } else {
        oled_write_raw_P(gui_alt_off, sizeof(gui_alt_off));
    }
}

// Idea from SoundMaster but uses local images rather than glcdfont.
// CTRL + SHIFT mod icons.
void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_shift_on[] = {
        // 'pixil-frame-0(6)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x7f, 0xbf, 0xdf, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xff,
        0xff, 0x7f, 0x3f, 0x5f, 0xef, 0xf7, 0xef, 0x5f, 0x3f, 0x7f, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x3f, 0x3f, 0x3f, 0x38, 0x3b, 0x3b, 0x3b, 0x38, 0x3f, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM ctrl_off_shift_on[] = {
        // 'pixil-frame-0(3)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x02, 0x81, 0x41, 0x21, 0x11, 0x21, 0x41, 0x81, 0x01, 0x01,
        0xff, 0x7f, 0x3f, 0x5f, 0xef, 0xf7, 0xef, 0x5f, 0x3f, 0x7f, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x3f, 0x3f, 0x3f, 0x38, 0x3b, 0x3b, 0x3b, 0x38, 0x3f, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM ctrl_on_shift_off[] = {
        // 'pixil-frame-0(4)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0x7f, 0xbf, 0xdf, 0xef, 0xdf, 0xbf, 0x7f, 0xff, 0xff,
        0x01, 0x81, 0xc1, 0xa1, 0x11, 0x09, 0x11, 0xa1, 0xc1, 0x81, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
        0x20, 0x20, 0x20, 0x27, 0x24, 0x24, 0x24, 0x27, 0x20, 0x20, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
    };
    static const char PROGMEM ctrl_shift_off[] = {
        // 'pixil-frame-0(5)', 32x14px
        0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x02, 0x81, 0x41, 0x21, 0x11, 0x21, 0x41, 0x81, 0x01, 0x01,
        0x01, 0x81, 0xc1, 0xa1, 0x11, 0x09, 0x11, 0xa1, 0xc1, 0x81, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
        0x20, 0x20, 0x20, 0x27, 0x24, 0x24, 0x24, 0x27, 0x20, 0x20, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00
    };

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_raw_P(ctrl_shift_on, sizeof(ctrl_shift_on));
    } else if(modifiers & MOD_MASK_CTRL) {
        oled_write_raw_P(ctrl_on_shift_off, sizeof(ctrl_on_shift_off));
    } else if(modifiers & MOD_MASK_SHIFT) {
        oled_write_raw_P(ctrl_off_shift_on, sizeof(ctrl_off_shift_on));
    } else {
        oled_write_raw_P(ctrl_shift_off, sizeof(ctrl_shift_off));
    }
}

static void render_pika(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
       {
            // 'pixil-frame-0(14)', 32x32px
            0x00, 0x80, 0xc0, 0xe0, 0xd0, 0x18, 0x98, 0x88, 0x48, 0x0c, 0x04, 0x04, 0x04, 0x82, 0x82, 0x02,
            0x02, 0x02, 0x02, 0x82, 0x84, 0x04, 0x04, 0x04, 0x08, 0x08, 0x88, 0x90, 0x10, 0xe0, 0xc0, 0x80,
            0xf1, 0x31, 0x51, 0x91, 0x61, 0x21, 0xfc, 0x03, 0x00, 0x18, 0x3c, 0x3d, 0x19, 0x00, 0x00, 0x30,
            0x4a, 0x48, 0xf0, 0xc0, 0x80, 0x99, 0x3d, 0x3c, 0x18, 0x00, 0x03, 0xfc, 0x01, 0x01, 0x01, 0x01,
            0x47, 0xaa, 0x15, 0x12, 0x45, 0xe2, 0xf0, 0x1f, 0x00, 0xc0, 0x00, 0x80, 0x00, 0xe0, 0x00, 0x04,
            0x0c, 0x0c, 0x04, 0x01, 0x02, 0x04, 0x19, 0x62, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x06, 0x08, 0xd0, 0xa3, 0xa4, 0x85, 0xc7, 0x40, 0x60,
            0x60, 0x60, 0x60, 0x40, 0xc0, 0x80, 0xa0, 0xa0, 0xd0, 0x08, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00,
        },
    };
    static const char PROGMEM shocked[IDLE_FRAMES][ANIM_SIZE] = {
        {
            0x03, 0x0f, 0x52, 0xa2, 0x84, 0x08, 0x18, 0x24, 0x40, 0x20, 0x20, 0x10, 0x20, 0x20, 0x20, 0x20,
            0x40, 0x20, 0x10, 0x0a, 0x84, 0x6e, 0x1e, 0x8f, 0x4b, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x40, 0xe4, 0xda, 0x81, 0x20, 0x20, 0x40, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x40,
            0x20, 0x20, 0x80, 0xc1, 0x1e, 0xa5, 0x43, 0x02, 0x21, 0x54, 0x9b, 0x15, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x40, 0x49, 0xb7, 0x03, 0x40, 0x80, 0x90, 0xa0, 0x62, 0x12, 0x12, 0x12, 0x60, 0xa0,
            0x90, 0x80, 0x41, 0x03, 0x3d, 0x69, 0xd1, 0x70, 0x14, 0x0a, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x0a, 0x08, 0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
            0x04, 0x08, 0x08, 0x0a, 0x0d, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
    };
    static const char PROGMEM talking[TAP_FRAMES][ANIM_SIZE] = {
        {
            0x03, 0x0f, 0x1e, 0x22, 0x44, 0x84, 0x04, 0x08, 0x08, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08, 0x08,
            0x08, 0x08, 0x08, 0x10, 0x10, 0x08, 0x08, 0x04, 0x84, 0x44, 0x22, 0x9e, 0xcf, 0xe3, 0xf0, 0xf0,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0xff, 0x30, 0x02, 0x06, 0x03, 0x00, 0x20, 0x14, 0x10, 0x20,
            0x02, 0x06, 0x33, 0x78, 0x78, 0x30, 0x00, 0x87, 0xfc, 0x42, 0x01, 0x11, 0xaa, 0x45, 0x03, 0x01,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x01, 0x00, 0x24, 0x48, 0x50, 0x32, 0x06, 0x06, 0x06,
            0x32, 0x50, 0x48, 0x44, 0x20, 0x10, 0x01, 0xff, 0xf0, 0x64, 0x2a, 0x11, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x2c, 0x20, 0x10, 0x18, 0x08, 0x08, 0x08, 0x08,
            0x08, 0x08, 0x18, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
        {
            0x07, 0x3f, 0xce, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,
            0x40, 0x80, 0x40, 0x20, 0x10, 0x08, 0x84, 0xce, 0x7f, 0xa7, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0xc3, 0xbc, 0x00, 0x20, 0x60, 0x30, 0x00, 0x00, 0x40, 0x00, 0x00, 0x20, 0x60,
            0x30, 0x80, 0x80, 0x00, 0x00, 0x3e, 0xe3, 0x14, 0x2a, 0x46, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0xf7, 0x0b, 0x00, 0x20, 0x40, 0x80, 0xa6, 0x69, 0x69, 0x66, 0xa0, 0x80,
            0x43, 0x27, 0x07, 0x83, 0x00, 0xf0, 0x1f, 0xa4, 0x42, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x07, 0xd8, 0xa1, 0x82, 0x82, 0xc2, 0x41, 0x40, 0x40, 0x40, 0x41, 0x42,
            0xc2, 0x82, 0x81, 0xa0, 0xd0, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },
    };
    // Assumes 1 frame prep stage.
    void pika_animation_phase(void) {
        // Switch frames.
        pika_current_frame = (pika_current_frame + 1) % 2;
        if(get_current_wpm() < MIN_ANIM_SPEED) {
            oled_write_raw_P(idle[0], sizeof(idle[0]));
        }
        if(get_current_wpm() >= MIN_ANIM_SPEED) {
             oled_write_raw_P(talking[abs(1 - pika_current_frame)], sizeof(talking[abs(1 - pika_current_frame)]));
        }
        if(is_deleting) {
            oled_write_raw_P(shocked[abs(1 - pika_current_frame)], sizeof(shocked[abs(1 - pika_current_frame)]));
        }
    }

    // Screen on and off.
    if (get_current_wpm() != 000) {
        oled_on();
        if(timer_elapsed32(pika_anim_timer) > ANIM_FRAME_DURATION) {
            pika_anim_timer = timer_read32();
            pika_animation_phase();
        }
        pika_anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(pika_anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(pika_anim_timer) > ANIM_FRAME_DURATION) {
                pika_anim_timer = timer_read32();
                pika_animation_phase();
            }
        }
    }
}

void render_bongo_cat(void) {
        static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        }
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0xff, 0xff, 0xff, 0x7c, 0x70, 0x40, 0x40,
        0x61, 0x5e, 0x80, 0xc0, 0xbc, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0f, 0x3f, 0xf8, 0xf0, 0xf0, 0x20,
        0x40, 0x80, 0x80, 0x00, 0x00, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0x1e, 0x01, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0x00, 0xf0, 0x0f, 0x80, 0x78, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x00, 0xe1, 0x1e, 0x01, 0xf0, 0x8f, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x19,
        0x19, 0x41, 0x0a, 0x22, 0x84, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01,
        },
        {
        0x00, 0xc0, 0x3e, 0x01, 0x00, 0x00, 0x00, 0xc0, 0xfc, 0x03, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00,
        0xe1, 0x1e, 0x00, 0xc0, 0xbc, 0x83, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x3c, 0x03, 0x00, 0x00, 0x00, 0x80, 0x78, 0x87, 0x00, 0x03, 0x0c, 0x30, 0xc0, 0x00, 0xe0, 0x1f,
        0x01, 0xc0, 0x3c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x31, 0x05, 0x41, 0x12, 0x04,
        0x00, 0x00, 0x00, 0x00, 0xf8, 0x87, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0xc0, 0x3f, 0x03, 0x80,
        0x78, 0x07, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x03, 0x05,
        0x00, 0x00, 0xf0, 0xcf, 0x00, 0x01, 0x06, 0x18, 0x60, 0x80, 0x80, 0x79, 0x07, 0x80, 0x78, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xe0, 0xfe, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0xf9, 0x07, 0x80, 0x78, 0x07, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x2c, 0x32, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x03, 0x0f, 0x3f, 0xff, 0x03, 0x01, 0x03, 0x07, 0x18, 0xf8, 0x07, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x18, 0x60, 0x80, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x3c, 0x00, 0x00, 0x00, 0x00,
        0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08, 0x08, 0x09, 0x0e, 0x0e, 0x01, 0xf3, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x60, 0x18,
        0x00, 0x00, 0x00, 0x00, 0xf0, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x09, 0x70, 0x80,
        0x00, 0x00, 0xf0, 0x1f, 0x10, 0x10, 0x10, 0x10, 0x10, 0x08, 0x08, 0x08, 0x04, 0x04, 0x02, 0x02,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x04, 0x02, 0x01
        },
    };

    //assumes 1 frame prep stage
    void bongo_animation_phase(void) {
        // Switch frames.
        if(get_current_wpm() < MIN_ANIM_SPEED) {
            oled_write_raw_P(idle[0], ANIM_SIZE);
        }
        if(get_current_wpm() >= MIN_ANIM_SPEED) {
            bongo_current_frame = (bongo_current_frame + 1) % TAP_FRAMES;
            oled_write_raw_P(tap[abs((TAP_FRAMES-1)-bongo_current_frame)], ANIM_SIZE);
        }
    }
    // Screen on and off.
    if (get_current_wpm() != 000) {
        oled_on();
        if(timer_elapsed32(bongo_anim_timer) > ANIM_FRAME_DURATION) {
            bongo_anim_timer = timer_read32();
            bongo_animation_phase();
        }
        bongo_anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(bongo_anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(bongo_anim_timer) > ANIM_FRAME_DURATION) {
                bongo_anim_timer = timer_read32();
                bongo_animation_phase();
            }
        }
    }
}

// WPM tracker
void render_wpm(void) {
    sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
    oled_write(wpm_str, false);
}

void render_status_main(void) {
    oled_set_cursor(0, 1);
    render_pika();
    oled_set_cursor(0, 7);
    render_layer_state();
    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_set_cursor(0, 11);
    render_mod_status_ctrl_shift(mods);
    oled_set_cursor(0, 13);
    render_mod_status_gui_alt(mods);
}

void render_secondary(void) {
    render_bongo_cat();
    oled_set_cursor(0, 13);
    sprintf(wpm_str, "WPM\n%03d", get_current_wpm());
    oled_write(wpm_str, false);
}

void oled_task_user(void) {
    // NOTE: on elite-cs this has to be swapped manually.
    // Each half thinks it `is_keyboard_master()`.
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc).
    } else {
        render_secondary();
    }
}
