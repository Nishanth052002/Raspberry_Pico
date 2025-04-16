/*
 * Example: Analog Input (ADC)
 * Description: Reads analog voltage on GPIO 26 (ADC0) and prints the raw value.
 */
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include <stdio.h>

int main() {
    stdio_init_all();    // Initialize standard IO
    adc_init();          // Initialize ADC peripheral
    adc_gpio_init(26);   // Initialize GPIO 26 as ADC input
    adc_select_input(0); // Select ADC input 0 (GPIO 26)

    while (true) {
        uint16_t result = adc_read();           // Read ADC value
        printf("ADC Value: %d\n", result);     // Print result
        sleep_ms(500);
    }
}