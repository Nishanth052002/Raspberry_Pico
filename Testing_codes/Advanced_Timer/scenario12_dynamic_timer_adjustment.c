
#include "pico/stdlib.h"
#include <stdio.h>

struct repeating_timer timer;
int interval = 1000;

bool callback(struct repeating_timer *t) {
    static int count = 0;
    printf("⏲️ Tick %d (Interval: %d ms)
", count++, interval);
    if (count == 5) {
        interval = 500;
        cancel_repeating_timer(&timer);
        add_repeating_timer_ms(interval, callback, NULL, &timer);
        printf("🔁 Interval adjusted to 500 ms
");
    }
    return true;
}

int main() {
    stdio_init_all();
    add_repeating_timer_ms(interval, callback, NULL, &timer);
    while (1) tight_loop_contents();
}
