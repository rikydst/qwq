#include "stanrc85.h"

static uint8_t top = 0;
static uint8_t middle = 0;
static uint8_t bottom = 0;

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_RED},
    {10, 2, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_GREEN},
    {11, 1, HSV_GREEN}
);   

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_BLUE},
    {11, 1, HSV_BLUE} 
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_WHITE},
    {11, 1, HSV_WHITE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
    // Boot up "fanfare"
    top = 1;
    writePin(INDICATOR_PIN_0, !top);
    wait_ms(200);
    top = 0;
    writePin(INDICATOR_PIN_0, !top);
    middle = 1;
    writePin(INDICATOR_PIN_1, !middle);
    wait_ms(200);
    middle = 0;
    writePin(INDICATOR_PIN_1, !middle);
    bottom = 1;
    writePin(INDICATOR_PIN_2, !bottom);
    wait_ms(200);
    bottom = 0;
    writePin(INDICATOR_PIN_2, !bottom);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    middle = bottom = 0;
    switch (get_highest_layer(state)) {
    case _FN1_60:
        middle = 1;
        break;
    case _FN2_60:
        bottom = 1;
        break;
    case _DEFAULT:
        middle = 1;
        bottom = 1;
        break;
    default: //  for any other layers, or the default layer
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    //rgblight_set_layer_state(0, led_state.caps_lock);
    writePin(INDICATOR_PIN_0, !led_state.caps_lock);
    writePin(INDICATOR_PIN_1, !middle);
    writePin(INDICATOR_PIN_2, !bottom);
    return false;
}