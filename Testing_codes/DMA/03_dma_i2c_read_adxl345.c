/*
 * Example 3: I2C Read from ADXL345 using DMA
 */
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5
#define ADXL345_ADDR 0x53

uint8_t data[6];

int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // Tell ADXL345 to point to data register
    uint8_t reg = 0x32;
    i2c_write_blocking(I2C_PORT, ADXL345_ADDR, &reg, 1, true);

    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);
    channel_config_set_read_increment(&cfg, false);
    channel_config_set_write_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_I2C0_RX);

    dma_channel_configure(
        dma_chan,
        &cfg,
        data,
        &i2c_get_hw(I2C_PORT)->data_cmd,
        sizeof(data),
        false
    );

    i2c_hw_t *i2c_hw = i2c_get_hw(I2C_PORT);
    for (int i = 0; i < sizeof(data); i++) {
        i2c_hw->data_cmd = 0x100;
    }

    dma_start_channel_mask(1u << dma_chan);
    dma_channel_wait_for_finish_blocking(dma_chan);

    printf("DMA I2C read complete: ");
    for (int i = 0; i < 6; i++) {
        printf("0x%02X ", data[i]);
    }
    printf("\n");

    while (1);
}