#include "custom_keycodes.h"
#include "shift_caps_word.h"
#include <stdint.h>

enum caps_word_mode_t caps_word_mode        = CW_UNDECIDED;
bool                  cw_last_key_was_space = false;
bool                  cw_last_key_was_slash = false;

bool process_shift_caps_word(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();

    switch (keycode) {
        case SFT_CW:
            if (record->tap.count && record->event.pressed) {
                if (!is_caps_word_on() || caps_word_mode != CW_PATH) {
                    caps_word_toggle();
                    return false;
                }
            }
            return true;
        case KC_SLSH:
            if (!mod_state && !is_caps_word_on()) {
                caps_word_on();
                caps_word_mode = CW_PATH;
            }
            return true;
        default:
            return true;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (caps_word_mode) {
        case CW_UNDECIDED:
            return caps_word_undecided(keycode);
        case CW_CONSTANT:
            return caps_word_constant(keycode);
        case CW_PATH:
            return caps_word_path(keycode);

        default:
            // Should be unreachable
            return false;
    }
}

bool caps_word_undecided(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            caps_word_mode = CW_CONSTANT;
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            caps_word_mode = CW_CONSTANT;
            return true;

        case KC_SLSH:
            caps_word_mode = CW_PATH;
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool caps_word_constant(uint16_t keycode) {
    if (cw_last_key_was_space && keycode != KC_SPC) {
        tap_code(KC_BSPC);
        tap_code16(KC_UNDS);
        cw_last_key_was_space = false;
    }

    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        case KC_SPC:
            if (cw_last_key_was_space) {
                tap_code(KC_BSPC);
                return false;
            } else {
                cw_last_key_was_space = true;
                return true;
            }

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool caps_word_path(uint16_t keycode) {
    if (cw_last_key_was_space && keycode != KC_SPC) {
        tap_code(KC_BSPC);
        tap_code(KC_SLSH);
        cw_last_key_was_space = false;
        cw_last_key_was_slash = true;
    }

    switch (keycode) {
        // Keycodes that continue Caps Word
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
        case KC_LSFT:
        case KC_RSFT:
            cw_last_key_was_slash = false;
            return true;

        case KC_SLSH:
            cw_last_key_was_slash = true;
            return true;

        case KC_SPC:
            if (cw_last_key_was_space) {
                tap_code(KC_BSPC);
                return false;
            } else if (cw_last_key_was_slash) {
                return false;
            } else {
                cw_last_key_was_space = true;
                cw_last_key_was_slash = false;
                return true;
            }

        default:
            return false;
    }
}

void caps_word_set_user(bool active) {
    if (active) {
        cw_last_key_was_space = false;
        cw_last_key_was_slash = false;
        caps_word_mode        = CW_UNDECIDED;
    }
}
