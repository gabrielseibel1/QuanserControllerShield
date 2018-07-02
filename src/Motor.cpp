//
// Definitions for dc motor actuation
//

#include "../include/Motor.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include "../include/galileo2io.h"

Motor::Motor() {
    //TODO open fd for L6203 ENABLE pin GPIO
    //TODO open fd for duty cycle
    disable();
    set_pwm_period();
    enable_pwm();
    set_voltage(0);
}

Motor::~Motor() {
    disable_pwm();
    //TODO disable and close fd for L6203 ENABLE pin GPIO
    //TODO close duty cycle fd
}

int Motor::set_voltage(float voltage) {
    int duty_cycle_ns;
    char str[100];

    if ((voltage > MAX_MOTOR_VOLTAGE) || (voltage < MIN_MOTOR_VOLTAGE)) {
        fprintf(stderr, "Out of range voltage (%f).\n", voltage);
        return -1;
    }

    //calculate necessary duty cycle to achieve desired average voltage
    //truncating is OK here, since it is a difference of just one nanosecond
    duty_cycle_ns = (int) (voltage * DUTY_CYCLE_SLOPE + DUTY_CYCLE_INTERCEPT);

    snprintf(str, sizeof str, "%d\n", duty_cycle_ns);
    if (write(duty_cycle_fd, str, strlen(str)) < strlen(str)) {
        fprintf(stderr, "Failed to set duty cycle\n");
        return -1;
    }
}

void Motor::disable() {
    //TODO set GPIO for L6203 ENABLE pin
}

void Motor::enable() {
    //TODO set GPIO for L6203 ENABLE pin
}

void Motor::disable_pwm() {
    pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "0");
}

void Motor::enable_pwm() {
    pputs("/sys/class/pwm/pwmchip0/pwm1/enable", "1");
}

void Motor::set_pwm_period() {
    pputs("/sys/class/pwm/pwmchip0/device/pwm_period", PWM_PERIOD_NS);
}
