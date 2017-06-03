#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define USB_MAX_POWER_CONSUMPTION 100
#define ONESHOT_TAP_TOGGLE        2
#define ONESHOT_TIMEOUT           500

#define MOUSEKEY_INTERVAL         20
#define MOUSEKEY_DELAY            0
#define MOUSEKEY_TIME_TO_MAX      40
#define MOUSEKEY_MAX_SPEED        7
#define MOUSEKEY_WHEEL_DELAY      0

#define DM_PLAY DYN_MACRO_PLAY1
#define DM_STRT DYN_REC_START1
#define DM_STOP DYN_REC_STOP

#define OSL_RSE OSL(RSE)
#define OSL_LWR OSL(LWR)
#define OSL_FUN OSL(FUN)

#define OSM_CTL OSM(MOD_LCTL)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)

#endif

