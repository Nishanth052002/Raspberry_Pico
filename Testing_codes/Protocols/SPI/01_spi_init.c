/*
 * Example 1: SPI Initialization (Bare-metal)
 * This sets up SPI0 on GPIOs 2 (CS), 3 (SCK), 4 (TX/MOSI), 5 (RX/MISO).
 * No transfer, just init.
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

    // Init SPI port at 1 MHz
    spi_init(SPI_PORT, 1 * 1000 * 1000);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_TX, GPIO_FUNC_SPI);
    gpio_set_function(PIN_RX, GPIO_FUNC_SPI);

    // Setup manual chip select
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);  // Deselect device

    while (1) {
        tight_loop_contents();
    }
}