//
// Created by gabriel on 7/4/18.
//


#include <QuanserControllerShield.h>
#include <unistd.h>

/**
 * Script for testing the quanser controller shield
 * @return 0 if succeeded, -1 if not
 */
int main(int argc, char *argv[]) {
    QuanserControllerShield *quanser = new QuanserControllerShield();
    for (int i = 0; i < 100; ++i) {
        quanser->motor->set_voltage_percentage(i);
        usleep(500);
    }

    quanser->motor->set_voltage(MIN_MOTOR_VOLTAGE);
    quanser->motor->set_voltage(0);
    quanser->motor->set_voltage(MAX_MOTOR_VOLTAGE);
}