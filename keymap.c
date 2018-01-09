// Nordic layout for Ergodox EZ

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_nordic.h"
#include "keymap_german.h"

// Layer names
#define BASE 0 // default layer
#define SYMB 1 // function layer
#define FUNCL 2 // symbol layer
#define MDIA 3 // media keys

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

#undef DEBOUNCE
#define DEBOUNCE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L2  |           |  L2  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  L1  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  -   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  |  <|> |  ¨^  | Alt | LGui|                                       | Ctrl |  Alt  |   '  |  ¨^  |  L1   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LEFT |RIGHT |       | DOWN | UP   |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Enter| Del  |------|       |------|  BSpc  | Spc  |
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,    KC_1,             KC_2,             KC_3,     KC_4,     KC_5,   _______,
        KC_TAB,    KC_Q,             KC_W,             KC_E,     KC_R,     KC_T,   MO(2),
        KC_CAPS,   KC_A,             KC_S,             KC_D,     KC_F,     KC_G,
        KC_LSFT,   KC_Z,             KC_X,             KC_C,     KC_V,     KC_B,   MO(1),
        MO(1),     KC_NONUS_BSLASH,  KC_RBRC,          KC_LALT,  KC_LGUI,

                                                       KC_LEFT, KC_RIGHT,
                                                                KC_HOME,
                                               KC_ENT, KC_DELT, KC_END,
        // right hand
        _______,     KC_6,   KC_7,      KC_8,     KC_9,     KC_0,        _______,
        MO(2),       KC_Y,   KC_U,      KC_I,     KC_O,     KC_P,        KC_LBRC,
                     KC_H,   KC_J,      KC_K,     KC_L,     KC_SCLN,     KC_QUOT,
        MO(1),       KC_N,   KC_M,      KC_COMM,  KC_DOT,   KC_SLSH,     KC_RSFT,
                             KC_RCTRL,  KC_RALT,  KC_BSLS,  KC_RBRC,     MO(1),
        KC_DOWN, KC_UP,
        KC_PGUP,
        KC_PGDN, KC_BSPC, KC_SPC
    ),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   ?  |   +  |   `  | SH(`)|      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   <  |   )  |   =  |   >  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   [  |   §  |   |  |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| BLTOG|       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|  BL+ |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |  BL- |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
 * Keymap 1: Symbol Layer (Dvorak translation)
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  {   |   [  |   ]  |   }  |      |           |      |   Up |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  <   |   (  |   )  |   >  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   `  |   ~  |  |   |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat| BLTOG|       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|  BL+ |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |  BL- |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,   KC_F1,    KC_F2,         KC_F3,           KC_F4,          KC_F5,           KC_F6,
       _______,   _______,  NO_QUES,       NO_PLUS,         NO_ACUT,        LSFT(NO_GRV),    _______,
       _______,   _______,  NO_LESS,       NO_RPRN,         NO_EQL,         NO_GRTR,
       _______,   _______,  _______,       KC_GRV,          LSFT(KC_GRV),   ALGR(NO_LESS),          _______,
       _______,   _______,  _______,       _______,         _______,

                                       RGB_MOD,BL_TOGG,
                                               BL_INC,
                               RGB_VAD,RGB_VAI,BL_DEC,
       // right hand
       _______, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_UP,   KC_7,   KC_8,    KC_9,    DE_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    DE_PLUS, _______,
       _______, DE_AMPR, KC_1,   KC_2,    KC_3,    DE_BSLS, _______,
                         _______,KC_DOT,  KC_0,    DE_EQL,  _______,
       RGB_TOG, RGB_SLD,
       _______,
       _______, RGB_HUD, RGB_HUI
),

/* Keymap 2: Basic layer with functions
 *
 *
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |  F11 |           | F12 |  F6  |  F7  |  F8  |  F9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  L2  |           |  L2  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  -   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  ¨^  |  <|>  | Alt | LGui|                                       | Ctrl |  Alt  |  ´`  |   +  | RGui |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LEFT |RIGHT |       | DOWN | UP   |
 *                                 ,------+------+------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Del   |------|       |------|  Enter | Bkspc|
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[FUNCL] = LAYOUT_ergodox(  // layer 1 : functions
  // left hand
  _______,  KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F11,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,
                                         _______, _______,
                                                        _______,
                                         _______,_______,_______,
  // right hand
  KC_F12,  KC_F6,   KC_F7,    KC_F8,    KC_F9,   KC_F10,     _______,
  _______,    _______,  _______,  _______,  _______,  _______,  _______,
  _______,  _______,  _______,  _______,  _______,  _______,
  _______,    _______,  _______,  _______,  _______,  _______,  _______,
                      _______,  _______,  _______,  _______,  _______,
  _______, _______,
  _______,
  _______, _______, _______
),

/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |VolDwn| Mute |VolUp |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Btn4 |MsLeft|MsDown|MsRght| Btn5 |------|           |------|      | Prev | Stop | Play | Next |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |WhRght|WhDown| WhUp |WhLeft|WhClk |      |           |      |BwSrch|BwBack|BwHome|BwRefr|BwFwd |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |MsAcl0|MsAcl1|MsAcl2|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------|Back  |Forwd |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RESET, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,
       _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
       _______, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN5,
       _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN3, _______,
       _______, _______, KC_ACL0, KC_ACL1, KC_ACL2,
                                           _______, _______,
                                                    _______,
                                  KC_BTN1, KC_BTN2, _______,
    // right hand
       _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
       _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, KC_F12,
                _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______,
       _______, KC_WSCH, KC_WBAK, KC_WHOM, KC_WREF, KC_WFWD, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, KC_WBAK, KC_WFWD
),
};

const uint16_t PROGMEM fn_actions[] = {
    [2] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 2 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}  

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    
    uint8_t layer = biton32(layer_state);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }   
};
