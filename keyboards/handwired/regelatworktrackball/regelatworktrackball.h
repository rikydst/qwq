/* Copyright 2021 Rodrigo Chandia <rodrigo.chandia@gmail.com>
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 *
 * For this keyboard I am rotating it 90 degrees counter clockwise.
 */
#define LAYOUT( \
    K00, K01, K02, \
    K03, K04, K05, \
    K06, K07, K08 \
) { \
  { K06, K03, K00 }, \
  { K07, K04, K01 }, \
  { K08, K05, K02 } \
}

