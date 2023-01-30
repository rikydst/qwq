/*
Copyright 2022 Swiftrax <swiftrax@gmail.com>

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


/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

// ROWS: Top to bottom, COLS: Left to right

#define MATRIX_ROW_PINS { B2, B1, F4, F1, F0 }
#define MATRIX_COL_PINS { F5, C6, F6, F7, C7, B6, B5, B4, D7, D6, D4, D5, D3, D2, D1, D0 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

#define ENCODERS_PAD_A { B3 }
#define ENCODERS_PAD_B { B7 }
