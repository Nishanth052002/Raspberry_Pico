/*
 * Baremetal Example: Pull-up Resistor
 * Description: Configure GPIO 14 with pull-up resistor.
 */
#define IO_BANK0_BASE 0x40014000
#define PADS_BANK0_BASE 0x4001C000
#define GPIO14_CTRL (IO_BANK0_BASE + 0x0E0)
#define PAD14 (PADS_BANK0_BASE + 0x038)

void delay(volatile int count) {
    while (count-- > 0) __asm volatile("nop");
}

int main() {
    *((volatile unsigned int*)GPIO14_CTRL) = 5; // Set function to SIO
    *((volatile unsigned int*)PAD14) |= (1 << 3); // Enable pull-up

    while (1) {
        delay(50000);
    }
}
