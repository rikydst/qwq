#include QMK_KEYBOARD_H

enum marianas_layers {
  QWERTY,
  COLEMAK,
  DVORAK,
  NAV_CLUSTER,
  //RGB,
  MOUSE,
  GAMING,
  SQLMACROS,
  SQLNAMES,
  FN_LAYER,
  LAYER_SEL
};

enum sql_macros {
  S_LFTJN = SAFE_RANGE, // L
  S_INRJN, // I
  S_SLCT,  // S
  S_FROM,  // F
  S_DSNCT, // D
  S_ORDER, // O
  S_WHERE, // W
  S_ALTER, // Esc


  N_DRDN,
  N_PRDCT,
  N_SPPLR,
  N_CNTCT,
  N_WRKFL,
  N_DIST,
  N_DSTRB,
  N_STEP,
  N_NSTNC,
  N_TASK,
  N_CNTR,
  N_PRCNG
};

uint32_t mainMode;

uint32_t layer_state_set_user(uint32_t state)
{
  switch (biton32(state))
  {
    case QWERTY:
      rgblight_mode(34);
      break;
    case COLEMAK:
      rgblight_mode(28);
      break;
    case DVORAK:
      rgblight_mode(29);
      break;
    case NAV_CLUSTER:
      rgblight_mode(32);
      break;
    /*
    case RGB:
      eeconfig_update_rgblight_default();
      break;
      */
    case MOUSE:
      rgblight_mode(30);
      break;
    case GAMING:
      rgblight_mode(31);
      break;
    case SQLMACROS:
      rgblight_setrgb(0x00, 0xFF, 0x80);
      rgblight_mode(5);
      break;
    case SQLNAMES:
      rgblight_setrgb(0x80, 0xFF, 0x00);
      rgblight_mode(5);
      break;
    case FN_LAYER:
      rgblight_setrgb(0x00, 0x80, 0xFF);
      rgblight_mode(2+3);
      break;
    case LAYER_SEL:
      rgblight_setrgb(0xFF, 0x00, 0xFF);
      rgblight_mode(2+3);
      break;
  }
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  if (record->event.pressed)
  {
    switch (keycode)
    {
      case S_LFTJN: SEND_STRING("LEFT JOIN"); return false;
      case S_INRJN: SEND_STRING("INNER JOIN "); return false;
      case S_SLCT:  SEND_STRING("SELECT "); return false;
      case S_FROM:  SEND_STRING("FROM "); return false;
      case S_DSNCT: SEND_STRING("DISTINCT "); return false;
      case S_ORDER: SEND_STRING("ORDER "); return false;
      case S_WHERE: SEND_STRING("WHERE "); return false;
      case S_ALTER: SEND_STRING("ALTER SESSION SET CURRENT_SCHEMA = "); return false;


      case N_DRDN:  SEND_STRING("Darden"); return false;
      case N_PRDCT: SEND_STRING("Product"); return false;
      case N_SPPLR: SEND_STRING("Supplier"); return false;
      case N_CNTCT: SEND_STRING("Contact"); return false;
      case N_WRKFL: SEND_STRING("Workflow"); return false;
      case N_DIST:  SEND_STRING("Dist"); return false;
      case N_DSTRB: SEND_STRING("Distributor"); return false;
      case N_STEP:  SEND_STRING("Step"); return false;
      case N_NSTNC: SEND_STRING("Instance"); return false;
      case N_TASK:  SEND_STRING("Task"); return false;
      case N_CNTR:  SEND_STRING("Center"); return false;
      case N_PRCNG:  SEND_STRING("Pricing"); return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY]=
    LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, LT(SQLNAMES,KC_BSLS),
      MO(FN_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, LT(SQLMACROS,KC_ENT),
      KC_LSPO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_NO,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_LGUI, KC_NO, KC_APP, KC_RCTL),

  [COLEMAK]=
    LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
      MO(FN_LAYER), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT,
      KC_LSPO, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_NO,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_LGUI, KC_NO, KC_APP, KC_RCTL),

  [DVORAK]=
    LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRC, KC_RBRC, KC_NO, KC_BSPC,
      KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH, KC_EQL, KC_BSLS,
      MO(FN_LAYER), KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS, KC_ENT,
      KC_LSPO, KC_NO, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSPC, KC_NO,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_LGUI, KC_NO, KC_APP, KC_RCTL),

  [NAV_CLUSTER]=
    LAYOUT(
      KC_TRNS, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, KC_INSERT, KC_HOME, KC_PGUP, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_END, KC_PGDOWN, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_UP, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_KP_0, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_TRNS, KC_TRNS, KC_TRNS),
/*
  [RGB]=
    LAYOUT(
      KC_TRNS, RGB_TOG, RGB_MOD, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_SPD, RGB_SPI, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
*/
  [MOUSE]=
    LAYOUT(
      KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN3, KC_BTN1, KC_MS_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [GAMING]=
    LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      KC_TRNS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSHIFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT, KC_NO,
      KC_LCTL, KC_NO, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RCTL, KC_NO, KC_NO, TO(QWERTY)),

  [SQLMACROS]=
    LAYOUT(
      S_ALTER, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, S_WHERE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S_INRJN, S_ORDER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_LBRC, S_SLCT,  S_DSNCT, S_FROM,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S_LFTJN, KC_TRNS, KC_RBRC, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [SQLNAMES]=
    LAYOUT(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, N_DRDN,  N_PRDCT, N_SPPLR, N_CNTCT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, N_WRKFL, N_DIST,  N_DSTRB, N_STEP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, N_NSTNC, N_TASK,  N_CNTR,  N_PRCNG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [FN_LAYER]=
    LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_DEL,
      KC_CAPSLOCK, KC_MPRV, KC_MPLY, KC_MNXT, LWIN(KC_R), KC_TRNS, KC_CALC, KC_PGUP, KC_UP, KC_PGDN, KC_PSCR, KC_SLCK, KC_BRK, KC_TRNS,
      KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS, KC_DEL, MO(LAYER_SEL),
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HYPR, KC_TRNS, KC_MEH, KC_TRNS),

  [LAYER_SEL]=
    LAYOUT(
      TO(QWERTY), TO(NAV_CLUSTER), KC_TRNS, TO(MOUSE), TO(GAMING), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, TO(QWERTY), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, TO(DVORAK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(COLEMAK), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, RESET, RESET, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};
/*
dfu-programmer atmega32u4 erase
dfu-programmer atmega32u4 flash dz60_marianas.hex
dfu-programmer atmega32u4 reset


*/
