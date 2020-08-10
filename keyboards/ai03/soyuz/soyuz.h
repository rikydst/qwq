/* Copyright 2019 Ryota Goto
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
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
 
#define LAYOUT_ortho_5x4( \
	K00, K01, K02, K03, \
	K10, K11, K12, K13, \
	K20, K21, K22, K23, \
	K30, K31, K32, K33, \
	K40, K41, K42, K43  \
) { \
	{ K00, K01, K02, K03 }, \
	{ K10, K11, K12, K13 }, \
	{ K20, K21, K22, K23 }, \
	{ K30, K31, K32, K33 }, \
	{ K40, K41, K42, K43 }  \
}

/* LAYOUT_Numpad_5x4_mrsendyyk
 * ┌───┬───┬───┬───┐
 * │00 │01 │02 │03 │
 * ├───┤───┤───┤───┤
 * │10 │11 │12 │   │
 * ├───┤───┤───┤23 │
 * │20 │21 │22 │   │
 * ├───┤───┤───┤───┤
 * │30 │31 │32 │   │
 * ├───┴───┤───┤43 │
 * │40     │42 │   │
 * └───────┴───┴───┘
*/
#define LAYOUT_Numpad_5x4_mrsendyyk( \
	K00, K01, K02, K03, \
	K10, K11, K12,      \
	K20, K21, K22, K23, \
	K30, K31, K32,      \
	K40,      K42, K43  \
) { \
	{ K00, K01,   K02, K03   }, \
	{ K10, K11,   K12, KC_NO }, \
	{ K20, K21,   K22, K23   }, \
	{ K30, K31,   K32, KC_NO }, \
	{ K40, KC_NO, K42, K43   }  \
}
