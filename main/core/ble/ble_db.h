/*
 * Copyright (C) 2018  SuperGreenLab <towelie@supergreenlab.com>
 * Author: Constantin Clauzel <constantin.clauzel@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#ifndef BLE_DB_H_
#define BLE_DB_H_

#include "esp_gatts_api.h"

#define CHAR_VAL(name) IDX_CHAR_##name, \
  IDX_CHAR_VAL_##name

#define CHAR_VAL_CFG(name) IDX_CHAR_##name, \
  IDX_CHAR_VAL_##name, \
  IDX_CHAR_CFG_##name

#define IDX(name) IDX_CHAR_##name
#define IDX_VALUE(name) IDX_CHAR_VAL_##name
#define IDX_CFG(name) IDX_CHAR_CFG_##name

enum idx
{
  IDX_SVC,

  /*
   * [GENERATED]
   */
    CHAR_VAL_CFG(WIFI_STATUS),
    CHAR_VAL(WIFI_SSID),
    CHAR_VAL_CFG(WIFI_PASSWORD),
    CHAR_VAL_CFG(WIFI_IP),
    CHAR_VAL_CFG(TIME),
    CHAR_VAL_CFG(STATE),
    CHAR_VAL(DEVICE_NAME),
    CHAR_VAL(BOX_0_TIMER_TYPE),
    CHAR_VAL_CFG(BOX_0_STARTED_AT),
    CHAR_VAL(BOX_0_ON_HOUR),
    CHAR_VAL(BOX_0_ON_MIN),
    CHAR_VAL(BOX_0_OFF_HOUR),
    CHAR_VAL(BOX_0_OFF_MIN),
    CHAR_VAL_CFG(BOX_0_STRETCH),
    CHAR_VAL_CFG(BOX_0_LED_DIM),
    CHAR_VAL_CFG(BOX_0_BLOWER),
    CHAR_VAL_CFG(BOX_0_LED_INFO),
  /*
   * [/GENERATED]
   */
  HRS_IDX_NB,
};

extern const esp_gatts_attr_db_t gatt_db[HRS_IDX_NB];

#endif
