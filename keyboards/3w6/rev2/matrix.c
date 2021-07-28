/*
Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
          2020 Pierre Chevalier <pierrechevalier83@gmail.com>
          2021 weteor

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

/*
 * This code was heavily inspired by the ergodox_ez keymap, and modernized
 * to take advantage of the quantum.h microcontroller agnostics gpio control
 * abstractions and use the macros defined in config.h for the wiring as opposed
 * to repeating that information all over the place.
 */

#include QMK_KEYBOARD_H
#include "i2c_master.h"

extern i2c_status_t tca9555_status;
#define I2C_TIMEOUT 1000

// For a better understanding of the i2c protocol, this is a good read:
// https://www.robot-electronics.co.uk/i2c-tutorial

// I2C address:
// See the datasheet, section 3.3.1 on addressing I2C devices and figure 3-6 for an
// illustration
// http://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf
// All address pins of the tca9555 are connected to the ground on the ferris
// | 0  | 1  | 0  | 0  | A2 | A1 | A0 |
// | 0  | 1  | 0  | 0  | 0  | 0  | 0  |
#define I2C_ADDR 0b0100000
#define I2C_ADDR_WRITE ((I2C_ADDR << 1) | I2C_WRITE)
#define I2C_ADDR_READ ((I2C_ADDR << 1) | I2C_READ)

// Register addresses
// See https://github.com/adafruit/Adafruit-tca9555-Arduino-Library/blob/master/Adafruit_tca9555.h
#define IODIRA 0x06  // i/o direction register
#define IODIRB 0x07
#define IREGP0 0x00  // GPIO pull-up resistor register
#define IREGP1 0x01
#define OREGP0 0x02  // general purpose i/o port register (write modifies OLAT)
#define OREGP1 0x03

bool         i2c_initialized = 0;
i2c_status_t tca9555_status = I2C_ADDR;

uint8_t init_tca9555(void) {
    print("starting init");
    tca9555_status = I2C_ADDR;

    // I2C subsystem
    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        wait_ms(I2C_TIMEOUT);
    }

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    tca9555_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);
    if (tca9555_status) goto out;
    tca9555_status = i2c_write(IODIRA, I2C_TIMEOUT);
    if (tca9555_status) goto out;
    // This means: write on pin 5 of port 0, read on rest
    tca9555_status = i2c_write(0b11111111, I2C_TIMEOUT);
    if (tca9555_status) goto out;
    // This means: we will write on pins 0 to 2 on port 1. read rest
    tca9555_status = i2c_write(0b11110000, I2C_TIMEOUT);
    if (tca9555_status) goto out;

out:
    i2c_stop();
    return tca9555_status;
}

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];      // debounced values

static matrix_row_t read_cols(uint8_t row);
static void         init_cols(void);
static void         unselect_rows(void);
static void         select_row(uint8_t row);

static uint8_t tca9555_reset_loop;

void matrix_init_custom(void) {
    // initialize row and col

    tca9555_status = init_tca9555();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i]     = 0;
    }
}

void matrix_power_up(void) {
    tca9555_status = init_tca9555();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

// Reads and stores a row, returning
// whether a change occurred.
static inline bool store_matrix_row(matrix_row_t current_matrix[], uint8_t index) {
    matrix_row_t temp = read_cols(index);
    if (current_matrix[index] != temp) {
        current_matrix[index] = temp;
        return true;
    }
    return false;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    if (tca9555_status) {  // if there was an error
        if (++tca9555_reset_loop == 0) {
            // if (++tca9555_reset_loop >= 1300) {
            // since tca9555_reset_loop is 8 bit - we'll try to reset once in 255 matrix scans
            // this will be approx bit more frequent than once per second
            dprint("trying to reset tca9555\n");
            tca9555_status = init_tca9555();
            if (tca9555_status) {
                dprint("right side not responding\n");
            } else {
                dprint("right side attached\n");
            }
        }
    }

    bool changed = false;
    for (uint8_t i = 0; i < MATRIX_ROWS_PER_SIDE; i++) {
        // select rows from left and right hands
        uint8_t left_index  = i;
        uint8_t right_index = i + MATRIX_ROWS_PER_SIDE;
        select_row(left_index);
        select_row(right_index);

        // we don't need a 30us delay anymore, because selecting a
        // left-hand row requires more than 30us for i2c.

        changed |= store_matrix_row(current_matrix, left_index);
        changed |= store_matrix_row(current_matrix, right_index);

        unselect_rows();
    }

    return changed;
}

static void init_cols(void) {
    // init on tca9555
    // not needed, already done as part of init_tca9555()

    // init on mcu
    pin_t matrix_col_pins_mcu[MATRIX_COLS_PER_SIDE] = MATRIX_COL_PINS_L;
    for (int pin_index = 0; pin_index < MATRIX_COLS_PER_SIDE; pin_index++) {
        pin_t pin = matrix_col_pins_mcu[pin_index];
        setPinInput(pin);
        writePinHigh(pin);
    }
}

static matrix_row_t read_cols(uint8_t row) {
    if (row < MATRIX_ROWS_PER_SIDE) {
        pin_t        matrix_col_pins_mcu[MATRIX_COLS_PER_SIDE] = MATRIX_COL_PINS_L;
        matrix_row_t current_row_value                         = 0;
        // For each col...
        for (uint8_t col_index = 0; col_index < MATRIX_COLS_PER_SIDE; col_index++) {
            // Select the col pin to read (active low)
            uint8_t pin_state = readPin(matrix_col_pins_mcu[col_index]);

            // Populate the matrix row with the state of the col pin
            current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
        }
        return current_row_value;
    } else {
        if (tca9555_status) {  // if there was an error
            return 0;
        } else {
            uint8_t data    = 0;
            uint8_t port0   = 0;
            tca9555_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);
            if (tca9555_status) goto out;
            tca9555_status = i2c_write(IREGP0, I2C_TIMEOUT);
            if (tca9555_status) goto out;
            tca9555_status = i2c_start(I2C_ADDR_READ, I2C_TIMEOUT);
            if (tca9555_status) goto out;
            tca9555_status = i2c_read_nack(I2C_TIMEOUT);
            if (tca9555_status < 0) goto out;
            
            port0 = ~(uint8_t)tca9555_status;

            // We read all the pins on GPIOA.
            // The initial state was all ones and any depressed key at a given column for the currently selected row will have its bit flipped to zero.
            // The return value is a row as represented in the generic matrix code were the rightmost bits represent the lower columns and zeroes represent non-depressed keys while ones represent depressed keys.
            // Since the pins connected to eact columns are sequential, and counting from zero up (col 5 -> GPIOA0, col 6 -> GPIOA1 and so on), the only transformation needed is a bitwise not to swap all zeroes and ones.
            data |= ( port0 & 0x01 ) << 4; 
            data |= ( port0 & 0x02 ) << 2; 
            data |= ( port0 & 0x04 ); 
            data |= ( port0 & 0x08 ) >> 2; 
            data |= ( port0 & 0x10 ) >> 4; 
            /* data            = ~((uint8_t)tca9555_status); */
            tca9555_status = I2C_STATUS_SUCCESS;
        out:
            i2c_stop();
            // return reverse_bits(data, MATRIX_COLS_PER_SIDE);
            return data;
        }
    }
}

static void unselect_rows(void) {
    // no need to unselect on tca9555, because the select step sets all
    // the other row bits high, and it's not changing to a different
    // direction

    // unselect rows on microcontroller
    pin_t matrix_row_pins_mcu[MATRIX_ROWS_PER_SIDE] = MATRIX_ROW_PINS_L;
    for (int pin_index = 0; pin_index < MATRIX_ROWS_PER_SIDE; pin_index++) {
        pin_t pin = matrix_row_pins_mcu[pin_index];
        setPinInput(pin);
        writePinLow(pin);
    }
}

static void select_row(uint8_t row) {
    uint8_t port1 = 0xff;

    if (row < MATRIX_ROWS_PER_SIDE) {
        // select on atmega32u4
        pin_t matrix_row_pins_mcu[MATRIX_ROWS_PER_SIDE] = MATRIX_ROW_PINS_L;
        pin_t pin                                       = matrix_row_pins_mcu[row];
        setPinOutput(pin);
        writePinLow(pin);
    } else {
        // select on tca9555
        if (tca9555_status) {  // if there was an error
                                // do nothing
        } else {
            switch(row) {
                case 4: port1 &= ~(1 << 0); break;
                case 5: port1 &= ~(1 << 1); break;
                case 6: port1 &= ~(1 << 2); break;
                case 7: port1 &= ~(1 << 3); break;
                default:                    break;
            }

            tca9555_status = i2c_start(I2C_ADDR_WRITE, I2C_TIMEOUT);
            if (tca9555_status) goto out;
            tca9555_status = i2c_write(OREGP1, I2C_TIMEOUT);
            if (tca9555_status) goto out;
            tca9555_status = i2c_write(port1, I2C_TIMEOUT);
            if (tca9555_status) goto out;
            // Select the desired row by writing a byte for the entire GPIOB bus where only the bit representing the row we want to select is a zero (write instruction) and every other bit is a one.
            // Note that the row - MATRIX_ROWS_PER_SIDE reflects the fact that being on the right hand, the columns are numbered from MATRIX_ROWS_PER_SIDE to MATRIX_ROWS, but the pins we want to write to are indexed from zero up on the GPIOB bus.
            /* tca9555_status = i2c_write(0xFF & ~(1 << (row - MATRIX_ROWS_PER_SIDE)), I2C_TIMEOUT); */

            if (tca9555_status) goto out;
        out:
            i2c_stop();
        }
    }
}
