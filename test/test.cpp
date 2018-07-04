/**
 * @file Test file
 */

#include <cstdio>
#include "../include/QuanserControllerShield.h"

/**
 * Script for testing the quanser controller shield
 * @return 0 if succeeded, -1 if not
 */
int main(int argc, char *argv[]) {
    QuanserControllerShield *quanserControllerShield = new QuanserControllerShield();
    float radians = quanserControllerShield->decoder->get_position_radians();
    printf("Hello quanser. Radians %f\n", radians);
}