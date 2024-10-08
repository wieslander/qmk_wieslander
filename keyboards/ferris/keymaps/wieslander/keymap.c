#include QMK_KEYBOARD_H
#include <stdint.h>

#include "custom_keycodes.h"
#include "layers.h"
#include "wieslander.h"
#include "g/keymap_combo.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,       KC_J,     KC_L,     KC_U,    KC_Y,    MAC_ARING,
        KC_A,     KC_R,     KC_S,     KC_T,     KC_G,       KC_M,     KC_N,     KC_E,    KC_I,    KC_O,
        KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,       KC_K,     KC_H,     MAC_AUML,DOT_CDUP,MAC_OUML,
                                      NUMWORD,  SFT_CW,     KC_SPC,   SYM_REP
    ),
    [WIN] = LAYOUT(
        ___,      ___,      ___,      ___,      ___,        ___,      ___,      ___,     ___,     WIN_ARING,
        ___,      ___,      ___,      ___,      ___,        ___,      ___,      ___,     ___,     ___,
        ___,      ___,      ___,      ___,      ___,        ___,      ___,      WIN_AUML,___,     WIN_OUML,
                                      ___,      ___,        ___,      ___
    ),
    [SYM] = LAYOUT(
        KC_PIPE,  KC_SCLN,  KC_SLSH,  KC_TILD,  KC_BSLS,    XXX,      XXX,      XXX,      XXX,      XXX,
        KC_LT,    KC_LBRC,  KC_LPRN,  KC_COMM,  KC_TAB,     XXX,      OSM_RSFT, OSM_RCMD, OSM_ROPT, OSM_RCTL,
        KC_GT,    KC_RBRC,  KC_RPRN,  KC_QUOT,  KC_GRV,     XXX,      KC_VOLD,  KC_MUTE,  KC_VOLU,  XXX,
                                      NAV_ENT,  FUN_BSP,    ___,      ___
    ),
    [NUM] = LAYOUT(
        G(KC_Q),  G(KC_W),  G(KC_F),  G(KC_P),  G(KC_B),    KC_COMM,  KC_7,     KC_8,     KC_9,     KC_COLN,
        OSM_LCTL, OSM_LOPT, OSM_LCMD, OSM_LSFT, XXX,        KC_EQL,   KC_4,     KC_5,     KC_6,     KC_MINS,
        G(KC_Z),  G(KC_X),  G(KC_C),  TT(NAV),  G(KC_V),    KC_DOT,   KC_1,     KC_2,     KC_3,     KC_SLSH,
                                      ___,      ___,        KC_SPC,   KC_0
    ),
    [NAV] = LAYOUT(
        XXX,      ___,      XXX,      XXX,      ___,        KC_PGDN,  KC_HOME,  KC_END,   KC_PGUP,  XXX,
        OSM_LCTL, OSM_LOPT, OSM_LCMD, OSM_LSFT, XXX,        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXX,
        G(KC_Z),  G(KC_X),  G(KC_C),  XXX,      G(KC_V),    XXX,      XXX,      XXX,      XXX,      XXX,
                                      ___,      ___,        KC_ENT,   MO(FUN)
    ),
    [FUN] = LAYOUT(
        KC_F9,    KC_F10,   KC_F11,   KC_F12,   XXX,        TO(BASE), QK_BOOT,  QK_MAKE,  QK_RBT,   ___,
        KC_F5,    KC_F6,    KC_F7,    KC_F8,    XXX,        TO(WIN),  OSM_RSFT, OSM_RCMD, OSM_ROPT, OSM_RCTL,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    XXX,        ___,      ___,      ___,      ___,      ___,
                                      ___,      ___,        ___,      ___
    )
};
