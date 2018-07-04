//
// Created by gabriel on 7/4/18.
//


#include <QuanserControllerShield.h>
#include <cstdio>
#include "../../../../../usr/include/unistd.h"

/**
 * Script for testing the quanser controller shield
 * @return 0 if succeeded, -1 if not
 */
int main(int argc, char *argv[]) {
    QuanserControllerShield *quanser = new QuanserControllerShield();

    quanser->decoder->reset_count();

    while (true) {
        printf("Radians: %f\n", quanser->decoder->get_position_radians());

        /*if (quanser->microSwitches->is_end_of_trajectory(ELB1)) {
            printf("Switch 1 pressed!\n");
        } else {
            printf(".1\n");
        }

        if (quanser->microSwitches->is_end_of_trajectory(ELB2)) {
            printf("Switch 2 pressed!\n");
        } else {
            printf(".2\n");
        }*/

        usleep(100000);
    }

    return 0;
}