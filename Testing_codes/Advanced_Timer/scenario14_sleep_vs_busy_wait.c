
#include "pico/stdlib.h"
#include <stdio.h>

void busy_wait_us(uint64_t us) {
    uint64_t start = time_us_64();
    while (time_us_64() - start < us);
}

int main() {
    stdio_init_all();
    printf("Testing busy-wait vs sleep_us
");

    uint64_t start, end;

    start = time_us_64();
    sleep_us(500);
    end = time_us_64();
    printf("sleep_us(500): %llu us
", end - start);

    start = time_us_64();
    busy_wait_us(500);
    end = time_us_64();
    printf("busy_wait_us(500): %llu us
", end - start);

    while (1) tight_loop_contents();
}
