/*
 * Example 3: Burst Read Multiple Bytes
 * Read N bytes continuously from MAX345.
 */
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT spi0
#define PIN_CS   2
#define PIN_SCK  3
#define PIN_TX   4
#define PIN_RX   5

int main() {
    stdio_init_all();
    spi_init(SPI_PORT, 2000 * 1000);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_TX, GPIO_FUNC_SPI);
    gpio_set_function(PIN_RX, GPIO_FUNC_SPI);
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);

    const uint8_t num_bytes = 6;
    uint8_t tx_data[6] = {0x00}; // Send dummy 0x00s
    uint8_t rx_data[6];

    while (1) {
        gpio_put(PIN_CS, 0);
        spi_write_read_blocking(SPI_PORT, tx_data, rx_data, num_bytes);
        gpio_put(PIN_CS, 1);

        printf("Burst Read: ");
        for (int i = 0; i < num_bytes; ++i) {
            printf("0x%02X ", rx_data[i]);
        }
        printf("\n");
        sleep_ms(1000);
    }
}