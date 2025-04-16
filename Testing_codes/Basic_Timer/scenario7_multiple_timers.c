
#include "pico/stdlib.h"
#include <stdio.h>

bool timer1_callback(struct repeating_timer *t) {
    printf("🔄 [Timer1 - 1000ms] Tick\n");
    return true;
}

bool timer2_callback(struct repeating_timer *t) {
    printf("🔄 [Timer2 - 500ms] Tick\n");
    return true;
}

int main() {
    stdio_init_all();
    printf("Starting Multiple Timers Demo...\n");

    static struct repeating_timer timer1, timer2;
    add_repeating_timer_ms(1000, timer1_callback, NULL, &timer1);
    add_repeating_timer_ms(500, timer2_callback, NULL, &timer2);

    while (1) {
        tight_loop_contents();
    }
}
