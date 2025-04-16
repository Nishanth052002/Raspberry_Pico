
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    uint64_t start = time_us_64();
    sleep_ms(100);
    uint64_t end = time_us_64();
    printf("Elapsed time: %llu us\n", end - start);
}
