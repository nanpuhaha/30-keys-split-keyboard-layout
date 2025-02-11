#include QMK_KEYBOARD_H

#include "definitions/layers.h"
#include "definitions/keycodes.h"
#include "definitions/keymap_blocks.h"
#include "features/taphold.h"
#include "features/tapdance.h"
#include "features/smart_case.h"
#include "features/os_toggle.h"
#include "features/macros.h"
#include "features/accents.h"
#include "features/combos.h"
#include "features/leader.h"
#include "features/custom_oneshot.h"
#include "features/common_shortcuts.h"
#include "features/select_word.h"
#include "features/dynamic_macro.h"
#include "features/swapper.h"
#include "features/custom_shift.h"

void matrix_scan_keymap(void);
