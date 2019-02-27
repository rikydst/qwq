/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
Copyright 2017 Erin Call <hello@erincall.com>

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
#include "wait.h"
#include "action_layer.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "numnavpad.h"
#include "i2cmaster.h"
#include "timer.h"


/* Set 0 if debouncing isn't needed */

#ifndef DEBOUNCING_DELAY
#   define DEBOUNCING_DELAY 5
#endif

#if (DEBOUNCING_DELAY > 0)
    static uint16_t debouncing_time;
    static bool debouncing = false;
#endif

#ifdef MATRIX_MASKED
    extern const matrix_row_t matrix_mask[];
#endif

#if (DIODE_DIRECTION == ROW2COL) || (DIODE_DIRECTION == COL2ROW)
static const uint8_t onboard_row_pins[MATRIX_ROWS] = MATRIX_ONBOARD_ROW_PINS;
static const uint8_t onboard_col_pins[MATRIX_COLS] = MATRIX_ONBOARD_COL_PINS;
static const bool col_expanded[MATRIX_COLS] = COL_EXPANDED;
#endif

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

static matrix_row_t matrix_debouncing[MATRIX_ROWS];

#if (DIODE_DIRECTION == COL2ROW)
    static const uint8_t expander_col_pins[MATRIX_COLS] = MATRIX_EXPANDER_COL_PINS;
    static void init_cols(void);
    static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row);
    static void unselect_rows(void);
    static void select_row(uint8_t row);
    static void unselect_row(uint8_t row);
#elif (DIODE_DIRECTION == ROW2COL)
    static const uint8_t expander_row_pins[MATRIX_ROWS] = MATRIX_EXPANDER_ROW_PINS;
    static void init_rows(void);
    static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col);
    static void unselect_cols(void);
    static void select_col(uint8_t col);
    static void unselect_col(uint8_t col);
#endif

static uint8_t expander_reset_loop;
uint8_t expander_status;
uint8_t expander_input_pin_mask;
bool i2c_initialized = false;

#ifdef DEBUG_MATRIX_SCAN_RATE
uint32_t matrix_timer;
uint32_t matrix_scan_count;
#endif

#define ROW_SHIFTER ((matrix_row_t)1)
#if (DIODE_DIRECTION == COL2ROW)
// bitmask to ensure the row state from the expander only applies to its columns
#define EXPANDER_MASK ((matrix_row_t)0b00111111)
#endif

__attribute__ ((weak))
void matrix_init_user(void) {}

__attribute__ ((weak))
void matrix_scan_user(void) {}

__attribute__ ((weak))
void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__ ((weak))
void matrix_scan_kb(void) {
  matrix_scan_user();
}

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    init_expander();

#if (DIODE_DIRECTION == COL2ROW)
    unselect_rows();
    init_cols();
#elif (DIODE_DIRECTION == ROW2COL)
    unselect_cols();
    init_rows();
#endif

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }

#ifdef DEBUG_MATRIX_SCAN_RATE
    matrix_timer = timer_read32();
    matrix_scan_count = 0;
#endif

    matrix_init_quantum();
}

void init_expander(void) {
    if (! i2c_initialized) {
        i2c_init();
        wait_us(1000000);
    }

    if (! expander_input_pin_mask) {
#if (DIODE_DIRECTION == COL2ROW)
        for (int col = 0; col < MATRIX_COLS; col++) {
            if (col_expanded[col]) {
                expander_input_pin_mask |= (1 << expander_col_pins[col]);
            }
        }
#elif (DIODE_DIRECTION == ROW2COL)
        for (int row = 0; row < MATRIX_ROWS; row++) {
            expander_input_pin_mask |= (1 << expander_row_pins[row]);
        }
#endif
    }

    expander_status = i2c_start(I2C_ADDR_WRITE); if (expander_status) goto out;
    expander_status = i2c_write(IODIRA);         if (expander_status) goto out;

    /*
    Pin direction and pull-up depends on both the diode direction
    and on whether the column register is 0 ("A") or 1 ("B"):
    +-------+---------------+---------------+
    |       | ROW2COL       | COL2ROW       |
    +-------+---------------+---------------+
    | Reg 0 | input, output | output, input |
    +-------+---------------+---------------+
    | Reg 1 | output, input | input, output |
    +-------+---------------+---------------+
    */

#if (EXPANDER_COLUMN_REGISTER == 0)
#   if (DIODE_DIRECTION == COL2ROW)
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
        expander_status = i2c_write(0);                       if (expander_status) goto out;
#   elif (DIODE_DIRECTION == ROW2COL)
        expander_status = i2c_write(0);                       if (expander_status) goto out;
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
#   endif
#elif (EXPANDER_COLUMN_REGISTER == 1)
#   if (DIODE_DIRECTION == COL2ROW)
        expander_status = i2c_write(0);                       if (expander_status) goto out;
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
#   elif (DIODE_DIRECTION == ROW2COL)
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
        expander_status = i2c_write(0);                       if (expander_status) goto out;
#   endif
#endif

    i2c_stop();

    // set pull-up
    // - unused  : off : 0
    // - input   : on  : 1
    // - driving : off : 0
    expander_status = i2c_start(I2C_ADDR_WRITE);              if (expander_status) goto out;
    expander_status = i2c_write(GPPUA);                       if (expander_status) goto out;
#if (EXPANDER_COLUMN_REGISTER == 0)
#   if (DIODE_DIRECTION == COL2ROW)
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
        expander_status = i2c_write(0);                       if (expander_status) goto out;
#   elif (DIODE_DIRECTION == ROW2COL)
        expander_status = i2c_write(0);                       if (expander_status) goto out;
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
#   endif
#elif (EXPANDER_COLUMN_REGISTER == 1)
#   if (DIODE_DIRECTION == COL2ROW)
        expander_status = i2c_write(0);                       if (expander_status) goto out;
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
#   elif (DIODE_DIRECTION == ROW2COL)
        expander_status = i2c_write(expander_input_pin_mask); if (expander_status) goto out;
        expander_status = i2c_write(0);                       if (expander_status) goto out;
#   endif
#endif

out:
    i2c_stop();
}

uint8_t matrix_scan(void)
{
    if (expander_status) { // if there was an error
        if (++expander_reset_loop == 0) {
            // since expander_reset_loop is 8 bit - we'll try to reset once in 255 matrix scans
            // this will be approx bit more frequent than once per second
            print("trying to reset expander\n");
            init_expander();
            if (expander_status) {
                print("left side not responding\n");
            } else {
                print("left side attached\n");
            }
        }
    }

#ifdef DEBUG_MATRIX_SCAN_RATE
    matrix_scan_count++;

    uint32_t timer_now = timer_read32();
    if (TIMER_DIFF_32(timer_now, matrix_timer)>1000) {
        print("matrix scan frequency: ");
        pdec(matrix_scan_count);
        print("\n");

        matrix_timer = timer_now;
        matrix_scan_count = 0;
    }
#endif

#if (DIODE_DIRECTION == COL2ROW)
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
#       if (DEBOUNCING_DELAY > 0)
            bool matrix_changed = read_cols_on_row(matrix_debouncing, current_row);

            if (matrix_changed) {
                debouncing = true;
                debouncing_time = timer_read();
            }
#       else
            read_cols_on_row(matrix, current_row);
#       endif
    }

#elif (DIODE_DIRECTION == ROW2COL)
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
#       if (DEBOUNCING_DELAY > 0)
            bool matrix_changed = read_rows_on_col(matrix_debouncing, current_col);

            if (matrix_changed) {
                debouncing = true;
                debouncing_time = timer_read();
            }
#       else
            read_rows_on_col(matrix, current_col);
#       endif

    }
#endif

#   if (DEBOUNCING_DELAY > 0)
        if (debouncing && (timer_elapsed(debouncing_time) > DEBOUNCING_DELAY)) {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
            debouncing = false;
        }
#   endif

    matrix_scan_quantum();
    return 1;
}

bool matrix_is_modified(void) // deprecated and evidently not called.
{
#if (DEBOUNCING_DELAY > 0)
    if (debouncing) return false;
#endif
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & (ROW_SHIFTER << col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
#ifdef MATRIX_MASKED
    return matrix[row] & matrix_mask[row];
#else
    return matrix[row];
#endif
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

#if (DIODE_DIRECTION == COL2ROW)

static void init_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        if (! col_expanded[x]) {
            uint8_t pin = onboard_col_pins[x];
            _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
            _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
        }
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Store last value of row prior to reading
    matrix_row_t last_row_value = current_matrix[current_row];

    // Clear data in matrix row
    current_matrix[current_row] = 0;

    // Select row and wait for row selection to stabilize
    select_row(current_row);
    wait_us(30);

    // Read columns from expander, unless it's in an error state
    if (! expander_status) {
        expander_status = i2c_start(I2C_ADDR_WRITE); if (expander_status) goto out;
        expander_status = i2c_write(GPIOA);          if (expander_status) goto out;
        expander_status = i2c_start(I2C_ADDR_READ);  if (expander_status) goto out;

        current_matrix[current_row] |= (~i2c_readNak()) & EXPANDER_MASK;

        out:
            i2c_stop();
    }

    // Read columns from onboard pins
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        if (! col_expanded[col_index]) {
            uint8_t pin = onboard_col_pins[col_index];
            uint8_t pin_state = (_SFR_IO8(pin >> 4) & _BV(pin & 0xF));
            current_matrix[current_row] |= pin_state ? 0 : (ROW_SHIFTER << col_index);
        }
    }

    unselect_row(current_row);

    return (last_row_value != current_matrix[current_row]);
}

static void select_row(uint8_t row) {
    // select on expander, unless it's in an error state
    if (! expander_status) {
        // set active row low  : 0
        // set other rows hi-Z : 1
        expander_status = i2c_start(I2C_ADDR_WRITE);   if (expander_status) goto out;
        expander_status = i2c_write(GPIOB);            if (expander_status) goto out;
        expander_status = i2c_write(0xFF & ~(1<<row)); if (expander_status) goto out;
    out:
        i2c_stop();
    }

    // select on teensy
    uint8_t pin = onboard_row_pins[row];
    _SFR_IO8((pin >> 4) + 1) |=  _BV(pin & 0xF); // OUT
    _SFR_IO8((pin >> 4) + 2) &= ~_BV(pin & 0xF); // LOW
}

static void unselect_row(uint8_t row)
{
    // No need to explicitly unselect expander pins--their I/O state is
    // set simultaneously, with a single bitmask sent to i2c_write. When
    // select_row selects a single pin, it implicitly unselects all the
    // other ones.

    // unselect on teensy
    uint8_t pin = onboard_row_pins[row];
    _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // OUT
    _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // LOW
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        unselect_row(x);
    }
}

#elif (DIODE_DIRECTION == ROW2COL)

static void init_rows(void)
{
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        uint8_t pin = onboard_row_pins[x];
        _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
        _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
    }
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col)
{
    bool matrix_changed = false;

    uint8_t column_state = 0;

    //select col and wait for selection to stabilize
    select_col(current_col);
    wait_us(30);

    if (current_col < 6) {
        // read rows from expander
        if (expander_status) {
            // it's already in an error state; nothing we can do
            return false;
        }

        expander_status = i2c_start(I2C_ADDR_WRITE); if (expander_status) goto out;
        expander_status = i2c_write(GPIOB);          if (expander_status) goto out;
        expander_status = i2c_start(I2C_ADDR_READ);  if (expander_status) goto out;
        column_state = i2c_readNak();

        out:
            i2c_stop();

        column_state = ~column_state;
    } else {
        for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
            if ((_SFR_IO8(onboard_row_pins[current_row] >> 4) & _BV(onboard_row_pins[current_row] & 0xF)) == 0) {
                column_state |= (1 << current_row);
            }
        }
    }

    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[current_row];

        if (column_state & (1 << current_row)) {
            // key closed; set state bit in matrix
            current_matrix[current_row] |= (ROW_SHIFTER << current_col);
        } else {
            // key open; clear state bit in matrix
            current_matrix[current_row] &= ~(ROW_SHIFTER << current_col);
        }

        // Determine whether the matrix changed state
        if ((last_row_value != current_matrix[current_row]) && !(matrix_changed))
        {
            matrix_changed = true;
        }
    }

    unselect_col(current_col);

    return matrix_changed;
}

static void select_col(uint8_t col)
{
    if (col_expanded[col]) {
        // select on expander
        if (expander_status) { // if there was an error
            // do nothing
        } else {
            // set active col low  : 0
            // set other cols hi-Z : 1
            expander_status = i2c_start(I2C_ADDR_WRITE);   if (expander_status) goto out;
            expander_status = i2c_write(GPIOA);            if (expander_status) goto out;
            expander_status = i2c_write(0xFF & ~(1<<col)); if (expander_status) goto out;
        out:
            i2c_stop();
        }
    } else {
        // select on teensy
        uint8_t pin = onboard_col_pins[col];
        _SFR_IO8((pin >> 4) + 1) |=  _BV(pin & 0xF); // OUT
        _SFR_IO8((pin >> 4) + 2) &= ~_BV(pin & 0xF); // LOW
    }
}

static void unselect_col(uint8_t col)
{
    if (col_expanded[col]) {
        // No need to explicitly unselect expander pins--their I/O state is
        // set simultaneously, with a single bitmask sent to i2c_write. When
        // select_col selects a single pin, it implicitly unselects all the
        // other ones.
    } else {
        // unselect on teensy
        uint8_t pin = onboard_col_pins[col];
        _SFR_IO8((pin >> 4) + 1) &= ~_BV(pin & 0xF); // IN
        _SFR_IO8((pin >> 4) + 2) |=  _BV(pin & 0xF); // HI
    }
}

static void unselect_cols(void)
{
    for(uint8_t x = 0; x < MATRIX_COLS; x++) {
        unselect_col(x);
    }
}
#endif
