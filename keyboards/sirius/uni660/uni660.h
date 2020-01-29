#pragma once
#define UNI660_H

#include "quantum.h"

#define red_led_off   PORTF |= (1<<5)
#define red_led_on    PORTF &= ~(1<<5)
#define blu_led_off   PORTF |= (1<<4)
#define blu_led_on    PORTF &= ~(1<<4)
#define grn_led_off   PORTD |= (1<<1)
#define grn_led_on    PORTD &= ~(1<<1)

#define set_led_off     red_led_off; grn_led_off; blu_led_off
#define set_led_red     red_led_on;  grn_led_off; blu_led_off
#define set_led_blue    red_led_off; grn_led_off; blu_led_on
#define set_led_green   red_led_off; grn_led_on;  blu_led_off
#define set_led_yellow  red_led_on;  grn_led_on;  blu_led_off
#define set_led_magenta red_led_on;  grn_led_off; blu_led_on
#define set_led_cyan    red_led_off; grn_led_on;  blu_led_on
#define set_led_white   red_led_on;  grn_led_on;  blu_led_on

/*
#define LED_B 5
#define LED_R 6
#define LED_G 7

#define all_leds_off PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)

#define red_led_on   PORTF |= (1<<LED_R)
#define red_led_off  PORTF &= ~(1<<LED_R)
#define grn_led_on   PORTF |= (1<<LED_G)
#define grn_led_off  PORTF &= ~(1<<LED_G)
#define blu_led_on   PORTF |= (1<<LED_B)
#define blu_led_off  PORTF &= ~(1<<LED_B)

#define set_led_off     PORTF &= ~(1<<LED_B) & ~(1<<LED_R) & ~(1<<LED_G)
#define set_led_red     PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_G) | (1<<LED_R)
#define set_led_blue    PORTF = PORTF & ~(1<<LED_G) & ~(1<<LED_R) | (1<<LED_B)
#define set_led_green   PORTF = PORTF & ~(1<<LED_B) & ~(1<<LED_R) | (1<<LED_G)
#define set_led_yellow  PORTF = PORTF & ~(1<<LED_B) | (1<<LED_R) | (1<<LED_G)
#define set_led_magenta PORTF = PORTF & ~(1<<LED_G) | (1<<LED_R) | (1<<LED_B)
#define set_led_cyan    PORTF = PORTF & ~(1<<LED_R) | (1<<LED_B) | (1<<LED_G)
#define set_led_white   PORTF |= (1<<LED_B) | (1<<LED_R) | (1<<LED_G)
*/

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT( \
  k00,    k01, k02, k03, k04, k05, k06, k46,         k08, k09, k0a, k0b, k0c, k0d, k0e, k0f,    k3f,\
  k10,    k11,  k12, k13, k14, k15, k16,           k18, k19, k1a, k1b, k1c, k1d, k1e,   k1f,    k2f,\
  k20,    k21,   k22, k23, k24, k25, k26,           k28, k29, k2a, k2b, k2c, k2d,       k2e,\
  k30,    k31,    k32, k33, k34, k35, k36,            k38, k39, k3a, k3b, k3c,       k3d,  k3e, \
  k40,    k41,   k42,  k43,    k44,  k45,            k48,       k49,   k4a,  k4c,     k4d, k4e, k4f   \
) \
  {                                                           \
    { k00, k01, k02, k03, k04, k05, k06,  KC_NO, k08, k09, k0a, k0b, k0c, k0d, k0e, k0f   }, \
    { k10, k11, k12, k13, k14, k15, k16,  KC_NO, k18, k19, k1a, k1b, k1c, k1d, k1e, k1f   }, \
    { k20, k21, k22, k23, k24, k25, k26,  KC_NO, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f   }, \
    { k30, k31, k32, k33, k34, k35, k36,  KC_NO, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f   }, \
    { k40, k41, k42, k43, k44, k45, k46,  KC_NO, k48, k49, k4a, KC_NO, k4c, k4d, k4e, k4f    }  \
  }
#endif
