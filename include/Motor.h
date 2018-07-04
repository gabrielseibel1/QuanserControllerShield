#ifndef QUANSERCONTROLLERSHIELD_MOTOR_H
#define QUANSERCONTROLLERSHIELD_MOTOR_H

#define MAX_MOTOR_VOLTAGE 27
#define MIN_MOTOR_VOLTAGE (-27)

/**
 * F = 1000Hz -> P = 0.001 s = 1000000 ns
 */
#define PWM_PERIOD_NS "1000000"

/**
 * a = PWM_PERIOD / (MAX_VOLTAGE - MIN_VOLTAGE)
 */
#define DUTY_CYCLE_SLOPE 18518.5185185

/**
 * b = a*MAX_VOLTAGE
 */
#define DUTY_CYCLE_INTERCEPT 500000

#define MOTOR_ENABLE_FILENAME "/sys/class/gpio/gpio38/value"

#define PWM_DUTY_CYCLE_FILENAME "/sys/class/pwm/pwmchip0/pwm3/duty_cycle"

/**
 * DC motor actuation based on PWM
 */
class Motor {

public:

    /**
     * Makes first configuration for the motor
     */
    Motor();

    /**
     * Close files
     */
    virtual ~Motor();

    /**
     * Turns motor OFF by setting its enable pin to 0
     */
    int disable();

    /**
     * Turns motor ON by setting its enable pin to 1
     */
    int enable();

    /**
     * Sets motor voltage from a percentage (0-100) of the possible range
     * 0 -> full throttle to side A
     * 50 -> no movement
     * 100 -> full throttle to side B
     * @param percentage value from 0 to 100 that corresponds to percentage of voltage range
     * @return 0 if success, -1 if failed
     */
    int set_voltage_percentage(float percentage);

    /**
     * Sets apparent voltage of the dc motor. Effectively, sets PWM duty cycle accordingly.
     * @param voltage The desired voltage between MAX_MOTOR_VOLTAGE and MIN_MOTOR_VOLTAGE
     */
    int set_voltage(float voltage);

private:

    /**
     * File descriptor for duty cycle configuration
     */
    int duty_cycle_fd;

    /**
     * File descriptor for enabling the motor
     */
    int enable_motor_fd;


    /**
     * Turns PWM ON
     */
    int enable_pwm();

    /**
     * Turns PWM OFF
     */
    int disable_pwm();

    /**
     * Configures PWM period to default value PWM_PERIOD_NS_INT
     */
    int set_pwm_period();
};




#endif //QUANSERCONTROLLERSHIELD_MOTOR_H
