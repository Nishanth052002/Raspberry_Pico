
#include "pico/stdlib.h"
#include <stdio.h>

bool timer_callback(struct repeating_timer *t) {
    printf("Timer fired under load!
");
    return true;
}

int main() {
    stdio_init_all();
    add_repeating_timer_ms(1000, timer_callback, NULL, NULL);

    while (1) {
        // Simulate load
        for (volatile int i = 0; i < 1000000; ++i);
    }
}
