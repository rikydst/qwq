#include "../../config.h"

// Sets good default for the speed of the mouse.
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_MAX_SPEED

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          100
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7

#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY

#define MOUSEKEY_WHEEL_MAX_SPEED    5
#define MOUSEKEY_WHEEL_TIME_TO_MAX  60
#define MOUSEKEY_WHEEL_DELAY        100

#undef TAPPING_TOGGLE

#define TAPPING_TOGGLE  1
