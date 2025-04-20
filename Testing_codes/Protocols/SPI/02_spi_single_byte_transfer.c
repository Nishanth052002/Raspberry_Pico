/*
 * Example 2: Send and Receive Single Byte
 * Exchanges one byte with MAX345 over SPI.
 */
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define PIN_CS   2
#define PIN_SCK  3
#define PIN_TX   4
#define PIN_RX   5

uint8_t spi_transfer(uint8_t data) {
    uint8_t rx;
    gpio_put(PIN_CS, 0);
    spi_write_read_blocking(SPI_PORT, &data, &rx, 1);
    gpio_put(PIN_CS, 1);
    return rx;
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
        uint8_t received = spi_transfer(0xAA);  // Send 0xAA, receive byte
        printf("Received: 0x%02X\n", received);
        sleep_ms(1000);
    }
}