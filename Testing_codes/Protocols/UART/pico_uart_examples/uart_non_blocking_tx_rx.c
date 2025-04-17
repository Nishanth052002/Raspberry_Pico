/*
 * UART Non-blocking TX/RX Example
 * Description: Demonstrates how to check UART status before sending/receiving data
 * to avoid blocking the main loop.
 */

#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart0

int main() {
    uart_init(UART_ID, 115200);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    while (true) {
        if (uart_is_writable(UART_ID)) {
            uart_putc(UART_ID, 'X'); // Transmit character when UART is ready
        }
        if (uart_is_readable(UART_ID)) {
            char ch = uart_getc(UART_ID); // Read if data is available
            uart_putc(UART_ID, ch); // Echo back
        }
        sleep_ms(100); // Small delay
    }
}