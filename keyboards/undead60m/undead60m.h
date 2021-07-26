#pragma once

#include "quantum.h"

#define LAYOUT( \
  K00, K01,   K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, \
  K10, K11,   K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, \
  K20, K21,   K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E,      \
  K30, K31,   K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,           \
  K40, K41,   K42, K43, K44,                K48,                K4C, K4D, K4E, K4F  \
) \
{ \
  { K00, K01,   K02, K03, K04, K05,   K06,   K07,   K08, K09,   K0A,   K0B,   K0C, K0D, K0E,   K0F  },  \
  { K10, K11,   K12, K13, K14, K15,   K16,   K17,   K18, K19,   K1A,   K1B,   K1C, K1D, K1E,   K1F  },  \
  { K20, K21,   K22, K23, K24, K25,   K26,   K27,   K28, K29,   K2A,   K2B,   K2C, K2D, K2E,   KC_NO }, \
  { K30, K31,   K32, K33, K34, K35,   K36,   K37,   K38, K39,   K3A,   K3B,   K3C, K3D, KC_NO, KC_NO }, \
  { K40, K41,   K42, K43, K44, KC_NO, KC_NO, KC_NO, K48, KC_NO, KC_NO, KC_NO, K4C, K4D, K4E,   K4F }    \
}
