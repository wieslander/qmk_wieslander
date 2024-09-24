#include "custom_keycodes.h"

bool process_shift_caps_word(uint16_t keycode, keyrecord_t *record) {
    if (keycode != SFT_CW) {
        return true;
    }

    if (record->tap.count && record->event.pressed) {
        caps_word_toggle();
        return false;
    }

    return true;
}
