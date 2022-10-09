#include QMK_KEYBOARD_H
#include "spacebarracecar.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

enum layers {
  _BASE,
  _RAISE,
  _LOWER,
  _GAME = _NAV+1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Backspace|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |\        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |7        |8        |9        |Tab      |Q        |W        |E        |R        |T        |Z        |U        |I        |O        |P        |Backspace|
|+        |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |4        |5        |6        |Esc/Nav  |A        |S        |D        |F        |G        |H        |J        |K        |L        |;        |'        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |1        |2        |3        |(/LShift |Y        |X        |C        |V        |B        |N        |M        |,        |.        |/        |)/RShift |
|Enter    |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |.        |0        |00       |RCtrl    |         |Alt      |Win      |Lower    |Space    |Enter    |Raise    |Win      |AltGr    |         |LCtrl    |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_BASE] = LAYOUT(
  KC_PMNS,  KC_PAST,  KC_PSLS,  KC_BSPC,  CU_GRV,   DE_1,     DE_2,     CU_3,     DE_4,     DE_5,     CU_6,     CU_7,     CU_8,     CU_9,     CU_0,     CU_BSLS,
  KC_PPLS,  KC_P7,    KC_P8,    KC_P9,    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     CU_Z,     DE_U,     DE_I,     DE_O,     DE_P,     KC_BSPC,
  KC_PPLS,  KC_P4,    KC_P5,    KC_P6,    CU_NAV,   DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     CU_SCLN,  CU_QUOT,
  KC_PENT,  KC_P1,    KC_P2,    KC_P3,    CU_LSFT,  CU_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     CU_COMM,  CU_DOT,   CU_SLSH,  CU_RSFT,
  KC_PENT,  KC_PDOT,  KC_P0,    KC_P00,   KC_LCTL,  XXXXXXX,  KC_LGUI,  KC_LALT,  LOWER,    KC_SPC,   CTLENT,   RAISE,    KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL
),

/* Lower
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Backspace|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |7        |8        |9        |~        |!        |"        |#        |$        |%        |^        |&        |*        |(        |)        |         |
|+        |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |4        |5        |6        |         |@        |Strg+X   |Strg+C   |Strg+V   |         |         |_        |+        |{        |}        ||        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |1        |2        |3        |         |?        |         |         |         |         |         |         |         |         |         |         |
|Enter    |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |.        |0        |00       |         |         |         |         |         |         |         |         |         |         |         |         |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_LOWER] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  DE_TILD,  DE_EXLM,  DE_DQUO,  DE_HASH,  DE_DLR,   DE_PERC,  CU_CIRC,  DE_AMPR,  DE_ASTR,  DE_LPRN,  DE_RPRN,  _______,
  _______,  _______,  _______,  _______,  _______,  DE_AT,    CTRLX,    CTRLC,    CTRLV,    XXXXXXX,  XXXXXXX,  DE_UNDS,  DE_PLUS,  DE_LCBR,  DE_RCBR,  DE_PIPE,
  _______,  _______,  _______,  _______,  _______,  DE_EURO,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DE_MINS,  CU_EQL,   CU_LBRC,  CU_RBRC,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Raise
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Backspace|`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |7        |8        |9        |`        |1        |2        |3        |4        |5        |6        |7        |8        |9        |0        |         |
|+        |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |4        |5        |6        |         |F1       |F2       |F3       |F4       |F5       |F6       |-        |=        |[        |]        |\        |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |1        |2        |3        |         |F7       |F8       |F9       |F10      |F11      |F12      |         |         |         |         |         |
|Enter    |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |.        |0        |00       |         |         |         |         |         |         |         |         |         |         |         |         |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_RAISE] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  CU_GRV,   DE_1,     DE_2,     CU_3,     DE_4,     DE_5,     CU_6,     CU_7,     CU_8,     CU_9,     CU_0,     _______,
  _______,  _______,  _______,  _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    DE_MINS,  CU_EQL,   CU_LBRC,  CU_RBRC,  CU_BSLS,
  _______,  _______,  _______,  _______,  _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXXXXXX,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

/* Deadkey
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Backspace|         |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |7        |8        |9        |         |         |         |         |         |         |         |Ü        |         |Ö        |         |         |
|+        |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |4        |5        |6        |         |Ä        |ß        |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |1        |2        |3        |         |         |         |         |         |         |         |         |         |         |         |         |
|Enter    |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |.        |0        |00       |         |         |         |         |         |"        |"        |         |         |         |         |         |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_DEADKEY] = LAYOUT(
  _______,  _______,  _______,  _______,  CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,
  _______,  _______,  _______,  _______,  KC_TAB,   CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_UE,    CU_ED,    CU_OE,    CU_ED,    _______,
  _______,  _______,  _______,  _______,  _______,  CU_AE,    CU_SS,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_DDQ,
  _______,  _______,  _______,  _______,  _______,  CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    CU_ED,    _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  CU_DDQ,   CU_DDQ,   _______,  _______,  _______,  _______,  _______
),

/* Navigation
,---------------------------------------------------------------------------------------------------------------------------------------------------------------.
|-        |*        |/        |Numlock  |Escape   |         |         |         |         |         |         |         |         |         |         |         |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |7        |8        |9        |ALT F4   |PageDown |Up       |PageUp   |Home     |         |         |         |Win+Up   |         |         |Del      |
|=        |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |4        |5        |6        |         |Left     |Down     |Right    |End      |         |         |Win+Left |Win+Down |Win+Right|         |Enter    |
|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |1        |2        |3        |         |Prev     |Pause    |Next     |LowerVol |RaiseVol |Mute     |         |         |         |         |         |
|Enter    |---------+---------+---------|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
|         |.        |0        |00       |QK_BOOT    |ESCT     |         |         |         |         |         |         |         |         |         |Game     |
`---------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/

[_NAV] = LAYOUT(
  _______,  _______,  _______,  KC_NLCK,  KC_ESC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
  CU_EQL,   _______,  _______,  _______,  _______,  KC_PGDN,  KC_UP,    KC_PGUP,  KC_HOME,  XXXXXXX,  XXXXXXX,  XXXXXXX,  GUIU,     XXXXXXX,  XXXXXXX,  KC_DEL,
  CU_EQL,   _______,  _______,  _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   XXXXXXX,  XXXXXXX,  GUIL,     GUID,     GUIR,     EMOJI,    KC_ENT,
  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_VOLD,  KC_VOLU,  KC_MUTE,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
  _______,  _______,  _______,  _______,  QK_BOOT,  ALTF4,    _______,  _______,  _______,  KC_SPC,   CTLENT,   _______,  _______,  _______,  _______,  CU_GAME
),

// Can be used to place macros on the numpad
[_GAME] = LAYOUT(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)

};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
  case MO(_LOWER):
    if (game){
      if(record->event.pressed) {
        register_code(KC_SPC);
      } else {
        unregister_code(KC_SPC);
      }
      return false;
    } else {
      return true;
    }
  case KC_LALT:
    if (game) {
      if (record->event.pressed){
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
    } else {
      return true;
    }
  case CU_GAME:
    if(record->event.pressed) {
      if (game)
        layer_on(_GAME);
      else
        layer_off(_GAME);
    }
    return false;
  default:
    return true;
  }
}
