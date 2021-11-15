#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		KC_1, KC_2, KC_3, 
		KC_4, KC_5, KC_6, 
		KC_7, KC_8, KC_9, 
		KC_0, KC_A, KC_B
	),

};



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
