#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/gpio.h"
#include "esp_system.h"
#include "esp_log.h"

#define LDR_ADC_CHANNEL ADC1_CHANNEL_3  // GPIO39 trên ESP32
#define LED_GPIO_PIN GPIO_NUM_2  // Đảm bảo sử dụng kiểu dữ liệu gpio_num_t

extern "C" void app_main() {
    // Cấu hình ADC
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(LDR_ADC_CHANNEL, ADC_ATTEN_DB_0); // Sử dụng giá trị attenuation thấp hơn

    // Cấu hình chân LED làm ngõ ra
    gpio_reset_pin(LED_GPIO_PIN);  // Sử dụng hàm mới thay vì gpio_pad_select_gpio
    gpio_set_direction(LED_GPIO_PIN, GPIO_MODE_OUTPUT);

    while (true) {
        int ldr_value = adc1_get_raw(LDR_ADC_CHANNEL);  // Đọc giá trị từ quang trở
        printf("LDR Value: %d\n", ldr_value);  // In giá trị ra UART

        // Điều khiển LED dựa trên giá trị LDR
        if (ldr_value < 2000) {
            gpio_set_level(LED_GPIO_PIN, 1);  // Bật LED nếu ánh sáng yếu
        } else {
            gpio_set_level(LED_GPIO_PIN, 0);  // Tắt LED nếu ánh sáng mạnh
        }

        vTaskDelay(pdMS_TO_TICKS(500));  // Đợi 0.5 giây trước khi đọc lại
    }
}
