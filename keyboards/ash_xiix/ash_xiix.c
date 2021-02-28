/* Copyright 2020 sh_xguitar
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
#include "ash_xiix.h"

bool led_update_kb(led_t led_state) {
    if (led_update_user(led_state)) {
        writePin(NUM_LOCK_LED_PIN, led_state.num_lock);
        writePin(CAPS_LOCK_LED_PIN, led_state.caps_lock);
        writePin(SCROLL_LOCK_LED_PIN, led_state.scroll_lock);
    }
    return true;
}
