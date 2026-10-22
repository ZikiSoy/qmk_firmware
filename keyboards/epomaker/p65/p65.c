/* Copyright 2025 Epomaker
 * Copyright 2025 Epomaker <https://github.com/Epomaker>
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

#include "keyboard_common.h"

// ===========================================================================
// Keyboard-specific data
// ===========================================================================

// Battery indicator LED indices (first row numbers 1 to 0)
const uint8_t Led_Batt_Index_Tab[BATTERY_LED_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

led_config_t g_led_config = { {
    { 0        , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   , NO_LED   },
	{ NO_LED   , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , NO_LED   , NO_LED   },
	{ 14       , 15       , 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , NO_LED   },
	{ 29       , 31       , 32       , 33       , 34       , 35       , 36       , 37       , 38       , 39       , 40       , 41       , NO_LED   , 42       , 43       , 57       },
	{ 44       , NO_LED   , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 52       , 53       , 54       , NO_LED   , 55       , 56       , NO_LED   },
	{ 58       , 59       , 60       , 30       , NO_LED   , 61       , NO_LED   , NO_LED   , NO_LED   , 62       , 63       , NO_LED   , NO_LED   , 64       , 65       , 66       }
},{
    { 0,  10},  { 15, 10}, { 30, 10}, { 45, 10}, { 60, 10}, { 75, 10}, { 90, 10}, {105, 10}, {120, 10}, { 135, 10}, { 150, 10}, { 165, 10}, { 180, 10},             { 202, 10},
    { 4,  20},  { 22, 20}, { 37, 20}, { 52, 20}, { 67, 20}, { 82, 20}, { 97, 20}, {112, 20}, {127, 20}, { 142, 20}, { 157, 20}, { 172, 20}, { 187, 20}, { 205, 20},             { 224, 20},
    { 0,  30},  {  7, 30}, { 25, 30}, { 40, 30}, { 55, 30}, { 70, 30}, { 85, 30}, {100, 30}, {115, 30}, { 130, 30}, { 145, 30}, { 160, 30}, { 175, 30},             { 202, 30}, { 224, 30},
    { 7,  40},             { 32, 40}, { 47, 40}, { 62, 40}, { 77, 40}, { 92, 40}, {107, 40}, {122, 40}, { 137, 40}, { 152, 40}, { 167, 40},             { 185, 40}, { 210, 40}, { 224, 40},
    { 0,  50},  { 18, 50}, { 37, 50},                                  { 92, 50},                                   { 150, 50}, { 168, 50},             { 195, 50}, { 210, 50}, { 224, 50}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,
    1,  1,  1,              1,              1,  1,      1,  1,  1
} };

// ===========================================================================
// QMK Callback Functions - Delegate to common implementations
// ===========================================================================

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    return kb_rgb_matrix_indicators_common(led_min, led_max);
}

void notify_usb_device_state_change_kb(struct usb_device_state usb_device_state) {
    kb_notify_usb_device_state_change(usb_device_state);
    notify_usb_device_state_change_user(usb_device_state);
}

bool led_update_kb(led_t led_state) {
    if (!led_update_user(led_state)) {
        return false;
    }
    return kb_led_update(led_state);
}

void housekeeping_task_kb(void) {
    kb_housekeeping_task();
    housekeeping_task_user();
}

void board_init(void) {
    kb_board_init();
}

void keyboard_post_init_kb(void) {
    kb_keyboard_post_init();
    keyboard_post_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    return kb_process_record_common(keycode, record);
}
