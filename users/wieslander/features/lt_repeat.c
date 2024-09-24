#include QMK_KEYBOARD_H
#include <stdint.h>

#include "custom_keycodes.h"

bool process_lt_repeat(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SYM_REP && record->tap.count) {
        if (process_last_key(QK_REP, record)) {
            process_repeat_key(QK_REP, record);
        }
        return false;
    }
    return true;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case SYM_REP:
            return false;
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_ENT ... KC_SLASH:
            if ((*remembered_mods & ~MOD_MASK_SHIFT) == 0) {
                return false;
            }
    }

    return true;
}
