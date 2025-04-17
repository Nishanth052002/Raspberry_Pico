
#include "pico/stdlib.h"
#include <stdio.h>

int64_t nested_timer_callback(alarm_id_t id, void *user_data) {
    printf("[Nested Timer] Second timer triggered!\n");
    return 0;
}

int64_t first_timer_callback(alarm_id_t id, void *user_data) {
    printf("[Nested Timer] First timer triggered. Scheduling second...\n");
    add_alarm_in_ms(2000, nested_timer_callback, NULL, true);
    return 0;
}

int main() {
    stdio_init_all();
    printf("Starting Nested Timer Demo...\n");
    add_alarm_in_ms(1000, first_timer_callback, NULL, true);
    while (1) {
        tight_loop_contents();
    }
}
