// dustypomerleau, Minidox config

#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "config_common.h"

#define CONVERT_TO_PROTON_C
#define EE_HANDS
#define IGNORE_MOD_TAP_INTERRUPT
#define ONESHOT_TIMEOUT 1000
#define PERMISSIVE_HOLD
#define PREVENT_STUCK_MODIFIERS
#define TAPPING_FORCE_HOLD // allows rapid mod use after tap event, but sacrifices double-tap to repeat
#define TAPPING_TERM 150
#define USE_SERIAL

// optional configuration:

// #define MOUSEKEY_DELAY 0 //  delay before cursor movement (high feels sluggish, low makes fine movement difficult)
// #define MOUSEKEY_INTERVAL 20 // time between movement reports - low settings feel like high mouse speed
// #define MOUSEKEY_MAX_SPEED 10
// #define MOUSEKEY_TIME_TO_MAX 60
// #define MOUSEKEY_WHEEL_DELAY 0
// #define MOUSEKEY_WHEEL_MAX_SPEED 8
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 4

// #define ONESHOT_TAP_TOGGLE 2 // not compatible with TAPPING_FORCE_HOLD

#endif
