/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_PERIPHERALNAMES_H
#define MBED_PERIPHERALNAMES_H

#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    UART_0 = (int)LPC_USART_BASE
} UARTName;

typedef enum {
    I2C_0 = (int)LPC_I2C_BASE
} I2CName;

typedef enum {
    ADC0_0 = 0,
    ADC0_1,
    ADC0_2,
    ADC0_3,
    ADC0_4,
    ADC0_5,
    ADC0_6,
    ADC0_7
} ADCName;

typedef enum {
    SPI_0 = (int)LPC_SSP0_BASE,
    SPI_1 = (int)LPC_SSP1_BASE
} SPIName;

typedef enum {
    PWM_1 = 0,
    PWM_2,
    PWM_3,
    PWM_4,
    PWM_5,
    PWM_6,
    PWM_7,
    PWM_8,
    PWM_9,
    PWM_10,
    PWM_11
} PWMName;

#define STDIO_UART_TX     USBTX
#define STDIO_UART_RX     USBRX
#define STDIO_UART        UART_0

// Default peripherals
#define MBED_SPI0         p5, p6, p7, p8
#define MBED_SPI1         p11, p12, p13, p14

#define MBED_UART0        p9, p10
#define MBED_UARTUSB      USBTX, USBRX

#define MBED_I2C0         p28, p27

#define MBED_ANALOGIN0    p15
#define MBED_ANALOGIN1    p16
#define MBED_ANALOGIN2    p17
#define MBED_ANALOGIN3    p18
#define MBED_ANALOGIN4    p19
#define MBED_ANALOGIN5    p20

#ifdef __cplusplus
}
#endif

#endif
