#include QMK_KEYBOARD_H

enum layers {
    BASE, // Default layer - Colemak DH Swedish
    WIN,  // Default layer, Windows version
    PUN,  // Punctuation
    SYM,  // Symbols
    NUM,  // Numbers
    NAV,  // Navigation
    FUN,  // Function keys
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    NEXTSEN,
    WIN_ARING,
    WIN_OUML,
    WIN_AUML,
};

#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,       KC_J,     KC_L,     KC_U,    KC_Y,    MAC_ARING,
        KC_A,     KC_R,     KC_S,     KC_T,     KC_G,       KC_M,     KC_N,     KC_E,    KC_I,    KC_O,
        KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,       KC_K,     KC_H,     MAC_AUML,KC_DOT,  MAC_OUML,
                                      MO(PUN),  QK_REP,     KC_SPC,   MO(SYM)
    ),
    [WIN] = LAYOUT(
        ___,      ___,      ___,      ___,      ___,        ___,      ___,      ___,     ___,     WIN_ARING,
        ___,      ___,      ___,      ___,      ___,        ___,      ___,      ___,     ___,     ___,
        ___,      ___,      ___,      ___,      ___,        ___,      ___,      WIN_AUML,___,     WIN_OUML,
                                      ___,      ___,        ___,      ___
    ),
    [PUN] = LAYOUT(
        G(KC_Q),  G(KC_W),  G(KC_F),  G(KC_P),  TO(BASE),   XXX,      KC_SCLN,  KC_TILD,  KC_GRV,   XXX,
        OSM_LCTL, OSM_LOPT, OSM_LCMD, OSM_LSFT, TO(WIN),    KC_EQL,   KC_COLN,  KC_COMM,  KC_MINS,  KC_UNDS,
        G(KC_Z),  G(KC_X),  G(KC_C),  TT(NAV),  G(KC_V),    UPDIR,    KC_EXLM,  KC_AT,    KC_SLSH,  KC_BSLS,
                                      ___,      ___,        NEXTSEN,  MO(FUN)
    ),
    [SYM] = LAYOUT(
        XXX,      XXX,      KC_DQT,   KC_QUOT,  XXX,        XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      KC_LBRC,  KC_LPRN,  KC_LCBR,  KC_TAB,     XXX,      OSM_RSFT, OSM_RCMD, OSM_ROPT, OSM_RCTL,
        XXX,      KC_RBRC,  KC_RPRN,  KC_RCBR,  XXX,        XXX,      KC_VOLD,  KC_MUTE,  KC_VOLU,  XXX,
                                      TT(NUM),  KC_BSPC,    ___,      ___
    ),
    [NUM] = LAYOUT(
        XXX,      XXX,      XXX,      XXX,      XXX,        KC_COLN,  KC_7,     KC_8,     KC_9,     KC_MINS,
        OSM_LCTL, OSM_LOPT, OSM_LCMD, OSM_LSFT, XXX,        KC_COMM,  KC_4,     KC_5,     KC_6,     KC_EQL,
        XXX,      XXX,      XXX,      TT(NAV),  XXX,        KC_DOT,   KC_1,     KC_2,     KC_3,     KC_SLSH,
                                      TO(BASE), ___,        KC_DOT,   KC_0
    ),
    [NAV] = LAYOUT(
        XXX,      ___,      XXX,      XXX,      ___,        KC_PGDN,  KC_HOME,  KC_END,   KC_PGUP,  XXX,
        OSM_LCTL, OSM_LOPT, OSM_LCMD, OSM_LSFT, XXX,        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXX,
        G(KC_Z),  G(KC_X),  G(KC_C),  XXX,      G(KC_V),    XXX,      XXX,      XXX,      XXX,      XXX,
                                      TO(BASE), ___,        NEXTSEN,  MO(FUN)
    ),
    [FUN] = LAYOUT(
        KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXX,        ___,      QK_BOOT,  QK_MAKE,  ___,      ___,
        KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXX,        ___,      OSM_RSFT, OSM_RCMD, OSM_ROPT, OSM_RCTL,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXX,        ___,      ___,      ___,      ___,      ___,
                                      TO(BASE), ___,        ___,      ___
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mod_state = get_mods();
    uint8_t oneshot_mod_state = get_oneshot_mods();

    switch (keycode) {
        case NEXTSEN:  // Next sentence macro.
            if (record->event.pressed) {
                SEND_STRING(". ");
                add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
            }
            return false;
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            }
            return false;
        case WIN_ARING:
            if (record->event.pressed) {
                register_code(KC_LALT);
                if ((mod_state & MOD_MASK_SHIFT) || (oneshot_mod_state & MOD_MASK_SHIFT)) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    tap_code(KC_P1);
                    tap_code(KC_P4);
                    tap_code(KC_P3);
                    set_mods(mod_state);
                } else {
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P9);
                }
                unregister_code(KC_LALT);
            }
            return false;
        case WIN_AUML:
            if (record->event.pressed) {
                register_code(KC_LALT);
                if ((mod_state & MOD_MASK_SHIFT) || (oneshot_mod_state & MOD_MASK_SHIFT)) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    tap_code(KC_P1);
                    tap_code(KC_P4);
                    tap_code(KC_P2);
                    set_mods(mod_state);
                } else {
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P2);
                    tap_code(KC_P8);
                }
                unregister_code(KC_LALT);
            }
            return false;
        case WIN_OUML:
            if (record->event.pressed) {
                register_code(KC_LALT);
                if ((mod_state & MOD_MASK_SHIFT) || (oneshot_mod_state & MOD_MASK_SHIFT)) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    tap_code(KC_P1);
                    tap_code(KC_P5);
                    tap_code(KC_P3);
                    set_mods(mod_state);
                } else {
                    tap_code(KC_P0);
                    tap_code(KC_P2);
                    tap_code(KC_P4);
                    tap_code(KC_P6);
                }
                unregister_code(KC_LALT);
            }
            return false;
    }
    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_WINDOWS) {
        layer_on(WIN);
    }
    return true;
}
