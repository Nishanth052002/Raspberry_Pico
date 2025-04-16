/*
 * Example: GPIO Interrupt
 * Description: Demonstrates setting up a GPIO interrupt on falling edge for GPIO 15.
 */
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <stdio.h>

void gpio_callback(uint gpio, uint32_t events) {
    printf("Interrupt on GPIO %d\n", gpio);
}

int main() {
    const uint INTERRUPT_PIN = 15;
    stdio_init_all();                        // Initialize standard IO
    gpio_init(INTERRUPT_PIN);               // Initialize the GPIO pin
    gpio_set_dir(INTERRUPT_PIN, GPIO_IN);   // Set as input
    gpio_pull_up(INTERRUPT_PIN);            // Enable pull-up resistor

    // Enable interrupt on falling edge
    gpio_set_irq_enabled_with_callback(INTERRUPT_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        tight_loop_contents();              // Wait for interrupts
    }
}