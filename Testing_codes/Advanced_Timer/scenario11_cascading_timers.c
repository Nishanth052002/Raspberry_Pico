
#include "pico/stdlib.h"
#include <stdio.h>

int64_t second_callback(alarm_id_t id, void *user_data) {
    printf("[Second Timer] Triggered after First");
    return 0;
}

int64_t first_callback(alarm_id_t id, void *user_data) {
    printf("[First Timer] Triggered");
    add_alarm_in_ms(1000, second_callback, NULL, true);
    return 0;
}

int main() {
    stdio_init_all();
    printf("Starting Cascading Timers...");
    add_alarm_in_ms(1000, first_callback, NULL, true);
    while (1) tight_loop_contents();
}
