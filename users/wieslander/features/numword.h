#pragma once
#include QMK_KEYBOARD_H

bool numword_active;

void numword_on(void);
void numword_off(void);
bool process_numword_key(keyrecord_t *);
void process_numword_keypress(uint16_t, keyrecord_t *);
bool keep_numword_active(uint16_t);
bool process_numword(uint16_t, keyrecord_t *);
