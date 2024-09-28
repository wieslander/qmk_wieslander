REPEAT_KEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
OS_DETECTION_ENABLE = yes
COMBO_ENABLE = yes
VPATH += keyboards/gboards/

SRC += wieslander.c \
	   features/lt_repeat.c \
	   features/shift_caps_word.c \
	   features/modtap.c \
	   features/numword.c
