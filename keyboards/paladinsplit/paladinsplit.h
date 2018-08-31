#ifndef PALADINSPLIT_H
#define PALADINSPLIT_H

#include "quantum.h"

#define LAYOUT_all( \
    KL00, KL01, KL02, KL03, KL04, KL05, KL06,   KR07, KR06, KR05, KR04, KR03, KR02, KR01, KR00, \
    KL10, KL11, KL12, KL13, KL14, KL15,          KR27, KR16, KR15, KR14, KR13, KR12, KR11, KR10, \
    KL20, KL21, KL22, KL23, KL24, KL25,         KR26, KR25, KR24, KR23, KR22, KR21, KR20, \
    KL30, KL31, KL32, KL33, KL34, KL35,          KR37, KR36, KR35, KR34, KR33, KR32, KR31, KR30, \
    KL40, KL41, KL42, KL43,                     KR45,                     KR44, KR43, KR42, KR41, KR40  \
) { \
    { KL00, KL01, KL02, KL03, KL04, KL05, KL06, KC_NO }, \
    { KL10, KL11, KL12, KL13, KL14, KL15, KC_NO, KC_NO }, \
    { KL20, KL21, KL22, KL23, KL24, KL25, KC_NO, KC_NO }, \
    { KL30, KL31, KL32, KL33, KL34, KL35, KC_NO, KC_NO }, \
    { KL40, KL41, KL42, KL43, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KR00, KR01, KR02, KR03, KR04, KR05, KR06, KR07 }, \
    { KR10, KR11, KR12, KR13, KR14, KR15, KR16, KC_NO }, \
    { KR20, KR21, KR22, KR23, KR24, KR25, KR26, KR27 }, \
    { KR30, KR31, KR32, KR33, KR34, KR35, KR36, KR37 }, \
    { KR40, KR41, KR42, KR43, KR44, KR45, KC_NO, KC_NO }  \
}


#endif
