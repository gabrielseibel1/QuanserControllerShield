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
    for (int i = MIN_MOTOR_VOLTAGE; i < MAX_MOTOR_VOLTAGE; ++i) {
        quanser->motor->set_voltage(i);
        usleep(75000);
    }

    quanser->motor->set_voltage(MIN_MOTOR_VOLTAGE);
    sleep(1);

    quanser->motor->set_voltage(0);
    sleep(1);

    quanser->motor->set_voltage(MAX_MOTOR_VOLTAGE);
    sleep(1);

}