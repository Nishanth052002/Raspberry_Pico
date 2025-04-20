/*
 * Example 8: ADC Sampling with DMA
 */
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/dma.h"

#define SAMPLES 100
uint16_t adc_buf[SAMPLES];

int main() {
    stdio_init_all();
    adc_init();
    adc_select_input(0);

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);
    channel_config_set_transfer_data_size(&cfg, DMA_SIZE_16);
    channel_config_set_read_increment(&cfg, false);
    channel_config_set_write_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_ADC);

    dma_channel_configure(
        dma_chan,
        &cfg,
        adc_buf,
        &adc_hw->fifo,
        SAMPLES,
        true
    );

    adc_fifo_setup(true, true, 1, false, false);
    adc_run(true);

    dma_channel_wait_for_finish_blocking(dma_chan);
    adc_run(false);

    printf("ADC DMA Capture Complete\n");
    for (int i = 0; i < SAMPLES; i++) {
        printf("%d ", adc_buf[i]);
    }
    printf("\n");

    while (1);
}