/*
 * Example 3: I2C Write to ADXL345 Register (e.g., POWER_CTL to enable measurement mode)
 * This demonstrates a write operation to configure the sensor.
 */
#include "pico/stdlib.h"
#include "hardware/i2c.h"

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

    uint8_t config_data[] = {0x2D, 0x08}; // POWER_CTL register, measure mode
    i2c_write_blocking(I2C_PORT, ADXL345_ADDR, config_data, 2, false);

    while (1) sleep_ms(1000);
}
