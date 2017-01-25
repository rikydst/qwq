#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define NAVG 3 // navigation

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  SHRUG,
  YAY,
  HUG,
  SMILE,
  SMILE2,
  HMM1,
  HMM2,
  BEAR1,
  BEAR2,
  FUU,
  EGGY1,
  EGGY2,
  FACE1,
  FACE2,
  UHU,
  SMRK1,
  SMRK2,
  LOVE
};

// TODO: Get rid of of keys I don't want. Make others that I do. Set up lots of makros (Using hyper (and meh)) keys (where to put them?)
// TODO: Need to change hotkeys for lastpass, and potentially make my own keys for them on one of my layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc/L3 |   1  |   2  |   3  |   4  |   5  |  6   |           |   6  |   7  |   8  |   9  |   0  |   -  |   =/L3 |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab/L1 |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \/L1 |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2| ctrl/'|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Lalt | Ralt |                                       | Lalt | Ralt |   [  |   ]  | ~/L1 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | Home |       | PgUp |  Ins   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 | Space|  TAB |------|       |------|  BSPC  |Enter |
 *                                 |      |      |   [  |       |  ]   |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
		LT(NAVG,KC_ESC),         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        LT(SYMB,KC_TAB),        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(SYMB),
        KC_LCTL,        LT(MDIA, KC_A),         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_RALT,KC_LALT,
                                              ALT_T(KC_APP),  KC_HOME,
                                                              KC_END,
                                               KC_SPC,KC_TAB,KC_LBRC,
        // right hand
		KC_6,     KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,             LT(NAVG,KC_EQL),
	TG(SYMB),    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             LT(SYMB, KC_BSLS),
	KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),CTL_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
		KC_LALT,  KC_RALT,KC_LBRC,KC_RBRC,          LT(SYMB,KC_TILD),
             KC_PGUP,        KC_INS,
             KC_PGDN,
             KC_RBRC,KC_BSPC, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *                                                  
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Toggle|Animat|       | Hue+ | Hue- |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|Solid |       |      |      |      |
 *                                 |ness- |ness+ |------|       |------| DEL  |      |
 *                                 |      |      |      |       | EPRM |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_TOG,RGB_MOD,
                                               RGB_SLD,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_F6, KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_F11,  KC_F12,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_TRNS,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_HUD, RGB_HUI,
       KC_TRNS,
       EPRM, KC_DEL, KC_TRNS
),
/* Keymap 2: Media, mouse and navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA , MOUSE and NAVIGATION
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT,  KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 3: Unicode
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | VER  |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | shrug| yay  | hug  | smile|smile2|      |           |      |  ■   |  λ   |  →   |  ➙   |  ▻   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | hmm1 | hmm2 | bear1| bear2| fuu  |------|           |------|  ☺   |  ☻   |  ☹   |  ♡   |  ♥   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | eggy1| eggy2| face1| face2| uhu  |      |           |      |  ❤   |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | smrk1| smrk2| love |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Unicode
[NAVG] = KEYMAP(
       KC_TRNS, VRSN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, SHRUG, YAY, HUG, SMILE, SMILE2, KC_TRNS,
       KC_TRNS, HMM1, HMM2, BEAR1, BEAR2, FUU,
       KC_TRNS, EGGY1, EGGY2, FACE1, FACE2, UHU, KC_TRNS,
       KC_TRNS, SMRK1, SMRK2, LOVE, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  UC(0x25a0), UC(0x03bb), UC(0x2192), UC(0x2799), UC(0x25bb), KC_TRNS,
                 UC(0x263a), UC(0x263b), UC(0x2639), UC(0x2661), UC(0x2665), KC_TRNS,
       KC_TRNS,  UC(0x2764), KC_TRNS, KC_MPRV, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

static void ang_tap (uint16_t code, ...) {
  uint16_t kc = code;
  va_list ap;

  va_start(ap, code);

  do {
    register_code16(kc);
    unregister_code16(kc);
    wait_ms(50);
    kc = va_arg(ap, int);
  } while (kc != 0);
  va_end(ap);
}

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  case SHRUG:
      if (record->event.pressed) {
	  unicode_input_start(); register_hex(0xaf); unicode_input_finish();
	  TAP_ONCE (KC_BSLS);
	  register_code (KC_RSFT); TAP_ONCE (KC_MINS); TAP_ONCE (KC_9); unregister_code (KC_RSFT);
	  unicode_input_start (); register_hex(0x30c4); unicode_input_finish();
	  register_code (KC_RSFT); TAP_ONCE (KC_0); TAP_ONCE (KC_MINS); unregister_code (KC_RSFT);
	  TAP_ONCE (KC_SLSH);
	  unicode_input_start (); register_hex(0xaf); unicode_input_finish();
      }
      return false;
      break;
  case YAY:
      if (record->event.pressed) {
	ang_tap (KC_BSLS, KC_O, KC_SLSH, 0);
      }
      return false;
      break;
 case HUG:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0f3c); unicode_input_finish();
     TAP_ONCE (KC_SPC);
     unicode_input_start(); register_hex(0x3064); unicode_input_finish();
     TAP_ONCE (KC_SPC);
     unicode_input_start(); register_hex(0x25d5); unicode_input_finish();
     unicode_input_start(); register_hex(0x005f); unicode_input_finish();
     unicode_input_start(); register_hex(0x25d5); unicode_input_finish();
     TAP_ONCE (KC_SPC);
     unicode_input_start(); register_hex(0x0f3d); unicode_input_finish();
     unicode_input_start(); register_hex(0x3064); unicode_input_finish();
   }
      return false;
      break;
  case SMILE:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0298); unicode_input_finish();
     unicode_input_start(); register_hex(0x203f); unicode_input_finish();
     unicode_input_start(); register_hex(0x0298); unicode_input_finish();
   }
      return false;
      break;
  case SMILE2:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x0298); unicode_input_finish();
     unicode_input_start(); register_hex(0x203f); unicode_input_finish();
     unicode_input_start(); register_hex(0x0298); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case HMM1:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
     unicode_input_start(); register_hex(0x005f); unicode_input_finish();
     unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
   }
      return false;
      break;
  case HMM2:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
     unicode_input_start(); register_hex(0x005f); unicode_input_finish();
     unicode_input_start(); register_hex(0x0ca0); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case BEAR1:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0295); unicode_input_finish();
     unicode_input_start(); register_hex(0x2022); unicode_input_finish();
     unicode_input_start(); register_hex(0x1d25); unicode_input_finish();
     unicode_input_start(); register_hex(0x2022); unicode_input_finish();
     unicode_input_start(); register_hex(0x0294); unicode_input_finish();
   }
      return false;
      break;
  case BEAR2:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x1d54); unicode_input_finish();
     unicode_input_start(); register_hex(0x1d25); unicode_input_finish();
     unicode_input_start(); register_hex(0x1d54); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case FUU:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x256d); unicode_input_finish();
     unicode_input_start(); register_hex(0x2229); unicode_input_finish();
     unicode_input_start(); register_hex(0x256e); unicode_input_finish();
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x002d); unicode_input_finish();
     unicode_input_start(); register_hex(0x005f); unicode_input_finish();
     unicode_input_start(); register_hex(0x002d); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
     unicode_input_start(); register_hex(0x256d); unicode_input_finish();
     unicode_input_start(); register_hex(0x2229); unicode_input_finish();
     unicode_input_start(); register_hex(0x256e); unicode_input_finish();
   }
      return false;
      break;
  case EGGY1:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x256f); unicode_input_finish();
     unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
     unicode_input_start(); register_hex(0x25a1); unicode_input_finish();
     unicode_input_start(); register_hex(0x00b0); unicode_input_finish();
     unicode_input_start(); register_hex(0xff09); unicode_input_finish();
     unicode_input_start(); register_hex(0x256f); unicode_input_finish();
   }
      return false;
      break;
  case EGGY2:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x0020); unicode_input_finish();
     unicode_input_start(); register_hex(0x309c); unicode_input_finish();
     unicode_input_start(); register_hex(0x002d); unicode_input_finish();
     unicode_input_start(); register_hex(0x309c); unicode_input_finish();
     unicode_input_start(); register_hex(0x30ce); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case FACE1:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x002d); unicode_input_finish();
     unicode_input_start(); register_hex(0x005f); unicode_input_finish();
     unicode_input_start(); register_hex(0x002d); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case FACE2:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x2022); unicode_input_finish();
     unicode_input_start(); register_hex(0x005f); unicode_input_finish();
     unicode_input_start(); register_hex(0x2022); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case UHU:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x2299); unicode_input_finish();
     unicode_input_start(); register_hex(0xfe4f); unicode_input_finish();
     unicode_input_start(); register_hex(0x2299); unicode_input_finish();
   }
      return false;
      break;
  case SMRK1:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x005e); unicode_input_finish();
     unicode_input_start(); register_hex(0x032e); unicode_input_finish();
     unicode_input_start(); register_hex(0x005e); unicode_input_finish();
   }
      return false;
      break;
  case SMRK2:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x0028); unicode_input_finish();
     unicode_input_start(); register_hex(0x005e); unicode_input_finish();
     unicode_input_start(); register_hex(0x032e); unicode_input_finish();
     unicode_input_start(); register_hex(0x005e); unicode_input_finish();
     unicode_input_start(); register_hex(0x0029); unicode_input_finish();
   }
      return false;
      break;
  case LOVE:
   if (record->event.pressed) {
     unicode_input_start(); register_hex(0x2665); unicode_input_finish();
     unicode_input_start(); register_hex(0x203f); unicode_input_finish();
     unicode_input_start(); register_hex(0x2665); unicode_input_finish();
   }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0xff,0x00,0x00);
      #endif
      break;
    case 2:
      ergodox_right_led_2_on();
      #ifdef RGBLIGHT_ENABLE
      rgblight_setrgb(0x00,0xff,0x00);
      #endif
      break;
    case 3:
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_ENABLE
       rgblight_setrgb(0x00,0x00,0xff);
      #endif
      break;
    case 4:
      ergodox_right_led_1_on(); // TODO: Make a fourth layer
      ergodox_right_led_3_on();
      break;
    default:
      // none
      break;
    }

};
