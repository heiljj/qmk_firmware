// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdbool.h>
#include "color.h"

enum custom_layers {
     _QWERTY,
     _LOWER,
     _RAISE,
     _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,   KC_NO,                              KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,LSFT_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D), KC_F,KC_G,                         KC_H,    KC_J,    RALT_T(KC_K),RCTL_T(KC_L),RSFT_T(KC_SCLN), KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,             KC_NO,   KC_N,    KC_M,  KC_COMM,  KC_DOT, KC_SLSH,  KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, TL_LOWR, KC_ENT,                    TL_UPPR, KC_SPC, KC_RSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,  KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR,  KC_GRV,  QK_GESC, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,LSFT_T(KC_1),LCTL_T(KC_2), LALT_T(KC_3),KC_4,   KC_5,                      KC_6,    KC_7,   RALT_T(KC_8), RCTL_T(KC_9), LSFT_T(KC_0), KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_NO,  _______, _______, _______, _______, _______,  KC_NO,            KC_NO,   KC_TAB, KC_EQL,  KC_PLUS, KC_MINUS, KC_BSLS, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______,  _______,                   _______, KC_BSPC, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  // can't use mod taps here because of os interpretation restrictions

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_LCBR,  KC_RCBR, KC_QUOT, KC_DQT, _______,                            _______,  _______, _______, _______, KC_TILD, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO, LSFT_T(KC_LBRC), KC_RBRC, KC_LPRN, KC_RPRN,_______,        KC_PIPE,  KC_EQL,  KC_PLUS, KC_MINUS, KC_UNDS,  KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   _______, _______, _______, _______, _______,  KC_NO,            KC_NO, _______, _______, _______, _______, _______,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______,   KC_TAB,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   _______, _______,  _______, _______, ,                            _______, _______, _______, _______, _______, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_UNDS,                            KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, KC_COLN, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS,  KC_NO,            KC_NO,  KC_PLUS, KC_END,  RM_HUED, RM_SATD, RM_VALD, KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
   // rgb_matrix_set_color(0, 20, 94, 85);
   rgb_matrix_set_color(1, 20, 94, 85);
   // rgb_matrix_set_color(2, 20, 94, 85);
   // rgb_matrix_set_color(3, 20, 94, 85);
   rgb_matrix_set_color(4, 20, 94, 85);
   // rgb_matrix_set_color(5, 20, 94, 85);
   // rgb_matrix_set_color(6, 20, 94, 85);
   rgb_matrix_set_color(7, 20, 94, 85);
   // rgb_matrix_set_color(8, 20, 94, 85);
   rgb_matrix_set_color(9, 20, 94, 85);
   rgb_matrix_set_color(10, 20, 94, 85);
   rgb_matrix_set_color(11, 20, 94, 85);
   rgb_matrix_set_color(12, 20, 94, 85);
   rgb_matrix_set_color(13, 20, 94, 85);
   // rgb_matrix_set_color(14, 20, 94, 85);
   // rgb_matrix_set_color(15, 20, 94, 85);
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
   // rgb_matrix_set_color(28, 90, 42, 67);
   // rgb_matrix_set_color(29, 66, 45, 87);
   rgb_matrix_set_color(30, 66, 45, 87);
   rgb_matrix_set_color(31, 49, 54, 95);
   rgb_matrix_set_color(32, 66, 45, 87);
   rgb_matrix_set_color(33, 66, 45, 87);
   // rgb_matrix_set_color(34, 20, 94, 85);
   rgb_matrix_set_color(35, 20, 94, 85);
   // rgb_matrix_set_color(36, 20, 94, 85);
   // rgb_matrix_set_color(37, 20, 94, 85);
   rgb_matrix_set_color(38, 20, 94, 85);
   // rgb_matrix_set_color(39, 20, 94, 85);
   // rgb_matrix_set_color(40, 20, 94, 85);
   rgb_matrix_set_color(41, 20, 94, 85);
   // rgb_matrix_set_color(42, 20, 94, 85);
   rgb_matrix_set_color(43, 20, 94, 85);
   rgb_matrix_set_color(44, 20, 94, 85);
   rgb_matrix_set_color(45, 20, 94, 85);
   rgb_matrix_set_color(46, 20, 94, 85);
   rgb_matrix_set_color(47, 20, 94, 85);
   // rgb_matrix_set_color(48, 20, 94, 85);
   // rgb_matrix_set_color(49, 20, 94, 85);
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
   // rgb_matrix_set_color(61, 90, 42, 67);
   // rgb_matrix_set_color(62, 90, 42, 67);
   rgb_matrix_set_color(63, 66, 45, 87);
   rgb_matrix_set_color(64, 66, 45, 87);
   rgb_matrix_set_color(65, 49, 54, 95);
   rgb_matrix_set_color(66, 66, 45, 87);
   // rgb_matrix_set_color(67, 66, 45, 87);
   rgb_matrix_set_color(67, 0, 0, 0);
   return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record, uint16_t prev_keycode) {
   if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
      switch (keycode) {
         case LSFT_T(KC_A): return 75;
         case RSFT_T(KC_SCLN): return 75;
         default: return 200;
      }
   }
   return 0;
}

