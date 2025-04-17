
#include "pico/stdlib.h"
#include <stdio.h>

bool timer_callback(struct repeating_timer *t) {
    printf("Timer fired!\n");
    return true; // keep repeating
}

int main() {
    stdio_init_all();
    struct repeating_timer timer;
    add_repeating_timer_ms(1000, timer_callback, NULL, &timer);
    while (1) {
        tight_loop_contents();
    }
}
