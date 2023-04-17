/*
Copyright 2023 Antonio Sesmero

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

  #include 2x6.h
 
enum {
    LAYER_0 = 0,
    LAYER_1 = 1,
	LAYER_2 = 2,
	// ..., the rest of your layers
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[LAYER_0] = LAYOUT_12(
		MEH(KC_A), MEH(KC_B), MEH(KC_C), MEH(KC_D), MEH(KC_E), MEH(KC_F), 
		LSG(KC_G), MEH(KC_H), MEH(KC_I), MEH(KC_J), MEH(KC_K), TO(1)), 
	
	[LAYER_1] = LAYOUT_12(
		MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5), MEH(KC_6), 
		LSG(KC_7), MEH(KC_8), MEH(KC_9), MEH(KC_0), MEH(KC_DOT), TO(2)), 
	 


	[LAYER_2] = LAYOUT_12(
		KC_F13, KC_F14, KC_F15, KC_F16, KC_F16, KC_F17, 
		KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, TO(0)), 

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    // INSERT CODE HERE: turn off all leds

    switch (layer) {
        case LAYER_0:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_1
			rgblight_setrgb(RGB_BLUE);
            break;
        case LAYER_1:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_2
			rgblight_setrgb(RGB_RED);
            break;
        case LAYER_2:
            // INSERT CODE HERE: turn on leds that correspond to YOUR_LAYER_2
			rgblight_setrgb(RGB_GREEN);
            break;
        // add case for each layer
    }
};
