//
// Definitions for dc motor actuation
//

#include "../include/Motor.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include "../include/galileo2io.h"

Motor::Motor() {
    //open file for L6203 ENABLE pin GPIO
    if ((enable_motor_fd = open(MOTOR_ENABLE_FILENAME, O_WRONLY)) == -1) {
        fprintf(stderr, "Failed to open motor enable GPIO file\n");
        exit(EXIT_FAILURE);
    }

    //open file for PWM duty cycle
    if ((duty_cycle_fd = open(PWM_DUTY_CYCLE_FILENAME, O_WRONLY)) == -1) {
        fprintf(stderr, "Failed to PWM duty cycle file\n");
        exit(EXIT_FAILURE);
    }

    //start with motor disabled
    if (disable() < 0) exit(EXIT_FAILURE);

    //set pwm period
    if (set_pwm_period() < 0) exit(EXIT_FAILURE);

    //enable pwm
    if (enable_pwm() < 0) exit(EXIT_FAILURE);

    //start with 0 voltage (stopped motor)
    if (set_voltage(0) < 0) exit(EXIT_FAILURE);
}

Motor::~Motor() {
    //set PWM to off
    disable_pwm();

    //set motor state to off
    disable();

    //close file descriptors
    if (close(enable_motor_fd) < 0) fprintf(stderr, "Failed to close motor enable GPIO file\n");
    if (close(duty_cycle_fd) < 0) fprintf(stderr, "Failed to duty cycle configuration file\n");
}

int Motor::set_voltage_percentage(float percentage) {
    //check range
    if (percentage > 100 || percentage < 0) {
        fprintf(stderr, "Invalid voltage percentage - use values from 0 to 100\n");
        return -1;
    }

    //get voltage from percentage
    float voltage = (percentage/100) * (MAX_MOTOR_VOLTAGE - MIN_MOTOR_VOLTAGE) + MIN_MOTOR_VOLTAGE;

    return set_voltage(voltage);
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
    lseek(duty_cycle_fd, 0, SEEK_SET);
    if (write(duty_cycle_fd, str, strlen(str)) < strlen(str)) {
        fprintf(stderr, "Failed to set duty cycle\n");
        return -1;
    }
}

int Motor::disable() {
    lseek(enable_motor_fd, 0, SEEK_SET);
    if (write(enable_motor_fd, "0", strlen("0")) < 0) {
        fprintf(stderr, "Failed to disable motor\n");
        return -1;
    }
    return 0;
}

int Motor::enable() {
    lseek(enable_motor_fd, 0, SEEK_SET);
    if (write(enable_motor_fd, "1", strlen("1")) < 0) {
        fprintf(stderr, "Failed to enable motor\n");
        return -1;
    }
    return 0;
}

int Motor::disable_pwm() {
    if (pputs("/sys/class/pwm/pwmchip0/pwm3/enable", "0") < 0) {
        fprintf(stderr, "Failed to disable pwm\n");
        return -1;
    }
    return 0;
}

int Motor::enable_pwm() {
    if (pputs("/sys/class/pwm/pwmchip0/pwm3/enable", "1") < 0) {
        fprintf(stderr, "Failed to enable pwm\n");
        return -1;
    }
    return 0;
}

int Motor::set_pwm_period() {
    if (pputs("/sys/class/pwm/pwmchip0/device/pwm_period", PWM_PERIOD_NS) < 0) {
        fprintf(stderr, "Failed to set pwm period\n");
        return -1;
    }
    return 0;
}
