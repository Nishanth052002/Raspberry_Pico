
#include "pico/stdlib.h"
#include <stdio.h>

enum State { IDLE, RUNNING, DONE };
enum State current_state = IDLE;

bool state_timer(struct repeating_timer *t) {
    switch (current_state) {
        case IDLE:    printf("State: IDLE -> RUNNING
"); current_state = RUNNING; break;
        case RUNNING: printf("State: RUNNING -> DONE
"); current_state = DONE; break;
        case DONE:    printf("State: DONE -> IDLE
"); current_state = IDLE; break;
    }
    return true;
}

int main() {
    stdio_init_all();
    add_repeating_timer_ms(2000, state_timer, NULL, NULL);
    while (1) tight_loop_contents();
}
