/* Copyright 2024 Gondolindrim
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

#include "quantum.h"

void keyboard_post_init_kb() {
    led_update_kb((led_t)host_keyboard_leds());
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        led_state.scroll_lock ? rgblight_setrgb_at(RGB_WHITE, 0) : rgblight_setrgb_at(RGB_OFF, 0); 
        led_state.caps_lock   ? rgblight_setrgb_at(RGB_WHITE, 1) : rgblight_setrgb_at(RGB_OFF, 1);
        led_state.caps_lock   ? rgblight_setrgb_at(RGB_WHITE, 2) : rgblight_setrgb_at(RGB_OFF, 2); 
    }
    return res;
}
