#include QMK_KEYBOARD_H
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base COLEMAK layer
 * ,---------------------------------------------------------------.
 * |GEsc| Q  | W  | F  | P  | G  | J  | L  | U  | Y  | :  |  Bspc  |
 * |---------------------------------------------------------------|
 * |Tab-Ctl| A  | R  | S  | T  | D  | H  | N  | E  | I  | O  |Quote|
 * |---------------------------------------------------------------|
 * |Shft/Cap| Z  | X  | C  | V  | B  | K  | M  | ,  | Up |    .    |
 * |---------------------------------------------------------------|
 *      |Ctrl|Gui |Alt | Spc/Lwr |   Spc/Rse   |Left|Down|Rght|
 *      `-----------------------------------------------------'
 */

	[_BASE] = LAYOUT_wrapper(
    __________________DIMPLE1__________________,
    __________________DIMPLE2__________________,
		__________________DIMPLE3L_________________,__________________DIMPLE3R_________________,
		__________________DIMPLE4__________________
	),

/* Lower Symbol Layer
 * ,---------------------------------------------------------------.
 * | ~  | !  | @  | #  | $  | %  | ^  | &  | *  | (  | )  |   Del  |
 * |---------------------------------------------------------------|
 * | Del  |    |    |    |    |    |    | _  | +  | {  | }  |  |   |
 * |---------------------------------------------------------------|
 * |        |    |    |    |    |    |    |    | ;  |PgUp|   ?     |
 * |---------------------------------------------------------------|
 *      |   |    |    |         |              |Home|PgDn|End |
 *      `-----------------------------------------------------'
 */

	[_LOWER] = LAYOUT_wrapper(
		_________________LOWER_1___________________,
    _________________LOWER_2___________________,
		_________________LOWER_3___________________,
		_________________LOWER_4___________________
	),

/* Raise Number Layer
 * ,---------------------------------------------------------------.
 * | `  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 0  |   Bspc |
 * |---------------------------------------------------------------|
 * | Ins  |    |    |    |    |    |    | -  | =  | [  | ]  |  \   |
 * |---------------------------------------------------------------|
 * |        |    |    |    |    |    |    |    |    |  . |   /     |
 * |---------------------------------------------------------------|
 *      |VolD|Mute|VolU|         |             |    |    |    |
 *      `-----------------------------------------------------'
 */

	[_RAISE] = LAYOUT_wrapper(
	___________________RAISE1__________________,
	___________________RAISE2__________________,
	___________________RAISE3__________________,
	___________________RAISE4__________________

	),

/*  Adjust Layer
 * ,---------------------------------------------------------------.
 * |RST |EEP |    |    |    |    |    |    |    |    |    |        |
 * |---------------------------------------------------------------|
 * | MP   |    |    |    |    |    |    |    |    |    |    |      |
 * |---------------------------------------------------------------|
 * | MODE   | HUI| HUD|M_SN|    |    |    |    |    |    |         |
 * |---------------------------------------------------------------|
 *      |RGB-|RGB |RGB+|         |             |    |    |    |
 *      `-----------------------------------------------------'
 */

	[_ADJUST] = LAYOUT_wrapper(
	___________________ADJST1__________________,
	___________________ADJST2__________________,
	___________________ADJST3__________________,
 	___________________ADJST4__________________

  ),
/* Fkey Layer
* ,---------------------------------------------------------------.
* |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10|        |
* |---------------------------------------------------------------|
* |      |    |    |    |    |    |    |    |    | F11| F12|      |
* |---------------------------------------------------------------|
* |        |    |    |    |    |    |    |    |    |    |         |
* |---------------------------------------------------------------|
*      |    |    |    |         |             |FKEY|    |    |
*      `-----------------------------------------------------'
*/

  [_FKEY] = LAYOUT_wrapper(
	___________________FKEY1___________________,
	___________________FKEY2___________________,
	___________________FKEY3___________________,
	___________________FKEY4___________________
  ),
};

bool led_set_user(led_t led_state) {
if (led_state.caps_lock) {
	writePinLow(E6);
	} else {
	writePinHigh(E6);
	}
  return false;
}
