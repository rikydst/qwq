#include QMK_KEYBOARD_H
#include "mousekey.h"

#define _QWERTY 0 // Base qerty
#define _SYMB 1// Symbol layer
#define _MOUSE 2//
#define _TRANS 3//
#define _SYMB2 4// old symbol level, more ergodox like

/* Macros */
enum {
  NONE = 0,
  // Diagonal mouse movement
  A_MUL,
  A_MUR,
  A_MDL,
  A_MDR,
};


//  Train out of using uncomfortable esc  and GUI keys.
/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | no     |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 |  FN0 |  FN1 |  FN2 |      |  bOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | `~     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |MouseFN0|   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,<  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | ~`   | ESC  |GUI/L |L1/RT |                                         | L1/UP|GUI/DN| [{   | ]}   |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | CTRL | ALT  |         | ALT  | GUI |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Del  |         | PgUp |      |      |
*                                 | BkSp | BkSp |------|         |------|Return| Space|
*                                 |      |      | FN0  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
           XXXXXXX, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_GRAVE, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           TT(_MOUSE) ,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
              KC_GRAVE,  KC_ESC, KC_FN4, LT(_SYMB, KC_RIGHT),
			   		KC_LCTL,KC_LALT,
			   		KC_DEL,
              		KC_BSPC, KC_DEL ,TT(_MOUSE) ,
        KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,TT(_MOUSE) ,KC_FN1  ,TT(_SYMB), KC_NO, RESET,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		LT(_SYMB, KC_UP), KC_FN7,  KC_LBRC ,KC_RBRC,
           KC_RALT,KC_RGUI,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),


/* _SYMB level, more planck like. Much work to make sequences into multi-finger rolls. eg ([1,0]), !=0
* Also sorted by frequency / strength of finger.
*
* ,-------------------------------------------------------------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |  ^   |   {  |   }  |  @   |  %   |                           |   &  |  [   |   (  |   )  |   _  |   \    |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |  !   |   #  |   0  |   =  |  ~   |                           |   *  |   +  |   1  |  -   |   ]  |  `     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |   6  |  7   |   8  |  9   | pipe |                           |   $  |  2   |   3  |   4  |  5   |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          |      |  :   |GUI/L |L1/RT |                                         | L1/UP|GUI/DN|  \   |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | CTRL |      |         | ALT  | GUI |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 | Cut  | Paste|------|         |------|      |      |
*                                 |      |      |Reset |         |      |      |      |
*                                 `--------------------'         `--------------------'
*/



[_SYMB] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  _______,  _______,  _______,  _______,  _______,
         _______,  KC_CIRC,  KC_LCBR, KC_RCBR,  KC_AT,  KC_PERC,
         _______,  KC_EXLM,  KC_HASH,  KC_0,   KC_EQL,  KC_TILD,
         _______,   KC_6,   KC_7,   KC_8,  KC_9, KC_PIPE,
                   _______,  KC_COLON,  KC_FN4, LT(_SYMB, KC_RIGHT),
                             _______,  _______,
                                       _______,
                    _______, _______,  RESET,
         _______,  _______,  _______,  _______,  _______,  _______, _______, TT(_MOUSE), KC_2,
         _______,  _______,  _______,  _______,  _______,  _______,
         KC_AMPR,  KC_LBRC,  KC_LPRN, KC_RPRN,  KC_UNDS,  _______,
         KC_ASTR,  KC_PLUS,  KC_1,    KC_MINS,   KC_RBRC,  KC_GRV,
         KC_DLR,   KC_2,   KC_3,   KC_4,  KC_5, XXXXXXX,
                   LT(_SYMB, KC_UP), KC_FN7,   KC_BSLS,  XXXXXXX,
         _______,  _______,
         _______,
         _______,  _______,  _______
    ),


/* _SYMB2ol level, more ergodox like
*
* ,-------------------------------------------------------------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      |      |      |      |      |      |      |        |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* |        |      |   *  |   #  |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |  /   |   <  |   >  |      |      |                           |      |      |   +  |   *  |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |  {   |   }  |      |      |                           |      |      |   =  |   -  |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |   =  |  (   |   )  |      |      |                           |      |      |      |   |  |      |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          |      |      |GUI/L |L1/RT |                                         | L1/UP|GUI/DN|  {   |   }  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | CTRL |      |         | ALT  | GUI |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      |      |         |      |      |      |
*                                 | BkSp | Del  |------|         |------|Mouse1|Mouse2|
*                                 |      |      |Reset |         |      |LClick|Rclick|
*                                 `--------------------'         `--------------------'
*/



[_SYMB2] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  _______,  KC_ASTR,  KC_HASH,  _______,  _______,
         _______,  KC_SLSH,  RSFT(KC_COMM), RSFT(KC_DOT),  _______,  _______,
         _______,  _______,  RSFT(KC_LBRC),  RSFT(KC_RBRC),   _______,  _______,
         _______,  KC_EQL,  RSFT(KC_9),  RSFT(KC_0),  _______,  _______,
                   _______,  _______,  KC_FN4, LT(_SYMB, KC_RIGHT),
                             _______,  _______,
                                       _______,
                    _______, _______,  RESET,
         _______,  _______,  _______,  _______,  _______,  _______, _______, TT(_MOUSE), KC_2,
         _______,  _______,  _______,  KC_ASTR,  _______,  _______,
         _______,  _______,  KC_PLUS,  KC_MINS,  _______,  _______,
         _______,  _______,  KC_EQL,  KC_PIPE,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,
                   LT(_SYMB, KC_UP), KC_FN7,   _______,  _______,
         _______,  _______,
         _______,
         _______,  _______,  _______
    ),
/* Keymap: Movement and function layer
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Caps   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 |  FN0 |  FN1 |  FN2 |  Tada |  bOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  !   |   @  |   #  |   $  |   %  |                           |  ^   |   &  |   *  |  (   |   )  |MS Fast |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |      |      |      |      |PgUp  |                           | MwU  |MS_UL | MS_U |MS_UR |      | Ms Norm|
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |MouseFN1|GUI_V |GUI X |GUI C |GUI_V |      |                           |      | MS_L |Mouse1| MS_R |      |MS Slow |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |PgDown|                           | MWD  | MDown|MS Dwn|MS_DR  |  ?  |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | ESC  |      |      |                                         |      |      |  {  |    }  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | CTRL | GUI  |         | ALT  | GUI  |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Mouse1|Mouse2|
*                                 |      |      | End  |         | PgDn |LClick|Rclick|
*                                 `--------------------'         `--------------------'
*/


[_MOUSE] = LAYOUT(
         KC_CAPS,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  KC_EXLM  ,KC_AT,    KC_HASH,  KC_DLR   ,KC_PERC   ,
         _______,  KC_NO,    KC_NO,    KC_UP,    KC_NO,    KC_PGUP,
         KC_FN1,   LGUI(KC_Z),LGUI(KC_X),LGUI(KC_C),LGUI(KC_V), KC_NO,
         _______,  KC_NO,    KC_NO,    KC_UP,    KC_NO,    KC_PGDN,
                   _______,  _______,  KC_NO,  KC_NO,
                             _______,  _______,
                                       _______,
                    _______, _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______, _______, TT(_MOUSE),RESET,
         KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_ACL2,
         KC_WH_U,  M(A_MUL), KC_MS_U,  M(A_MUR), KC_NO,  KC_ACL1,
         KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,  KC_ACL0,
         KC_WH_D,  M(A_MDL), KC_MS_D,  M(A_MDR), RSFT(KC_LBRC), RSFT(KC_RBRC),
                   KC_LCBR,  KC_RCBR,  KC_NO,  KC_NO,
         _______,  _______,
         _______,
         _______,  KC_BTN1,  KC_BTN2
    ),



/* EMPTY
*
* ,-------------------------------------------------------------------------------------------------------------------.
* |        |      |      |      |      |      |      |      |      |      |      |      |      |      |      |  bOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* |        |      |      |      |      |      |                           |      |      |      |      |      |        |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          |      |      |      |      |                                         |      |      |    |      |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Mouse1|Mouse2|
*                                 |      |      | End  |         | PgDn |LClick|Rclick|
*                                 `--------------------'         `--------------------'
*/



[_TRANS] = LAYOUT(
         _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______,
         _______,  _______,  _______,  _______,  _______,  _______,
          _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
                   _______,  _______,  _______,  _______,
                             _______,  _______,
                                       _______,
                    _______, _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______, _______, TT(_MOUSE), KC_2,
         _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,  _______,
                   _______,  _______,  _______,  _______,
         _______,  _______,
         _______,
         _______,  _______,  _______
    ),


};



const uint16_t PROGMEM fn_actions[] = {
   [1] = ACTION_LAYER_TOGGLE(_MOUSE) ,
	[4]= ACTION_MODS_TAP_KEY(MOD_LGUI,KC_LEFT),
	[7]= ACTION_MODS_TAP_KEY(MOD_LGUI,KC_DOWN),


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;

	// from  algernon's ErgoDox EZ layout,
       case A_MUL:
        if (record->event.pressed) {
          mousekey_on(KC_MS_UP);
          mousekey_on(KC_MS_LEFT);
        } else {
          mousekey_off(KC_MS_UP);
          mousekey_off(KC_MS_LEFT);
        }
        mousekey_send();
        break;

      case A_MUR:
        if (record->event.pressed) {
          mousekey_on(KC_MS_UP);
          mousekey_on(KC_MS_RIGHT);
        } else {
          mousekey_off(KC_MS_UP);
          mousekey_off(KC_MS_RIGHT);
        }
        mousekey_send();
        break;

      case A_MDL:
        if (record->event.pressed) {
          mousekey_on(KC_MS_DOWN);
          mousekey_on(KC_MS_LEFT);
        } else {
          mousekey_off(KC_MS_DOWN);
          mousekey_off(KC_MS_LEFT);
        }
        mousekey_send();
        break;

      case A_MDR:
        if (record->event.pressed) {
          mousekey_on(KC_MS_DOWN);
          mousekey_on(KC_MS_RIGHT);
        } else {
          mousekey_off(KC_MS_DOWN);
          mousekey_off(KC_MS_RIGHT);
        }
        mousekey_send();
        break;
     }
    return MACRO_NONE;
};


void matrix_init_user(void) {


}

void matrix_scan_user(void) {

#ifdef ALVICSTEP_CONFIG_H
 int8_t layer = biton32(layer_state);

        switch (layer) {
        case 1:
                if (!(host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK))) {
                        all_led_off();
                        caps_lock_led_on();
                }
                break;

        case 2:
                if (!(host_keyboard_leds() & (1 << USB_LED_SCROLL_LOCK))) {
                        all_led_off();
                        scroll_lock_led_on();
                }
        case 0:
                all_led_off();
                num_lock_led_on();
                break;
        default:
                break;
        }
#endif

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
