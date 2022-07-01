#include QMK_KEYBOARD_H

#include "custom_shift.h"

static bool isBackspacing = false;

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
            // Repeat backspace if hold RAI_BSP when shifted

        case RAI_BSP:
            if (isShifted || isBackspacing) {
                if (record->event.pressed) {
                    register_code(KC_BSPC);
                    isBackspacing = true;
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    unregister_code(KC_BSPC);
                    isBackspacing = false;
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }

    if (!record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    uint16_t key = extract_base_tapping_keycode(keycode);

    switch (keycode) {
            // Inverted colon and semicolon
        case KC_COLN:
            if (isShifted) {
                clear_shift();
                tap_code(KC_SCLN);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;
    }

    switch (key) {
            // Shifted numrow = numpad

        case KC_1 ... KC_0:
            if (isShifted) {
                tap_code(key + 59);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;
    }

    return PROCESS_RECORD_CONTINUE;
}
