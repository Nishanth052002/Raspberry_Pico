/*
 * Baremetal Example: GPIO Interrupt
 * Description: Configure GPIO 15 for falling edge interrupt using direct register access.
 * Requirements: NVIC setup, IRQ handler defined in vector table.
 */

#include <stdint.h>

#define SIO_BASE            0xD0000000
#define IO_BANK0_BASE       0x40014000
#define PADS_BANK0_BASE     0x4001C000
#define RESETS_BASE         0x4000C000
#define NVIC_ISER           ((volatile uint32_t*)(0xE000E100))

#define GPIO_CTRL_OFFSET    0x004
#define GPIO15_CTRL         (IO_BANK0_BASE + 0x0E0)
#define GPIO15_STATUS       (IO_BANK0_BASE + 0x108)
#define GPIO15_INTR         (IO_BANK0_BASE + 0x110)
#define PADS_GPIO15         (PADS_BANK0_BASE + 0x03C)

#define PROC0_INTS          0xE000E200
#define IO_IRQ_BANK0        13

void delay(volatile uint32_t count) {
    while (count--) __asm volatile("nop");
}

// Interrupt handler for IO_BANK0 (handles GPIO 0–29 interrupts)
void isr_io_bank0(void) {
    volatile uint32_t* intr = (volatile uint32_t*)GPIO15_INTR;

    // Check and clear interrupt
    if (*intr & (1u << 15)) {
        // Do something on interrupt
        // Example: toggle LED or store flag
        *((volatile uint32_t*)(SIO_BASE + 0x014)) = (1 << 25);  // Set LED
        delay(100000);
        *((volatile uint32_t*)(SIO_BASE + 0x018)) = (1 << 25);  // Clear LED
        *intr = (1u << 15);  // Clear IRQ
    }
}

int main() {
    // Reset IO_BANK0
    *((volatile uint32_t*)(RESETS_BASE + 0x0)) |= (1 << 5);
    *((volatile uint32_t*)(RESETS_BASE + 0x0)) &= ~(1 << 5);

    // Configure GPIO 15 as input with pull-up
    *((volatile uint32_t*)GPIO15_CTRL) = 5;        // Function SIO
    *((volatile uint32_t*)PADS_GPIO15) |= (1 << 3); // Pull-up enable

    // Configure GPIO 25 as output for LED (for testing)
    *((volatile uint32_t*)(SIO_BASE + 0x020)) |= (1 << 25);

    // Set interrupt for GPIO 15 on falling edge
    *((volatile uint32_t*)GPIO15_STATUS) = (1 << 3);  // Fall = bit 3
    *((volatile uint32_t*)GPIO15_INTR) = (1 << 15);   // Clear interrupt

    // Enable IRQ in NVIC
    *NVIC_ISER |= (1 << IO_IRQ_BANK0);  // IO_BANK0 = IRQ 13

    while (1) {
        __asm volatile("wfi");  // Wait for interrupt (low-power idle)
    }
}
