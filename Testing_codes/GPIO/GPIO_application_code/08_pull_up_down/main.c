/*
 * Example: Pull-up/down resistors
 * Description: Demonstrates enabling pull-up resistor on GPIO 14.
 */
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    const uint PIN = 14;
    stdio_init_all();               // Initialize stdio
    gpio_init(PIN);
    gpio_set_dir(PIN, GPIO_IN);
    gpio_pull_up(PIN);             // Enable pull-up resistor

    while (true) {
        printf("Pin state: %d\n", gpio_get(PIN));
        sleep_ms(500);
    }
}
