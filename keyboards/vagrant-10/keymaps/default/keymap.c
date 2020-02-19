#include QMK_KEYBOARD_H

#define HOME 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[HOME] = LAYOUT(
		KC_NO, KC_NO, KC_PENT,
		KC_P7, KC_P8, KC_P9,
		KC_P4, KC_P5, KC_P6,
		KC_P1, KC_P2, KC_P3),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
