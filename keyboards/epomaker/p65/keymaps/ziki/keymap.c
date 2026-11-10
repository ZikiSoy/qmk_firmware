/* EPOMAKER P65 - keymap ported from the kmonad config (apple.kbd).
 *
 * Layer 0/1/2/3 are fixed by the board firmware:
 *   0 = Windows base, 1 = Mac base (turned on by the Mac/Win switch),
 *   2 = Fn (Win),     3 = Fn (Mac).
 * New layers go above them.
 *
 * kmonad -> QMK
 *   caps  tap esc / hold nav (tap-next)            -> LT(_NAV, KC_ESC)  + hold-on-other-key + retro tap
 *   a     tap a   / hold shortcut (next-release)   -> LT(_APP, KC_A)    + permissive hold
 *   s/l   tap / hold shift (tap-hold 200)          -> LSFT_T / RSFT_T
 *   d/k   tap / hold nav (next-release)            -> LT(_NAV, ...)     + permissive hold
 *   `around (layer-toggle src) <mod>`              -> _SRC layer on while any real modifier is held
 *   cmd-button "open -a X"                         -> Hyper+key, launched by Hammerspoon (see hammerspoon.lua)
 *   F-row media keys (P65 has no F row)            -> number row of _NAV
 */
#include QMK_KEYBOARD_H
#include "keyboard_common.h"

enum layers {
    _WIN = 0,
    _MAC,
    _FN_WIN,
    _FN_MAC,
    _SRC,   // home-row keys become plain letters while a modifier is held
    _NAV,
    _APP,   // "shortcut" layer: app launchers
};

/* ---- home row ---- */
#define CAPS_NV LT(_NAV, KC_ESC)
#define HR_A    LT(_APP, KC_A)
#define HR_S    LSFT_T(KC_S)
#define HR_D    LT(_NAV, KC_D)
#define HR_K    LT(_NAV, KC_K)
#define HR_L    RSFT_T(KC_L)

/* ---- nav aliases (macOS) ---- */
#define TAB_L   SGUI(KC_LBRC)   // ltab  M-S-[
#define TAB_R   SGUI(KC_RBRC)   // rtab  M-S-]
#define MSN_CTL LCTL(KC_UP)     // mc    C-up
#define APP_WIN LCTL(KC_DOWN)   // aw    C-down
#define SCAT    SGUI(KC_SPC)    // scat  M-S-spc

/* ---- app launchers: Hyper (ctrl+opt+cmd+shift) + key ---- */
#define AP_SUBL HYPR(KC_S)
#define AP_MAIL HYPR(KC_G)
#define AP_JETS HYPR(KC_U)
#define AP_CIDR HYPR(KC_J)
#define AP_CHRM HYPR(KC_K)
#define AP_FIRE HYPR(KC_L)
#define AP_CHAT HYPR(KC_C)
#define AP_MEET HYPR(KC_M)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WIN] = LAYOUT_tkl_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        CAPS_NV, CAPS_NV, HR_A,    HR_S,    HR_D,    KC_F,    KC_G,    KC_H,    KC_J,    HR_K,    HR_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN_WIN),               KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_MAC] = LAYOUT_tkl_ansi(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        CAPS_NV, CAPS_NV, HR_A,    HR_S,    HR_D,    KC_F,    KC_G,    KC_H,    KC_J,    HR_K,    HR_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, MO(_FN_MAC),               KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /* Fn layers: stock keymap (BT/2.4G, RGB, battery, F1-F12), except Fn+A / Fn+S = MW_CH:
     * toggles Mac/Win and saves it, so the keyboard boots back into the same mode. */
    [_FN_WIN] = LAYOUT_tkl_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  EE_CLR,           KC_MUTE,
        KC_TAB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  KC_T,    KC_Y,    KC_U,    KC_PSCR, KC_SCRL, KC_PAUS, RM_HUED, RM_HUEU, RM_NEXT,          KC_INS,
        KC_CAPS, KC_CAPS, MW_CH,   MW_CH,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RM_SATD, RM_SATU, RGB_RTOG,         KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    SIX_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          RM_VALU, KC_END,
        KC_LCTL, QK_WLO,  KC_LALT,                            QK_BAT,                             KC_RALT, KC_NO,                     RM_SPDD, RM_VALD, RM_SPDU
    ),
    [_FN_MAC] = LAYOUT_tkl_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  EE_CLR,           KC_MUTE,
        KC_TAB,  MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,  KC_T,    KC_Y,    KC_U,    KC_PSCR, KC_SCRL, KC_PAUS, RM_HUED, RM_HUEU, RM_NEXT,          KC_INS,
        KC_CAPS, KC_CAPS, MW_CH,   MW_CH,   KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RM_SATD, RM_SATU, RGB_RTOG,         KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    SIX_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          RM_VALU, KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            QK_BAT,                             KC_RGUI, KC_NO,                     RM_SPDD, RM_VALD, RM_SPDU
    ),
    /* kmonad `src`: while ctrl/opt/cmd/shift is held, home-row keys are plain letters (no tap-hold delay) */
    [_SRC] = LAYOUT_tkl_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_A,    KC_S,    KC_D,    _______, _______, _______, _______, KC_K,    KC_L,    _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,                   _______, _______, _______
    ),
    /* nav: number row = the Mac F-row media keys the P65 doesn't have
     *   1 bri-  2 bri+  3 launchpad  4 mission ctl  5 rgb-  6 rgb+  7 prev  8 play  9 next  0 mute  - vol-  = vol+ */
    [_NAV] = LAYOUT_tkl_ansi(
        _______, KC_BRID, KC_BRIU, KC_LPAD, KC_MCTL, RM_VALD, RM_VALU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, TAB_L,   KC_UP,   TAB_R,   _______, KC_HOME, KC_END,  _______,          _______,
        _______, _______, _______, _______, _______, MSN_CTL, APP_WIN, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, _______,          _______,
        _______,          _______, _______, _______, _______, _______, KC_ENT,  _______, KC_BSPC, KC_INS,  KC_DEL,  _______,          _______, _______,
        _______, _______, _______,                            SCAT,                               _______, _______,                   _______, _______, _______
    ),
    /* shortcut: hold `a`, then press the key -> Hyper+key -> Hammerspoon opens the app */
    [_APP] = LAYOUT_tkl_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, AP_JETS, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, AP_SUBL, _______, _______, AP_MAIL, _______, AP_CIDR, AP_CHRM, AP_FIRE, _______, _______, _______,          _______,
        _______,          _______, _______, AP_CHAT, _______, _______, _______, AP_MEET, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,                   _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_WIN]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MAC]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN_WIN] = { ENCODER_CCW_CW(RM_SATD, RM_SATU) },
    [_FN_MAC] = { ENCODER_CCW_CW(RM_SPDD, RM_SPDU) },
    [_SRC]    = { ENCODER_CCW_CW(_______, _______) },
    [_NAV]    = { ENCODER_CCW_CW(KC_BRID, KC_BRIU) },  // hold caps + turn knob = screen brightness
    [_APP]    = { ENCODER_CCW_CW(_______, _______) },
};
#endif

/* ---- kmonad `around (layer-toggle src) <mod>` ---- */
static uint8_t src_mods_held = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL: case KC_LSFT: case KC_LALT: case KC_LGUI:
        case KC_RCTL: case KC_RSFT: case KC_RALT: case KC_RGUI:
            if (record->event.pressed) {
                if (src_mods_held++ == 0) layer_on(_SRC);
            } else if (src_mods_held > 0 && --src_mods_held == 0) {
                layer_off(_SRC);
            }
            break;
    }
    return true;
}

/* ---- per-key tap-hold, matching kmonad semantics ---- */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HR_A: case HR_D: case HR_K:   // tap-hold-next-release
            return true;
    }
    return false;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return keycode == CAPS_NV;              // tap-next
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    return keycode == CAPS_NV;              // long lone press of caps still sends esc
}
