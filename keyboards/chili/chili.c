/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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
#include "chili.h"

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up
    led_init_ports();
    matrix_init_user();
}

void led_init_ports(void) {
    setPinOutput(B1);
    writePinHigh(B1);
    setPinOutput(B2);
    writePinHigh(B2);
    setPinOutput(B3);
    writePinHigh(B3);
}

void led_set_kb(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        writePinLow(B1);
    } else {
        writePinHigh(B1);
    }
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        writePinLow(B2);
    } else {
        writePinHigh(B2);
    }
	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
        writePinLow(B3);
    } else {
        writePinHigh(B3);
    }
    led_set_user(usb_led);
}
