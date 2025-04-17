/*
 * UART Hello World
 * Description: Sends "Hello, UART!" over UART0.
 */

#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    while (true) {
        printf("Hello, UART!\n");
        sleep_ms(1000);
    }
}