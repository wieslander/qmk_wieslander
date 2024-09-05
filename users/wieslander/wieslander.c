#include QMK_KEYBOARD_H

#include "custom_keycodes.h"
#include "layers.h"
#include "wieslander.h"

bool     num_lock          = false;
uint16_t WIN_ARING_UPPER[] = {KC_P1, KC_P4, KC_P3, 0};
uint16_t WIN_ARING_LOWER[] = {KC_P0, KC_P2, KC_P2, KC_P9, 0};
uint16_t WIN_AUML_UPPER[]  = {KC_P1, KC_P4, KC_P2, 0};
uint16_t WIN_AUML_LOWER[]  = {KC_P0, KC_P2, KC_P2, KC_P8, 0};
uint16_t WIN_OUML_UPPER[]  = {KC_P1, KC_P5, KC_P3, 0};
uint16_t WIN_OUML_LOWER[]  = {KC_P0, KC_P2, KC_P4, KC_P6, 0};

bool process_tap_or_long_press_send_string(keyrecord_t *record, char *long_press_string) {
    if (!record->tap.count) {
        if (record->event.pressed) {
            SEND_STRING(long_press_string);
        }
        return false;
    }
    return true;
}

void set_num_lock(void) {
    if (!num_lock) {
        tap_code(KC_NUM);
    }
}

void tap_alt_code(uint16_t *alt_code) {
    for (uint8_t index = 0; alt_code[index] != 0; ++index) {
        tap_code(alt_code[index]);
    }
}

bool process_win_alt_keycodes(keyrecord_t *record, uint16_t *alt_code_lower, uint16_t *alt_code_upper) {
    uint16_t mod_state         = get_mods();
    uint16_t oneshot_mod_state = get_oneshot_mods();

    if (record->event.pressed) {
        set_num_lock();
        register_code(KC_LALT);
        if ((mod_state & MOD_MASK_SHIFT) || (oneshot_mod_state & MOD_MASK_SHIFT)) {
            del_mods(MOD_MASK_SHIFT);
            del_oneshot_mods(MOD_MASK_SHIFT);
            tap_alt_code(alt_code_upper);
            set_mods(mod_state);
        } else {
            tap_alt_code(alt_code_lower);
        }
        unregister_code(KC_LALT);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_REP:
            if (record->tap.count) {
                if (process_last_key(QK_REP, record)) {
                    process_repeat_key(QK_REP, record);
                }
                return false;
            }
            return true;
        case DOT_CDUP:
            return process_tap_or_long_press_send_string(record, "../");
        case EQL_PAD:
            return process_tap_or_long_press_send_string(record, " = ");
        case CLEAR:
            if (record->event.pressed) {
                clear_keyboard();
                layer_clear();
            }
            return false;
        case WIN_ARING:
            return process_win_alt_keycodes(record, WIN_ARING_LOWER, WIN_ARING_UPPER);
        case WIN_AUML:
            return process_win_alt_keycodes(record, WIN_AUML_LOWER, WIN_AUML_UPPER);
        case WIN_OUML:
            return process_win_alt_keycodes(record, WIN_OUML_LOWER, WIN_OUML_UPPER);
    }
    return true;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    return keycode != SFT_REP;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_WINDOWS) {
        layer_on(WIN);
    }
    return true;
}

bool led_update_user(led_t led_state) {
    num_lock = led_state.num_lock;
    return true;
}

void keyboard_post_init_user(void) {
    led_t led_state = host_keyboard_led_state();
    num_lock        = led_state.num_lock;
}
