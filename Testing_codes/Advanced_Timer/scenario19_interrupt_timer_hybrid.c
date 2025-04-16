#include "pico/stdlib.h"
#include <stdio.h>
#include "hardware/gpio.h"

const uint LED_PIN = 25;

bool timer_callback(struct repeating_timer *t) {
    gpio_put(LED_PIN, !gpio_get(LED_PIN));
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    add_repeating_timer_ms(200, timer_callback, NULL, NULL);
    while (1) tight_loop_contents();
}
