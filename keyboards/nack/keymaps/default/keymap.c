/* Copyright 2020 pastapojken <pastapojken@gmail.com>
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
#include QMK_KEYBOARD_H
#include "nack.h"

#define ____ KC_TRNS

extern keymap_config_t keymap_config;

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    BASE,
    NUM,
    FN
};

enum keymap_keycodes {
    KK_RESET = NEW_SAFE_RANGE    
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
/*   __________________________________________________________________________________________________________________________________________________________________________
    | \            \            \            \            \            \            \            \            \            \            \            \            \            \        */                                                                                                                                                                 
//  | |----TAB-----|---Q--------|-----W------|-----E------|-----R------|----T-------|-----Y------|-----U------|----I-------|------O-----|----P-------|----Å-------|--( ¨^~ )---|  
       KC_TAB,      KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,\
//  | |----ESC-----|---A--------|---S--------|----D-------|-----F------|-----G------|-----H------|-----J------|-----K------|-----L------|-----Ö------|-----Ä------|--( '* )----|  
       KC_ESC,      KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,     KC_NUHS,\
//  | |---SHIFT----|---Z--------|---X--------|----C-------|-----V------|-----B------|-----N------|------M-----|---( ,; )---|---( .: )---|---( -_ )---|----UP------|-BACKSPACE--|  
       CK_LSFT,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,     CK_UP_PGUP,  CK_BSPC_DEL,\
//  | |---CTRL-----|---ALT------|---META-----|----FN_1----|----------SPACE----------|----FN_2----|----AltGr---|--( <>| )---|---ENETER---|-LEFT-------|---DOWN-----|--RIGHT-----|  
       KC_LCTL,     KC_LALT,     KC_LGUI,     TT(NUM),     KC_SPC,      KC_NO,       TT(FN),      CK_RALT,     KC_NUBS,     KC_ENT,     CK_LEFT_HOME,CK_DOWN_PGDOWN,CK_RIGHT_END
//   \|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|         
    ),
    [NUM] = LAYOUT(
/*   __________________________________________________________________________________________________________________________________________________________________________
    | \            \            \            \            \            \            \            \            \            \            \            \            \            \        */                                                                                                                                                                         
//  | |---TAB------|---( 1! )---|--( 2"@ )---|--( 3#£ )---|---( 4¤$ )--|--( 5%€ )---|---( 6& )---|--( 7/{ )---|--( 8([ )---|--( 9)] )---|--( 0=} )---|---( +?\ )--|---( ´` )---|
       ____,        KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,\
//  | |----ESC-----|-----F1-----|-----F2-----|----F3------|----F4------|----F5------|-----F6-----|-----F7------|----F8-----|-----F9-----|-----F10----|----F11-----|----F12-----|  
       ____,        KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,\
//  | |---SHIFT----|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|  
       ____,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,\
//  | |---CTRL-----|---ALT------|---META-----|---FN_1-----|------------|------------|----FN_2----|--AltGr-----|---( §½ )---|------------|------------|------------|------------|  
       ____,        ____,        ____,        TT(FN),       KC_NO,      KC_NO,       TO(BASE),    ____,        KC_GRV,      KC_NO,       KC_NO,       KC_NO,       KC_NO
//   \|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|         
    ),
    [FN] = LAYOUT(
/*   __________________________________________________________________________________________________________________________________________________________________________
    | \            \            \            \            \            \            \            \            \            \            \            \            \            \        */                                                                                                                                                           
//  | |-RGB TOGGLE-|-CHANGE RGB-|-RGB HUE UP-|-RGB SAT UP-|------------|------------|------------|------------|------------|------------|------------|------------|-RESET KBD--|  
       RGB_TOG,     RGB_MOD,     RGB_HUI,     RGB_SAI,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KK_RESET,\
//  | |------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|  
       MU_TOG,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,\
//  | |------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|------------|-RGB LIGHT +|------------|  
       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       RGB_VAI,     KC_NO,\
//  | |------------|------------|------------|---FN_1-----|------------|------------|----FN_2----|------------|------------|------------|------------|-RGB LIGHT -|------------|  
       KC_NO,       KC_NO,       KC_NO,       TT(NUM),     KC_NO,       KC_NO,       TO(BASE),    KC_NO,       KC_NO,       KC_NO,       KC_NO,       RGB_VAD,     KC_NO
//   \|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|____________|         
    )
};

void rgb_matrix_update_pwm_buffers(void);

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
        static uint32_t key_timer;
        switch (keycode) {
            case KK_RESET: // Basically, turn off RGB before resetting
                if (record->event.pressed) {
                    key_timer = timer_read32();
                    #ifdef RGBLIGHT_ENABLE
                    rgb_matrix_disable_noeeprom();
                    #endif
                } else {
                    if (timer_elapsed32(key_timer) >= 20) {
                        reset_keyboard();
                    }
                }
                break;
        }
        return true;
};
