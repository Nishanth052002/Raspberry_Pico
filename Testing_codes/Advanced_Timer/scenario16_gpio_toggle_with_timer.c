
#include "pico/stdlib.h"
#include <stdio.h"

const uint LED_PIN = 25;

bool toggle_callback(struct repeating_timer *t) {
    static bool state = false;
    gpio_put(LED_PIN, state);
    state = !state;
    return true;
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    add_repeating_timer_ms(500, toggle_callback, NULL, NULL);
    while (1) tight_loop_contents();
}
