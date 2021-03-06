// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _DVORAK_M,
  _DVORAK_J,
  _LOWER_M,
  _RAISE_M,
  _SRAISE_M,
  _LOWER_J,
  _RAISE_J,
  _SPACE_FN_M,
  _SPACE_FN_M_ALT,
  _SPACE_FN_J,
  _FN_M,
  _FN_J,
  _NUMLOCK,
  _ADJUST
};

enum planck_keycodes {
  DVORAK_M = SAFE_RANGE,
  DVORAK_J,
  LOWER_M,
  RAISE_M,
  SRAISE_M,
  LOWER_J,
  RAISE_J,
  SPACE_FN_J,
  SPACE_FN_M,
  FN_J,
  FN_M,
  NUMLOCK,
  BACKLIT,
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

#define A_CLOSE  LGUI(KC_W) // Pomme-w Close
#define A_CUT    LGUI(KC_X) // Pomme-x Cut
#define A_COPY   LGUI(KC_C) // Pomme-c Copy
#define A_PASTE  LGUI(KC_V) // Pomme-v Paste
#define A_UNDO   LGUI(KC_Z) // Pomme-z Undo
#define A_REDO   LGUI(KC_Y) // Pomme-y Redo
#define A_FIND   LGUI(KC_F) // Pomme-v Find

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak m4rs
 * ┌────────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │Tab     │   '  │   ,  │   .  │   P  │   Y  ║   F  │   G  │   C  │   R  │   L  │Bksp  │
 * ├────────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │Ctrl/Esc│   A  │   O  │   E  │   U  │   I  ║   D  │   H  │   T  │   N  │   S  │Enter │
 * ├────────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │Shift   │   ;  │   Q  │   J  │   K  │   X  ║   B  │   M  │   W  │   V  │   Z  │Shft /│
 * ├────────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │Esc     │  Fn  │ GUI  │ Alt  │Lower │    Space    │Raise │ Left │ Down │  Up  │Right │
 * └────────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_DVORAK_M] = {
  {KC_TAB,        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   KC_F,   KC_G,    KC_C,    KC_R,    KC_L,  KC_BSPC},
  {CTL_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   KC_D,   KC_H,    KC_T,    KC_N,    KC_S,  KC_ENT},
  {KC_LSFT,       KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,  SFT_T(KC_SLSH)},
  {KC_ESC,        FN_M,    KC_LGUI, KC_LALT, LOWER_M, KC_SPC, KC_SPC, RAISE_M, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},

/* Dvorak jouff
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │ Tab  │   '  │   ,  │   .  │   P  │   Y  ║   F  │   G  │   C  │   R  │   L  │Bksp  │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Esc  │   A  │   O  │   E  │   U  │   I  ║   D  │   H  │   T  │   N  │   S  │Enter │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │ Shift│   ;  │   Q  │   J  │   K  │   X  ║   B  │   M  │   W  │   V  │   Z  │Shift │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │ FN   │ Ctrl │ Alt  │ GUI  │Lower │    Space    │Raise │ Left │ Down │  Up  │Right │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_DVORAK_J] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,  KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    KC_S,  KC_ENT},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,  KC_RSFT},
  {KC_FN1, KC_LCTL, KC_LALT, KC_LGUI, LOWER_J, KC_SPC, KC_SPC, RAISE_J, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT}
},

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
[_LOWER_M] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,       KC_MINS,       KC_EQL,        KC_DEL},
  {_______, KC_MINS, KC_UNDS, KC_QUES, KC_EQL,  KC_PLUS, _______, KC_LPRN,    KC_RPRN,       KC_LCBR,       KC_RCBR,       KC_PIPE},
  {_______, W_CLOSE, W_UNDO,  W_CUT,   W_COPY,  W_PASTE, _______, UC(0x00ab), UC(0x00bb),    _______,       _______,       _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    LCTL(KC_HOME), LCTL(KC_PGUP), LCTL(KC_PGDN), LCTL(KC_END)}
},

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
[_RAISE_M] = {
  {_______,  UC(0x00e4), UC(0x00ea), UC(0x00eb), UC(0x00fc), _______,    KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN3, KC_WH_U, _______},
  {_______,  UC(0x00e0), UC(0x00f4), UC(0x00e9), UC(0x00fb), UC(0x00ee), KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______},
  {SRAISE_M, UC(0x00e2), UC(0x00f6), UC(0x00e8), UC(0x00f9), UC(0x00ef), KC_ACL2, KC_BTN4, KC_BTN1, KC_BTN5, _______, _______},
  {_______,  _______,    _______,    _______,    _______,    _______,    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},
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
[_SRAISE_M] = {
  {_______, UC(0x00c4), UC(0x00ca), UC(0x00cb), UC(0x00dc), _______,    KC_ACL0, KC_BTN1, KC_MS_U, KC_BTN3, KC_WH_U, _______},
  {_______, UC(0x00c0), UC(0x00d4), UC(0x00c9), UC(0x00db), UC(0x00ce), KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______},
  {_______, UC(0x00c2), UC(0x00d6), UC(0x00c8), UC(0x00d9), UC(0x00cf), KC_ACL2, KC_BTN4, KC_BTN1, KC_BTN5, _______, _______},
  {_______, _______,    _______,    _______,    _______,    _______,    _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},

/* Space Fn m4rs
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
[_SPACE_FN_M] = {
  {_______, KC_PGUP, KC_HOME, KC_UP,   KC_END,   S(KC_A), S(KC_B), KC_KP_7, KC_KP_8, KC_KP_9, KC_PSLS, _______},
  {_______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, S(KC_C), S(KC_D), KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_PENT},
  {_______, _______, KC_WBAK, KC_WREF, KC_WFWD,  S(KC_E), S(KC_F), KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, _______},
  {_______, _______, _______, _______, _______,  _______, _______, KC_KP_0, KC_PDOT, KC_PEQL, KC_PMNS, _______}
},

/* Space Fn m4rs alternatif
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
[_SPACE_FN_M_ALT] = {
  {_______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, KC_PGUP, KC_HOME, KC_UP,   KC_END,   S(KC_A), S(KC_B), _______},
  {_______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, S(KC_C), S(KC_D), KC_PENT},
  {_______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______, KC_WBAK, KC_WREF, KC_WFWD,  S(KC_E), S(KC_F), _______},
  {_______, KC_KP_0, KC_PDOT, KC_PEQL, KC_PMNS, _______, _______, _______, _______,  _______, _______, _______}
},

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
[_FN_M] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______},
  {KC_CAPS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______},
  {KC_RCTL, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Lower jouff
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  ║   6  │   7  │   8  │   9  │   0  │ Bksp │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Del  │  F1  │  F2  │  F3  │  F4  │  F5  ║  F6  │   -  │   =  │   [  │   ]  │  \   │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │  F7  │  F8  │  F9  │  F10 │  F11 ║  F12 │ISO # │ISO / │      │      │Enter │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │ Next │ Vol- │ Vol+ │ Play │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_Lower_J] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise jouff
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │   `  │   1  │   2  │   3  │   4  │   5  ║   6  │   7  │   8  │   9  │   0  │ Del  │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │   ø  │   €  │   µ  │   ±  ║   £  │      │  [   │   ]  │ │ \  │Enter │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │ Redo │ Undo │ Cut  │ Copy │ Paste║      │      │      │   -  │   =  │Shift │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │ Home │ PgUp │ PgDn │ End  │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_RAISE_J] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
  {_______, ______, ______,   _____, ________, _______, _______, _______, KC_LBRC, KC_RBRC, LC_BSLS, KC_ENT},
  {_______, A_REDO, A_UNDO,   A_CUT,   A_COPY,  A_PASTE, _______, _______, ______,  KC_MINS, KC_EQL, KC_RSFT},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
},

/* Space Fn jouff
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_SPACE_FN_J] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Fn jouff
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_FN_J] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* NumLock
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_NUMLOCK] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* Adjust (Lower + Raise)
 * ┌──────┬──────┬──────┬──────┬──────┬──────╥──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │ Reset│      │      │      │      ║      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╫──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │Aud on│Audoff│AGnorm║AGswap│ m4rs │Jouff │      │      │      │
 * ├──────┼──────┼──────┼──────┼───┄──┼──────╫──────┼───┄──┼──────┼──────┼──────┼──────┤
 * │      │Voice-│Voice+│Mus on│Musoff│MIDIon║MIDIof│      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────╨──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │             │      │      │      │      │      │
 * └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______},
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DVORAK_M, DVORAK_J, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______,  _______,  _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______}
}


};

#ifdef AUDIO_ENABLE

float tone_startup[][2]  = SONG(STARTUP_SOUND);
float tone_dvorak_m[][2] = SONG(DVORAK_SOUND);
float tone_dvorak_j[][2] = SONG(COLEMAK_SOUND);
float music_scale[][2]   = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK_J:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak_j, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK_J);
      }
      return false;
      break;
    case DVORAK_M:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak_m, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_DVORAK_M);
      }
      return false;
      break;
    case LOWER_M:
      if (record->event.pressed) {
        layer_on(_LOWER_M);
        update_tri_layer(_LOWER_M, _RAISE_M, _ADJUST);
      } else {
        layer_off(_LOWER_M);
        update_tri_layer(_LOWER_M, _RAISE_M, _ADJUST);
      }
      return false;
      break;
    case RAISE_M:
      if (record->event.pressed) {
        layer_on(_RAISE_M);
        update_tri_layer(_LOWER_M, _RAISE_M, _ADJUST);
      } else {
        layer_off(_RAISE_M);
        update_tri_layer(_LOWER_M, _RAISE_M, _ADJUST);
      }
      return false;
      break;
    case SRAISE_M:
      if (record->event.pressed) {
        layer_on(_SRAISE_M);
      } else {
        layer_off(_SRAISE_M);
      }
      return false;
      break;
    case LOWER_J:
      if (record->event.pressed) {
        layer_on(_LOWER_J);
        update_tri_layer(_LOWER_J, _RAISE_J, _ADJUST);
      } else {
        layer_off(_LOWER_J);
        update_tri_layer(_LOWER_J, _RAISE_J, _ADJUST);
      }
      return false;
      break;
    case RAISE_J:
      if (record->event.pressed) {
        layer_on(_RAISE_J);
        update_tri_layer(_LOWER_J, _RAISE_J, _ADJUST);
      } else {
        layer_off(_RAISE_J);
        update_tri_layer(_LOWER_J, _RAISE_J, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif
