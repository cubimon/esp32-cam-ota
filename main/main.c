#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#include "wifi.h"
#include "ota_server.h"
#include "webserver.h"
#include "light.h"
#include "camera.h"

void app_main() {
    // disable brown detection
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);

    // initialize nvs
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    static httpd_handle_t server = NULL;
    init_wifi_softap();
    init_ota_server();
    server = start_webserver();
    init_light();
    init_camera();
}
