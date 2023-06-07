#pragma once

//more info at https://docs.qmk.fm/#/feature_rgb_matrix?id=additional-configh-options

//KEYBOARD_bastardkb_charybdis_3x5
//KEYBOARD_crkbd_rev1
//KEYBOARD_dztech_dz60rgb_v2_1 ???
//the planck is RGBLIGHT not RGB MATRIX

//Clear variables that might have been defined elsewhere
#undef RGB_DISABLE_WHEN_USB_SUSPENDED
#undef RGB_MATRIX_DEFAULT_HUE
#undef RGB_MATRIX_DEFAULT_SAT
#undef RGB_MATRIX_DEFAULT_VAL
#undef RGB_MATRIX_DEFAULT_SPD
#undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#undef RGB_MATRIX_KEYPRESSES
#undef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#undef RGB_MATRIX_TYPING_HEATMAP_SPREAD
#undef RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT
#undef RGB_MATRIX_TYPING_HEATMAP_SLIM
#undef RGB_MATRIX_DEFAULT_MODE

// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects

//Then undefine all the RGB Animations
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
//These modes also require the RGB_MATRIX_FRAMEBUFFER_EFFECTS define to be available.
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
//These modes also require the RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES define to be available.
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH





//Set common configuration for all keyboards
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define RGB_MATRIX_DEFAULT_HUE 4
#define RGB_MATRIX_DEFAULT_SAT 79
#define RGB_MATRIX_DEFAULT_VAL 59
#define RGB_MATRIX_DEFAULT_SPD 32



//Set per keyboard configuration
#if defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_dztech_dz60rgb_v2_1)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define RGB_MATRIX_KEYPRESSES
//no extra defines required
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#   define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#   define ENABLE_RGB_MATRIX_DUAL_BEACON
#   define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#   define ENABLE_RGB_MATRIX_HUE_BREATHING
//requires RGB_MATRIX_FRAMEBUFFER_EFFECTS
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#   define ENABLE_RGB_MATRIX_DIGITAL_RAIN
//requires RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#   define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#   define ENABLE_RGB_MATRIX_SPLASH
#   define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING

//MT32U4 has limited memory
#elif defined(KEYBOARD_crkbd_rev1)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS 
//no extra defines required
//requires RGB_MATRIX_FRAMEBUFFER_EFFECTS 
#   define ENABLE_RGB_MATRIX_TYPING_HEATMAP

#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

//enable minimal effects to save memory
#else
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#   define ENABLE_RGB_MATRIX_BREATHING
#   define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#endif //defined(KEYBOARD_bastardkb_charybdis_3x5) || defined(KEYBOARD_dztech_dz60rgb_v2_1)



//post configuration

#if defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
#   define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 18    //default 25
#   define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40               //40
#   define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16           //16
#   define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 20        //32
//#   define RGB_MATRIX_TYPING_HEATMAP_SLIM
#endif //ENABLE_RGB_MATRIX_TYPING_HEATMAP
