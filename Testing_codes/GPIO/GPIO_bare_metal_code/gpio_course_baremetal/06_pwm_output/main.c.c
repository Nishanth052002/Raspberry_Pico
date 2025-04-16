/*
 * Baremetal Example: PWM Output
 * Description: Setup PWM on GPIO 16 using direct register access.
 */
#define RESETS_BASE 0x4000C000
#define PWM_BASE    0x40050000
#define SLICE_NUM   0

#define PWM_CH0_CSR  (PWM_BASE + 0x000)
#define PWM_CH0_DIV  (PWM_BASE + 0x004)
#define PWM_CH0_TOP  (PWM_BASE + 0x010)
#define PWM_CH0_CC   (PWM_BASE + 0x00C)

void delay(volatile int count) {
    while (count-- > 0) __asm volatile("nop");
}

int main() {
    *((volatile unsigned int*)(RESETS_BASE + 0x0)) |= (1 << 5);
    *((volatile unsigned int*)(RESETS_BASE + 0x0)) &= ~(1 << 5);

    *((volatile unsigned int*)(PWM_CH0_DIV)) = (1 << 4); // Divider
    *((volatile unsigned int*)(PWM_CH0_TOP)) = 255;
    *((volatile unsigned int*)(PWM_CH0_CC)) = 128;       // 50% duty
    *((volatile unsigned int*)(PWM_CH0_CSR)) = (1 << 0); // Enable

    while (1) {
        delay(100000);
    }
}