/* Copyright 2016 Jack Humbert
 * Copyright 2020 JohSchneider
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

#if defined(__AVR__)
#    include <avr/pgmspace.h>
#    include <avr/interrupt.h>
#    include <avr/io.h>
#endif

#include "audio.h"

extern bool    playing_note;
extern bool    playing_melody;
extern uint8_t note_timbre;

#define CPU_PRESCALER 8

/*
  Audio Driver: PWM

  drive up to two speakers through the AVR PWM hardware-peripheral, using timer1 and/or timer3 on Atmega32U4.

  the primary channel_1 can be connected to either pin PC4 PC5 or PC6 (the later being used by most AVR based keyboards) with a PMW signal generated by timer3
  and an optional secondary channel_2 on either pin PB5, PB6 or PB7, with a PWM signal from timer1

  alternatively, the PWM pins on PORTB can be used as only/primary speaker
*/

#if defined(AUDIO_PIN) && (AUDIO_PIN != C4) && (AUDIO_PIN != C5) && (AUDIO_PIN != C6) && (AUDIO_PIN != B5) && (AUDIO_PIN != B6) && (AUDIO_PIN != B7)
#    error "Audio feature enabled, but no suitable pin selected as AUDIO_PIN - see docs/feature_audio under the AVR settings for available options."
#endif

#if (AUDIO_PIN == C4) || (AUDIO_PIN == C5) || (AUDIO_PIN == C6)
#    define AUDIO1_PIN_SET
#    define AUDIO1_TIMSKx TIMSK3
#    define AUDIO1_TCCRxA TCCR3A
#    define AUDIO1_TCCRxB TCCR3B
#    define AUDIO1_ICRx ICR3
#    define AUDIO1_WGMx0 WGM30
#    define AUDIO1_WGMx1 WGM31
#    define AUDIO1_WGMx2 WGM32
#    define AUDIO1_WGMx3 WGM33
#    define AUDIO1_CSx0 CS30
#    define AUDIO1_CSx1 CS31
#    define AUDIO1_CSx2 CS32

#    if (AUDIO_PIN == C6)
#        define AUDIO1_COMxy0 COM3A0
#        define AUDIO1_COMxy1 COM3A1
#        define AUDIO1_OCIExy OCIE3A
#        define AUDIO1_OCRxy OCR3A
#        define AUDIO1_PIN C6
#        define AUDIO1_TIMERx_COMPy_vect TIMER3_COMPA_vect
#    elif (AUDIO_PIN == C5)
#        define AUDIO1_COMxy0 COM3B0
#        define AUDIO1_COMxy1 COM3B1
#        define AUDIO1_OCIExy OCIE3B
#        define AUDIO1_OCRxy OCR3B
#        define AUDIO1_PIN C5
#        define AUDIO1_TIMERx_COMPy_vect TIMER3_COMPB_vect
#    elif (AUDIO_PIN == C4)
#        define AUDIO1_COMxy0 COM3C0
#        define AUDIO1_COMxy1 COM3C1
#        define AUDIO1_OCIExy OCIE3C
#        define AUDIO1_OCRxy OCR3C
#        define AUDIO1_PIN C4
#        define AUDIO1_TIMERx_COMPy_vect TIMER3_COMPC_vect
#    endif
#endif

#if defined(AUDIO_PIN) && defined(AUDIO_PIN_ALT) && (AUDIO_PIN == AUDIO_PIN_ALT)
#    error "Audio feature: AUDIO_PIN and AUDIO_PIN_ALT on the same pin makes no sense."
#endif

#if ((AUDIO_PIN == B5) && ((AUDIO_PIN_ALT == B6) || (AUDIO_PIN_ALT == B7))) || ((AUDIO_PIN == B6) && ((AUDIO_PIN_ALT == B5) || (AUDIO_PIN_ALT == B7))) || ((AUDIO_PIN == B7) && ((AUDIO_PIN_ALT == B5) || (AUDIO_PIN_ALT == B6)))
#    error "Audio feature: PORTB as AUDIO_PIN and AUDIO_PIN_ALT at the same time is not supported."
#endif

#if defined(AUDIO_PIN_ALT) && (AUDIO_PIN_ALT != B5) && (AUDIO_PIN_ALT != B6) && (AUDIO_PIN_ALT != B7)
#    error "Audio feature: the pin selected as AUDIO_PIN_ALT is not supported."
#endif

#if (AUDIO_PIN == B5) || (AUDIO_PIN == B6) || (AUDIO_PIN == B7) || (AUDIO_PIN_ALT == B5) || (AUDIO_PIN_ALT == B6) || (AUDIO_PIN_ALT == B7)
#    define AUDIO2_PIN_SET
#    define AUDIO2_TIMSKx TIMSK1
#    define AUDIO2_TCCRxA TCCR1A
#    define AUDIO2_TCCRxB TCCR1B
#    define AUDIO2_ICRx ICR1
#    define AUDIO2_WGMx0 WGM10
#    define AUDIO2_WGMx1 WGM11
#    define AUDIO2_WGMx2 WGM12
#    define AUDIO2_WGMx3 WGM13
#    define AUDIO2_CSx0 CS10
#    define AUDIO2_CSx1 CS11
#    define AUDIO2_CSx2 CS12

#    if (AUDIO_PIN == B5) || (AUDIO_PIN_ALT == B5)
#        define AUDIO2_COMxy0 COM1A0
#        define AUDIO2_COMxy1 COM1A1
#        define AUDIO2_OCIExy OCIE1A
#        define AUDIO2_OCRxy OCR1A
#        define AUDIO2_PIN B5
#        define AUDIO2_TIMERx_COMPy_vect TIMER1_COMPA_vect
#    elif (AUDIO_PIN == B6) || (AUDIO_PIN_ALT == B6)
#        define AUDIO2_COMxy0 COM1B0
#        define AUDIO2_COMxy1 COM1B1
#        define AUDIO2_OCIExy OCIE1B
#        define AUDIO2_OCRxy OCR1B
#        define AUDIO2_PIN B6
#        define AUDIO2_TIMERx_COMPy_vect TIMER1_COMPB_vect
#    elif (AUDIO_PIN == B7) || (AUDIO_PIN_ALT == B7)
#        define AUDIO2_COMxy0 COM1C0
#        define AUDIO2_COMxy1 COM1C1
#        define AUDIO2_OCIExy OCIE1C
#        define AUDIO2_OCRxy OCR1C
#        define AUDIO2_PIN B7
#        define AUDIO2_TIMERx_COMPy_vect TIMER1_COMPC_vect
#    endif
#endif

// C6 seems to be the assumed default by many existing keyboard - but sill warn the user
#if !defined(AUDIO1_PIN_SET) && !defined(AUDIO2_PIN_SET)
#    pragma message "Audio feature enabled, but no suitable pin selected - see docs/feature_audio under the AVR settings for available options. Don't expect to hear anything... :-)"
// TODO: make this an error - go through the breaking-change-process and change all keyboards to the new define
#endif
// -----------------------------------------------------------------------------

#ifdef AUDIO1_PIN_SET
static float channel_1_frequency = 0.0f;
void         channel_1_set_frequency(float freq) {
    if (freq == 0.0f)  // a pause/rest is a valid "note" with freq=0
    {
        // disable the output, but keep the pwm-ISR going (with the previous
        // frequency) so the audio-state keeps getting updated
        // Note: setting the duty-cycle 0 is not possible on non-inverting PWM mode - see the AVR data-sheet
        AUDIO1_TCCRxA &= ~(_BV(AUDIO1_COMxy1) | _BV(AUDIO1_COMxy0));
        return;
    } else {
        AUDIO1_TCCRxA |= _BV(AUDIO1_COMxy1);  // enable output, PWM mode
    }

    channel_1_frequency = freq;

    // set pwm period
    AUDIO1_ICRx = (uint16_t)(((float)F_CPU) / (freq * CPU_PRESCALER));
    // and duty cycle
    AUDIO1_OCRxy = (uint16_t)((((float)F_CPU) / (freq * CPU_PRESCALER)) * note_timbre / 100);
}

void channel_1_start(void) {
    // enable timer-counter ISR
    AUDIO1_TIMSKx |= _BV(AUDIO1_OCIExy);
    // enable timer-counter output
    AUDIO1_TCCRxA |= _BV(AUDIO1_COMxy1);
}

void channel_1_stop(void) {
    // disable timer-counter ISR
    AUDIO1_TIMSKx &= ~_BV(AUDIO1_OCIExy);
    // disable timer-counter output
    AUDIO1_TCCRxA &= ~(_BV(AUDIO1_COMxy1) | _BV(AUDIO1_COMxy0));
}
#endif

#ifdef AUDIO2_PIN_SET
static float channel_2_frequency = 0.0f;
void         channel_2_set_frequency(float freq) {
    if (freq == 0.0f) {
        AUDIO2_TCCRxA &= ~(_BV(AUDIO2_COMxy1) | _BV(AUDIO2_COMxy0));
        return;
    } else {
        AUDIO2_TCCRxA |= _BV(AUDIO2_COMxy1);
    }

    channel_2_frequency = freq;

    AUDIO2_ICRx  = (uint16_t)(((float)F_CPU) / (freq * CPU_PRESCALER));
    AUDIO2_OCRxy = (uint16_t)((((float)F_CPU) / (freq * CPU_PRESCALER)) * note_timbre / 100);
}

float channel_2_get_frequency(void) { return channel_2_frequency; }

void channel_2_start(void) {
    AUDIO2_TIMSKx |= _BV(AUDIO2_OCIExy);
    AUDIO2_TCCRxA |= _BV(AUDIO2_COMxy1);
}

void channel_2_stop(void) {
    AUDIO2_TIMSKx &= ~_BV(AUDIO2_OCIExy);
    AUDIO2_TCCRxA &= ~(_BV(AUDIO2_COMxy1) | _BV(AUDIO2_COMxy0));
}
#endif

void audio_driver_initialize() {
#ifdef AUDIO1_PIN_SET
    channel_1_stop();
    setPinOutput(AUDIO1_PIN);
#endif

#ifdef AUDIO2_PIN_SET
    channel_2_stop();
    setPinOutput(AUDIO2_PIN);
#endif

    // TCCR3A / TCCR3B: Timer/Counter #3 Control Registers TCCR3A/TCCR3B, TCCR1A/TCCR1B
    // Compare Output Mode (COM3An and COM1An) = 0b00 = Normal port operation
    //   OC3A -- PC6
    //   OC3B -- PC5
    //   OC3C -- PC4
    //   OC1A -- PB5
    //   OC1B -- PB6
    //   OC1C -- PB7

    // Waveform Generation Mode (WGM3n) = 0b1110 = Fast PWM Mode 14. Period = ICR3, Duty Cycle OCR3A)
    //   OCR3A - PC6
    //   OCR3B - PC5
    //   OCR3C - PC4
    //   OCR1A - PB5
    //   OCR1B - PB6
    //   OCR1C - PB7

    // Clock Select (CS3n) = 0b010 = Clock / 8
#ifdef AUDIO1_PIN_SET
    // initialize timer-counter
    AUDIO1_TCCRxA = (0 << AUDIO1_COMxy1) | (0 << AUDIO1_COMxy0) | (1 << AUDIO1_WGMx1) | (0 << AUDIO1_WGMx0);
    AUDIO1_TCCRxB = (1 << AUDIO1_WGMx3) | (1 << AUDIO1_WGMx2) | (0 << AUDIO1_CSx2) | (1 << AUDIO1_CSx1) | (0 << AUDIO1_CSx0);
#endif

#ifdef AUDIO2_PIN_SET
    AUDIO2_TCCRxA = (0 << AUDIO2_COMxy1) | (0 << AUDIO2_COMxy0) | (1 << AUDIO2_WGMx1) | (0 << AUDIO2_WGMx0);
    AUDIO2_TCCRxB = (1 << AUDIO2_WGMx3) | (1 << AUDIO2_WGMx2) | (0 << AUDIO2_CSx2) | (1 << AUDIO2_CSx1) | (0 << AUDIO2_CSx0);
#endif
}

void audio_driver_stop() {
#ifdef AUDIO1_PIN_SET
    channel_1_stop();
#endif

#ifdef AUDIO2_PIN_SET
    channel_2_stop();
#endif
}

void audio_driver_start(void) {
#ifdef AUDIO1_PIN_SET
    channel_1_start();
    if (playing_note) {
        channel_1_set_frequency(audio_get_processed_frequency(0));
    }
#endif

#if !defined(AUDIO1_PIN_SET) && defined(AUDIO2_PIN_SET)
    channel_2_start();
    if (playing_note) {
        channel_2_set_frequency(audio_get_processed_frequency(0));
    }
#endif
}

static volatile uint32_t isr_counter = 0;
#ifdef AUDIO1_PIN_SET
ISR(AUDIO1_TIMERx_COMPy_vect) {
    isr_counter++;
    if (isr_counter < channel_1_frequency / (CPU_PRESCALER * 8)) return;

    isr_counter        = 0;
    bool state_changed = audio_update_state();

    if (!playing_note && !playing_melody) {
        channel_1_stop();
#    ifdef AUDIO2_PIN_SET
        channel_2_stop();
#    endif
        return;
    }

    if (state_changed) {
        channel_1_set_frequency(audio_get_processed_frequency(0));
#    ifdef AUDIO2_PIN_SET
        if (audio_get_number_of_active_tones() > 1) {
            channel_2_set_frequency(audio_get_processed_frequency(1));
        } else {
            channel_2_stop();
        }
#    endif
    }
}
#endif

#if !defined(AUDIO1_PIN_SET) && defined(AUDIO2_PIN_SET)
ISR(AUDIO2_TIMERx_COMPy_vect) {
    isr_counter++;
    if (isr_counter < channel_2_frequency / (CPU_PRESCALER * 8)) return;

    isr_counter        = 0;
    bool state_changed = audio_update_state();

    if (!playing_note && !playing_melody) {
        channel_2_stop();
        return;
    }

    if (state_changed) {
        channel_2_set_frequency(audio_get_processed_frequency(0));
    }
}
#endif
