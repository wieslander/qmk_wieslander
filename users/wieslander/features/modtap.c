#include QMK_KEYBOARD_H
#include "custom_keycodes.h"

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYM_REP:
        case SFT_CW:
            return true;
        default:
            return false;
    }
}
