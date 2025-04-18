/*
 * Example 6: DMA Memory Copy with Interrupt
 */
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

#define SIZE 32
uint8_t src[SIZE], dst[SIZE];
volatile bool dma_done = false;

void dma_handler() {
    dma_done = true;
    dma_hw->ints0 = 1u << 0;  // Clear interrupt
}

int main() {
    stdio_init_all();

    for (int i = 0; i < SIZE; i++) src[i] = i;

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config c = dma_channel_get_default_config(dma_chan);
    channel_config_set_transfer_data_size(&c, DMA_SIZE_8);
    channel_config_set_read_increment(&c, true);
    channel_config_set_write_increment(&c, true);

    dma_channel_configure(dma_chan, &c, dst, src, SIZE, false);
    dma_channel_set_irq0_enabled(dma_chan, true);
    irq_set_exclusive_handler(DMA_IRQ_0, dma_handler);
    irq_set_enabled(DMA_IRQ_0, true);

    dma_channel_start(dma_chan);

    while (!dma_done);

    printf("DMA memory copy with interrupt complete.\n");
    while (1);
}