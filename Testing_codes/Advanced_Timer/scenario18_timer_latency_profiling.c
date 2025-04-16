#include "pico/stdlib.h"
#include <stdio.h>

const uint LED_PIN = 25;

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    gpio_put(LED_PIN, 1); // Set pin high on trigger
    sleep_us(10);         // Keep it high for a short time
    gpio_put(LED_PIN, 0); // Set pin low
    return 0;
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    add_alarm_in_ms(1000, alarm_callback, NULL, true);
    while (1) tight_loop_contents();
}
