/*
 * Example 4: SPI Write to a Register
 * Writes a value to a register on MAX345 (e.g. 0x01).
 */
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define PIN_CS   2
#define PIN_SCK  3
#define PIN_TX   4
#define PIN_RX   5

void spi_write_register(uint8_t reg, uint8_t value) {
    uint8_t buffer[2] = {reg, value};
    gpio_put(PIN_CS, 0);
    spi_write_blocking(SPI_PORT, buffer, 2);
    gpio_put(PIN_CS, 1);
}

int main() {
    stdio_init_all();
    spi_init(SPI_PORT, 1000 * 1000);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_TX, GPIO_FUNC_SPI);
    gpio_set_function(PIN_RX, GPIO_FUNC_SPI);
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);

    spi_write_register(0x01, 0xFF);  // Example register write
    while (1) sleep_ms(1000);
}