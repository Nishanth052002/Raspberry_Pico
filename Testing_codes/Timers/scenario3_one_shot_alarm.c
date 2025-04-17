#include "pico/stdlib.h"
#include <stdio.h>

int64_t alarm_callback(alarm_id_t id, void *user_data) {
    printf("One-shot alarm triggered!\n");
    return 0;
}

int main() {
    stdio_init_all();
    add_alarm_in_ms(3000, alarm_callback, NULL, true);
    while (1) {
        tight_loop_contents();
    }
}
