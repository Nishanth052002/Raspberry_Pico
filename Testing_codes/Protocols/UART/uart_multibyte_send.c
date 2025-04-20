/*
 * UART Multi-byte Send Example
 * Description: Shows how to send strings and buffers over UART using uart_write_blocking.
 */

#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>

#define UART_ID uart1

int main() {
    uart_init(UART_ID, 115200);
    gpio_set_function(4, GPIO_FUNC_UART);
    gpio_set_function(5, GPIO_FUNC_UART);

    const char* msg = "Sending message via uart_write_blocking\n";

    /*-Send raw byte buffers of any kind
     -uint8_t* buffer + length
     -Flexible — works for both text and binary
     -No — you specify the exact number of bytes
     -Yes — can send any binary data
     -You specify how many bytes to send
     -Better for structured or custom protocols
*/

    while (true) {
        uart_write_blocking(UART_ID, (const uint8_t*)msg, strlen(msg));
        sleep_ms(2000);
    }
}