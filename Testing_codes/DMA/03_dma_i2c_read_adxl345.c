#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/dma.h"
#include <stdio.h>
#include "pico/stdio_usb.h"

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5
#define ADXL345_ADDR 0x53

uint8_t data[6];

int main() {
    stdio_init_all();
    while (!stdio_usb_connected()) {
        sleep_ms(500);
    }

    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    // Put ADXL345 in measurement mode
    uint8_t config[] = {0x2D, 0x08};  // POWER_CTL = 0x08
    i2c_write_blocking(I2C_PORT, ADXL345_ADDR, config, 2, false);
    sleep_ms(10);

    // Set register pointer to 0x32 (DATAX0)
    uint8_t reg = 0x32;
    i2c_write_blocking(I2C_PORT, ADXL345_ADDR, &reg, 1, true);  // Send reg with no STOP (repeated start)

    // Trigger 6 read commands manually to populate I2C RX FIFO
    for (int i = 0; i < 6; i++) {
        i2c_get_hw(I2C_PORT)->data_cmd = 0x100;  // READ = 1
    }

    // DMA setup
    int dma_chan = dma_claim_unused_channel(true);
    dma_channel_config cfg = dma_channel_get_default_config(dma_chan);
    channel_config_set_read_increment(&cfg, false);
    channel_config_set_write_increment(&cfg, true);
    channel_config_set_dreq(&cfg, DREQ_I2C0_RX);

    dma_channel_configure(
        dma_chan,
        &cfg,
        data,
        &i2c_get_hw(I2C_PORT)->data_cmd,  // FIXED: use data_cmd for RX
        sizeof(data),
        true
    );
    
    // Wait for DMA transfer to complete
    dma_channel_wait_for_finish_blocking(dma_chan);

    // Print received data
    printf("DMA I2C read complete:\n");
    for (int i = 0; i < 6; i++) {
        printf("0x%02X ", data[i]);
    }
    printf("\n");

    while (1) {
        tight_loop_contents();
    }
}
