/*
 * UART Custom Configuration Example
 * Description: Demonstrates how to configure UART with custom settings.
 */

#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart1

int main() {
    uart_init(UART_ID, 19200);
    gpio_set_function(4, GPIO_FUNC_UART); // TX
    gpio_set_function(5, GPIO_FUNC_UART); // RX

    uart_set_hw_flow(UART_ID, false, false);
    uart_set_format(UART_ID, 7, 2, UART_PARITY_EVEN);
    uart_puts(UART_ID, "Custom UART config\n");

    while (true) {
        sleep_ms(1000);
    }
}