#include QMK_KEYBOARD_H

#include "smart_case.h"

smart_case_t smart_case = {.timer = 0, .type = NO_CASE};

void clear_shift(void) {
    del_oneshot_mods(MOD_MASK_SHIFT);
    unregister_mods(MOD_MASK_SHIFT);
}

bool smart_case_timer_expired(void) {
    return smart_case.timer > 0 && (timer_elapsed(smart_case.timer) > 5 * CUSTOM_ONESHOT_TIMEOUT);
}

void start_smart_case_timer(void) {
    smart_case.timer = timer_read();
}

void clear_smart_case_timer(void) {
    smart_case.timer = 0;
}

void disable_smart_case(void) {
    smart_case.type = NO_CASE;
    clear_smart_case_timer();
    clear_shift();
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void check_disable_smart_case(void) {
    if (smart_case_timer_expired()) {
        disable_smart_case();
    }
}

void enable_smartcase(smart_case_type_t smart_case_types) {
    if (smart_case.type == NO_CASE) {
        smart_case.type = smart_case_types;
    } else {
        smart_case.type = smart_case.type | smart_case_types;
    }
    start_smart_case_timer();
}

void enable_capslock(void) {
    enable_smartcase(CAPS_LOCK);
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void set_smart_case(smart_case_type_t smart_case_types) {
    if (smart_case_types & CAPS_LOCK) {
        enable_capslock();
        return;
    }
    if (smart_case_types & CAMEL_CASE) {
        // Setting CapsWord with CamelCase already set, makes Pascal Case
        if (has_smart_case(WORD_CASE)) {
            disable_smart_case();
            add_oneshot_mods(MOD_LSFT);
        }
    }
    enable_smartcase(smart_case_types);
}

bool has_smart_case(smart_case_type_t smart_case_types) {
    return smart_case.type & smart_case_types;
}

bool has_any_smart_case(void) {
    return smart_case.type != NO_CASE;
}

void toggle_capslock(bool capslock) {
    if (capslock) {
        set_smart_case(CAPS_LOCK);
    } else {
        disable_smart_case();
    }
}

void toggle_smart_case(smart_case_type_t smart_case_types) {
    if (has_smart_case(smart_case_types)) {
        disable_smart_case();
    } else {
        set_smart_case(smart_case_types);
    }
}

void set_smart_case_for_mods(keyrecord_t *record) {
    int8_t mods = get_mods();
    disable_smart_case();
    if (mods == 0 || mods & MOD_BIT(KC_LCTL)) {
        toggle_smart_case(WORD_CASE);
        toggle_capslock(!host_keyboard_led_state().caps_lock);
    }
    if (mods & MOD_BIT(KC_RCTL)) {
        toggle_capslock(!host_keyboard_led_state().caps_lock);
    }
    if (mods & MOD_BIT(KC_LSFT)) {
        toggle_smart_case(CAMEL_CASE);
    }
    if (mods & MOD_BIT(KC_RSFT)) {
        toggle_smart_case(SLASH_CASE);
    }
    if (mods & MOD_BIT(KC_LGUI)) {
        toggle_smart_case(SNAKE_CASE);
    }
    if (mods & MOD_BIT(KC_RGUI)) {
        toggle_smart_case(KEBAB_CASE);
    }
}

static bool spacing = false;

process_record_result_t process_smart_case(uint16_t keycode, keyrecord_t *record) {
    if (has_any_smart_case() && record->event.pressed) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet.
                if (record->tap.count == 0) {
                    return PROCESS_RECORD_CONTINUE;
                }
                // Get the base tapping keycode of a mod- or layer-tap key.
                keycode = extract_base_tapping_keycode(keycode);
        }
        if (keycode != KC_SPC) {
            spacing = false;
        }
        // Extend, process or break case
        switch (keycode) {
            case KC_SPC:
                if (spacing) {
                    if (has_smart_case(CAMEL_CASE) || has_smart_case(SNAKE_CASE) || has_smart_case(KEBAB_CASE) ||
                        has_smart_case(SLASH_CASE)) {
                        if (has_smart_case(SNAKE_CASE) || has_smart_case(KEBAB_CASE) || has_smart_case(SLASH_CASE)) {
                            tap_code(KC_BSPC);
                        }
                        tap_code(KC_SPC);
                        disable_smart_case();
                        return PROCESS_RECORD_RETURN_FALSE;
                    }
                } else {
                    spacing = true;
                }
                if (has_smart_case(WORD_CASE) && !(has_smart_case(SNAKE_CASE)) && !(has_smart_case(CAMEL_CASE))) {
                    disable_smart_case();
                    return PROCESS_RECORD_CONTINUE;
                }
                if (has_smart_case(SNAKE_CASE)) {
                    tap_code16(KC_UNDS);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(KEBAB_CASE)) {
                    tap_code16(KC_MINS);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(SLASH_CASE)) {
                    tap_code(KC_SLSH);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(CAMEL_CASE)) {
                    add_oneshot_mods(MOD_LSFT);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            case STR_MACRO_START ... STR_MACRO_END:
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_MINS:
            case KC_UNDS:
            case KC_LEFT:
            case KC_RIGHT:
            case KC_HOME:
            case KC_END:
            case MAI_ACT:
            case MAI_CAS:
                start_smart_case_timer();
                break;
            case KC_DOT:
            case TD_DOT:
            case KC_SLSH:
                if (has_smart_case(SLASH_CASE)) {
                    start_smart_case_timer();
                    break;
                }
            default:
                if (is_key_on_tap(keycode) && (has_smart_case(WORD_CASE) || !has_smart_case(CAPS_LOCK))) {
                    disable_smart_case();
                }
                break;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}