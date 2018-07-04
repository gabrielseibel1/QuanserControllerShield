//
// Created by gabriel on 7/4/18.
//


#include <QuanserControllerShield.h>
#include <cstdio>

/**
 * Script for testing the quanser controller shield
 * @return 0 if succeeded, -1 if not
 */
int main(int argc, char *argv[]) {
    QuanserControllerShield *quanser = new QuanserControllerShield();

    while (true) {
        printf("Radians: %f\n", quanser->decoder->get_position_radians());

        if (quanser->microSwitches->is_end_of_trajectory(ELB1)) {
            printf("Switch 1 pressed!\n");
        }

        if (quanser->microSwitches->is_end_of_trajectory(ELB2)) {
            printf("Switch 2 pressed!\n");
        }
    }

    return 0;
}