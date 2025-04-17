/*
 * Example 2: Read Device ID from ADXL345
 * Reads from register 0x00 to verify I2C communication.
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
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    uint8_t reg = 0x00;
    uint8_t id;

    i2c_write_blocking(I2C_PORT, ADXL345_ADDR, &reg, 1, true);
    i2c_read_blocking(I2C_PORT, ADXL345_ADDR, &id, 1, false);

    printf("ADXL345 Device ID: 0x%02X\n", id);

    while (1) sleep_ms(1000);
}
