/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

static const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  {
    {KC_Q, KC_W, KC_E, KC_R, KC_T,                 KC_NO,    KC_Y, KC_U, KC_I, KC_O, KC_P},
    {KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_NO,    KC_H, KC_J, KC_K, KC_L, KC_SCOLON },
    {KC_Z, KC_X, KC_C, KC_V, KC_B,                 KC_A,  KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH},
    {KC_ESCAPE, KC_TAB, KC_INSERT, KC_LSHIFT, KC_BSPACE, KC_B,  KC_SPACE, KC_MINUS, KC_EQUAL, KC_LBRACKET, KC_RBRACKET}
  },
};  // to test: KC_CAPS, KT_BTLD, KC_A

static const action_t fn_actions[] = {
};

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    return keymaps[(layer)][(key.row)][(key.col)];
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    return fn_actions[FN_INDEX(keycode)];
}
