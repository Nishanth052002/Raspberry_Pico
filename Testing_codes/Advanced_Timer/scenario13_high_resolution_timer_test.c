
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    printf("High Resolution Timer Test");

    uint64_t start = time_us_64();
    sleep_us(200);
    uint64_t end = time_us_64();

    printf("Elapsed (expected ~200 us): %llu us", end - start);
    while (1) tight_loop_contents();
}
