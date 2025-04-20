/*
 * Example 7: DMA Timer-Triggered Transfer (Repetitive Copy)
 */
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/timer.h"

#define SIZE 4
uint32_t src[SIZE] = {10, 20, 30, 40};
uint32_t dst[SIZE];

int main() {
    stdio_init_all();

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config c = dma_channel_get_default_config(dma_chan);
    channel_config_set_transfer_data_size(&c, DMA_SIZE_32);
    channel_config_set_read_increment(&c, true);
    channel_config_set_write_increment(&c, true);
    channel_config_set_chain_to(&c, dma_chan);  // Auto-restart

    dma_channel_configure(dma_chan, &c, dst, src, SIZE, false);

    dma_channel_start(dma_chan);

    sleep_ms(1000);

    printf("Timer-triggered DMA repetitive copy (manual trigger here)\n");
    while (1);
}