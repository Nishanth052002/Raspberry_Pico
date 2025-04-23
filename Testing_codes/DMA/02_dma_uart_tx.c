/*
 * Example 2: UART TX with DMA
 * Sends a message over UART using DMA.
 */
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "pico/stdio_usb.h"
#include "hardware/uart.h"
#include <stdio.h>

#define UART_ID uart0
#define UART_TX_PIN 0

char message[] = "Hello from DMA UART!\n";

int main() {
    stdio_init_all();

    uart_init(UART_ID, 115200);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);

    while (!stdio_usb_connected()) {
        sleep_ms(1000);
    }

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);
    channel_config_set_read_increment(&cfg, true);
    channel_config_set_write_increment(&cfg, false);
    channel_config_set_dreq(&cfg, DREQ_UART0_TX);

    dma_channel_configure(
        dma_chan,
        &cfg,
        &uart_get_hw(UART_ID)->dr,
        message,
        sizeof(message) - 1,
        true
    );

    dma_channel_wait_for_finish_blocking(dma_chan);
    printf("DMA UART TX complete\n");

    while (1);
}