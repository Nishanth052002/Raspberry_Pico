/*
 * Example 9: UART RX Using DMA
 */
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/dma.h"

#define UART_ID uart0
#define UART_RX_PIN 1
#define BUF_LEN 32

uint8_t rx_buf[BUF_LEN];

int main() {
    stdio_init_all();

    uart_init(UART_ID, 115200);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);
    channel_config_set_transfer_data_size(&cfg, DMA_SIZE_8);
    channel_config_set_read_increment(&cfg, false);
    channel_config_set_write_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_UART0_RX);

    dma_channel_configure(
        dma_chan,
        &cfg,
        rx_buf,
        &uart_get_hw(UART_ID)->dr,
        BUF_LEN,
        true
    );

    dma_channel_wait_for_finish_blocking(dma_chan);
    printf("DMA UART RX complete: %s\n", rx_buf);

    while (1);
}