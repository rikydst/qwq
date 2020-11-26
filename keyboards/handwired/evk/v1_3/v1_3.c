/* Copyright 2020 Yang Cui
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
#include "v1_3.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.
// For reference, visit https://docs.qmk.fm/#/custom_quantum_functions?id=layer-change-code


void matrix_init_kb(void) {
  // keyboard start-up codes
  // runs once when the firmware starts up

    // Set pins as output for lighting the LEDs
    setPinOutput(D4); // Layer 1 Status Light
    setPinOutput(D5); // Caps Lock Status Light

    matrix_init_user();
}

//void matrix_scan_kb(void) {
//  // looping keyboard codes
//  // runs every cycle (a lot)
//
//    matrix_scan_user();
//}

//bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
//  // per-action keyboard codes
//  // runs for every key-press action, just before processing by the firmware
//
//    return process_record_user(keycode, record);
//}

// Set LED based on layer
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        writePin(D5, 1);
        break;
    default: //  for any other layers, or the default layer
        writePin(D5, 0);
        break;
    }
    return state;
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        // writePin sets the pin high for 1 and low for 0.
        writePin(D4, led_state.caps_lock);
    }
    return res;
}

