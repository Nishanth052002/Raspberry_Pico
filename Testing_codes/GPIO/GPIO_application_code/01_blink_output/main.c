/*
 * Example: Blink an LED
 * Description: This example blinks the onboard LED (GPIO 25) every 500 milliseconds.
 */
#include "pico/stdlib.h"

int main() {
    const uint LED_PIN = 25;
    gpio_init(LED_PIN);                  // Initialize the GPIO pin
    gpio_set_dir(LED_PIN, GPIO_OUT);     // Set the pin as output

    while (true) {
        gpio_put(LED_PIN, 1);            // Turn LED on
        sleep_ms(500);                   // Wait for 500 ms
        gpio_put(LED_PIN, 0);            // Turn LED off
        sleep_ms(500);                   // Wait for 500 ms
    }
}
