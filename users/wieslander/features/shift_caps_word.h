enum caps_word_mode_t {
    CW_UNDECIDED,
    CW_CONSTANT,
    CW_PATH,
};
bool cw_last_key_was_space;
bool cw_last_key_was_slash;

bool process_shift_caps_word(uint16_t, keyrecord_t *);
bool caps_word_undecided(uint16_t);
bool caps_word_constant(uint16_t);
bool caps_word_path(uint16_t);
