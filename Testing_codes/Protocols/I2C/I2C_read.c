/*
 * Example 1: Basic I2C read from ADXL345 (Raw Acceleration Data)
 * Reads raw acceleration data from registers 0x32 to 0x37.
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

    uint8_t reg = 0x32;
    uint8_t data[6];

    while (1) {
        i2c_write_blocking(I2C_PORT, ADXL345_ADDR, &reg, 1, true);
        i2c_read_blocking(I2C_PORT, ADXL345_ADDR, data, 6, false);

        int16_t x = (data[1] << 8) | data[0];
        int16_t y = (data[3] << 8) | data[2];
        int16_t z = (data[5] << 8) | data[4];

        printf("X: %d, Y: %d, Z: %d\n", x, y, z);
        sleep_ms(500);
    }
}
