#ifndef KB_H
#define KB_H

#include "quantum.h"

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108,       \
	K200, K201, K202, K203, K204, K205, K206, K207  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  KC_NO }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  KC_NO, KC_NO }  \
}

#endif