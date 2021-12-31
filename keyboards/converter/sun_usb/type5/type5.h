/*
  Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#pragma once

#include "quantum.h"

#define XXX KC_NO

/* sun type 5 keyboard, JP Unix-style
,-------.  ,---,  ,---------------. ,---------------. ,---------------.   ,-----------. ,---------------.
|   76  |  | 0F|  | 05| 06| 08| 0A| | 0C| 0E| 10| 11| | 12| 07| 09| 0B|   | 16| 17| 15| | 2D| 02| 04| 30|
`-------'  `---'  `---------------' `---------------' `---------------'   `-----------' `---------------'
,-------.  ,-----------------------------------------------------------.  ,-----------. ,---------------.
| 01| 03|  | 1D| 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29| 58| 2A|  | 2C| 34| 60| | 62| 2E| 2F| 47|
|-------|  |-----------------------------------------------------------|  |------------ |---------------|
| 19| 1A|  |  35 | 36| 37| 38| 39| 3A| 3B| 3C| 3D| 3E| 3F| 40| 41| 2B  |  | 42| 4A| 7B| | 44| 45| 46|   |
|-------|  |-----------------------------------------------------------|  `-----------' |-----------| 7D|
| 31| 33|  |  4C  | 4D| 4E| 4F| 50| 51| 52| 53| 54| 55| 56| 57|   59   |                | 5B| 5C| 5D|   |
|-------|  |-----------------------------------------------------------|      ,---.     |-----------|---|
| 48| 49|  |   63   | 64| 65| 66| 67| 68| 69| 6A| 6B| 6C| 6D|    6E    |      | 14|     | 70| 71| 72|   |
|-------|  |-----------------------------------------------------------|  .-----------. |-----------| 5A|
| 5F| 61|  | 77 | 13| 78 |*73 |       79         |*74 |*75| 7A | 43| 0D|  | 18| 1B| 1C| |   5E  | 32|   |
`-------'  `-----------------------------------------------------------'  `-----------' `---------------'
*/
#define LAYOUT_jp_unix( \
       K76,    K0F,      K05, K06, K08, K0A, K0C, K0E, K10, K11, K12, K07, K09, K0B,       K16, K17, K15,  K2D, K02, K04, K30, \
    K01, K03,  K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K58, K2A,  K2C, K34, K60,  K62, K2E, K2F, K47, \
    K19, K1A,  K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K2B,       K42, K4A, K7B,  K44, K45, K46, K7D, \
    K31, K33,  K4C, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57,      K59,                       K5B, K5C, K5D, \
    K48, K49,  K63,      K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D,      K6E,            K14,       K70, K71, K72, K5A, \
    K5F, K61,  K77, K13, K78, K73,           K79,           K74, K75, K7A, K43, K0D,       K18, K1B, K1C,     K5E,   K32 \
) { \
    { XXX, K01, K02, K03, K04, K05, K06, K07 }, \
    { K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K48, K49, K4A, XXX, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, K56, K57 }, \
    { K58, K59, K5A, K5B, K5C, K5D, K5E, K5F }, \
    { K60, K61, K62, K63, K64, K65, K66, K67 }, \
    { K68, K69, K6A, K6B, K6C, K6D, K6E, XXX }, \
    { K70, K71, K72, K73, K74, K75, K76, K77 }, \
    { K78, K79, K7A, K7B, XXX, K7D, XXX, XXX } \
}

/* Sun type 5 keyboard, US Unix-style
,-------.  ,---,  ,---------------. ,---------------. ,---------------.   ,-----------. ,---------------.
|   76  |  | 0F|  | 05| 06| 08| 0A| | 0C| 0E| 10| 11| | 12| 07| 09| 0B|   | 16| 17| 15| | 2D| 02| 04| 30|
`-------'  `---'  `---------------' `---------------' `---------------'   `-----------' `---------------'
,-------.  ,-----------------------------------------------------------.  ,-----------. ,---------------.
| 01| 03|  | 1D| 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29| 58| 2A|  | 2C| 34| 60| | 62| 2E| 2F| 47|
|-------|  |-----------------------------------------------------------|  |------------ |---------------|
| 19| 1A|  |  35 | 36| 37| 38| 39| 3A| 3B| 3C| 3D| 3E| 3F| 40| 41| 2B  |  | 42| 4A| 7B| | 44| 45| 46|   |
|-------|  |-----------------------------------------------------------|  `-----------' |-----------| 7D|
| 31| 33|  |  4C  | 4D| 4E| 4F| 50| 51| 52| 53| 54| 55| 56| 57|   59   |                | 5B| 5C| 5D|   |
|-------|  |-----------------------------------------------------------|      ,---.     |-----------|---|
| 48| 49|  |   63   | 64| 65| 66| 67| 68| 69| 6A| 6B| 6C| 6D|    6E    |      | 14|     | 70| 71| 72|   |
|-------|  |-----------------------------------------------------------|  .-----------. |-----------| 5A|
| 5F| 61|  | 77 | 13| 78 |            79                 |  7A | 43| 0D|  | 18| 1B| 1C| |   5E  | 32|   |
`-------'  `-----------------------------------------------------------'  `-----------' `---------------'
*/
#define LAYOUT_us_unix( \
       K76,    K0F,      K05, K06, K08, K0A, K0C, K0E, K10, K11, K12, K07, K09, K0B,       K16, K17, K15,  K2D, K02, K04, K30, \
    K01, K03,  K1D, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K58, K2A,  K2C, K34, K60,  K62, K2E, K2F, K47, \
    K19, K1A,  K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K2B,       K42, K4A, K7B,  K44, K45, K46, K7D, \
    K31, K33,  K4C, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57,      K59,                       K5B, K5C, K5D, \
    K48, K49,  K63,      K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D,      K6E,            K14,       K70, K71, K72, K5A, \
    K5F, K61,  K77, K13, K78,                K79,                     K7A, K43, K0D,       K18, K1B, K1C,     K5E,   K32 \
) { \
    { XXX, K01, K02, K03, K04, K05, K06, K07 }, \
    { K08, K09, K0A, K0B, K0C, K0D, K0E, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K48, K49, K4A, XXX, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, K56, K57 }, \
    { K58, K59, K5A, K5B, K5C, K5D, K5E, K5F }, \
    { K60, K61, K62, K63, K64, K65, K66, K67 }, \
    { K68, K69, K6A, K6B, K6C, K6D, K6E, XXX }, \
    { K70, K71, K72, XXX, XXX, XXX, K76, K77 }, \
    { K78, K79, K7A, K7B, XXX, K7D, XXX, XXX } \
}

/* Sun type 5 keyboard, US ANSI-style
   ,-------.  ,---,  ,---------------. ,---------------. ,---------------.   ,-----------. ,---------------.
   |   76  |  | 1D|  | 05| 06| 08| 0A| | 0C| 0E| 10| 11| | 12| 07| 09| 0B|   | 16| 17| 15| | 2D| 02| 04| 30|
   `-------'  `---'  `---------------' `---------------' `---------------'   `-----------' `---------------'
   ,-------.  ,-----------------------------------------------------------.  ,-----------. ,---------------.
   | 01| 03|  | 2A| 1E| 1F| 20| 21| 22| 23| 24| 25| 26| 27| 28| 29|   2B  |  | 2C| 34| 60| | 62| 2E| 2F| 47|
   |-------|  |-----------------------------------------------------------|  |------------ |---------------|
   | 19| 1A|  |  35 | 36| 37| 38| 39| 3A| 3B| 3C| 3D| 3E| 3F| 40| 41| 58  |  | 42| 4A| 7B| | 44| 45| 46|   |
   |-------|  |-----------------------------------------------------------|  `-----------' |-----------| 7D|
   | 31| 33|  |  77  | 4D| 4E| 4F| 50| 51| 52| 53| 54| 55| 56| 57|   59   |                | 5B| 5C| 5D|   |
   |-------|  |-----------------------------------------------------------|      ,---.     |-----------|---|
   | 48| 49|  |   63   | 64| 65| 66| 67| 68| 69| 6A| 6B| 6C| 6D|    6E    |      | 14|     | 70| 71| 72|   |
   |-------|  |-----------------------------------------------------------|  .-----------. |-----------| 5A|
   | 5F| 61|  |  4C  | 13| 78 |              79              | 7A | 43| 0D|  | 18| 1B| 1C| |   5E  | 32|   |
   `-------'  `-----------------------------------------------------------'  `-----------' `---------------'
*/
#define LAYOUT_ansi( \
       K76,    K1D,      K05, K06, K08, K0A, K0C, K0E, K10, K11, K12, K07, K09, K0B,  K16, K17, K15,  K2D, K02, K04, K30, \
    K01, K03,  K2A, K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2B,  K2C, K34, K60,  K62, K2E, K2F, K47, \
    K19, K1A,  K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, K3E, K3F, K40, K41, K58,  K42, K4A, K7B,  K44, K45, K46, K7D, \
    K31, K33,  K77, K4D, K4E, K4F, K50, K51, K52, K53, K54, K55, K56, K57,      K59,                  K5B, K5C, K5D, \
    K48, K49,  K63,      K64, K65, K66, K67, K68, K69, K6A, K6B, K6C, K6D,      K6E,       K14,       K70, K71, K72, K5A, \
    K5F, K61,  K4C, K13, K78,                K79,                     K7A, K43, K0D,  K18, K1B, K1C,     K5E,   K32 \
) { \
    { XXX, K01, K02, K03, K04, K05, K06, K07 }, \
    { K08, K09, K0A, K0B, K0C, K0D, K0E, XXX }, \
    { K10, K11, K12, K13, K14, K15, K16, K17 }, \
    { K18, K19, K1A, K1B, K1C, K1D, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27 }, \
    { K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37 }, \
    { K38, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, K42, K43, K44, K45, K46, K47 }, \
    { K48, K49, K4A, XXX, K4C, K4D, K4E, K4F }, \
    { K50, K51, K52, K53, K54, K55, K56, K57 }, \
    { K58, K59, K5A, K5B, K5C, K5D, K5E, K5F }, \
    { K60, K61, K62, K63, K64, K65, K66, K67 }, \
    { K68, K69, K6A, K6B, K6C, K6D, K6E, XXX }, \
    { K70, K71, K72, XXX, XXX, XXX, K76, K77 }, \
    { K78, K79, K7A, K7B, XXX, K7D, XXX, XXX } \
}
