/*
 * Example: PWM Output
 * Description: Outputs PWM signal on GPIO 16 with 50% duty cycle.
 */
#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
    const uint PWM_PIN = 16;
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); // Set GPIO function to PWM
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN); // Get PWM slice

    pwm_set_wrap(slice_num, 255);               // Set max counter value
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 128); // 50% duty cycle
    pwm_set_enabled(slice_num, true);           // Enable PWM

    while (true) {
        tight_loop_contents();                  // Idle loop
    }
}
