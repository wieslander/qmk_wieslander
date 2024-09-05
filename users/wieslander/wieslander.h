#pragma once
#include QMK_KEYBOARD_H

#include <stdint.h>

bool process_tap_or_long_press_send_string(keyrecord_t *record, char *long_press_string);
void set_num_lock(void);
void tap_alt_code(uint16_t *alt_code);
bool process_win_alt_keycodes(keyrecord_t *record, uint16_t *alt_code_lower, uint16_t *alt_code_upper);
