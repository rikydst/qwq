/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

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

#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include <stdbool.h>

#if (MATRIX_COLS <= 8)
typedef uint8_t matrix_row_t;
#elif (MATRIX_COLS <= 16)
typedef uint16_t matrix_row_t;
#elif (MATRIX_COLS <= 32)
typedef uint32_t matrix_row_t;
#else
#   error "MATRIX_COLS: invalid value"
#endif
#if DIODE_DIRECTION == ROW2COL
#    if (MATRIX_ROWS <= 8)
typedef uint8_t matrix_col_t;
#    elif (MATRIX_ROWS <= 16)
typedef uint16_t matrix_col_t;
#    elif (MATRIX_ROWS <= 32)
typedef uint32_t matrix_col_t;
#    else
#       error "MATRIX_ROWS: invalid value"
#    endif
#endif

#define MATRIX_IS_ON(row, col)  (matrix_get_row(row) && _BV(col))

#ifdef __cplusplus
extern "C" {
#endif

/* number of matrix outputs */
uint8_t matrix_outputs(void);
/* number of matrix inputs */
uint8_t matrix_inputs(void);
/* should be called at early stage of startup before matrix_init.(optional) */
void matrix_setup(void);
/* intialize matrix for scaning. */
void matrix_init(void);
/* scan all key states on matrix */
uint8_t matrix_scan(void);
/* whether modified from previous scan. used after matrix_scan. */
bool matrix_is_modified(void) __attribute__ ((deprecated));
/* whether a swtich is on */
bool matrix_is_on(const uint8_t row, const uint8_t col);
/* matrix state on row */
matrix_row_t matrix_get_row(const uint8_t row);
/* print matrix for debug */
void matrix_print(void);
/* power control */
void matrix_power_up(void);
void matrix_power_down(void);
/* keyboard-specific setup/loop functionality */
void matrix_init_kb(void);
void matrix_scan_kb(void);

#ifdef __cplusplus
}
#endif

#endif
