#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    if (record->event.pressed) {
        switch (keycode) {

            // Degree symbol

            case SS_DEG:
                if (os.type == MACOS) {
                    tap_code16(LSFT(RALT(KC_8)));
                } else {
                    tap_code16(LSFT(LCTL(KC_2)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
                
            // Macro layer

            case SS_DAND:
                SEND_STRING("&&");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DPIP:
                SEND_STRING("||");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_EQU:
                clear_shift();
                tap_code(KC_EQL);
                tap_code(KC_EQL);
                if (isShifted) {
                    tap_code(KC_EQL);
                }
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_NEQ:
                clear_shift();
                tap_code16(KC_EXLM);
                tap_code(KC_EQL);
                if (isShifted) {
                    tap_code(KC_EQL);
                }
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_ARR:
                if (isShifted) {
                    clear_shift();
                    SEND_STRING("=>");
                } else {
                    SEND_STRING("->");
                }
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DDS:
                SEND_STRING("../");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_AO:
                clear_shift();
                tap_code16(KC_TILD);
                tap_code(KC_A);
                tap_code(KC_O);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CAO:
                clear_shift();
                tap_code16(KC_QUOT);
                tap_code(KC_C);
                tap_code16(KC_TILD);
                tap_code(KC_A);
                tap_code(KC_O);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_OES:
                clear_shift();
                tap_code16(KC_TILD);
                tap_code(KC_O);
                tap_code(KC_E);
                tap_code(KC_S);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_COES:
                clear_shift();
                tap_code16(KC_QUOT);
                tap_code(KC_C);
                tap_code16(KC_TILD);
                tap_code(KC_O);
                tap_code(KC_E);
                tap_code(KC_S);
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}