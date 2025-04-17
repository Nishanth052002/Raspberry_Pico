
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>

void core1_entry() {
    while (1) {
        sleep_ms(3000);
        printf("[Core 1] Running independently every 3 seconds\n");
    }
}

int main() {
    stdio_init_all();
    printf("Starting Multicore Timer Demo...\n");

    multicore_launch_core1(core1_entry);

    while (1) {
        printf("[Core 0] Main loop...\n");
        sleep_ms(1000);
    }
}
