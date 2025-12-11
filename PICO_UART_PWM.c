#include "pico/stdlib.h"
#include "PWM.h"
#include "UART.h"

int main(){
    //Onboard LED
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, true);
    
    //Setting PWM
    int duty_cycle = get_duty_cycle(PWM_FREQ, FULL_STOP_MS);
    // pwm_set_freq_duty(slice_num, chan, PWM_FREQ, duty_cycle);

    //Reading UART
    while (1) {
        // Read a single character (Blocking)
        char received_char = uart_getc(UART_ID);

        // Read a specified number of bytes
        uint8_t buffer[10];
        uart_read_blocking(UART_ID, buffer, 10);
    }

    return 0;
}

