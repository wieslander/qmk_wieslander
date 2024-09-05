#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CLEAR = SAFE_RANGE,
    WIN_ARING,
    WIN_OUML,
    WIN_AUML,
};

#define XXX KC_NO
#define ___ KC_TRNS

#define MAC_ARING ROPT(KC_A)
#define MAC_OUML ROPT(KC_O)
#define MAC_AUML ROPT(KC_QUOT)

#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LOPT OSM(MOD_LALT)
#define OSM_LCMD OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_ROPT OSM(MOD_RALT)
#define OSM_RCMD OSM(MOD_RGUI)
#define OSM_RSFT OSM(MOD_RSFT)

#define DOT_CDUP LT(0, KC_DOT)
#define EQL_PAD LT(0, KC_EQL)

#define SFT_REP LSFT_T(QK_REP)
