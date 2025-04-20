#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "blink.pio.h"

#define LED_PIN 25

int main() {
    stdio_init_all();
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &blink_program);
    uint sm = pio_claim_unused_sm(pio, true);
    blink_program_init(pio, sm, offset, LED_PIN);
    while (1) {
        tight_loop_contents();
    }
}