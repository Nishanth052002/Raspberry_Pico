/*
 * Example 1: DMA Basic Memory Copy
 * Demonstrates how to use DMA to copy memory (from src to dst).
 */
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/sync.h"

#define SIZE 32

int main() {
    stdio_init_all();

    uint8_t src[SIZE], dst[SIZE];
    for (int i = 0; i < SIZE; i++) src[i] = i;

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config c = dma_channel_get_default_config(dma_chan);
    channel_config_set_transfer_data_size(&c, DMA_SIZE_8);
    channel_config_set_read_increment(&c, true);
    channel_config_set_write_increment(&c, true);

    dma_channel_configure(
        dma_chan,
        &c,
        dst,        // write address
        src,        // read address
        SIZE,       // number of transfers
        true        // start immediately
    );

    dma_channel_wait_for_finish_blocking(dma_chan);

    printf("Memory copy complete!\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", dst[i]);
    }
    printf("\n");

    while (1);
}