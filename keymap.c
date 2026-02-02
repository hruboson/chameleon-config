// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
     * │  Esc │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │  Del │
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * │  Tab │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │ Bksp │
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * │  Esc │   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * │ Shft │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │ Ent  │
     * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
     * │ AltGr│ CTRL │  ALT │  Win │ Lower│ Space│ Space│ Raise│   ←  │   ↓  │   ↑  │  →   │
     * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
     */
    [_QWERTY] = LAYOUT_ortho_5x12(
        QK_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,
        KC_LGUI,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
        MO(_LOWER), KC_LCTL,    KC_LGUI,    KC_LALT,    KC_ENT,     KC_ENT,     KC_SPC,     KC_SPC,      KC_RALT,    KC_LGUI,   KC_RCTL,    MO(_RAISE)
    ),
    [_RAISE] = LAYOUT_ortho_5x12(
        KC_GRV,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,
        XXXXXXX,    KC_HOME,    KC_UP,   KC_END,   XXXXXXX,    _______,    _______,    _______,    _______,    _______,    KC_PSCR,    KC_F11,
        XXXXXXX,    KC_LEFT,    KC_DOWN, KC_RIGHT, XXXXXXX,    _______,    _______,    _______,    _______,    _______,    _______,    KC_F12,
        _______,    _______,    _______, _______,  _______,    _______,    _______,    _______,    KC_MUTE,    KC_MPLY,    KC_MPRV,    KC_MNXT,
        _______,    _______,    _______, _______,  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_LOWER] = LAYOUT_ortho_5x12(
        KC_NUHS,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    MS_BTN3,    _______,    KC_MINS,    KC_EQL,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    MS_BTN1,    MS_UP,      MS_BTN2,    MS_WHLU,    MS_ACL0,
        KC_CAPS,    _______,    _______,    _______,    _______,    _______,    _______,    MS_LEFT,    MS_DOWN,    MS_RGHT,    MS_WHLD,    MS_ACL1,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    MS_ACL2,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
    [_ADJUST] = LAYOUT_ortho_5x12(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [2] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [3] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  }
};
#endif
