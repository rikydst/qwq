/*
Copyright 2011, 2012, 2013 Jun Wako <wakojun@gmail.com>

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
#include <stdint.h>
#include "keyboard.h"
#include "matrix.h"
#include "keymap.h"
#include "host.h"
#include "led.h"
#include "keycode.h"
#include "timer.h"
#include "print.h"
#include "debug.h"
#include "command.h"
#include "util.h"
#include "sendchar.h"
#include "eeconfig.h"
#include "backlight.h"
#ifdef BOOTMAGIC_ENABLE
#   include "bootmagic.h"
#else
#   include "magic.h"
#endif
#ifdef MOUSEKEY_ENABLE
#   include "mousekey.h"
#endif
#ifdef PS2_MOUSE_ENABLE
#   include "ps2_mouse.h"
#endif
#ifdef SERIAL_MOUSE_ENABLE
#   include "serial_mouse.h"
#endif
#ifdef ADB_MOUSE_ENABLE
#   include "adb.h"
#endif

#ifdef MATRIX_HAS_GHOST
static bool is_row_ghosting(uint8_t row){
    matrix_row_t matrix_row = matrix_get_row(row);
    /* no ghosting happens when only one key in the row is pressed */
    if (!(matrix_row - 1 & matrix_row)) return false;
    /* ghosting occurs when two keys in the same column are pressed */
    for (int8_t r = MATRIX_ROWS - 1; r >= 0; --r) {
        if (r != row && matrix_get_row(r) & matrix_row) return true;
    }
    return false;
}

#endif

__attribute__ ((weak))
void matrix_setup(void) {
}

void keyboard_setup(void) {
    matrix_setup();
}

void keyboard_init(void) {
    timer_init();
    matrix_init();
#ifdef PS2_MOUSE_ENABLE
    ps2_mouse_init();
#endif
#ifdef SERIAL_MOUSE_ENABLE
    serial_mouse_init();
#endif
#ifdef ADB_MOUSE_ENABLE
    adb_mouse_init();
#endif
#ifdef BOOTMAGIC_ENABLE
    bootmagic();
#else
    magic();
#endif
#ifdef BACKLIGHT_ENABLE
    backlight_init();
#endif
#if defined(NKRO_ENABLE) && defined(FORCE_NKRO)
	keyboard_nkro = true;
#endif
}

/* does routine keyboard jobs */
void keyboard_task(void) {
    static matrix_row_t matrix_previous[MATRIX_ROWS];
#ifdef MATRIX_HAS_GHOST
    static matrix_row_t matrix_deghosting[MATRIX_ROWS];
#endif
    static uint8_t led_status = 0;
    matrix_row_t matrix_row = 0;
    matrix_row_t matrix_row_changes = 0;
    matrix_scan();
    for (int8_t r = MATRIX_ROWS - 1; r >= 0; --r) {
        matrix_row = matrix_get_row(r);
        matrix_row_changes = matrix_row ^ matrix_previous[r];
        if (matrix_row_changes) {
#ifdef MATRIX_HAS_GHOST
            if (is_row_ghosting(r)) {
                /* debugs the deghosting mechanism */
                /* doesn't update matrix_previous until the ghosting has stopped
                 * in order to prevent the last key from being lost */
                if (debug_matrix && matrix_deghosting[r] != matrix_row) {
                    matrix_print();
                }
                matrix_deghosting[r] = matrix_row;
                continue;
            }
            matrix_deghosting[r] = matrix_row;
#endif
            if (debug_matrix) matrix_print();
            for (int8_t c = MATRIX_COLS - 1; c >= 0; --c) {
                matrix_row_t col_mask = (matrix_row_t)1 << c;
                if (matrix_row_changes & col_mask) {
                    keyevent_t event;
                    event.key = (keypos_t){ .row = r, .col = c };
                    event.pressed = matrix_row & col_mask;
                    /* the time should not be 0 */
                    event.time = timer_read() | 1;
                    action_exec(event);
                    /* records the processed key */
                    matrix_previous[r] ^= col_mask;
                    /* processes one key event per call */
                    goto MATRIX_LOOP_END;
                }
            }
        }
    }
    /* sends tick events when the keyboard is idle */
    action_exec(TICK);
MATRIX_LOOP_END:
#ifdef MOUSEKEY_ENABLE
    /* repeats and accelerates the mouse keys */
    mousekey_task();
#endif
#ifdef PS2_MOUSE_ENABLE
    ps2_mouse_task();
#endif
#ifdef SERIAL_MOUSE_ENABLE
    serial_mouse_task();
#endif
#ifdef ADB_MOUSE_ENABLE
    adb_mouse_task();
#endif
    /* updates the LEDs */
    if (led_status != host_keyboard_leds()) {
        led_status = host_keyboard_leds();
        keyboard_set_leds(led_status);
    }
}

void keyboard_set_leds(uint8_t leds) {
    if (debug_keyboard) dprintf("Keyboard LEDs state: %x\n", leds);
    led_set(leds);
}
