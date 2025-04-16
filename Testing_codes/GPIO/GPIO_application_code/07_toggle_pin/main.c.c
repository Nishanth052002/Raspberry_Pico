/*
 * Example: Toggle GPIO Pin
 * Description: Toggles GPIO 25 (onboard LED) every 500ms using XOR mask.
 */
#include "pico/stdlib.h"

int main() {
    const uint TOGGLE_PIN = 25;
    gpio_init(TOGGLE_PIN);
    gpio_set_dir(TOGGLE_PIN, GPIO_OUT);

    while (true) {
        gpio_xor_mask(1 << TOGGLE_PIN); // Toggle pin using XOR mask
        sleep_ms(500);
    }
}