/*
 * Example: Button Input
 * Description: Reads a digital button connected to GPIO 14 and prints its state.
 */
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    const uint BUTTON_PIN = 14;
    stdio_init_all();                    // Initialize standard IO
    gpio_init(BUTTON_PIN);               // Initialize the GPIO pin
    gpio_set_dir(BUTTON_PIN, GPIO_IN);   // Set pin as input

    while (true) {
        if (gpio_get(BUTTON_PIN)) {
            printf("Button Pressed\n");
        } else {
            printf("Button Released\n");
        }
        sleep_ms(200);                   // Delay to avoid bouncing
    }
}
