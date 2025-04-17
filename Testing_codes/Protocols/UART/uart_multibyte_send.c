/*
 * UART Multi-byte Send Example
 * Description: Shows how to send strings and buffers over UART using uart_write_blocking.
 */

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>

#define UART_ID uart0

int main() {
    uart_init(UART_ID, 115200);
    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    const char* msg = "Sending message via uart_write_blocking\n";

    while (true) {
        uart_write_blocking(UART_ID, (const uint8_t*)msg, strlen(msg));
        sleep_ms(2000);
    }
}