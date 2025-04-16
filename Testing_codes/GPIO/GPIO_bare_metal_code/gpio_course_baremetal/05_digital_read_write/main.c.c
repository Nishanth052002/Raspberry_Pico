/*
 * Baremetal Example: Digital Read and Write
 * Description: Mirror input from GPIO 14 to GPIO 25 using SIO.
 */
#define INPUT_PIN 14
#define OUTPUT_PIN 25
#define SIO_BASE 0xD0000000
#define GPIO_OE (SIO_BASE + 0x020)
#define GPIO_IN (SIO_BASE + 0x004)
#define GPIO_OUT_SET (SIO_BASE + 0x014)
#define GPIO_OUT_CLR (SIO_BASE + 0x018)

void delay(volatile int count) {
    while (count-- > 0) __asm volatile("nop");
}

int main() {
    *((volatile unsigned int*)GPIO_OE) |= (1 << OUTPUT_PIN);
    *((volatile unsigned int*)GPIO_OE) &= ~(1 << INPUT_PIN);

    while (1) {
        if (*((volatile unsigned int*)GPIO_IN) & (1 << INPUT_PIN)) {
            *((volatile unsigned int*)GPIO_OUT_SET) = (1 << OUTPUT_PIN);
        } else {
            *((volatile unsigned int*)GPIO_OUT_CLR) = (1 << OUTPUT_PIN);
        }
        delay(30000);
    }
}