// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "color.h"

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_HOME,          KC_END,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, TL_LOWR, KC_ENT,                    KC_SPC,  TL_UPPR, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_UP,   _______, QK_BOOT, _______,                            KC_DQT,  KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PGDN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, EE_CLR,  _______, _______, _______, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, KC_DEL,                    KC_DEL,  _______, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_TOGG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RM_NEXT, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_UNDS,                            KC_EQL,  KC_HOME, RM_HUEU, RM_SATU, KC_COLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, EE_CLR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   rgb_matrix_set_color(0, 20, 94, 85);
   rgb_matrix_set_color(1, 20, 94, 85);
   rgb_matrix_set_color(2, 20, 94, 85);
   rgb_matrix_set_color(3, 20, 94, 85);
   rgb_matrix_set_color(4, 20, 94, 85);
   rgb_matrix_set_color(5, 20, 94, 85);
   rgb_matrix_set_color(6, 20, 94, 85);
   rgb_matrix_set_color(7, 20, 94, 85);
   rgb_matrix_set_color(8, 20, 94, 85);
   rgb_matrix_set_color(9, 20, 94, 85);
   rgb_matrix_set_color(10, 20, 94, 85);
   rgb_matrix_set_color(11, 20, 94, 85);
   rgb_matrix_set_color(12, 20, 94, 85);
   rgb_matrix_set_color(13, 20, 94, 85);
   rgb_matrix_set_color(14, 20, 94, 85);
   rgb_matrix_set_color(15, 20, 94, 85);
   rgb_matrix_set_color(16, 20, 94, 85);
   rgb_matrix_set_color(17, 20, 94, 85);
   rgb_matrix_set_color(18, 20, 94, 85);
   rgb_matrix_set_color(19, 20, 94, 85);
   rgb_matrix_set_color(20, 20, 94, 85);
   rgb_matrix_set_color(21, 90, 42, 67);
   rgb_matrix_set_color(22, 90, 42, 67);
   rgb_matrix_set_color(23, 90, 42, 67);
   rgb_matrix_set_color(24, 90, 42, 67);
   rgb_matrix_set_color(25, 90, 42, 67);
   rgb_matrix_set_color(26, 90, 42, 67);
   rgb_matrix_set_color(27, 90, 42, 67);
   rgb_matrix_set_color(28, 90, 42, 67);
   rgb_matrix_set_color(29, 66, 45, 87);
   rgb_matrix_set_color(30, 66, 45, 87);
   rgb_matrix_set_color(31, 49, 54, 95);
   rgb_matrix_set_color(32, 66, 45, 87);
   rgb_matrix_set_color(33, 66, 45, 87);
   rgb_matrix_set_color(34, 20, 94, 85);
   rgb_matrix_set_color(35, 20, 94, 85);
   rgb_matrix_set_color(36, 20, 94, 85);
   rgb_matrix_set_color(37, 20, 94, 85);
   rgb_matrix_set_color(38, 20, 94, 85);
   rgb_matrix_set_color(39, 20, 94, 85);
   rgb_matrix_set_color(40, 20, 94, 85);
   rgb_matrix_set_color(41, 20, 94, 85);
   rgb_matrix_set_color(42, 20, 94, 85);
   rgb_matrix_set_color(43, 20, 94, 85);
   rgb_matrix_set_color(44, 20, 94, 85);
   rgb_matrix_set_color(45, 20, 94, 85);
   rgb_matrix_set_color(46, 20, 94, 85);
   rgb_matrix_set_color(47, 20, 94, 85);
   rgb_matrix_set_color(48, 20, 94, 85);
   rgb_matrix_set_color(49, 20, 94, 85);
   rgb_matrix_set_color(50, 20, 94, 85);
   rgb_matrix_set_color(51, 20, 94, 85);
   rgb_matrix_set_color(52, 20, 94, 85);
   rgb_matrix_set_color(53, 20, 94, 85);
   rgb_matrix_set_color(54, 20, 94, 85);
   rgb_matrix_set_color(55, 90, 42, 67);
   rgb_matrix_set_color(56, 90, 42, 67);
   rgb_matrix_set_color(57, 90, 42, 67);
   rgb_matrix_set_color(58, 90, 42, 67);
   rgb_matrix_set_color(59, 90, 42, 67);
   rgb_matrix_set_color(60, 90, 42, 67);
   rgb_matrix_set_color(61, 90, 42, 67);
   rgb_matrix_set_color(62, 90, 42, 67);
   rgb_matrix_set_color(63, 66, 45, 87);
   rgb_matrix_set_color(64, 66, 45, 87);
   rgb_matrix_set_color(65, 49, 54, 95);
   rgb_matrix_set_color(66, 66, 45, 87);
   rgb_matrix_set_color(67, 66, 45, 87);
   return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}