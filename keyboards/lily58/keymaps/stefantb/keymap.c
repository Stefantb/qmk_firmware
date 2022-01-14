#include QMK_KEYBOARD_H
#include "keymap_icelandic.h"
#include <stdio.h>

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
enum layer_number
{
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
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

// rulers
//                           ,        ,        ,        ,        ,        ,        ,        ,
//,        ,        ,        ,        ,        ,        ,--------,--------,        ,        ,        ,        ,        ,

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1!  |  2"  |  3#  |  4$  |  5%  |                    |  6&  | 7/ { | 8( [ | 9) ] | 0= } | Ö \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  Q@  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Ð   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Æ  | '^´  |
 * |------+------+------+------+------+------|       |    |  del  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |   Þ  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_QWERTY] = LAYOUT(
   KC_ESC  ,IS_1    ,IS_2    ,IS_3    ,IS_4    ,IS_5                      ,IS_6    ,IS_7    ,IS_8    ,IS_9    ,IS_0    ,IS_ODIA
  ,KC_TAB  ,IS_Q    ,IS_W    ,IS_E    ,IS_R    ,IS_T                      ,IS_Y    ,IS_U    ,IS_I    ,IS_O    ,IS_P    ,IS_ETH
  ,KC_LCTRL,IS_A    ,IS_S    ,IS_D    ,IS_F    ,IS_G                      ,IS_H    ,IS_J    ,IS_K    ,IS_L    ,IS_AE   ,IS_ACUT
  ,KC_LSFT ,IS_Z    ,IS_X    ,IS_C    ,IS_V    ,IS_B    ,XXXXXXX ,KC_DEL  ,IS_N    ,IS_M    ,IS_COMM ,IS_DOT  ,IS_THRN ,KC_RSFT
                             ,KC_LALT ,KC_LGUI ,MLOWER  ,KC_SPC  ,KC_ENT  ,MRAISE  ,KC_BSPC ,KC_RALT
  ),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   |  |   {  |   }  |   _  |   ?  | pgup |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   °  |      |      |      |      |      |-------.    ,-------|   <  |   (  |   )  |   +  |   -  | pgdn |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   >  |   [  |   ]  |   *  | home | end  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_LOWER] = LAYOUT(
   KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6                     ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,IS_PIPE ,IS_LCBR ,IS_RCBR ,IS_UNDS ,IS_QUES ,KC_PGUP
  ,IS_RNGA ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,IS_LABK ,IS_LPRN ,IS_RPRN ,IS_PLUS ,IS_MINS ,KC_PGDN
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,IS_RABK ,IS_LBRC ,IS_RBRC ,IS_ASTR ,KC_HOME ,KC_END
                             ,_______ ,_______ ,_______ ,_______ ,_______ ,TRAISE  ,_______ ,_______
  ),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | `    |  '   |  ~   |-------.    ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      | pscr | ins  |-------|    |-------| mute | vold | volu |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_RAISE] = LAYOUT(
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ,KC_CAPS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ,_______ ,XXXXXXX ,XXXXXXX ,IS_GRV  ,IS_QUOT ,IS_TILD                   ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PSCR ,KC_INS  ,XXXXXXX ,XXXXXXX ,KS_MUTE ,KS_VOLD ,KS_VOLU ,KS_TCHT ,XXXXXXX ,XXXXXXX
                             ,_______ ,_______ ,TQWERTY ,_______ ,_______ ,TADJUST ,_______ ,_______
  ),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |  -   |  7   |  8   |  9   |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|  =   |  4   |  5   |  6   |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|  0   |  1   |  2   |  3   |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,IS_MINS ,IS_7    ,IS_8    ,IS_9    ,IS_SLSH ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX                   ,IS_EQL  ,IS_4    ,IS_5    ,IS_6    ,IS_ASTR ,XXXXXXX
  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,IS_0    ,IS_1    ,IS_2    ,IS_3    ,IS_PLUS ,XXXXXXX
                             ,_______ ,_______ ,TQWERTY ,_______ ,_______ ,TQWERTY ,_______ ,_______
  )
};
// clang-format on

#ifdef OLED_ENABLE
//*****************************************************************************
// Rendering is done in vertical orientation.
//
// With a 6x8 font (width x height) and 32x128 screen,
// we have 5 colums and 16 lines.
//*****************************************************************************

#include "glyphs.h"

//*****************************************************************************
// We want the vertical orientation.
//*****************************************************************************
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    if (!is_keyboard_master())
    {
        return OLED_ROTATION_270;
    }
    else
    {
        return OLED_ROTATION_270;
    }
    return rotation;
}

//*****************************************************************************
// The understanding is that layer_state is a bitmask for active
// layers. This function searches down towards the base layer
// for an active layer and returns the bit position.
//
// There can be more than one layer active at the same time.
//
//*****************************************************************************
int find_active_top_layer(void)
{
    // when the board has just been started, it seems layer_state
    // has not been initialized so lets
    if (layer_state == 0)
    {
        return 0;
    }

    // search the first five layers.
    for (int i = 4; i >= 0; --i)
    {
        if (layer_state >> i && 0x1)
        {
            return i;
        }
    }

    // no active layer in our range
    return -1;
}

//*****************************************************************************
//
//*****************************************************************************
static int initial_render = 0;
void       render_layer(void)
{
    if (initial_render < 2)
    {
        if (layer_state != 0)
        {
            initial_render = 2;
            oled_clear();
        }

        if (initial_render == 0)
        {
            oled_write_raw_P(hacker, sizeof(hacker));
            initial_render = 1;
        }
        return;
    }

    int state = find_active_top_layer();
    switch (state)
    {
    case 0: oled_write_raw_P(one, sizeof(one)); break;
    case 1: oled_write_raw_P(two, sizeof(two)); break;
    case 2: oled_write_raw_P(three, sizeof(three)); break;
    case 3: oled_write_raw_P(four, sizeof(four)); break;
    case 4: oled_write_raw_P(five, sizeof(five)); break;
    case 5: break;
    default: break;
    }
    oled_set_cursor(0, 4);
}

//*****************************************************************************
//
//*****************************************************************************
static char layer_state_str[24];

bool oled_task_user(void)
{
    // If you want to change the display of OLED, you need to change here
    render_layer();

    if (layer_state < 2)
    {
        return false;
    }

    if (is_keyboard_master())
    {
        oled_write_ln("_____", false);

        // Put the actual number on the last line, just for observation.
        oled_set_cursor(0, 15);
        snprintf(layer_state_str, sizeof(layer_state_str), "L: %lu", layer_state);
        oled_write_ln(layer_state_str, false);

        // oled_write_ln(read_layer_state(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
        // oled_write_raw_P(hacker, sizeof(hacker));
        // oled_write_raw_P(one, sizeof(one));
        // oled_write_ln(read_layer_state(), false);
    }
    else
    {
        oled_set_cursor(0, 12);
        if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK))
        {
            oled_write_ln("CAPS", false);
        }
        else
        {
            oled_write_ln("   ", false);
        }
        // oled_write_ln(read_layer_state(), false);
        // oled_write(read_logo(), false);
    }

    // TODO figure out what this return means.
    return false;
}

#endif // OLED_ENABLE

//*****************************************************************************
//
//*****************************************************************************

// layer_state_t layer_state_set_user(layer_state_t state)
// {
//     // return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//     return state;
// }

// When you add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
// const char *read_logo(void);
// void set_keylog(uint16_t keycode, keyrecord_t *record);
// const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   if (record->event.pressed) {
//
// #ifdef OLED_ENABLE
//     // set_keylog(keycode, record);
// #endif
//
//     // set_timelog();
//   }
//   return true;
//
