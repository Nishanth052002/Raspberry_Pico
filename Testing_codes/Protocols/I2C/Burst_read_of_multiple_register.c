/*
 * Example 4: Read multiple registers (burst read)
 * Demonstrates reading a block of consecutive registers from ADXL345.
 */
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5
#define ADXL345_ADDR 0x53

int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 400 * 1000); // Using a faster bus speed here
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    uint8_t reg = 0x30;
    uint8_t buffer[10];

    while (1) {
        i2c_write_blocking(I2C_PORT, ADXL345_ADDR, &reg, 1, true);
        i2c_read_blocking(I2C_PORT, ADXL345_ADDR, buffer, 10, false);

        printf("Raw block read: ");
        for (int i = 0; i < 10; i++) {
            printf("0x%02X ", buffer[i]);
        }
        printf("\n");

        sleep_ms(1000);
    }
}
