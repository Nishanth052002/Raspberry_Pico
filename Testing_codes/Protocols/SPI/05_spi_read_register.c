/*
 * Example 5: SPI Read Register
 * Sends register address and reads back a value.
 */
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define PIN_CS   2
#define PIN_SCK  3
#define PIN_TX   4
#define PIN_RX   5

uint8_t spi_read_register(uint8_t reg) {
    uint8_t tx[] = {reg};
    uint8_t rx[1];
    gpio_put(PIN_CS, 0);
    spi_write_blocking(SPI_PORT, tx, 1);
    spi_read_blocking(SPI_PORT, 0x00, rx, 1);
    gpio_put(PIN_CS, 1);
    return rx[0];
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

    while (1) {
        uint8_t val = spi_read_register(0x01);
        printf("Reg 0x01: 0x%02X\n", val);
        sleep_ms(1000);
    }
}