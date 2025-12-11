#ifndef CONFIG_PWM
#define CONFIG_PWM

// GPIO         0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 
// GPIO        16 17 18 19 20 21 22 23 24 25 26 27 28 29
// PWM Channel 0A 0B 1A 1B 2A 2B 3A 3B 4A 4B 5A 5B 6A 6B 7A 7B

// Two channels of the same slice run at the same frequency, but can have a different duty rate. 
// 3A -> Slice 3, channel A

uint32_t pwm_set_freq_duty(uint slice_num, uint chan, uint32_t freq, int duty_cycle);
int get_duty_cycle(uint freq, float pulse_len_ms);

#endif