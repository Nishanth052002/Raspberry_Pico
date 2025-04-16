#include "pico/stdlib.h"
#include "pico/multicore.h"
#include <stdio.h>
#include <stdbool.h>

volatile bool trigger = false;

bool timer_callback(struct repeating_timer *t) {
    trigger = true;
    return true;
}

void core1_entry() {
    while (1) {
        if (trigger) {
            printf("Core 1 received trigger!");
            trigger = false;
        }
    }
}

int main() {
    stdio_init_all();
    multicore_launch_core1(core1_entry);
    add_repeating_timer_ms(1500, timer_callback, NULL, NULL);
    while (1) tight_loop_contents();
}
