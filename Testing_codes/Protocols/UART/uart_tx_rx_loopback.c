/*
 * UART Loopback Example
 * Description: Sends and receives data using UART0. Connect TX to RX for loopback.
 */

#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart0
#define BAUD_RATE 9600

int main() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(0, GPIO_FUNC_UART); // TX
    gpio_set_function(1, GPIO_FUNC_UART); // RX

    while (true) {
        if (uart_is_readable(UART_ID)) {
            uint8_t ch = uart_getc(UART_ID);
            uart_putc(UART_ID, ch); // Echo back
        }
    }
}