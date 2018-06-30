//
// Definitions for dc motor actuation
//

#include "motor.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/galileo2io.h"

//private functions

/**
 * Turns PWM ON
 */
void enable_pwm();

/**
 * Configures PWM period to default value PWM_PERIOD_NS_INT
 */
void set_pwm_period();


//public functions

void disable_motor() {
    //TODO set GPIO for L6203 ENABLE pin
}

void enable_motor() {
    //TODO set GPIO for L6203 ENABLE pin
}

void enable_pwm() {
    pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "1");
}

void set_pwm_period() {
    pputs("/sys/class/pwm/pwmchip0/device/pwm_period", PWM_PERIOD_NS);
}

void prepare_motor_actuation() {
    disable_motor();
    set_pwm_period();
    enable_pwm();
    set_motor_voltage(0);
}

void set_motor_voltage(float voltage) {
    int duty_cycle_ns;
    char str[100];

    if ((voltage > MAX_MOTOR_VOLTAGE) || (voltage < MIN_MOTOR_VOLTAGE)) {
        fprintf(stderr, "Out of range voltage (%f).\n", voltage);
        exit(EXIT_FAILURE);
    }

    //calculate necessary duty cycle to achieve desired average voltage
    //truncating is OK here, since it is a difference of just one nanosecond
    duty_cycle_ns = (int) (voltage * DUTY_CYCLE_SLOPE + DUTY_CYCLE_INTERCEPT);

    snprintf(str, sizeof str, "%d\n", duty_cycle_ns);
    pputs("/sys/class/pwm/pwmchip0/pwm1/duty_cycle", str);
}