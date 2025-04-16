/*
 * Baremetal Example: Button Input
 * Description: Reads GPIO 14 and sets GPIO 25 accordingly without SDK.
 */
#define BUTTON_PIN 14
#define LED_PIN 25
#define SIO_BASE 0xD0000000
#define GPIO_OE (SIO_BASE + 0x020)
#define GPIO_IN (SIO_BASE + 0x004)
#define GPIO_OUT_SET (SIO_BASE + 0x014)
#define GPIO_OUT_CLR (SIO_BASE + 0x018)

void delay(volatile int count) {
    while (count-- > 0) __asm volatile("nop");
}

int main() {
    *((volatile unsigned int*)GPIO_OE) |= (1 << LED_PIN);    // LED as output
    *((volatile unsigned int*)GPIO_OE) &= ~(1 << BUTTON_PIN); // Button as input

    while (1) {
        if (*((volatile unsigned int*)GPIO_IN) & (1 << BUTTON_PIN)) {
            *((volatile unsigned int*)GPIO_OUT_SET) = (1 << LED_PIN); // Turn on
        } else {
            *((volatile unsigned int*)GPIO_OUT_CLR) = (1 << LED_PIN); // Turn off
        }
        delay(50000);
    }
}