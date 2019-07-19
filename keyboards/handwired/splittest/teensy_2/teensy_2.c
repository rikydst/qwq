#include QMK_KEYBOARD_H

bool is_keyboard_master(void) {
    // TODO: replace this override once USB host detection is implemented
    // SPLIT_HAND_PIN Combined with MASTER_LEFT or MASTER_RIGHT, it gives a crude
    // way to force teensy to run as slave/master
    setPinInput(SPLIT_HAND_PIN);
    return readPin(SPLIT_HAND_PIN);
}
