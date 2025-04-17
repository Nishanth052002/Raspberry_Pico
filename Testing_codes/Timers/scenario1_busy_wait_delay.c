
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    while (1) {
        printf("LED ON\n");
        sleep_ms(1000); // Delay 1 second
        printf("LED OFF\n");
        sleep_ms(1000);
    }
}
