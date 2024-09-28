#include QMK_KEYBOARD_H

#include "numword.h"
#include "custom_keycodes.h"
#include "layers.h"

bool numword_active = false;

void numword_on(void) {
    numword_active = true;
    layer_on(NUM);
}

void numword_off(void) {
    numword_active = false;
    layer_off(NUM);
}

bool process_numword_key(keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        numword_on();
        return false;
    }
    return true;
}

bool keep_numword_active(uint16_t keycode) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_DOT:
        case KC_COMM:
            return true;
        default:
            return false;
    }
}

void process_numword_keypress(uint16_t keycode, keyrecord_t *record) {
    if (!keep_numword_active(keycode)) {
        numword_off();
    }
}

bool process_numword(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUMWORD:
            return process_numword_key(record);
        default:
            if (numword_active) {
                process_numword_keypress(keycode, record);
            }
            return true;
    }
}
