#include "PWM.h"
#include "hardware/pwm.h"

#define FULL_FORWARD_MS 1.9
#define FULL_REVERSE_MS 1.1
#define FULL_STOP_MS 1.5
#define PWM_FREQ 400
#define PWM_PIN 22

void configPWM() {
    //PWM Config
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    uint chan = pwm_gpio_to_channel(PWM_PIN);
    pwm_set_enabled(slice_num, true);
}

int get_duty_cycle(uint freq, float pulse_len_ms) {
    float total_pulse_ms = 1.0/freq*1000;
    return (pulse_len_ms/total_pulse_ms)*100;
}

uint32_t pwm_set_freq_duty(uint slice_num, uint chan, uint32_t freq, int duty_cycle) {
    uint32_t clock = 125000000;
    uint32_t divider16 = clock / freq / 4096 + (clock % (freq * 4096) != 0);
    if (divider16 / 16 == 0) divider16 = 16;

    uint32_t wrap = clock * 16 / divider16 / freq - 1;

    pwm_set_clkdiv_int_frac(slice_num, divider16/16, divider16 & 0xF);
    pwm_set_wrap(slice_num, wrap);
    pwm_set_chan_level(slice_num, chan, wrap * duty_cycle / 100);

    return wrap;
}