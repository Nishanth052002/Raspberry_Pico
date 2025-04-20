/*
 * Example 4: SPI DMA read from MAX345
 */
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/dma.h"

#define SPI_PORT spi0
#define PIN_CS   2
#define PIN_SCK  3
#define PIN_TX   4
#define PIN_RX   5

uint8_t tx_buf[6] = {0};
uint8_t rx_buf[6];

int main() {
    stdio_init_all();
    spi_init(SPI_PORT, 1 * 1000 * 1000);
    gpio_set_function(PIN_SCK, GPIO_FUNC_SPI);
    gpio_set_function(PIN_TX, GPIO_FUNC_SPI);
    gpio_set_function(PIN_RX, GPIO_FUNC_SPI);
    gpio_init(PIN_CS);
    gpio_set_dir(PIN_CS, GPIO_OUT);
    gpio_put(PIN_CS, 1);

    int tx_dma = dma_claim_unused_channel(true);
    int rx_dma = dma_claim_unused_channel(true);

    dma_channel_config tx_cfg = dma_channel_get_default_config(tx_dma);
    channel_config_set_transfer_data_size(&tx_cfg, DMA_SIZE_8);
    channel_config_set_dreq(&tx_cfg, DREQ_SPI0_TX);
    channel_config_set_read_increment(&tx_cfg, true);
    channel_config_set_write_increment(&tx_cfg, false);

    dma_channel_config rx_cfg = dma_channel_get_default_config(rx_dma);
    channel_config_set_transfer_data_size(&rx_cfg, DMA_SIZE_8);
    channel_config_set_dreq(&rx_cfg, DREQ_SPI0_RX);
    channel_config_set_read_increment(&rx_cfg, false);
    channel_config_set_write_increment(&rx_cfg, true);

    gpio_put(PIN_CS, 0);

    dma_channel_configure(rx_dma, &rx_cfg, rx_buf, &spi_get_hw(SPI_PORT)->dr, 6, false);
    dma_channel_configure(tx_dma, &tx_cfg, tx_buf, &spi_get_hw(SPI_PORT)->dr, 6, false);

    dma_start_channel_mask((1u << tx_dma) | (1u << rx_dma));
    dma_channel_wait_for_finish_blocking(rx_dma);
    dma_channel_wait_for_finish_blocking(tx_dma);

    gpio_put(PIN_CS, 1);

    printf("DMA SPI read done: ");
    for (int i = 0; i < 6; i++) {
        printf("0x%02X ", rx_buf[i]);
    }
    printf("\n");

    while (1);
}