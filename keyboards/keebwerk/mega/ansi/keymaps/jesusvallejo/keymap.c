/* Copyright 2020 Yiancar
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
#include "drivers/issi/is31fl3733.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_65_ansi( /* Base */
    KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
    KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
    KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

[1] = LAYOUT_65_ansi( /* FN */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_VOLU, KC_VOLD, KC_MUTE,                KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[2] = LAYOUT_65_ansi( /* Empty for dynamic keymaps */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[3] = LAYOUT_65_ansi( /* Empty for dynamic keymaps */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};


static uint16_t ledTimer; // timer for led animations

uint8_t R = 0; // led values
uint8_t G = 0;
uint8_t B = 0;

// boot animation parameters

uint8_t bootFirst=3; // number of increment slides
uint8_t bootSec=3; // number of full blink

//breathing animation parameters

const uint16_t travelTime = 1000;// time the leds take to go from off to on or on to off
const uint16_t fadeStep = 5;// steps for the fade in and out, 0-255 by steps of 10
const uint16_t fadeTime = 20;// time between each fade step
const uint8_t maxBrightness=255; // keep them multipliers of fade Step between 0 and 255
const uint8_t minBrightness=0;

uint16_t previousTime = 0;
uint16_t time = 0;

bool bootAnimation(void){
    if (bootFirst>0 || bootSec>0){    
     if(bootFirst!=0){
        if (timer_elapsed(ledTimer) > 150) 
        {
            G = 255;
            R = 0;
            B = 0;
            IS31FL3733_set_color( 6+64-1, R, G, B );
        }
         if (timer_elapsed(ledTimer) > 300) 
        {
            G = 255;
            R = 255;
            B = 0;
            IS31FL3733_set_color( 6+64-1, R, G, B );
        }
       if (timer_elapsed(ledTimer) > 400) 
        {
            G = 255;
            R = 255;
            B = 255;
            IS31FL3733_set_color( 6+64-1, R, G, B );
        }
        if (timer_elapsed(ledTimer) > 500)
        {
            G = 0;
            R = 0;
            B = 0;
            IS31FL3733_set_color( 6+64-1, R, G, B );
            ledTimer = timer_read();
            bootFirst--;
        }
     }

     if (bootFirst==0 && bootSec!=0){

         if (timer_elapsed(ledTimer) > 200) 
        {
            G = 255;
            R = 255;
            B = 255;
            IS31FL3733_set_color( 6+64-1, R, G, B );
        }
        if (timer_elapsed(ledTimer) > 400)
        {
            G = 0;
            R = 0;
            B = 0;
            IS31FL3733_set_color( 6+64-1, R, G, B );
            ledTimer = timer_read();
            bootSec--;
        }
     }
     return false;
    }
    return true;
}


void breathing(void) {
    if(timer_elapsed(ledTimer)<travelTime){
        time = timer_elapsed(ledTimer);
        if((time - previousTime) > fadeTime && R<maxBrightness){
            G+=fadeStep;
            R+=fadeStep;
            B+=fadeStep;
            IS31FL3733_set_color( 6+64-1, R, G, B );
            previousTime = time;
        }
    }
    else if(timer_elapsed(ledTimer)<(travelTime *  2)){
        time = timer_elapsed(ledTimer);
        if((time - previousTime) > fadeTime && R>minBrightness){
            G-=fadeStep;
            R-=fadeStep;
            B-=fadeStep;
            IS31FL3733_set_color( 6+64-1, R, G, B );
            previousTime = time;
        } 
    }
    else {
        R=0;
        G=0;
        B=0;
        IS31FL3733_set_color( 6+64-1, R, G, B );
        previousTime = 0;
        time = 0;
        ledTimer=timer_read();
    }
}

bool capsState; // this avoids turning off the leds each matrix_scan_user() call
bool prevCapsState;// this avoids turning off the leds each matrix_scan_user() call

void matrix_scan_user(void){
    if(bootAnimation()){
    capsState = host_keyboard_led_state().caps_lock; // this avoids turning off the leds each matrix_scan_user() call
    if (capsState) {
        breathing();
        prevCapsState = capsState; // this avoids turning off the leds each matrix_scan_user() call
    } 
    else if(!capsState && capsState != prevCapsState){ // this avoids turning off the leds each matrix_scan_user() call
        G = 0;
        R = 0;
        B = 0;
        IS31FL3733_set_color( 6+64-1, R, G, B );
        prevCapsState = capsState; // this avoids turning off the leds each matrix_scan_user() call
    }
    }
}

// void keyboard_post_init_user(void) {
//     debug_enable=true;
//  }