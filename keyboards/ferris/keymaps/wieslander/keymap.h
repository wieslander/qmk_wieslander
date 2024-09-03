#pragma once
#include QMK_KEYBOARD_H

#include <stdint.h>

void set_num_lock(void);
bool process_win_alt_keycodes(keyrecord_t *record, uint16_t *alt_code_lower, uint16_t *alt_code_upper);
void tap_alt_code(uint16_t *alt_code);
