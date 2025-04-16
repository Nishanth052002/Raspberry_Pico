
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    printf("Starting Timer Precision Test...\n");

    uint64_t start = time_us_64();
    sleep_ms(100);  // Simulated task
    uint64_t end = time_us_64();

    printf("[Precision Test] Elapsed time: %llu us (Expected ~100000 us)\n", end - start);
    while (1) {
        tight_loop_contents();
    }
}
