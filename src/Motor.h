//
// Headers for dc motor actuation
//

#ifndef QUANSERCONTROLLERSHIELD_MOTOR_H
#define QUANSERCONTROLLERSHIELD_MOTOR_H

#define MAX_MOTOR_VOLTAGE 27
#define MIN_MOTOR_VOLTAGE (-27)

#define PWM_PERIOD_NS "10000000"

//a = PWM_PERIOD / (MAX_VOLTAGE - MIN_VOLTAGE)
#define DUTY_CYCLE_SLOPE 185185.185185

//b = a*MAX_VOLTAGE
#define DUTY_CYCLE_INTERCEPT 5000000

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
    void disable();

    /**
     * Turns motor ON by setting its enable pin to 1
     */
    void enable();

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
    void enable_pwm();

    /**
     * Turns PWM OFF
     */
    void disable_pwm();

    /**
     * Configures PWM period to default value PWM_PERIOD_NS_INT
     */
    void set_pwm_period();
};




#endif //QUANSERCONTROLLERSHIELD_MOTOR_H
