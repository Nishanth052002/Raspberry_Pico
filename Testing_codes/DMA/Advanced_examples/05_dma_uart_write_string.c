/*
 * Example 5: UART Write Using DMA (String)
 */
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/dma.h"

#define UART_ID uart0
#define UART_TX_PIN 0

const char msg[] = "UART DMA Write Test String\n";

int main() {
    stdio_init_all();
    uart_init(UART_ID, 115200);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);
    channel_config_set_read_increment(&cfg, true);
    channel_config_set_write_increment(&cfg, false);
    channel_config_set_dreq(&cfg, DREQ_UART0_TX);

    dma_channel_configure(
        dma_chan,
        &cfg,
        &uart_get_hw(UART_ID)->dr,
        msg,
        sizeof(msg) - 1,
        true
    );

    dma_channel_wait_for_finish_blocking(dma_chan);

    while (1);
}