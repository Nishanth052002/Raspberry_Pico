
#include "pico/stdlib.h"
#include <stdio.h>

struct repeating_timer timer;

bool callback(struct repeating_timer *t) {
    static int count = 0;
    printf("Timer %d\n", count++);
    if (count == 5) {
        cancel_repeating_timer(t);
        printf("Timer canceled\n");
    }
    return true;
}

int main() {
    stdio_init_all();
    add_repeating_timer_ms(1000, callback, NULL, &timer);
    while (1) {
        tight_loop_contents();
    }
}
