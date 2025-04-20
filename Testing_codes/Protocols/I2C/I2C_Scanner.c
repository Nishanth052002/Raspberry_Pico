#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5

int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 100 * 1000); // 100kHz standard I2C speed

    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    sleep_ms(2000); // Wait for USB connection
    printf("I2C Scanner Starting...\n");

    for (uint8_t addr = 0x08; addr <= 0x77; addr++) {
        uint8_t dummy;
        int result = i2c_read_blocking(I2C_PORT, addr, &dummy, 1, false);

        if (result >= 0) {
            printf("Found I2C device at address 0x%02X\n", addr);
        }

        sleep_ms(10); // Small delay between probes
    }

    printf("Scan complete.\n");

    while (1) {
        tight_loop_contents(); // Idle loop
    }
}
