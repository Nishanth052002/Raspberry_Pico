/*
 * Baremetal Example: ADC Read
 * Description: Read raw ADC value from GPIO 26 (ADC0) using direct register access.
 */
#define RESETS_BASE     0x4000C000
#define RESET_ADC       (1 << 30)
#define ADC_BASE        0x4004C000
#define ADC_CS          (*(volatile unsigned int *)(ADC_BASE + 0x00))
#define ADC_RESULT      (*(volatile unsigned int *)(ADC_BASE + 0x04))
#define ADC_INSEL       0   // GPIO26 is ADC0

void delay(volatile int count) {
    while (count-- > 0) __asm volatile("nop");
}

int main() {
    *((volatile unsigned int*)(RESETS_BASE + 0x0)) |= RESET_ADC;
    *((volatile unsigned int*)(RESETS_BASE + 0x0)) &= ~RESET_ADC;

    ADC_CS = (1 << 0);        // Enable ADC
    ADC_CS &= ~(0x7 << 4);    // Clear AINSEL
    ADC_CS |= (ADC_INSEL << 4); // Select ADC0

    while (1) {
        ADC_CS |= (1 << 3); // Start conversion
        while (!(ADC_CS & (1 << 8))); // Wait for ready
        unsigned int result = ADC_RESULT & 0xFFF;
        delay(100000);
    }
}
