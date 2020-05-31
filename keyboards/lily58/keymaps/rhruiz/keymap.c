#include QMK_KEYBOARD_H
#include "rhruiz.h"
#include "layouts/kc_keys.h"

#define KC__GFN1 MO(_GAMEFN1)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT_kc_wrapper(
// .-----+-----------------------------.                .-----------------------------+-----.
     TILD,   ________L_BL_R1________   ,                    ________R_BL_R1________   , ESC ,
// |-----+-----------------------------|                |-----------------------------------|
     TAB ,   ________L_BL_R2________   ,                    ________R_BL_R2________   , BSPC,
// |-----+-----------------------------|                |-----------------------------------|
     CESC,   ________L_BL_R3________   ,                    ________R_BL_R3________   , QUOT,
// |-----------------------------------|-----|    |-----|-----------------------------------|
     LSFT,   ________L_BL_R4________   , _TAP,      _BCK,   ________R_BL_R4________   , RSFT,
// `-----+----------------------------/-----/      \-----\----------------------------+-----'
                    LALT, LGUI, _FN1 , _CSP,          ENTS, _FN2 , ALBS, RGUI
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_KEY_OVERRIDE] = LAYOUT_kc( \
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     , DEL ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     , DQUO,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,_TAN,       _FWD,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_FN1] = LAYOUT_kc_wrapper(
// .-----+-----------------------------.                .-----------------------------+-----.
     F11 ,   ________L_LWR_1________   ,                    ________R_LWR_1________   , F12 ,
// |-----+-----------------------------|                |-----------------------------+-----|
     TILD,   ________L_LWR_2________   ,                    ________R_LWR_2________   ,     ,
// |-----+-----------------------------|                |-----------------------------+-----|
         ,   ________L_LWR_3________   ,                    ________R_LWR_3________   ,     ,
// |-----+-----------------------------|-----|    |-----|-----------------------------+-----|
         ,   ________L_LWR_4________   ,     ,          ,   ________R_LWR_4________   ,     ,
// `-----+----------------------------/-----/      \-----\----------------------------+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

 [_FN2] = LAYOUT_kc_wrapper(
// .-----+-----------------------------.                .-----------------------------+-----.
     ESC ,   ________L_RSE_1________   ,                    ________R_RSE_1________   ,     ,
// |-----+-----------------------------|                |-----------------------------+-----|
     GRV ,   ________L_RSE_2________   ,                    ________R_RSE_2________   ,     ,
// |-----+-----------------------------|                |-----------------------------+-----|
         ,   ________L_RSE_3________   ,                    ________R_RSE_3________   ,     ,
// |-----+-----------------------------|-----|    |-----|-----------------------------+-----|
         ,   ________L_RSE_4________   ,     ,          ,   ________R_RSE_4________   ,     ,
// `-----+----------------------------/-----/      \-----\----------------------------+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
 ),

  [_CFG] = LAYOUT_kc_wrapper(
// .-----+-----------------------------.                .-----------------------------+-----.
     ESC ,   ________L_CFG_1________   ,                    ________R_CFG_1________   , _RST,
// |-----+-----------------------------|                |-----------------------------+-----|
         ,   ________L_CFG_2________   ,                    ________R_CFG_2________   , MAKE,
// |-----+-----------------------------|                |-----------------------------+-----|
         ,   ________L_CFG_3________   ,                    ________R_CFG_3________   ,     ,
// |-----+-----------------------------|-----|    |-----|-----------------------------+-----|
         ,   ________L_CFG_4________   , _TGM,      _TGN,   ________R_CFG_4________   ,     ,
// `-----+----------------------------/-----/      \-----\----------------------------+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_NUM] = LAYOUT_kc_wrapper(
// .-----+-----------------------------.                .-----------------------------+-----.
         ,   _____NUMBERS_LEFT_____    ,                    _____NUMBERS_RGHT_____    ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     , BTN1, MS_U, BTN2, WH_D,                      ,  4  ,  5  ,  6  , PLUS,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     , MS_L, MS_D, MS_R, WH_U,                  ASTR,  1  ,  2  ,  3  , MINS,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,      _TGN, EQL ,  0  ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_GAME] = LAYOUT_kc(
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     , BSPC,          ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     , _GFN1,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

  [_GAMEFN1] = LAYOUT_kc_wrapper(
// .-----+-----------------------------.                .-----+-----+-----+-----+-----+-----.
         ,   _____NUMBERS_RGHT_____    ,                      ,     ,     ,     ,     ,     ,
// |-----+-----------------------------|                |-----+-----+-----+-----+-----+-----|
         ,   ____FUNCTIONS_LEFT____    ,                      ,     ,  UP ,     ,     ,     ,
// |-----+-----------------------------|                |-----+-----+-----+-----+-----+-----|
         ,   ____FUNCTIONS_RGHT____    ,                      , LEFT, DOWN,RIGHT, COLN,     ,
// |-----+-----------------------------|-----|    |-----|-----------------------------+-----|
         ,     ,     ,     ,     ,     ,     ,          ,     ,     ,  LT ,  GT , QUES,     ,
// `-----+----------------------------/-----/      \-----\----------------------------+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
  ),

/* template
// .-----+-----+-----+-----+-----+-----.                .-----+-----+-----+-----+-----+-----.
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|                |-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,                      ,     ,     ,     ,     ,     ,
// |-----+-----+-----+-----+-----+-----|-----|    |-----|-----+-----+-----+-----+-----+-----|
         ,     ,     ,     ,     ,     ,     ,          ,     ,     ,     ,     ,     ,     ,
// `-----+-----+-----+-----+-----+----/-----/      \-----\----+-----+-----+-----+-----+-----'
                        ,     ,      ,     ,              ,      ,     ,
//                `-----+-----+----'/-----/          \-----\'----+-----+-----'
*/
};
// clang-format on
