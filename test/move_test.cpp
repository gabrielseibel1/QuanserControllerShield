/**
 * @file Test file
 */

#include <cstdio>
#include <QuanserControllerShield.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <PIDController.h>
#include "../../../../../usr/include/unistd.h"

#define THRESHOLD 0.00001

/**
 * Script for testing the quanser controller shield
 * @return 0 if succeeded, -1 if not
 */
int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <voltage>", argv[0]);
        exit(EXIT_FAILURE);
    }

    float voltage;

    //initialize quanser modules
    QuanserControllerShield *quanser = new QuanserControllerShield();

    voltage = (float) atof(argv[1]);

    if (voltage < MIN_MOTOR_VOLTAGE || voltage > MAX_MOTOR_VOLTAGE) {
        fprintf(stderr, "Usage: %s <voltage from -27 to 27>", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Setting %f volts...\n", voltage);

    //stop the motor
    quanser->motor->set_voltage(voltage);
    quanser->motor->enable();

    usleep(5000000);

    quanser->motor->set_voltage(0);
    quanser->motor->disable();

    //close files
    delete quanser;

    return 0;
}