/* Copyright 2021 Rafael Romão @rafaelromao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ROMAK] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________ROMAK_L1____________________ , XXXXXXX , XXXXXXX , ___________________ROMAK_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L2____________________ , XXXXXXX , XXXXXXX , ___________________ROMAK_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ROMAK_L3____________________ , XXXXXXX , XXXXXXX , ___________________ROMAK_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____ROMAK_L4_____ ,      XXXXXXX      , ____ROMAK_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_NUMPAD] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________NUMPAD_L1___________________ , XXXXXXX , XXXXXXX , ___________________NUMPAD_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NUMPAD_L2___________________ , XXXXXXX , XXXXXXX , ___________________NUMPAD_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NUMPAD_L3___________________ , XXXXXXX , XXXXXXX , ___________________NUMPAD_R3___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____NUMPAD_L4____ ,      XXXXXXX      , ____NUMPAD_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________LOWER_L1____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L3____________________ , XXXXXXX , XXXXXXX , ___________________LOWER_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____LOWER_L4_____ ,      XXXXXXX      , ____LOWER_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |_______________________________ ________________________________________________________________________________________|
      ___________________RAISE_L1____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L3____________________ , XXXXXXX , XXXXXXX , ___________________RAISE_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____RAISE_L4_____ ,      XXXXXXX      , ____RAISE_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_NAVIGATION] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_L4__ ,      XXXXXXX      , __NAVIGATION_R4__ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MOUSE] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MOUSE_L1____________________ , XXXXXXX , XXXXXXX , ___________________MOUSE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L2____________________ , XXXXXXX , XXXXXXX , ___________________MOUSE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MOUSE_L3____________________ , XXXXXXX , XXXXXXX , ___________________MOUSE_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MOUSE_L4_____ ,      XXXXXXX      , ____MOUSE_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_FUNCTIONS] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________FUNCTIONS_L1________________ , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R1________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L2________________ , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R2________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________FUNCTIONS_L3________________ , XXXXXXX , XXXXXXX , ___________________FUNCTIONS_R3________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____FUNCTIONS_L4_ ,      XXXXXXX      , ____FUNCTIONS_R4_ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MEDIA] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MEDIA_L1____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L3____________________ , XXXXXXX , XXXXXXX , ___________________MEDIA_R3____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MEDIA_L4_____ ,      XXXXXXX      , ____MEDIA_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_______________________________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |_______________________________________________________________________________________________________________________|
      ___________________MAINTENANCE_L1______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L2______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MAINTENANCE_L3______________ , XXXXXXX , XXXXXXX , ___________________MAINTENANCE_R3______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __MAINTENANCE_L4_ ,      XXXXXXX      , __MAINTENANCE_R4_ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_______________________________________________________________________________________________________________________|
};

// RGB Indicators

extern leader_t leader;
extern select_word_t select_word;

void rgb_matrix_indicators_user(void) {

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(11, RGB_ORANGE);
    }

    uint8_t mods = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    if (isShift) {
        rgb_matrix_set_color(13, RGB_WHITE);
    }
    if (isCtrl) {
        rgb_matrix_set_color(14, RGB_WHITE);
    }
    if (isAlt) {
        rgb_matrix_set_color(15, RGB_WHITE);
    }
    if (isGui) {
        rgb_matrix_set_color(27, RGB_WHITE);
    }

    if (leader.isLeading) {
        rgb_matrix_set_color(1, RGB_WHITE);
    }

    if (select_word.state != STATE_NONE) {
        rgb_matrix_set_color(2, RGB_WHITE);
    }

    switch(get_highest_layer(layer_state|default_layer_state)) {
        case _NUMPAD:
            rgb_matrix_set_color(0, RGB_CYAN);
            break;
        case _LOWER:
            rgb_matrix_set_color(40, RGB_WHITE);
            break;
        case _RAISE:
            rgb_matrix_set_color(42, RGB_WHITE);
            break;
        case _FUNCTIONS:
            rgb_matrix_set_color(12, RGB_WHITE);
            break;
        case _NAVIGATION:
            rgb_matrix_set_color(39, RGB_WHITE);
            break;
        case _MOUSE:
            rgb_matrix_set_color(43, RGB_WHITE);
            break;
        case _MEDIA:
            rgb_matrix_set_color(23, RGB_WHITE);
            break;
        case _MAINTENANCE:
            rgb_matrix_set_color(39, RGB_WHITE);
            rgb_matrix_set_color(43, RGB_WHITE);
            rgb_matrix_set_color(4, RGB_WHITE);
            rgb_matrix_set_color(2, RGB_WHITE);
            rgb_matrix_set_color(9, RGB_WHITE);
            rgb_matrix_set_color(7, RGB_RED);
            break;
        default:
            break;
    }
}
