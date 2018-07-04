/**
 * @file Test file
 */

#include <cstdio>
#include <QuanserControllerShield.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <PIDController.h>

#define THRESHOLD 0.00001

/**
 * Script for testing the quanser controller shield
 * @return 0 if succeeded, -1 if not
 */
int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <angle from 0 to 180>", argv[0]);
        exit(EXIT_FAILURE);
    }

    clock_t last, now;
    float angle, sample, new_voltage, delta, rad_angle;

    //initialize quanser modules
    QuanserControllerShield *quanser = new QuanserControllerShield();

    //initialize PID controller
    PIDController pid = PIDController(0.1, 0.2, 0.0005);
    pid.set_max_limit(MAX_MOTOR_VOLTAGE);
    pid.set_min_limit(MIN_MOTOR_VOLTAGE);

    angle = (float) atof(argv[1]);

    if (angle < 0 || angle > 180) {
        fprintf(stderr, "Usage: %s <angle from 0 to 180>", argv[0]);
        exit(EXIT_FAILURE);
    }

    rad_angle = (float) (angle * M_PI) / 180;

    //enable motor
    quanser->motor->enable();

    //send joint to reference position, so that the counting can begin
    quanser->send_joint_to_reference_position();

    //define the desired position of the joint
    pid.set_point(rad_angle);
    last = clock();

    while (true) {

        //break if a micro switch is triggered
        if (!quanser->microSwitches->is_end_of_trajectory(ELB1) ||
            !quanser->microSwitches->is_end_of_trajectory(ELB1))
            break;

        //get current joint position
        sample = quanser->decoder->get_position_radians();

        delta = sample - rad_angle;
        delta = delta < 0 ? -1 * delta : delta;

        //convergence: joint arrived at desired position
        if (delta <= THRESHOLD) break;

        now = clock();

        //calculate and set the necessary voltage to be applied at the motor
        new_voltage = pid.compute((float) (now - last) / CLOCKS_PER_SEC, sample);
        quanser->motor->set_voltage(new_voltage);

        last = now;
    }

    //stop the motor
    quanser->motor->set_voltage(0);
    quanser->motor->disable();

    //close files
    delete quanser;

    return 0;
}