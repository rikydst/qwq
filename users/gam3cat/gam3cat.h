/*Copyright 2021 @Gam3cat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#ifndef USERSPACE
#define USERSPACE

#pragma once
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "version.h"

void my_custom_function(void);

#define FN_CAPS LT(_FL, KC_CAPS)

enum userspace_layers {
    _BL = 0,    // Base Layer
    _WL,        // Workman Layer
    _NL,        // Norman Layer
    _DL,        // Dvorak Layer
    _CL,        // Base Layer
    _FL,        // Function Layer
    _AL,        // Adjust Layer
};


enum userspace_custom_keycodes {
    QMK_REV = SAFE_RANGE,
    KC_WEB,
    KC_SP4,
    SM_GLHF,
    SM_VA1,
    SM_VA2,
    SM_VA3,
    SM_VAA,
    SM_VAF,
    SM_VAG,
    SM_VAM,
    SM_VAT1,
    SM_VAT2,
    SM_VAT3,
    SM_VB1,
    SM_VB2,
    SM_VB3,
    SM_VBA,
    SM_VBB,
    SM_VBD,
    SM_VBE,
    SM_VBF,
    SM_VBG,
    SM_VBJ1,
    SM_VBJ3,
    SM_VBJJ,
    SM_VBM,
    SM_VBS,
    SM_VC1,
    SM_VC2,
    SM_VC3,
    SM_VCB,
    SM_VCC,
    SM_VCJ,
    SM_VD1,
    SM_VD2,
    SM_VD3,
    SM_VDD,
    SM_VDF,
    SM_VDG,
    SM_VDM,
    SM_VEA,
    SM_VEG,
    SM_VEJ,
    SM_VEL,
    SM_VER,
    SM_VET,
    SM_VEW,
    SM_VF1,
    SM_VF2,
    SM_VF3,
    SM_VFF,
    SM_VG1,
    SM_VG2,
    SM_VG3,
    SM_VGG,
    SM_VH1,
    SM_VH2,
    SM_VH3,
    SM_VHH,
    SM_VHS,
    SM_VI1,
    SM_VI2,
    SM_VI3,
    SM_VII,
    SM_VQ1,
    SM_VQ2,
    SM_VQ3,
    SM_VQF,
    SM_VQG,
    SM_VQN,
    SM_VQQ,
    SM_VR1,
    SM_VR2,
    SM_VR3,
    SM_VRJ,
    SM_VRR,
    SM_VRS,
    SM_VSA1,
    SM_VSA2,
    SM_VSA3,
    SM_VSAA,
    SM_VSAF,
    SM_VSAG,
    SM_VSAM,
    SM_VSBB,
    SM_VSBN,
    SM_VSBT,
    SM_VSD1,
    SM_VSD2,
    SM_VSD3,
    SM_VSDD,
    SM_VSDF,
    SM_VSDG,
    SM_VSDM,
    SM_VSG1,
    SM_VSG2,
    SM_VSG3,
    SM_VSGG,
    SM_VSO,
    SM_VSQ1,
    SM_VSQ2,
    SM_VSQ3,
    SM_VSQQ,
    SM_VSR,
    SM_VSS,
    SM_VST1,
    SM_VST2,
    SM_VST3,
    SM_VSTB,
    SM_VSTT,
    SM_VT1,
    SM_VT2,
    SM_VT3,
    SM_VTT,
    SM_VVA,
    SM_VVB,
    SM_VVC,
    SM_VVGB,
    SM_VVGF,
    SM_VVGG,
    SM_VVGH,
    SM_VVGL,
    SM_VVGN,
    SM_VVGO,
    SM_VVGQ,
    SM_VVGR,
    SM_VVGS,
    SM_VVGT,
    SM_VVGW,
    SM_VVK,
    SM_VVM,
    SM_VVN,
    SM_VVP,
    SM_VVS,
    SM_VVT,
    SM_VVVA,
    SM_VVVB,
    SM_VVVC,
    SM_VVVD,
    SM_VVVE,
    SM_VVVF,
    SM_VVVG,
    SM_VVVJ,
    SM_VVVP,
    SM_VVVR,
    SM_VVVS,
    SM_VVVT,
    SM_VVVW,
    SM_VVVX,
    SM_VVW,
    SM_VVX,
    SM_VVY,
    SM_VXC,
    SM_VXD,
    SM_VXE,
    SM_VXF,
    SM_VXG,
    SM_VXS,
    SM_VXW,
    NEW_SAFE_RANGE
};


#endif
