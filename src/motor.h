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

/**
 * Prepares motor for actuation, configuring and enabling PWM, but leaving motor OFF.
 */
void prepare_motor_actuation();

/**
 * Turns motor OFF by setting its enable pin to 0
 */
void disable_motor();

/**
 * Turns motor ON by setting its enable pin to 1
 */
void enable_motor();

/**
 * Sets apparent voltage of the dc motor. Effectively, sets PWM duty cycle accordingly.
 * @param voltage The desired voltage between MAX_MOTOR_VOLTAGE and MIN_MOTOR_VOLTAGE
 */
void set_motor_voltage(float voltage);

#endif //QUANSERCONTROLLERSHIELD_MOTOR_H
