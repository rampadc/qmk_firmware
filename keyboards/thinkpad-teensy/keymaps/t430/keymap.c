/* Copyright 2019 Cong Nguyen
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


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    { /* Base */
        {KC_GRAVE,KC_F1,KC_F2,KC_5,KC_6,KC_EQUAL,KC_F8,KC_MINUS,KC_F9,KC_NO,KC_HOME,KC_DELETE,KC_NO,KC_NO,KC_NO,KC_LCTRL},
        {KC_1,KC_2,KC_3,KC_4,KC_7,KC_8,KC_9,KC_0,KC_F10,KC_F12,KC_F11,KC_INSERT,KC_END,KC_NO,KC_NO,KC_NO},
        {KC_Q,KC_W,KC_E,KC_R,KC_U,KC_I,KC_O,KC_P,KC_NO,KC_NO,KC_AUDIO_VOL_UP,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO},
        {KC_TAB,KC_CAPSLOCK,KC_F3,KC_T,KC_Y,KC_RBRACKET,KC_F7,KC_LBRACKET,KC_BSPACE,KC_LGUI,KC_AUDIO_VOL_DOWN,KC_NO,KC_NO,KC_NO,KC_LSHIFT,KC_NO},
        {KC_A,KC_S,KC_D,KC_F,KC_J,KC_K,KC_L,KC_SCOLON,KC_BSLASH,KC_NO,KC_AUDIO_MUTE,KC_PSCREEN,KC_NO,KC_NO,KC_NO,KC_NO},
        {KC_ESCAPE,KC_NO,KC_F4,KC_G,KC_H,KC_F6,KC_NO,KC_QUOTE,KC_F5,KC_NO,KC_NO,KC_NO,KC_UP,KC_LALT,KC_NO,KC_NO},
        {KC_Z,KC_X,KC_C,KC_V,KC_M,KC_COMMA,KC_DOT,KC_NO,KC_ENTER,KC_NO,91,KC_PGUP,KC_NO,KC_NO,KC_RSHIFT,KC_NO},
        {KC_NO,KC_NO,KC_NO,KC_B,KC_N,KC_NO,KC_NO,KC_SLASH,KC_SPACE,KC_RIGHT,KC_DOWN,KC_PGDOWN,KC_LEFT,KC_RALT,KC_NO,KC_RCTRL}
    },
    // FN Layer
	{
		{KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_SYSTEM_WAKE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_SYSTEM_SLEEP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS},
		{KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, BL_STEP,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS}
	}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

bool is_FN_pressed(void) {
  if (PINE & (1 << 1)) {
    return true;
  }
  return false;
}

void matrix_init_user(void) {
  // FN input active-low
  DDRE &= ~(1 << 1);
  PORTE |= (1 << 1);
}

void matrix_scan_user(void) {
  if (is_FN_pressed()) {
    layer_on(1);
  } else {
    layer_off(1);
  }
}

void led_set_user(uint8_t usb_led) {

}
