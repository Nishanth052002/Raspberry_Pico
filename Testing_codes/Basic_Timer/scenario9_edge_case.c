
#include "pico/stdlib.h"
#include <stdio.h>

int64_t zero_delay_callback(alarm_id_t id, void *user_data) {
    printf("[Edge Case] Zero-delay alarm triggered!\n");
    return 0;
}

int main() {
    stdio_init_all();
    printf("Starting Edge Case Timer Test...\n");

    // Test zero delay
    add_alarm_in_ms(0, zero_delay_callback, NULL, true);

    // Try to cancel an invalid timer
    bool result = cancel_alarm((alarm_id_t)999);
    printf("[Edge Case] Cancel result for invalid ID: %s\n", result ? "Success" : "Failure");

    while (1) {
        tight_loop_contents();
    }
}
