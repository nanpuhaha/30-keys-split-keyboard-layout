#include QMK_KEYBOARD_H

#include "accents.h"

extern os_t os;

void tap_accent_dead_key(uint16_t keycode) {
    switch (keycode) {
        case MC_GV_A:
            tap_code16(KC_GRV);
            break;
        case MC_CR_A:
        case MC_CR_E:
        case MC_CR_O:
            tap_code16(KC_CIRC);
            break;
        case MC_TL_A:
        case MC_TL_O:
            tap_code16(KC_TILD);
            break;
        case MC_SQ_C:
        case MC_SQ_A:
        case MC_SQ_E:
        case MC_SQ_I:
        case MC_SQ_O:
        case MC_SQ_U:
            tap_code(KC_QUOT);
            break;
    }
}

void tap_accent_tap_key(uint32_t keycode) {
    switch (keycode) {
        case MC_GV_A:
        case MC_CR_A:
        case MC_TL_A:
        case MC_SQ_A:
            tap_code(KC_A);
            break;
        case MC_CR_E:
        case MC_SQ_E:
            tap_code(KC_E);
            break;
        case MC_TL_O:
        case MC_CR_O:
        case MC_SQ_O:
            tap_code(KC_O);
            break;
        case MC_SQ_I:
            tap_code(KC_I);
            break;
        case MC_SQ_U:
            tap_code(KC_U);
            break;
        case MC_SQ_C:
            tap_code(KC_C);
            break;
    }
}

bool is_accented_keycode(uint16_t keycode) {
    switch (keycode) {
        case MC_GV_A:
        case MC_CR_A:
        case MC_TL_A:
        case MC_SQ_A:
        case MC_CR_E:
        case MC_SQ_E:
        case MC_SQ_I:
        case MC_TL_O:
        case MC_CR_O:
        case MC_SQ_O:
        case MC_SQ_U:
        case MC_SQ_C:
            return true;
    }
    return false;
}

process_record_result_t process_ngrams(uint16_t keycode, bool isShifted) {
    switch (keycode) {
        case MC_AO:
            clear_shift();
            tap_code16(KC_TILD);
            tap_code(KC_A);
            tap_code(KC_O);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_CAO:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_C);
            tap_code16(KC_TILD);
            tap_code(KC_A);
            tap_code(KC_O);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_OES:
            clear_shift();
            tap_code16(KC_TILD);
            tap_code(KC_O);
            tap_code(KC_E);
            tap_code(KC_S);
            return PROCESS_RECORD_RETURN_FALSE;
        case MC_COES:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_C);
            tap_code16(KC_TILD);
            tap_code(KC_O);
            tap_code(KC_E);
            tap_code(KC_S);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_accents(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Accented characters

    if (is_accented_keycode(keycode)) {
        clear_locked_and_oneshot_mods();
        tap_accent_dead_key(keycode);
        if (isShifted) {
            register_mods(MOD_LSFT);
        }
        tap_accent_tap_key(keycode);
        if (isShifted) {
            unregister_mods(MOD_LSFT);
        }
        check_disable_oneshot(keycode);
        return PROCESS_RECORD_RETURN_FALSE;
    }

    // Ngrams

    switch (process_ngrams(keycode, isShifted)) {
        case PROCESS_RECORD_RETURN_FALSE:
            check_disable_oneshot(keycode);
            return PROCESS_RECORD_RETURN_FALSE;
        default:
            break;
    };

    check_disable_oneshot(keycode);
    return PROCESS_RECORD_CONTINUE;
}
