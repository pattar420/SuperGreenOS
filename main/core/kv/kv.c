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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../log/log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

#include "kv.h"
#include "kv_ble.h"
#include "../include_modules.h"

void init_helpers();
nvs_handle kv_handle;

void open_kv() {
  // Initialize NVS
  esp_err_t err = nvs_flash_init();
  if (err == ESP_ERR_NVS_NO_FREE_PAGES) {
    // NVS partition was truncated and needs to be erased
    // Retry nvs_flash_init
    ESP_ERROR_CHECK(nvs_flash_erase());
    err = nvs_flash_init();
  }
  ESP_ERROR_CHECK( err );

  err = nvs_open("kv_store", NVS_READWRITE, &kv_handle);
  if (err != ESP_OK) {
    ESP_LOGI(SGO_LOG_EVENT, "@KV Error (%s) opening NVS handle!\n", esp_err_to_name(err));
  }
}

void preinit_kv() {
  /*
   * [GENERATED]
   */

  init_helpers();
  const char *default_wifi_ssid = "";
  defaultstr(WIFI_SSID, default_wifi_ssid);
  const char *default_wifi_password = "";
  defaultstr(WIFI_PASSWORD, default_wifi_password);
  const char *default_wifi_ap_ssid = DEFAULT_AP_SSID;
  defaultstr(WIFI_AP_SSID, default_wifi_ap_ssid);
  const char *default_wifi_ap_password = DEFAULT_AP_PASSWORD;
  defaultstr(WIFI_AP_PASSWORD, default_wifi_ap_password);
  const char *default_mdns_domain = DEFAULT_MDNS_DOMAIN;
  defaultstr(MDNS_DOMAIN, default_mdns_domain);
  const char *default_wifi_ip = "0.0.0.0";
  defaultstr(WIFI_IP, default_wifi_ip);
  int default_time = 0;
  defaulti(TIME, default_time);
  int default_n_restarts = 0;
  defaulti(N_RESTARTS, default_n_restarts);
  int default_ota_timestamp = OTA_BUILD_TIMESTAMP;
  defaulti(OTA_TIMESTAMP, default_ota_timestamp);
  const char *default_ota_server_ip = CONFIG_OTA_SERVER_IP;
  defaultstr(OTA_SERVER_IP, default_ota_server_ip);
  const char *default_ota_server_hostname = CONFIG_OTA_SERVER_HOSTNAME;
  defaultstr(OTA_SERVER_HOSTNAME, default_ota_server_hostname);
  const char *default_ota_server_port = CONFIG_OTA_SERVER_PORT;
  defaultstr(OTA_SERVER_PORT, default_ota_server_port);
  const char *default_ota_basedir = CONFIG_OTA_BASEDIR;
  defaultstr(OTA_BASEDIR, default_ota_basedir);
  const char *default_broker_url = CONFIG_BROKER_URL;
  defaultstr(BROKER_URL, default_broker_url);
  const char *default_broker_channel = "";
  defaultstr(BROKER_CHANNEL, default_broker_channel);
  const char *default_broker_clientid = "";
  defaultstr(BROKER_CLIENTID, default_broker_clientid);
  int default_i2c_0_sda = DEFAULT_I2C_0_SDA;
  defaulti(I2C_0_SDA, default_i2c_0_sda);
  int default_i2c_0_scl = DEFAULT_I2C_0_SCL;
  defaulti(I2C_0_SCL, default_i2c_0_scl);
  int default_i2c_0_enabled = 1;
  defaulti(I2C_0_ENABLED, default_i2c_0_enabled);
  int default_i2c_1_sda = DEFAULT_I2C_1_SDA;
  defaulti(I2C_1_SDA, default_i2c_1_sda);
  int default_i2c_1_scl = DEFAULT_I2C_1_SCL;
  defaulti(I2C_1_SCL, default_i2c_1_scl);
  int default_i2c_1_enabled = 0;
  defaulti(I2C_1_ENABLED, default_i2c_1_enabled);
  int default_state = FIRST_RUN;
  defaulti(STATE, default_state);
  const char *default_device_name = "SuperGreenDriver";
  defaultstr(DEVICE_NAME, default_device_name);
  int default_box_0_enabled = 1;
  defaulti(BOX_0_ENABLED, default_box_0_enabled);
  int default_box_0_timer_type = TIMER_MANUAL;
  defaulti(BOX_0_TIMER_TYPE, default_box_0_timer_type);
  int default_box_0_timer_output = 0;
  defaulti(BOX_0_TIMER_OUTPUT, default_box_0_timer_output);
  int default_box_0_started_at = 0;
  defaulti(BOX_0_STARTED_AT, default_box_0_started_at);
  int default_box_0_on_hour = 1;
  defaulti(BOX_0_ON_HOUR, default_box_0_on_hour);
  int default_box_0_on_min = 0;
  defaulti(BOX_0_ON_MIN, default_box_0_on_min);
  int default_box_0_off_hour = 19;
  defaulti(BOX_0_OFF_HOUR, default_box_0_off_hour);
  int default_box_0_off_min = 0;
  defaulti(BOX_0_OFF_MIN, default_box_0_off_min);
  int default_box_0_stretch = 0;
  defaulti(BOX_0_STRETCH, default_box_0_stretch);
  int default_box_0_led_dim = 0;
  defaulti(BOX_0_LED_DIM, default_box_0_led_dim);
  int default_box_0_blower = 50;
  defaulti(BOX_0_BLOWER, default_box_0_blower);
  int default_box_0_blower_mode = BLOWER_MODE_MANUAL;
  defaulti(BOX_0_BLOWER_MODE, default_box_0_blower_mode);
  int default_box_0_blower_gpio = DEFAULT_BOX_0_BLOWER_GPIO;
  defaulti(BOX_0_BLOWER_GPIO, default_box_0_blower_gpio);
  int default_box_0_blower_enabled = 1;
  defaulti(BOX_0_BLOWER_ENABLED, default_box_0_blower_enabled);
  int default_box_0_sht1x_temp_c = -1000000;
  defaulti(BOX_0_SHT1X_TEMP_C, default_box_0_sht1x_temp_c);
  int default_box_0_sht1x_temp_f = -1000000;
  defaulti(BOX_0_SHT1X_TEMP_F, default_box_0_sht1x_temp_f);
  int default_box_0_sht1x_humi = -1000000;
  defaulti(BOX_0_SHT1X_HUMI, default_box_0_sht1x_humi);
  int default_box_0_sht21_temp_c = -1000000;
  defaulti(BOX_0_SHT21_TEMP_C, default_box_0_sht21_temp_c);
  int default_box_0_sht21_temp_f = -1000000;
  defaulti(BOX_0_SHT21_TEMP_F, default_box_0_sht21_temp_f);
  int default_box_0_sht21_humi = -1000000;
  defaulti(BOX_0_SHT21_HUMI, default_box_0_sht21_humi);
  int default_box_0_arduino_co2 = -1000000;
  defaulti(BOX_0_ARDUINO_CO2, default_box_0_arduino_co2);
  int default_box_0_dust_gpy2y10 = -1000000;
  defaulti(BOX_0_DUST_GPY2Y10, default_box_0_dust_gpy2y10);
  int default_box_1_enabled = 1;
  defaulti(BOX_1_ENABLED, default_box_1_enabled);
  int default_box_1_timer_type = TIMER_MANUAL;
  defaulti(BOX_1_TIMER_TYPE, default_box_1_timer_type);
  int default_box_1_timer_output = 0;
  defaulti(BOX_1_TIMER_OUTPUT, default_box_1_timer_output);
  int default_box_1_started_at = 0;
  defaulti(BOX_1_STARTED_AT, default_box_1_started_at);
  int default_box_1_on_hour = 1;
  defaulti(BOX_1_ON_HOUR, default_box_1_on_hour);
  int default_box_1_on_min = 0;
  defaulti(BOX_1_ON_MIN, default_box_1_on_min);
  int default_box_1_off_hour = 19;
  defaulti(BOX_1_OFF_HOUR, default_box_1_off_hour);
  int default_box_1_off_min = 0;
  defaulti(BOX_1_OFF_MIN, default_box_1_off_min);
  int default_box_1_stretch = 0;
  defaulti(BOX_1_STRETCH, default_box_1_stretch);
  int default_box_1_led_dim = 0;
  defaulti(BOX_1_LED_DIM, default_box_1_led_dim);
  int default_box_1_blower = 50;
  defaulti(BOX_1_BLOWER, default_box_1_blower);
  int default_box_1_blower_mode = BLOWER_MODE_MANUAL;
  defaulti(BOX_1_BLOWER_MODE, default_box_1_blower_mode);
  int default_box_1_blower_gpio = DEFAULT_BOX_1_BLOWER_GPIO;
  defaulti(BOX_1_BLOWER_GPIO, default_box_1_blower_gpio);
  int default_box_1_blower_enabled = 1;
  defaulti(BOX_1_BLOWER_ENABLED, default_box_1_blower_enabled);
  int default_box_1_sht1x_temp_c = -1000000;
  defaulti(BOX_1_SHT1X_TEMP_C, default_box_1_sht1x_temp_c);
  int default_box_1_sht1x_temp_f = -1000000;
  defaulti(BOX_1_SHT1X_TEMP_F, default_box_1_sht1x_temp_f);
  int default_box_1_sht1x_humi = -1000000;
  defaulti(BOX_1_SHT1X_HUMI, default_box_1_sht1x_humi);
  int default_box_1_sht21_temp_c = -1000000;
  defaulti(BOX_1_SHT21_TEMP_C, default_box_1_sht21_temp_c);
  int default_box_1_sht21_temp_f = -1000000;
  defaulti(BOX_1_SHT21_TEMP_F, default_box_1_sht21_temp_f);
  int default_box_1_sht21_humi = -1000000;
  defaulti(BOX_1_SHT21_HUMI, default_box_1_sht21_humi);
  int default_box_1_arduino_co2 = -1000000;
  defaulti(BOX_1_ARDUINO_CO2, default_box_1_arduino_co2);
  int default_box_1_dust_gpy2y10 = -1000000;
  defaulti(BOX_1_DUST_GPY2Y10, default_box_1_dust_gpy2y10);
  int default_box_2_enabled = 0;
  defaulti(BOX_2_ENABLED, default_box_2_enabled);
  int default_box_2_timer_type = TIMER_MANUAL;
  defaulti(BOX_2_TIMER_TYPE, default_box_2_timer_type);
  int default_box_2_timer_output = 0;
  defaulti(BOX_2_TIMER_OUTPUT, default_box_2_timer_output);
  int default_box_2_started_at = 0;
  defaulti(BOX_2_STARTED_AT, default_box_2_started_at);
  int default_box_2_on_hour = 1;
  defaulti(BOX_2_ON_HOUR, default_box_2_on_hour);
  int default_box_2_on_min = 0;
  defaulti(BOX_2_ON_MIN, default_box_2_on_min);
  int default_box_2_off_hour = 19;
  defaulti(BOX_2_OFF_HOUR, default_box_2_off_hour);
  int default_box_2_off_min = 0;
  defaulti(BOX_2_OFF_MIN, default_box_2_off_min);
  int default_box_2_stretch = 0;
  defaulti(BOX_2_STRETCH, default_box_2_stretch);
  int default_box_2_led_dim = 0;
  defaulti(BOX_2_LED_DIM, default_box_2_led_dim);
  int default_box_2_blower = 50;
  defaulti(BOX_2_BLOWER, default_box_2_blower);
  int default_box_2_blower_mode = BLOWER_MODE_MANUAL;
  defaulti(BOX_2_BLOWER_MODE, default_box_2_blower_mode);
  int default_box_2_blower_gpio = DEFAULT_BOX_2_BLOWER_GPIO;
  defaulti(BOX_2_BLOWER_GPIO, default_box_2_blower_gpio);
  int default_box_2_blower_enabled = 0;
  defaulti(BOX_2_BLOWER_ENABLED, default_box_2_blower_enabled);
  int default_box_2_sht1x_temp_c = -1000000;
  defaulti(BOX_2_SHT1X_TEMP_C, default_box_2_sht1x_temp_c);
  int default_box_2_sht1x_temp_f = -1000000;
  defaulti(BOX_2_SHT1X_TEMP_F, default_box_2_sht1x_temp_f);
  int default_box_2_sht1x_humi = -1000000;
  defaulti(BOX_2_SHT1X_HUMI, default_box_2_sht1x_humi);
  int default_box_2_sht21_temp_c = -1000000;
  defaulti(BOX_2_SHT21_TEMP_C, default_box_2_sht21_temp_c);
  int default_box_2_sht21_temp_f = -1000000;
  defaulti(BOX_2_SHT21_TEMP_F, default_box_2_sht21_temp_f);
  int default_box_2_sht21_humi = -1000000;
  defaulti(BOX_2_SHT21_HUMI, default_box_2_sht21_humi);
  int default_box_2_arduino_co2 = -1000000;
  defaulti(BOX_2_ARDUINO_CO2, default_box_2_arduino_co2);
  int default_box_2_dust_gpy2y10 = -1000000;
  defaulti(BOX_2_DUST_GPY2Y10, default_box_2_dust_gpy2y10);
  int default_led_0_duty = 0;
  defaulti(LED_0_DUTY, default_led_0_duty);
  int default_led_1_duty = 0;
  defaulti(LED_1_DUTY, default_led_1_duty);
  int default_led_2_duty = 0;
  defaulti(LED_2_DUTY, default_led_2_duty);
  int default_led_3_duty = 0;
  defaulti(LED_3_DUTY, default_led_3_duty);
  int default_led_4_duty = 0;
  defaulti(LED_4_DUTY, default_led_4_duty);
  int default_led_5_duty = 0;
  defaulti(LED_5_DUTY, default_led_5_duty);
  int default_led_6_duty = 0;
  defaulti(LED_6_DUTY, default_led_6_duty);
  int default_led_0_gpio = DEFAULT_LED_0_GPIO;
  defaulti(LED_0_GPIO, default_led_0_gpio);
  int default_led_1_gpio = DEFAULT_LED_1_GPIO;
  defaulti(LED_1_GPIO, default_led_1_gpio);
  int default_led_2_gpio = DEFAULT_LED_2_GPIO;
  defaulti(LED_2_GPIO, default_led_2_gpio);
  int default_led_3_gpio = DEFAULT_LED_3_GPIO;
  defaulti(LED_3_GPIO, default_led_3_gpio);
  int default_led_4_gpio = DEFAULT_LED_4_GPIO;
  defaulti(LED_4_GPIO, default_led_4_gpio);
  int default_led_5_gpio = DEFAULT_LED_5_GPIO;
  defaulti(LED_5_GPIO, default_led_5_gpio);
  int default_led_6_gpio = DEFAULT_LED_6_GPIO;
  defaulti(LED_6_GPIO, default_led_6_gpio);
  int default_led_0_x = 0;
  defaulti(LED_0_X, default_led_0_x);
  int default_led_1_x = 0;
  defaulti(LED_1_X, default_led_1_x);
  int default_led_2_x = 0;
  defaulti(LED_2_X, default_led_2_x);
  int default_led_3_x = 0;
  defaulti(LED_3_X, default_led_3_x);
  int default_led_4_x = 0;
  defaulti(LED_4_X, default_led_4_x);
  int default_led_5_x = 0;
  defaulti(LED_5_X, default_led_5_x);
  int default_led_6_x = 0;
  defaulti(LED_6_X, default_led_6_x);
  int default_led_0_y = 0;
  defaulti(LED_0_Y, default_led_0_y);
  int default_led_1_y = 0;
  defaulti(LED_1_Y, default_led_1_y);
  int default_led_2_y = 0;
  defaulti(LED_2_Y, default_led_2_y);
  int default_led_3_y = 0;
  defaulti(LED_3_Y, default_led_3_y);
  int default_led_4_y = 0;
  defaulti(LED_4_Y, default_led_4_y);
  int default_led_5_y = 0;
  defaulti(LED_5_Y, default_led_5_y);
  int default_led_6_y = 0;
  defaulti(LED_6_Y, default_led_6_y);
  int default_led_0_z = 0;
  defaulti(LED_0_Z, default_led_0_z);
  int default_led_1_z = 0;
  defaulti(LED_1_Z, default_led_1_z);
  int default_led_2_z = 0;
  defaulti(LED_2_Z, default_led_2_z);
  int default_led_3_z = 0;
  defaulti(LED_3_Z, default_led_3_z);
  int default_led_4_z = 0;
  defaulti(LED_4_Z, default_led_4_z);
  int default_led_5_z = 0;
  defaulti(LED_5_Z, default_led_5_z);
  int default_led_6_z = 0;
  defaulti(LED_6_Z, default_led_6_z);
  int default_led_0_enabled = 1;
  defaulti(LED_0_ENABLED, default_led_0_enabled);
  int default_led_1_enabled = 1;
  defaulti(LED_1_ENABLED, default_led_1_enabled);
  int default_led_2_enabled = 1;
  defaulti(LED_2_ENABLED, default_led_2_enabled);
  int default_led_3_enabled = 1;
  defaulti(LED_3_ENABLED, default_led_3_enabled);
  int default_led_4_enabled = 1;
  defaulti(LED_4_ENABLED, default_led_4_enabled);
  int default_led_5_enabled = 1;
  defaulti(LED_5_ENABLED, default_led_5_enabled);
  int default_led_6_enabled = 1;
  defaulti(LED_6_ENABLED, default_led_6_enabled);
  int default_led_0_box = 0;
  defaulti(LED_0_BOX, default_led_0_box);
  int default_led_1_box = 0;
  defaulti(LED_1_BOX, default_led_1_box);
  int default_led_2_box = 0;
  defaulti(LED_2_BOX, default_led_2_box);
  int default_led_3_box = 0;
  defaulti(LED_3_BOX, default_led_3_box);
  int default_led_4_box = 1;
  defaulti(LED_4_BOX, default_led_4_box);
  int default_led_5_box = 1;
  defaulti(LED_5_BOX, default_led_5_box);
  int default_led_6_box = 1;
  defaulti(LED_6_BOX, default_led_6_box);
  int default_led_0_dim = 100;
  defaulti(LED_0_DIM, default_led_0_dim);
  int default_led_1_dim = 100;
  defaulti(LED_1_DIM, default_led_1_dim);
  int default_led_2_dim = 100;
  defaulti(LED_2_DIM, default_led_2_dim);
  int default_led_3_dim = 100;
  defaulti(LED_3_DIM, default_led_3_dim);
  int default_led_4_dim = 100;
  defaulti(LED_4_DIM, default_led_4_dim);
  int default_led_5_dim = 100;
  defaulti(LED_5_DIM, default_led_5_dim);
  int default_led_6_dim = 100;
  defaulti(LED_6_DIM, default_led_6_dim);
  int default_led_0_fade = 1;
  defaulti(LED_0_FADE, default_led_0_fade);
  int default_led_1_fade = 1;
  defaulti(LED_1_FADE, default_led_1_fade);
  int default_led_2_fade = 1;
  defaulti(LED_2_FADE, default_led_2_fade);
  int default_led_3_fade = 1;
  defaulti(LED_3_FADE, default_led_3_fade);
  int default_led_4_fade = 1;
  defaulti(LED_4_FADE, default_led_4_fade);
  int default_led_5_fade = 1;
  defaulti(LED_5_FADE, default_led_5_fade);
  int default_led_6_fade = 1;
  defaulti(LED_6_FADE, default_led_6_fade);

  /*
   * [/GENERATED]
   */
}

void postinit_kv() {
  /*
   * [GENERATED]
   */

  sync_ble_str(WIFI_SSID, IDX_VALUE(WIFI_SSID));
  sync_ble_str(WIFI_IP, IDX_VALUE(WIFI_IP));
  sync_ble_i(TIME, IDX_VALUE(TIME));
  sync_ble_i(STATE, IDX_VALUE(STATE));
  sync_ble_str(DEVICE_NAME, IDX_VALUE(DEVICE_NAME));
  sync_ble_i(BOX_0_TIMER_TYPE, IDX_VALUE(BOX_0_TIMER_TYPE));
  sync_ble_i(BOX_0_STARTED_AT, IDX_VALUE(BOX_0_STARTED_AT));
  sync_ble_i(BOX_0_ON_HOUR, IDX_VALUE(BOX_0_ON_HOUR));
  sync_ble_i(BOX_0_ON_MIN, IDX_VALUE(BOX_0_ON_MIN));
  sync_ble_i(BOX_0_OFF_HOUR, IDX_VALUE(BOX_0_OFF_HOUR));
  sync_ble_i(BOX_0_OFF_MIN, IDX_VALUE(BOX_0_OFF_MIN));
  sync_ble_i(BOX_0_STRETCH, IDX_VALUE(BOX_0_STRETCH));
  sync_ble_i(BOX_0_LED_DIM, IDX_VALUE(BOX_0_LED_DIM));
  sync_ble_i(BOX_0_BLOWER, IDX_VALUE(BOX_0_BLOWER));

  // Initialize non-nvs keys
  int default_wifi_status = DISCONNECTED;
  set_wifi_status(default_wifi_status);
  int default_ota_status = OTA_STATUS_IDLE;
  set_ota_status(default_ota_status);
  int default_reboot = 0;
  set_reboot(default_reboot);
  const char *default_box_0_led_info = "";
  set_box_0_led_info(default_box_0_led_info);
  const char *default_box_1_led_info = "";
  set_box_1_led_info(default_box_1_led_info);
  const char *default_box_2_led_info = "";
  set_box_2_led_info(default_box_2_led_info);


  /*
   * [/GENERATED]
   */
}

void reset_defaults() {
  const char *default_wifi_ssid = "";
  setstr(WIFI_SSID, default_wifi_ssid);
  const char *default_wifi_password = "";
  setstr(WIFI_PASSWORD, default_wifi_password);
  const char *default_wifi_ap_ssid = DEFAULT_AP_SSID;
  setstr(WIFI_AP_SSID, default_wifi_ap_ssid);
  const char *default_wifi_ap_password = DEFAULT_AP_PASSWORD;
  setstr(WIFI_AP_PASSWORD, default_wifi_ap_password);
  const char *default_mdns_domain = DEFAULT_MDNS_DOMAIN;
  setstr(MDNS_DOMAIN, default_mdns_domain);
  const char *default_wifi_ip = "0.0.0.0";
  setstr(WIFI_IP, default_wifi_ip);
  int default_time = 0;
  seti(TIME, default_time);
  int default_n_restarts = 0;
  seti(N_RESTARTS, default_n_restarts);
  int default_ota_timestamp = OTA_BUILD_TIMESTAMP;
  seti(OTA_TIMESTAMP, default_ota_timestamp);
  const char *default_ota_server_ip = CONFIG_OTA_SERVER_IP;
  setstr(OTA_SERVER_IP, default_ota_server_ip);
  const char *default_ota_server_hostname = CONFIG_OTA_SERVER_HOSTNAME;
  setstr(OTA_SERVER_HOSTNAME, default_ota_server_hostname);
  const char *default_ota_server_port = CONFIG_OTA_SERVER_PORT;
  setstr(OTA_SERVER_PORT, default_ota_server_port);
  const char *default_ota_basedir = CONFIG_OTA_BASEDIR;
  setstr(OTA_BASEDIR, default_ota_basedir);
  const char *default_broker_url = CONFIG_BROKER_URL;
  setstr(BROKER_URL, default_broker_url);
  const char *default_broker_channel = "";
  setstr(BROKER_CHANNEL, default_broker_channel);
  const char *default_broker_clientid = "";
  setstr(BROKER_CLIENTID, default_broker_clientid);
  int default_i2c_0_sda = DEFAULT_I2C_0_SDA;
  seti(I2C_0_SDA, default_i2c_0_sda);
  int default_i2c_0_scl = DEFAULT_I2C_0_SCL;
  seti(I2C_0_SCL, default_i2c_0_scl);
  int default_i2c_0_enabled = 1;
  seti(I2C_0_ENABLED, default_i2c_0_enabled);
  int default_i2c_1_sda = DEFAULT_I2C_1_SDA;
  seti(I2C_1_SDA, default_i2c_1_sda);
  int default_i2c_1_scl = DEFAULT_I2C_1_SCL;
  seti(I2C_1_SCL, default_i2c_1_scl);
  int default_i2c_1_enabled = 0;
  seti(I2C_1_ENABLED, default_i2c_1_enabled);
  int default_state = FIRST_RUN;
  seti(STATE, default_state);
  const char *default_device_name = "SuperGreenDriver";
  setstr(DEVICE_NAME, default_device_name);
  int default_box_0_enabled = 1;
  seti(BOX_0_ENABLED, default_box_0_enabled);
  int default_box_0_timer_type = TIMER_MANUAL;
  seti(BOX_0_TIMER_TYPE, default_box_0_timer_type);
  int default_box_0_timer_output = 0;
  seti(BOX_0_TIMER_OUTPUT, default_box_0_timer_output);
  int default_box_0_started_at = 0;
  seti(BOX_0_STARTED_AT, default_box_0_started_at);
  int default_box_0_on_hour = 1;
  seti(BOX_0_ON_HOUR, default_box_0_on_hour);
  int default_box_0_on_min = 0;
  seti(BOX_0_ON_MIN, default_box_0_on_min);
  int default_box_0_off_hour = 19;
  seti(BOX_0_OFF_HOUR, default_box_0_off_hour);
  int default_box_0_off_min = 0;
  seti(BOX_0_OFF_MIN, default_box_0_off_min);
  int default_box_0_stretch = 0;
  seti(BOX_0_STRETCH, default_box_0_stretch);
  int default_box_0_led_dim = 0;
  seti(BOX_0_LED_DIM, default_box_0_led_dim);
  int default_box_0_blower = 50;
  seti(BOX_0_BLOWER, default_box_0_blower);
  int default_box_0_blower_mode = BLOWER_MODE_MANUAL;
  seti(BOX_0_BLOWER_MODE, default_box_0_blower_mode);
  int default_box_0_blower_gpio = DEFAULT_BOX_0_BLOWER_GPIO;
  seti(BOX_0_BLOWER_GPIO, default_box_0_blower_gpio);
  int default_box_0_blower_enabled = 1;
  seti(BOX_0_BLOWER_ENABLED, default_box_0_blower_enabled);
  int default_box_0_sht1x_temp_c = -1000000;
  seti(BOX_0_SHT1X_TEMP_C, default_box_0_sht1x_temp_c);
  int default_box_0_sht1x_temp_f = -1000000;
  seti(BOX_0_SHT1X_TEMP_F, default_box_0_sht1x_temp_f);
  int default_box_0_sht1x_humi = -1000000;
  seti(BOX_0_SHT1X_HUMI, default_box_0_sht1x_humi);
  int default_box_0_sht21_temp_c = -1000000;
  seti(BOX_0_SHT21_TEMP_C, default_box_0_sht21_temp_c);
  int default_box_0_sht21_temp_f = -1000000;
  seti(BOX_0_SHT21_TEMP_F, default_box_0_sht21_temp_f);
  int default_box_0_sht21_humi = -1000000;
  seti(BOX_0_SHT21_HUMI, default_box_0_sht21_humi);
  int default_box_0_arduino_co2 = -1000000;
  seti(BOX_0_ARDUINO_CO2, default_box_0_arduino_co2);
  int default_box_0_dust_gpy2y10 = -1000000;
  seti(BOX_0_DUST_GPY2Y10, default_box_0_dust_gpy2y10);
  int default_box_1_enabled = 1;
  seti(BOX_1_ENABLED, default_box_1_enabled);
  int default_box_1_timer_type = TIMER_MANUAL;
  seti(BOX_1_TIMER_TYPE, default_box_1_timer_type);
  int default_box_1_timer_output = 0;
  seti(BOX_1_TIMER_OUTPUT, default_box_1_timer_output);
  int default_box_1_started_at = 0;
  seti(BOX_1_STARTED_AT, default_box_1_started_at);
  int default_box_1_on_hour = 1;
  seti(BOX_1_ON_HOUR, default_box_1_on_hour);
  int default_box_1_on_min = 0;
  seti(BOX_1_ON_MIN, default_box_1_on_min);
  int default_box_1_off_hour = 19;
  seti(BOX_1_OFF_HOUR, default_box_1_off_hour);
  int default_box_1_off_min = 0;
  seti(BOX_1_OFF_MIN, default_box_1_off_min);
  int default_box_1_stretch = 0;
  seti(BOX_1_STRETCH, default_box_1_stretch);
  int default_box_1_led_dim = 0;
  seti(BOX_1_LED_DIM, default_box_1_led_dim);
  int default_box_1_blower = 50;
  seti(BOX_1_BLOWER, default_box_1_blower);
  int default_box_1_blower_mode = BLOWER_MODE_MANUAL;
  seti(BOX_1_BLOWER_MODE, default_box_1_blower_mode);
  int default_box_1_blower_gpio = DEFAULT_BOX_1_BLOWER_GPIO;
  seti(BOX_1_BLOWER_GPIO, default_box_1_blower_gpio);
  int default_box_1_blower_enabled = 1;
  seti(BOX_1_BLOWER_ENABLED, default_box_1_blower_enabled);
  int default_box_1_sht1x_temp_c = -1000000;
  seti(BOX_1_SHT1X_TEMP_C, default_box_1_sht1x_temp_c);
  int default_box_1_sht1x_temp_f = -1000000;
  seti(BOX_1_SHT1X_TEMP_F, default_box_1_sht1x_temp_f);
  int default_box_1_sht1x_humi = -1000000;
  seti(BOX_1_SHT1X_HUMI, default_box_1_sht1x_humi);
  int default_box_1_sht21_temp_c = -1000000;
  seti(BOX_1_SHT21_TEMP_C, default_box_1_sht21_temp_c);
  int default_box_1_sht21_temp_f = -1000000;
  seti(BOX_1_SHT21_TEMP_F, default_box_1_sht21_temp_f);
  int default_box_1_sht21_humi = -1000000;
  seti(BOX_1_SHT21_HUMI, default_box_1_sht21_humi);
  int default_box_1_arduino_co2 = -1000000;
  seti(BOX_1_ARDUINO_CO2, default_box_1_arduino_co2);
  int default_box_1_dust_gpy2y10 = -1000000;
  seti(BOX_1_DUST_GPY2Y10, default_box_1_dust_gpy2y10);
  int default_box_2_enabled = 0;
  seti(BOX_2_ENABLED, default_box_2_enabled);
  int default_box_2_timer_type = TIMER_MANUAL;
  seti(BOX_2_TIMER_TYPE, default_box_2_timer_type);
  int default_box_2_timer_output = 0;
  seti(BOX_2_TIMER_OUTPUT, default_box_2_timer_output);
  int default_box_2_started_at = 0;
  seti(BOX_2_STARTED_AT, default_box_2_started_at);
  int default_box_2_on_hour = 1;
  seti(BOX_2_ON_HOUR, default_box_2_on_hour);
  int default_box_2_on_min = 0;
  seti(BOX_2_ON_MIN, default_box_2_on_min);
  int default_box_2_off_hour = 19;
  seti(BOX_2_OFF_HOUR, default_box_2_off_hour);
  int default_box_2_off_min = 0;
  seti(BOX_2_OFF_MIN, default_box_2_off_min);
  int default_box_2_stretch = 0;
  seti(BOX_2_STRETCH, default_box_2_stretch);
  int default_box_2_led_dim = 0;
  seti(BOX_2_LED_DIM, default_box_2_led_dim);
  int default_box_2_blower = 50;
  seti(BOX_2_BLOWER, default_box_2_blower);
  int default_box_2_blower_mode = BLOWER_MODE_MANUAL;
  seti(BOX_2_BLOWER_MODE, default_box_2_blower_mode);
  int default_box_2_blower_gpio = DEFAULT_BOX_2_BLOWER_GPIO;
  seti(BOX_2_BLOWER_GPIO, default_box_2_blower_gpio);
  int default_box_2_blower_enabled = 0;
  seti(BOX_2_BLOWER_ENABLED, default_box_2_blower_enabled);
  int default_box_2_sht1x_temp_c = -1000000;
  seti(BOX_2_SHT1X_TEMP_C, default_box_2_sht1x_temp_c);
  int default_box_2_sht1x_temp_f = -1000000;
  seti(BOX_2_SHT1X_TEMP_F, default_box_2_sht1x_temp_f);
  int default_box_2_sht1x_humi = -1000000;
  seti(BOX_2_SHT1X_HUMI, default_box_2_sht1x_humi);
  int default_box_2_sht21_temp_c = -1000000;
  seti(BOX_2_SHT21_TEMP_C, default_box_2_sht21_temp_c);
  int default_box_2_sht21_temp_f = -1000000;
  seti(BOX_2_SHT21_TEMP_F, default_box_2_sht21_temp_f);
  int default_box_2_sht21_humi = -1000000;
  seti(BOX_2_SHT21_HUMI, default_box_2_sht21_humi);
  int default_box_2_arduino_co2 = -1000000;
  seti(BOX_2_ARDUINO_CO2, default_box_2_arduino_co2);
  int default_box_2_dust_gpy2y10 = -1000000;
  seti(BOX_2_DUST_GPY2Y10, default_box_2_dust_gpy2y10);
  int default_led_0_duty = 0;
  seti(LED_0_DUTY, default_led_0_duty);
  int default_led_1_duty = 0;
  seti(LED_1_DUTY, default_led_1_duty);
  int default_led_2_duty = 0;
  seti(LED_2_DUTY, default_led_2_duty);
  int default_led_3_duty = 0;
  seti(LED_3_DUTY, default_led_3_duty);
  int default_led_4_duty = 0;
  seti(LED_4_DUTY, default_led_4_duty);
  int default_led_5_duty = 0;
  seti(LED_5_DUTY, default_led_5_duty);
  int default_led_6_duty = 0;
  seti(LED_6_DUTY, default_led_6_duty);
  int default_led_0_gpio = DEFAULT_LED_0_GPIO;
  seti(LED_0_GPIO, default_led_0_gpio);
  int default_led_1_gpio = DEFAULT_LED_1_GPIO;
  seti(LED_1_GPIO, default_led_1_gpio);
  int default_led_2_gpio = DEFAULT_LED_2_GPIO;
  seti(LED_2_GPIO, default_led_2_gpio);
  int default_led_3_gpio = DEFAULT_LED_3_GPIO;
  seti(LED_3_GPIO, default_led_3_gpio);
  int default_led_4_gpio = DEFAULT_LED_4_GPIO;
  seti(LED_4_GPIO, default_led_4_gpio);
  int default_led_5_gpio = DEFAULT_LED_5_GPIO;
  seti(LED_5_GPIO, default_led_5_gpio);
  int default_led_6_gpio = DEFAULT_LED_6_GPIO;
  seti(LED_6_GPIO, default_led_6_gpio);
  int default_led_0_x = 0;
  seti(LED_0_X, default_led_0_x);
  int default_led_1_x = 0;
  seti(LED_1_X, default_led_1_x);
  int default_led_2_x = 0;
  seti(LED_2_X, default_led_2_x);
  int default_led_3_x = 0;
  seti(LED_3_X, default_led_3_x);
  int default_led_4_x = 0;
  seti(LED_4_X, default_led_4_x);
  int default_led_5_x = 0;
  seti(LED_5_X, default_led_5_x);
  int default_led_6_x = 0;
  seti(LED_6_X, default_led_6_x);
  int default_led_0_y = 0;
  seti(LED_0_Y, default_led_0_y);
  int default_led_1_y = 0;
  seti(LED_1_Y, default_led_1_y);
  int default_led_2_y = 0;
  seti(LED_2_Y, default_led_2_y);
  int default_led_3_y = 0;
  seti(LED_3_Y, default_led_3_y);
  int default_led_4_y = 0;
  seti(LED_4_Y, default_led_4_y);
  int default_led_5_y = 0;
  seti(LED_5_Y, default_led_5_y);
  int default_led_6_y = 0;
  seti(LED_6_Y, default_led_6_y);
  int default_led_0_z = 0;
  seti(LED_0_Z, default_led_0_z);
  int default_led_1_z = 0;
  seti(LED_1_Z, default_led_1_z);
  int default_led_2_z = 0;
  seti(LED_2_Z, default_led_2_z);
  int default_led_3_z = 0;
  seti(LED_3_Z, default_led_3_z);
  int default_led_4_z = 0;
  seti(LED_4_Z, default_led_4_z);
  int default_led_5_z = 0;
  seti(LED_5_Z, default_led_5_z);
  int default_led_6_z = 0;
  seti(LED_6_Z, default_led_6_z);
  int default_led_0_enabled = 1;
  seti(LED_0_ENABLED, default_led_0_enabled);
  int default_led_1_enabled = 1;
  seti(LED_1_ENABLED, default_led_1_enabled);
  int default_led_2_enabled = 1;
  seti(LED_2_ENABLED, default_led_2_enabled);
  int default_led_3_enabled = 1;
  seti(LED_3_ENABLED, default_led_3_enabled);
  int default_led_4_enabled = 1;
  seti(LED_4_ENABLED, default_led_4_enabled);
  int default_led_5_enabled = 1;
  seti(LED_5_ENABLED, default_led_5_enabled);
  int default_led_6_enabled = 1;
  seti(LED_6_ENABLED, default_led_6_enabled);
  int default_led_0_box = 0;
  seti(LED_0_BOX, default_led_0_box);
  int default_led_1_box = 0;
  seti(LED_1_BOX, default_led_1_box);
  int default_led_2_box = 0;
  seti(LED_2_BOX, default_led_2_box);
  int default_led_3_box = 0;
  seti(LED_3_BOX, default_led_3_box);
  int default_led_4_box = 1;
  seti(LED_4_BOX, default_led_4_box);
  int default_led_5_box = 1;
  seti(LED_5_BOX, default_led_5_box);
  int default_led_6_box = 1;
  seti(LED_6_BOX, default_led_6_box);
  int default_led_0_dim = 100;
  seti(LED_0_DIM, default_led_0_dim);
  int default_led_1_dim = 100;
  seti(LED_1_DIM, default_led_1_dim);
  int default_led_2_dim = 100;
  seti(LED_2_DIM, default_led_2_dim);
  int default_led_3_dim = 100;
  seti(LED_3_DIM, default_led_3_dim);
  int default_led_4_dim = 100;
  seti(LED_4_DIM, default_led_4_dim);
  int default_led_5_dim = 100;
  seti(LED_5_DIM, default_led_5_dim);
  int default_led_6_dim = 100;
  seti(LED_6_DIM, default_led_6_dim);
  int default_led_0_fade = 1;
  seti(LED_0_FADE, default_led_0_fade);
  int default_led_1_fade = 1;
  seti(LED_1_FADE, default_led_1_fade);
  int default_led_2_fade = 1;
  seti(LED_2_FADE, default_led_2_fade);
  int default_led_3_fade = 1;
  seti(LED_3_FADE, default_led_3_fade);
  int default_led_4_fade = 1;
  seti(LED_4_FADE, default_led_4_fade);
  int default_led_5_fade = 1;
  seti(LED_5_FADE, default_led_5_fade);
  int default_led_6_fade = 1;
  seti(LED_6_FADE, default_led_6_fade);
}

bool hasi(const char * key) {
  int32_t value;
  esp_err_t err = nvs_get_i32(kv_handle, (const char *)key, &value);
  return err == ESP_OK;
}

int geti(const char * key) {
  int32_t value;
  esp_err_t err = nvs_get_i32(kv_handle, (const char *)key, &value);
  ESP_ERROR_CHECK(err);
  return (int)value;
}

void seti(const char * key, int value) {
  esp_err_t err = nvs_set_i32(kv_handle, (const char *)key, (int32_t)value);
  ESP_ERROR_CHECK(err);
  nvs_commit(kv_handle);
}

void defaulti(const char * key, int value) {
  if (!hasi(key)) {
    seti(key, value);
  }
}

bool hasstr(const char * key) {
  size_t length;
  esp_err_t err = nvs_get_str(kv_handle, (const char *)key, NULL, &length);
  return err == ESP_OK;
}

void getstr(const char * key, char *value, size_t length) {
  esp_err_t err = nvs_get_str(kv_handle, key, value, &length);
  ESP_ERROR_CHECK(err);
}

void setstr(const char * key, const char * value) {
  esp_err_t err = nvs_set_str(kv_handle, (const char *)key, value);
  ESP_ERROR_CHECK(err);
  nvs_commit(kv_handle);
}

void defaultstr(const char * key, const char * value) {
  if (!hasstr(key)) {
    setstr(key, value);
  }
}
