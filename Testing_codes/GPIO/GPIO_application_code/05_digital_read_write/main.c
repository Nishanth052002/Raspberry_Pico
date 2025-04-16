/*
 * Example: Digital Read & Write
 * Description: Reads a digital signal on GPIO 14 and mirrors it to GPIO 25.
 */
#include "pico/stdlib.h"

int main() {
    const uint INPUT_PIN = 14;
    const uint OUTPUT_PIN = 25;

    gpio_init(INPUT_PIN);                  // Initialize input pin
    gpio_set_dir(INPUT_PIN, GPIO_IN);      // Set as input

    gpio_init(OUTPUT_PIN);                 // Initialize output pin
    gpio_set_dir(OUTPUT_PIN, GPIO_OUT);    // Set as output

    while (true) {
        bool state = gpio_get(INPUT_PIN);  // Read input state
        gpio_put(OUTPUT_PIN, state);       // Output the same state
        sleep_ms(50);
    }
}
