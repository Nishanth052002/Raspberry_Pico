/*
 * UART FIFO Usage Example
 * Description: Demonstrates enabling/disabling FIFO buffers and how it affects communication.
 */

#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart0

int main() {
    uart_init(UART_ID, 9600);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    // Disable FIFO (optional to see impact)
    uart_set_fifo_enabled(UART_ID, false);

    printf("UART FIFO disabled. Type something:
");

    while (true) {
        if (uart_is_readable(UART_ID)) {
            char ch = uart_getc(UART_ID);
            uart_putc(UART_ID, ch); // Echo back
        }
    }
}