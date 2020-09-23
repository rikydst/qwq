/*
Copyright 2018 Jeff Shufelt <jshuf@puppyfish.com> @jshuf

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"
#include "led.h"

inline void kbd19x_caps_led_on(void)    { DDRB |=  (1<<0); PORTB &= ~(1<<0); }
inline void kbd19x_caps_led_off(void)   { DDRB &= ~(1<<0); PORTB &= ~(1<<0); }

inline void kbd19x_sclk_led_on(void)    { DDRB |=  (1<<1); PORTB &= ~(1<<1); }
inline void kbd19x_sclk_led_off(void)   { DDRB &= ~(1<<1); PORTB &= ~(1<<1); }

inline void kbd19x_nmlk_led_on(void)    { DDRB |=  (1<<2); PORTB &= ~(1<<2); }
inline void kbd19x_nmlk_led_off(void)   { DDRB &= ~(1<<2); PORTB &= ~(1<<2); }

// readability
#define XXX KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

// 2u backspace: XXX, k71
// split backspace: k1d, k71

// 2u numpad +: k2c, XXX
// split numpad +: k2c, k3c

// 2u numpad enter: k4c, XXX
// split numpad enter: k4c, k5c

// 2.25u lshift: k40, XXX
// split (1.25u, 1u) lshift: k40, k41

// ANSI enter or ISO enter: k3e
// backslash or NUHS: k73

// left winkey: k50, k51, k52
// left WKL: k50, XXX, k52

// right winkey: k59, k5a, k57
// right WKL: k59, XXX, k57

#define LAYOUT_all( \
  k00,  k01, k02, k03, k04,  k60, k61, k62, k63,  k09, k06, k07, k08,   k72,  k0f, k0a, k0b, k0c, \
  k10, k11, k12, k13, k14, k64, k65, k66, k67, k19, k1a, k17, k18, k1d, k71,  k1f, k1g, k1b, k1c, \
  k20,  k21, k22, k23, k24, k68, k69, k6a, k6b, k29, k2a, k27, k28,     k73,  k2f, k2g, k2b, k2c, \
  k30,    k32, k33, k34, k35, k6c, k75, k76, k77, k3a, k36, k37,        k3e,  k3f, k3g, k3b, k3c, \
  k40,  k41, k42, k43, k44, k78, k79, k7a, k7b, k49, k4a, k47, k48,    k74,   k4f, k4g, k4b, k4c, \
  k50,  k51, k52,                k56,            k59, k5a, k57,   k5d, k53, k5f,   k5g, k5b, k5c  \
)\
{\
  {k00, k01, k02, k03, k04, k09, k06, k07, k08, k0f, k0a, k0b, k0c},\
  {k10, k11, k12, k13, k14, k19, k1a, k17, k18, k1f, k1g, k1b, k1c},\
  {k20, k21, k22, k23, k24, k29, k2a, k27, k28, k2f, k2g, k2b, k2c},\
  {k30, k32, k33, k34, k35, k3a, k36, k37, k3e, k3f, k3g, k3b, k3c},\
  {k40, k41, k42, k43, k44, k49, k4a, k47, k48, k4f, k4g, k4b, k4c},\
  {k50, k51, k52, k53, k5f, k59, k5a, k57, k5d, k56, k5g, k5b, k5c},\
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c},\
  {k1d, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, XXX},\
}

#define LAYOUT_ansi( \
  k00,  k01, k02, k03, k04,  k60, k61, k62, k63,  k09, k06, k07, k08, k72,     k0f, k0a, k0b, k0c, \
  k10, k11, k12, k13, k14, k64, k65, k66, k67, k19, k1a, k17, k18,    k71,     k1f, k1g, k1b, k1c, \
  k20,  k21, k22, k23, k24, k68, k69, k6a, k6b, k29, k2a, k27, k28,   k73,     k2f, k2g, k2b, k2c, \
  k30,    k32, k33, k34, k35, k6c, k75, k76, k77, k3a, k36, k37,      k3e,     k3f, k3g, k3b,      \
  k40,      k42, k43, k44, k78, k79, k7a, k7b, k49, k4a, k47,    k48,   k74,   k4f, k4g, k4b, k4c, \
  k50, k51, k52,                k56,            k59, k5a, k57,     k5d, k53, k5f,   k5g, k5b       \
)\
{\
  {k00, k01, k02, k03, k04, k09, k06, k07, k08, k0f, k0a, k0b, k0c},\
  {k10, k11, k12, k13, k14, k19, k1a, k17, k18, k1f, k1g, k1b, k1c},\
  {k20, k21, k22, k23, k24, k29, k2a, k27, k28, k2f, k2g, k2b, k2c},\
  {k30, k32, k33, k34, k35, k3a, k36, k37, k3e, k3f, k3g, k3b, XXX},\
  {k40, XXX, k42, k43, k44, k49, k4a, k47, k48, k4f, k4g, k4b, k4c},\
  {k50, k51, k52, k53, k5f, k59, k5a, k57, k5d, k56, k5g, k5b, XXX},\
  {k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k6a, k6b, k6c},\
  {XXX, k71, k72, k73, k74, k75, k76, k77, k78, k79, k7a, k7b, XXX},\
}
