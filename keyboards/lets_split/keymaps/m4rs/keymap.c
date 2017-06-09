#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3
#define _SRAISE 4
#define _SPACE_FN 5
#define _SPACE_FN_ALT 6
#define _FN 7
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  SRAISE,
  SPACE_FN,
  FN,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define W_CLOSE  LCTL(KC_W) // C-w Close
#define W_CUT    LCTL(KC_X) // C-x Cut
#define W_COPY   LCTL(KC_C) // C-c Copy
#define W_PASTE  LCTL(KC_V) // C-v Paste
#define W_UNDO   LCTL(KC_Z) // C-z Undo
#define W_REDO   LCTL(KC_Y) // C-y Redo
#define W_FIND   LCTL(KC_F) // C-v Find

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),


/* Dvorak m4rs
 * ┌────────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │Tab     │   "  │   ,  │   .  │   P  │   Y  ║   F  │   G  │   C  │   R  │   L  │Bksp  │
 * ├────────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │Ctrl/Esc│   A  │   O  │   E  │   U  │   I  ║   D  │   H  │   T  │   N  │   S  │Enter │
 * ├────────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │Shift   │   ;  │   Q  │   J  │   K  │   X  ║   B  │   M  │   W  │   V  │   Z  │Shft /│
 * ├────────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │Esc     │  Fn  │ GUI  │ Alt  │Lower │SpceFn║SpceFn│Raise │ Left │ Down │  Up  │Right │
 * └────────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
/*[_DVORAK] = {*/
  /*{KC_TAB,                                KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPC},*/
  /*{ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,  KC_ENT},*/
  /*{KC_LSFT,                               KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,  ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SLSH) },*/
  /*{KC_RCTL,                               KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}*/
/*},*/
[_DVORAK] = KEYMAP( \
  KC_TAB,        KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,        KC_F,    KC_G,        KC_C,    KC_R,  KC_L,    KC_BSPC,        \
  CTL_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,  KC_I,        KC_D,    KC_H,        KC_T,    KC_N,  KC_S,    KC_ENT,         \
  KC_LSFT,       KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,        KC_B,    KC_M,        KC_W,    KC_V,  KC_Z,    SFT_T(KC_SLSH), \
  KC_ESC,        FN,      KC_LGUI, KC_LALT, LOWER, LT(SPACE_FN, KC_SPC), LT(SPACE_FN, KC_SPC), RAISE, KC_LEFT, KC_DOWN,        KC_UP, KC_RGHT \
),

/* Lower m4rs
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │   ~  │   !  │   @  │   #  │   $  │   %  ║   ^  │   &  │   *  │ - _  │ = +  │ Del  │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   -  │   _  │   ?  │   =  │   +  ║      │   (  │   )  │   {  │   }  │  │   │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │Close │ Undo │ Cut  │ Copy │Paste ║      │   «  │   »  │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │ ▒▒▒▒ │             │      │C(Hom)│C(PUp)│C(PDn)│C(End)│
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,       KC_MINS,       KC_EQL,        KC_DEL, \
  _______, KC_MINS, KC_UNDS, KC_QUES, KC_EQL,  KC_PLUS, _______, KC_LPRN,    KC_RPRN,       KC_LCBR,       KC_RCBR,       KC_PIPE, \
  _______, W_CLOSE, W_UNDO,  W_CUT,   W_COPY,  W_PASTE, _______, UC(0x00ab), UC(0x00bb),    _______,       _______,       _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,    LCTL(KC_HOME), LCTL(KC_PGUP), LCTL(KC_PGDN), LCTL(KC_END) \
),

/* Raise m4rs avec unicode directement, si ça marche on peut se servir d'un mapping qwerty
 * pour l'os plutôt que qwerty international ce qui symplifie plein de choses
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │   ä  │   ê  │   ë  │   ü  │      ║Macel0│Mbtn1 │Mup   │Mbtn3 │MWup  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   à  │   ô  │   é  │   û  │   î  ║Macel1│Mleft │MDown │Mright│MWdn  │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │SRAISE│   â  │   ö  │   è  │   ù  │   ï  ║Macel2│Mbtn4 │Mbtn2 │Mbtn5 │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │ ▒▒▒▒ │ Home │ PgUp │ PgDn │ End  │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_RAISE] = KEYMAP( \
  _______,  UC(0x00e4), UC(0x00ea), UC(0x00eb), UC(0x00fc), _______,    KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN3, KC_WH_U, _______, \
  _______,  UC(0x00e0), UC(0x00f4), UC(0x00e9), UC(0x00fb), UC(0x00ee), KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, \
  SRAISE,   UC(0x00e2), UC(0x00f6), UC(0x00e8), UC(0x00f9), UC(0x00ef), KC_ACL2, KC_BTN4, KC_BTN1, KC_BTN5, _______, _______, \
  _______,  _______,    _______,    _______,    _______,    _______,    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END \
),
/* Raise m4rs avec unicode shifté
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │   Ä  │   Ê  │   Ë  │   Ü  │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   À  │   Ô  │   É  │   Û  │   Î  ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │ ▒▒▒▒ │   Â  │   Ö  │   È  │   Ù  │   Ï  ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │ ▒▒▒▒ │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_SRAISE] = KEYMAP( \
  _______, UC(0x00c4), UC(0x00ca), UC(0x00cb), UC(0x00dc), _______,    KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN3, KC_WH_U, _______, \
  _______, UC(0x00c0), UC(0x00d4), UC(0x00c9), UC(0x00db), UC(0x00ce), KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, \
  _______, UC(0x00c2), UC(0x00d6), UC(0x00c8), UC(0x00d9), UC(0x00cf), KC_ACL2, KC_BTN4, KC_BTN1, KC_BTN5, _______, _______, \
  _______, _______,    _______,    _______,    _______,    _______,    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END \
),

/* Space Fn
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │ PgUp │ Home │   ↑  │  End │   A  ║   B  │   7  │   8  │   9  │   /  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ PgDn │   ←  │   ↓  │   →  │   C  ║   D  │   4  │   5  │   6  │   *  │Enter │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │      │WWWBAK│WWWREF│WWWFWD│   E  ║   F  │   1  │   2  │   3  │   +  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │ ▒▒▒▒▒▒▒▒▒▒▒ │   0  │   .  │   =  │   -  │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_SPACE_FN] = KEYMAP( \
  _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,   S(KC_A), S(KC_B), KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, _______, \
  _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, S(KC_C), S(KC_D), KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_PENT, \
  _______, _______, KC_WBAK, KC_WREF, KC_WFWD,  S(KC_E), S(KC_F), KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, _______, \
  _______, _______, _______, _______, _______,  _______, _______, KC_KP_0, KC_PDOT, KC_PEQL, KC_PMNS, _______ \
),

/* Space Fn alternatif
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │   /  │   1  │   2  │   3  │   A  ║   B  │ Home │   ↑  │  End │ PgUp │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   *  │   4  │   5  │   6  │   C  ║   D  │   ←  │   ↓  │   →  │ PgDn │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │   +  │   7  │   8  │   9  │   E  ║   F  │WWWbak│WWWref│WWWfwd│      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │   ─  │   0  │   .  │   =  │ ▒▒▒▒▒▒▒▒▒▒▒ │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_SPACE_FN_ALT] = KEYMAP( \
  _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, KC_PGUP, KC_HOME, KC_UP,   KC_END,   S(KC_A), S(KC_B), _______, \
  _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, S(KC_C), S(KC_D), KC_PENT, \
  _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, KC_WBAK, KC_WREF, KC_WFWD,  S(KC_E), S(KC_F), _______, \
  _______, KC_KP_0, KC_PDOT, KC_PEQL, KC_PMNS, _______, _______, _______, _______,  _______, _______, _______ \
),

/* Fn m4rs : RCtrl assigné à compose sous linux
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  F1  │  F2  │  F3  │  F4  │      ║      │MPrev │MPlay │MNext │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │CapsL │  F5  │  F6  │  F7  │  F8  │      ║      │ Mute │ Vol+ │ Vol- │      │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │RCtrl │  F9  │  F10 │  F11 │  F12 │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │ ▒▒▒▒ │      │      │      │             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_FN] = KEYMAP( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, \
  KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, \
  KC_RCTL, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
#endif

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case SRAISE:
      if (record->event.pressed) {
        layer_on(_SRAISE);
      } else {
        layer_off(_SRAISE);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
