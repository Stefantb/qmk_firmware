#include QMK_KEYBOARD_H
#include "keymap_icelandic.h"

//*****************************************************************************
//
//*****************************************************************************
#define KS_MUTE KC__MUTE
#define KS_VOLU KC__VOLUP
#define KS_VOLD KC__VOLDOWN
// toggle touchpad
#define KS_TCHT KC_F21

//*****************************************************************************
//
//*****************************************************************************
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    // _ARROWS,
    // _SYMBOLS,
    // _NUMBERS,
    // _MEDIA,
};

#define MRAISE MO(_RAISE)
#define MLOWER MO(_LOWER)

#define TQWERTY MO(_QWERTY)
#define TLOWER MO(_LOWER)
#define TRAISE MO(_RAISE)
#define TADJUST MO(_ADJUST)

//*****************************************************************************
//
//*****************************************************************************
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     // KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_GRAVE,
     // KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
     // KC_BSPC, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     // KC_LSFT, CTL_T(KC_Z)  , KC_X  , KC_C  , KC_V  , KC_B  ,                  KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_BSLASH,
     //                  KC_LALT,KC_LCTRL,                                                       KC_DEL, KC_PMNS,
     //                                  KC_SPC, MO(_ARROWS),                          MO(_MOUSE), KC_ENT,
     //                                  KC_LCMD, MO(_SYMBOLS),                        KC_EQL, KC_RALT,
     //                                  KC_LALT, MO(_NUMBERS),                        MO(_MEDIA), KC_EJCT

// QWERTY
//    .-----------------------------------------.                    .-----------------------------------------.
//    | ESC  |  1!  |  2"  |  3#  |  4$  |  5%  |                    |  6&  | 7/ { | 8( [ | 9) ] | 0= } | Ö \  |
//    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//    | Tab  |  Q@  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Ð   |
//    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//    |LCTRL |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   Æ  | '^´  |
//    |------+------+------+------+------+------|                    |------+------+------+------+------+------|
//    |LShift|   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |  ,;  |  .:  |   Þ  |RShift|
//    '-----------------------------------------'                    '-----------------------------------------'
//                      | LAlt | LGUI |                                         | RAlt | LGUI |
//                      '------------------------.                   .------------------------'
//                                |      |      |                    |      |      |
//                                '--------------------.      .--------------------'
//                                       |   E  |   R  |      |   E  |   R  |
//                                       +------+------+      +------+------+
//                                       |   D  |   F  |      |   D  |   F  |
//                                       +------+------+      +------+------+

  [_QWERTY] = LAYOUT_5x6(
//,        ,        ,        ,        ,        ,              ,        ,        ,        ,        ,        ,
   KC_ESC  ,IS_1    ,IS_2    ,IS_3    ,IS_4    ,IS_5          ,IS_6    ,IS_7    ,IS_8    ,IS_9    ,IS_0    ,IS_ODIA
  ,KC_TAB  ,IS_Q    ,IS_W    ,IS_E    ,IS_R    ,IS_T          ,IS_Y    ,IS_U    ,IS_I    ,IS_O    ,IS_P    ,IS_ETH
  ,KC_LCTRL,IS_A    ,IS_S    ,IS_D    ,IS_F    ,IS_G          ,IS_H    ,IS_J    ,IS_K    ,IS_L    ,IS_AE   ,IS_ACUT
  ,KC_LSFT ,IS_Z    ,IS_X    ,IS_C    ,IS_V    ,IS_B          ,IS_N    ,IS_M    ,IS_COMM ,IS_DOT  ,IS_THRN ,KC_RSFT
                         ,_______ ,KC_LALT                                  ,KC_RALT ,_______
                                      ,KC_LGUI ,MLOWER        ,MRAISE  ,KC_BSPC
                                      ,_______ ,KC_SPC        ,KC_ENT  ,_______
                                      ,_______ ,_______       ,KC_DEL  ,_______
  ),

  [_LOWER] = LAYOUT_5x6(
   KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6       ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,IS_PIPE ,IS_LCBR ,IS_RCBR ,IS_UNDS ,IS_QUES ,KC_PGUP
  ,IS_RNGA ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,IS_LABK ,IS_LPRN ,IS_RPRN ,IS_PLUS ,IS_MINS ,KC_PGDN
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,IS_RABK ,IS_LBRC ,IS_RBRC ,IS_ASTR ,KC_HOME ,KC_END
                         ,_______ ,_______                                ,_______ ,_______
                                      ,_______ ,_______     ,TRAISE  ,_______
                                      ,_______ ,_______     ,_______ ,_______
                                      ,_______ ,_______     ,_______ ,_______
  ),

  [_RAISE] = LAYOUT_5x6(
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ,KC_CAPS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ,_______ ,XXXXXXX ,XXXXXXX ,IS_GRV  ,IS_QUOT ,IS_TILD     ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PSCR ,KC_INS      ,KS_MUTE ,KS_VOLD ,KS_VOLU ,KS_TCHT ,XXXXXXX ,XXXXXXX
                         ,_______ ,_______                                ,_______ ,_______
                                      ,_______ ,TQWERTY     ,TADJUST ,_______
                                      ,_______ ,_______     ,_______ ,_______
                                      ,_______ ,_______     ,_______ ,_______
  ),

  [_ADJUST] = LAYOUT_5x6(
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,IS_MINS ,IS_7    ,IS_8    ,IS_9    ,IS_SLSH ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,IS_EQL  ,IS_4    ,IS_5    ,IS_6    ,IS_ASTR ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX     ,IS_0    ,IS_1    ,IS_2    ,IS_3    ,IS_PLUS ,XXXXXXX
                         ,_______ ,_______                                ,_______ ,_______
                                      ,_______ ,TQWERTY     ,TQWERTY ,_______
                                      ,_______ ,_______     ,_______ ,_______
                                      ,_______ ,_______     ,_______ ,_______
  ),

  // [_ARROWS] = LAYOUT_5x6(
  //
  //                  RESET,_______, _______ ,_______,_______ ,TG(_WINDOWS),                        _______,_______,_______,_______,_______,_______,
  //                  _______,_______,_______,_______,_______,_______,                        _______, KC_HOME , KC_UP , KC_END ,_______,_______,
  //                  _______,_______,_______,_______,_______ ,_______,                        KC_HOME, KC_LEFT , KC_DOWN , KC_RIGHT ,KC_END,_______,
  //                  _______,_______,_______,_______,_______,_______,                        _______, KC_PGDOWN , _______ , KC_PGUP ,_______ ,_______,
  //                                       RESET,_______,                                                       _______, _______,
  //                                                          _______,_______,            _______,_______,
  //                                                          _______,_______,            _______,_______,
  //                                                          _______,_______,            _______,_______
  //
  //               ),
  // [_SYMBOLS] = LAYOUT_5x6(
  //
  //                   _______,_______, _______ ,_______,_______ ,_______,                        KC_CIRC,KC_CIRC,KC_LABK,KC_RABK,_______,_______,
  //                   _______,_______,_______,_______,_______,_______,                        KC_LABK, KC_AT , KC_LCBR , KC_RCBR ,KC_HASH,KC_RABK,
  //                   _______,_______,_______,_______,_______ ,_______,                        KC_PERC, KC_EQL , KC_LPRN , KC_RPRN ,KC_DLR,KC_AMPR,
  //                   _______,_______,_______,_______,_______,_______,                        KC_TILD, KC_GRAVE , KC_LBRC , KC_RBRC ,KC_PIPE ,KC_EXLM,
  //                                        _______,_______,                                                       KC_PPLS, KC_PMNS,
  //                                                           _______,_______,            _______,_______,
  //                                                           _______,_______,            _______,_______,
  //                                                           _______,_______,            _______,_______
  //
  //                ),
  // [_NUMBERS] = LAYOUT_5x6(
  //
  //                   RESET,_______, _______ ,_______,_______ ,_______,                        KC_PSLS,KC_PAST,KC_PPLS,KC_PMNS,_______,_______,
  //                   _______,_______,_______,KC_PSLS,KC_PAST,_______,                        _______, KC_7 , KC_8 , KC_9 ,_______,_______,
  //                   _______,_______,_______,KC_PMNS,KC_PPLS ,_______,                        _______, KC_4 , KC_5 , KC_6 ,_______,_______,
  //                   _______,_______,_______,_______,_______,_______,                        _______, KC_1 , KC_2 , KC_3 ,_______ ,_______,
  //                                        _______,_______,                                                       KC_0, KC_DOT,
  //                                                           _______,_______,            _______,_______,
  //                                                           _______,_______,            _______,_______,
  //                                                           _______,_______,            _______,_______
  //
  //                ),
  // [_MEDIA] = LAYOUT_5x6(
  //
  //                 KC_MSTP,KC_MPRV, KC_MPLY ,KC_MNXT,_______ ,_______,                        _______,_______,_______,_______,_______,_______,
  //                 _______,_______,_______,_______,KC_VOLU,_______,                        RGB_SPI, _______ , _______ , _______ ,_______,_______,
  //                 _______,_______,_______,_______,KC_VOLD ,_______,                        RGB_TOG, RGB_MODE_FORWARD , RGB_HUI , RGB_SAI ,RGB_VAI,_______,
  //                 _______,_______,_______,_______,KC_MUTE,_______,                        RGB_SPD, RGB_MODE_REVERSE , RGB_HUD , RGB_SAD ,RGB_VAD ,_______,
  //                                      _______,_______,                                                       _______, _______,
  //                                                         _______,_______,            _______,_______,
  //                                                         _______,_______,            _______,_______,
  //                                                         _______,_______,            _______,_______
  //
  //              ),
};
// clang-format on

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    oled_write_ln("hello", false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    // oled_write(read_logo(), false);
    oled_write_ln("hello", false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}



