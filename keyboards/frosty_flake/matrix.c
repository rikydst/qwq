/*
  Copyright 2017 Gabriel Young <gabeplaysdrums@live.com>

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

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

#ifndef DEBOUNCING_DELAY
#   define DEBOUNCING_DELAY 5
#endif
static uint8_t debouncing = DEBOUNCING_DELAY;

static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t scan_col(void);
static void select_col(uint8_t row);

void matrix_init(void) {
    /* Row output pins */
    DDRD  |=  0b01111011;
    /* Column input pins */
    DDRC  &= ~0b10000000;
    DDRB  &= ~0b01111111;
    PORTC |=  0b10000000;
    PORTB |=  0b01111111;

    for (uint8_t i=0; i < MATRIX_ROWS; i++)
        matrix[i] = matrix_debouncing[i] = 0;

    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
        select_col(col);
        _delay_us(3);
        matrix_row_t col_scan = scan_col();
        for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
            bool prev_bit = matrix_debouncing[row] & ((matrix_row_t)1<<col);
            bool curr_bit = col_scan & (1<<row);
            if (prev_bit != curr_bit) {
                matrix_debouncing[row] ^= ((matrix_row_t)1<<col);
                debouncing = DEBOUNCING_DELAY;
            }
        }
    }

    if (debouncing) {
        if (--debouncing)
            _delay_ms(1);
        else
            for (uint8_t i = 0; i < MATRIX_ROWS; i++)
                matrix[i] = matrix_debouncing[i];
    }

    matrix_scan_quantum();
    return 1;
}

inline matrix_row_t matrix_get_row(uint8_t row) {
    return matrix[row];
}

void matrix_print(void) {
  print("\nr\\c ABCDEFGHIJKLMNOPQR\n");
  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    matrix_row_t matrix_row = matrix_get_row(row);
    xprintf("%02X: ", row);
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
      bool curr_bit = matrix_row & (1<<col);
      xprintf("%c", curr_bit ? '*' : '.');
    }
    print("\n");
  }
}

uint8_t matrix_key_count(void) {
  uint8_t count = 0;
  for (uint8_t row = 0; row < MATRIX_ROWS; row++)
    count += bitpop32(matrix[row]);
  return count;
}

static matrix_row_t scan_col(void) {
    return (
        (PINC&(1<<7) ? 0 : ((matrix_row_t)1<<0)) |
        (PINB&(1<<5) ? 0 : ((matrix_row_t)1<<1)) |
        (PINB&(1<<4) ? 0 : ((matrix_row_t)1<<2)) |
        (PINB&(1<<6) ? 0 : ((matrix_row_t)1<<3)) |
        (PINB&(1<<1) ? 0 : ((matrix_row_t)1<<4)) |
        (PINB&(1<<2) ? 0 : ((matrix_row_t)1<<5)) |
        (PINB&(1<<3) ? 0 : ((matrix_row_t)1<<6)) |
        (PINB&(1<<0) ? 0 : ((matrix_row_t)1<<7))
    );
}

static void select_col(uint8_t col) {
    switch (col) {
        case  0: PORTD = (PORTD & ~0b01111011) | 0b00011011; break;
        case  1: PORTD = (PORTD & ~0b01111011) | 0b01000011; break;
        case  2: PORTD = (PORTD & ~0b01111011) | 0b01101010; break;
        case  3: PORTD = (PORTD & ~0b01111011) | 0b01111001; break;
        case  4: PORTD = (PORTD & ~0b01111011) | 0b01100010; break;
        case  5: PORTD = (PORTD & ~0b01111011) | 0b01110001; break;
        case  6: PORTD = (PORTD & ~0b01111011) | 0b01100001; break;
        case  7: PORTD = (PORTD & ~0b01111011) | 0b01110000; break;
        case  8: PORTD = (PORTD & ~0b01111011) | 0b01100000; break;
        case  9: PORTD = (PORTD & ~0b01111011) | 0b01101000; break;
        case 10: PORTD = (PORTD & ~0b01111011) | 0b00101011; break;
        case 11: PORTD = (PORTD & ~0b01111011) | 0b00110011; break;
        case 12: PORTD = (PORTD & ~0b01111011) | 0b00100011; break;
        case 13: PORTD = (PORTD & ~0b01111011) | 0b01111000; break;
        case 14: PORTD = (PORTD & ~0b01111011) | 0b00010011; break;
        case 15: PORTD = (PORTD & ~0b01111011) | 0b01101001; break;
        case 16: PORTD = (PORTD & ~0b01111011) | 0b00001011; break;
        case 17: PORTD = (PORTD & ~0b01111011) | 0b00111011; break;
    }
}