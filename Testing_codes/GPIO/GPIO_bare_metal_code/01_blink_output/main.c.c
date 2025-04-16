/*
 * Baremetal Example: Blink an LED
 * Description: Blinks GPIO 25 using SIO registers without SDK functions.
 */
#define LED_PIN 25
#define SIO_BASE 0xD0000000
#define GPIO_OUT_XOR (SIO_BASE + 0x01C)
#define GPIO_OE (SIO_BASE + 0x020)

void delay(volatile int count) {
    while (count-- > 0) __asm volatile("nop");
}

int main() {
    *((volatile unsigned int*)GPIO_OE) |= (1 << LED_PIN); // Set pin as output

    while (1) {
        *((volatile unsigned int*)GPIO_OUT_XOR) = (1 << LED_PIN); // Toggle LED
        delay(1000000);
    }
}