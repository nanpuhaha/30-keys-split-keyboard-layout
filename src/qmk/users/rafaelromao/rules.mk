SRC += secret.c
SRC += rafaelromao.c
SRC += definitions/keycodes.c
SRC += features/taphold.c
SRC += features/ngrams_key.c
SRC += features/default_mod_key.c
SRC += features/capitalize_key.c
SRC += features/tapdance.c
SRC += features/capslock_timer.c
SRC += features/os_toggle.c
SRC += features/macros.c
SRC += features/combos.c
SRC += features/leader.c
SRC += features/select_word.c
SRC += features/dynamic_macro.c
SRC += features/accentuation.c
SRC += features/window_swapper.c
SRC += features/custom_shortcuts.c
SRC += features/custom_shift.c

LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes # Audio control and System control
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
LEADER_ENABLE = yes
NKRO_ENABLE = no
BOOTMAGIC_ENABLE = no
BACKLIGHT_ENABLE = no
SWAP_HANDS_ENABLE = no
KEY_LOCK_ENABLE = no
CONSOLE_ENABLED = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
MUSIC_ENABLE = no
