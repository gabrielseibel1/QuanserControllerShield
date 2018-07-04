#ifndef QUANSERCONTROLLERSHIELD_PIDCONTROLLER_H
#define QUANSERCONTROLLERSHIELD_PIDCONTROLLER_H

/**
 * PID Controller
 */
class PIDController {

public:

    /**
     * Makes first configuration for the PIDController
     */
    PIDController(float kp, float ki, float kd);

    /**
     * Sets the max limit
     * @param value in voltage for max limit
     */
    void set_max_limit(float value);

    /**
     * Sets the min limit
     * @param value in voltage for min limit
     */
    void set_min_limit(float value);

    /**
     * Sets new point that motor needs to reach
     * @param new_point radian value
     */
    void set_point(float new_point);

    /**
     * Computes PID routine
     * @param delta time in radians
     * @param sample in radians
     * @return
     */
    float compute(float delta, float sample);

private:

    /**
     * Point where motor must go (radians)
     */
    float point;

    /**
     * Constants used for PID
     */
    float Kp;
    float Ki;
    float Kd;

    /**
     * Max limit in voltages
     */
    float max_limit;

    /**
     * Min limit in voltages
     */
    float min_limit;

    /**
     * Saves the last sample for integration
     */
    float last_sample;

    /**
     * Used to calculate the PID equation
     */
    float integrated;

};

#endif //QUANSERCONTROLLERSHIELD_PIDCONTROLLER_H