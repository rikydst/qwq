#ifndef ABNT2_83_H
#define ABNT2_83_H

#include "quantum.h"
extern bool iota_gfx_init(void);
extern void iota_gfx_task(void);
extern bool iota_gfx_off(void);
extern bool iota_gfx_on(void);
extern void iota_gfx_flush(void);
extern void iota_gfx_write_char(uint8_t c);
extern void iota_gfx_write(const char *data);
extern void iota_gfx_write_P(const char *data);
extern void iota_gfx_clear_screen(void);

#define LAYOUT( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012, K013, K014, K015, K016, K017, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, K117, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212,       K214, K215, K216, K217, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, K314, K315, K316, K317, \
	K400, K401, K402,                   K406,             K409, K410, K411, K412, K413, K414, K415, K416  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015,  K016,  K017 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116,  K117 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  KC_NO, K214,  K215,  K216,  K217 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  K312,  K313,  K314,  K315,  K316,  K317 }, \
	{ K400,  K401,  K402,  KC_NO, KC_NO, KC_NO, K406,  KC_NO, KC_NO, K409,  K410,  K411,  K412,  K413,  K414,  K415,  K416,  KC_NO }  \
}

#endif