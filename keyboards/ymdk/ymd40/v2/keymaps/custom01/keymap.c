/* Customización teclado YMD40 por Santiago Intxausti <intxausti@gmail.com>
 * 
 *La capa _ADJUST no la consigo hacer funcionar por lo que he tenido que crear la capa _AJUSTES en su lugar
 */

#include QMK_KEYBOARD_H


// FUNCION PARA ACTIVAR EL NUMLOCK DE LA CAPA _NUM_PAD
void led_set_user(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    tap_code(KC_NLCK);
  }
}


// FUNCIONES TAP DANCE
void dance_cln_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_N);
    } else {
        SEND_STRING(SS_DOWN(X_RALT) SS_TAP(X_N));
        clear_keyboard();
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_N);
    }
}

//NOMBRES TAP DANCE
enum {
    TD_ENE,
    TD_SIFT_CAPSLOCK

};

// Tap Dance DEFINICIONES
qk_tap_dance_action_t tap_dance_actions[] = {
    // 1 TOQUE PARA OPC 1 DOS PARA OPC 2
    [TD_ENE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset),
    [TD_SIFT_CAPSLOCK]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_SHIFT, KC_CAPS_LOCK)

};



enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _AJUSTES,
  _MOV,
  _ONE_HAND,
  _NUM_PAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_ortho_4x12(
       KC_TAB,			KC_Q,		KC_W,		KC_E,			KC_R,				KC_T,				KC_Y,				KC_U,			KC_I,		KC_O,		KC_P,		KC_BSPC,
       LT(_MOV,KC_ESC),		KC_A,		KC_S,		KC_D,			KC_F,				KC_G,				KC_H,				KC_J,			KC_K,		KC_L,		KC_SCLN,	KC_QUOT,
       TD(TD_SIFT_CAPSLOCK),	KC_Z,		KC_X,		KC_C,			KC_V,				KC_B,				TD(TD_ENE),			KC_M,			KC_COMM,	KC_DOT,		KC_SLSH,	KC_SFTENT,
       KC_LCTL,			TT(_NUM_PAD),	KC_LGUI,	KC_LALT,		LT(_LOWER, KC_BSPC),		LT(_ONE_HAND, KC_SPACE),	LT(_ONE_HAND, KC_SPACE),	LT(_RAISE,KC_ENT),	KC_RALT,	KC_RGUI,	KC_APP,		KC_LEAD
    ),

    [_RAISE] = LAYOUT_ortho_4x12(
        KC_TILD,	KC_EXLM,	KC_AT,		KC_HASH,	KC_DLR,		KC_PERC,	KC_CIRC,	KC_AMPR,	KC_ASTR,	KC_LPRN,	KC_RPRN,	KC_BSPC,
        KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		KC_PIPE,	KC_UNDS,	KC_PLUS,	KC_LCBR,	KC_RCBR,	KC_PIPE,
        KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		KC_NO,		KC_MUTE,	KC_NO,		KC_LBRC,	KC_RBRC,	KC_VOLU,
        KC_LCTL,	KC_NO,		KC_LGUI,	KC_LALT,	MO(_AJUSTES),	KC_SPC,		KC_SPC,		KC_ENT,		KC_MRWD,	KC_MPLY,	KC_MFFD,	KC_VOLD
    ),

    [_LOWER] = LAYOUT_ortho_4x12(
	KC_GRV,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,	KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_BSPC,
	KC_F13,		KC_F14,		KC_F15,		KC_F16,		KC_F17,		KC_F18,	KC_BSLS,	KC_MINS,	KC_EQL,		KC_LBRC,	KC_RBRC,	KC_BSLS,
        KC_F19,		KC_F20,		KC_F21,		KC_F22,		KC_F23,		KC_F24,	KC_NO,		KC_MUTE,	KC_NO,		KC_NO,		KC_NO,		KC_VOLU,
	KC_LCTL,	KC_NO,		KC_LGUI,	KC_LALT,	KC_BSPC,	KC_SPC,	KC_SPC,		KC_TRNS,	KC_MRWD,	KC_MPLY,	KC_MFFD,	KC_VOLD
    ),
    
    [_ADJUST] = LAYOUT_ortho_4x12(
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		DEBUG,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),
    
    [_AJUSTES] = LAYOUT_ortho_4x12(
	RESET,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		DEBUG,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		LAG_NRM,	LAG_SWP,	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,
	KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		DM_REC1,	DM_REC2,	DM_RSTP,	DM_RSTP,	DM_RSTP,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [_MOV] = LAYOUT_ortho_4x12(
	KC_TAB,		KC_NO,	KC_NO,		DM_PLY1,	DM_PLY2,			KC_NO,		KC_NO,		KC_PGUP,	KC_INS,	KC_PSCR,	KC_SLCK,	KC_PAUS,
	KC_TRNS,	KC_NO,	KC_LCTL,	KC_LALT,	KC_LSFT,			KC_HOME,	KC_LEFT,	KC_DOWN,	KC_UP,	KC_RGHT,	KC_NO,		KC_NO,
	KC_NO,		KC_NO,	KC_DEL,		KC_NO,		LCTL(KC_LEFT_GUI),	KC_END,		KC_END,		KC_PGDN,	KC_NO,	KC_NO,		KC_NO,		KC_NO,
	KC_NO,		KC_NO,	KC_NO,		KC_NO,		KC_BSPC,			KC_TRNS,	KC_TRNS,	KC_ENT,		KC_NO,	KC_NO,		C(G(KC_LEFT)),	C(G(KC_RIGHT))
    ),

    [_ONE_HAND] = LAYOUT_ortho_4x12(
	KC_BSPC,	KC_P,		KC_O,	KC_I,		KC_U,	KC_Y,		KC_T,		KC_R,	KC_E,	KC_W,	KC_Q,	KC_TAB,
	KC_QUOT,	KC_SCLN,	KC_L,	KC_K,		KC_J,	KC_H,		KC_G,		KC_F,	KC_D,	KC_S,	KC_A,	KC_ESC,
	KC_SFTENT,	KC_SLSH,	KC_DOT,	KC_COMM,	KC_M,	TD(TD_ENE),	KC_B,		KC_V,	KC_C,	KC_X,	KC_Z,	TD(TD_SIFT_CAPSLOCK),
	KC_LEAD,	KC_NO,		KC_NO,	KC_NO,		KC_NO,	KC_TRNS,	KC_TRNS,	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO
    ),  
    

    [_NUM_PAD] = LAYOUT_ortho_4x12(
        KC_TAB,   		KC_7, 		KC_8,	KC_9, 		KC_NO, 		KC_NO,		KC_PSLS, 	KC_P7,		KC_P8,	KC_P9,		KC_PPLS,	KC_PAST,
        LM(_QWERTY, MOD_LCTL),	KC_4, 		KC_5, 	KC_6, 		KC_NO,		KC_BSPC,	KC_BSPC, 	KC_P4, 		KC_P5, 	KC_P6, 		KC_PPLS,	KC_PPLS,
        LM(_QWERTY, MOD_LCTL), 	KC_1, 		KC_2, 	KC_3,   	KC_NO, 		KC_NO, 		KC_NO, 		KC_P1,		KC_P2, 	KC_P3,		KC_PENT,	KC_NO,
        LM(_QWERTY, MOD_LCTL),	KC_TRNS, 	KC_0,  	KC_LALT, 	KC_0, 		KC_ENT, 	KC_ENT, 	KC_P0,		KC_P0, 	KC_PDOT, 	KC_PENT,	KC_NO
    )

};

/*layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// FUNCION TECLA LEADER
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_THREE_KEYS(KC_C, KC_A, KC_S) {
      SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_DELETE))));
    }

  }
}


