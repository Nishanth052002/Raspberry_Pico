/*
 * Example: PWM Fade
 * Description: Outputs a fading PWM signal on GPIO 16 by varying the duty cycle.
 */
#include "pico/stdlib.h"
#include "hardware/pwm.h"

int main() {
    const uint PWM_PIN = 16;
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); // Set GPIO function to PWM
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN); // Get PWM slice

    pwm_set_wrap(slice_num, 255);               // Set max counter value (8-bit resolution)
    pwm_set_enabled(slice_num, true);           // Enable PWM

    int direction = 1;                          // 1 for increasing, -1 for decreasing
    int level = 0;                              // Starting duty cycle level

    while (true) {
        pwm_set_chan_level(slice_num, PWM_CHAN_A, level); // Set current duty cycle

        // Update level for fading effect
        level += direction;
        if (level >= 255) {                     // Reached maximum brightness
            level = 255;
            direction = -1;                     // Start decreasing
        } else if (level <= 0) {                // Reached minimum brightness
            level = 0;
            direction = 1;                      // Start increasing
        }

        sleep_ms(10);                           // Small delay for smooth fading (adjust as needed)
    }
}
