/* Copyright 2021 QMK
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

#pragma once

//#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 1151
//#define EEPROM_SIZE 1152

#define FEE_PAGE_SIZE (0x200)
#define FEE_PAGE_COUNT (8)

#define FEE_PAGE_BASE_ADDRESS (0x1F000)
#define FEE_MCU_FLASH_SIZE (0x1000)

#define EECONFIG_USER_DATA_SIZE 4

#define EECONFIG_KB_DATA_SIZE 1

#define TRANSIENT_EEPROM_SIZE 4096


#include "fs026_eeprom.h"

// BLE configuration
#define USER_BLE_ID (0X00A5)
#define USER_BLE1_NAME "EPOMAKER P65-1"
#define USER_BLE2_NAME "EPOMAKER P65-2"
#define USER_BLE3_NAME "EPOMAKER P65-3"

#define RGB_MATRIX_LED_COUNT 67
#define LED_CONNECTION_INDEX 66 // Connection indicator
#define LED_CAP_INDEX 29        // Caps Lock indicator
#define LED_WIN_L_INDEX 59      // Win Lock indicator
#define LED_BATT_INDEX 30       // Battery indicator
#define LED_BLE_1_INDEX 15      // BLE 1 indicator
#define LED_BLE_2_INDEX 16      // BLE 2 indicator
#define LED_BLE_3_INDEX 17      // BLE 3 indicator
#define LED_2P4G_INDEX 18       // 2.4G indicator
#define LED_USB_INDEX 19        // USB indicator
