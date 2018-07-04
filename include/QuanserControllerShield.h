#ifndef QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H
#define QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H

#include "Motor.h"
#include "Decoder.h"
#include "MicroSwitches.h"

/**
 * High level abstraction of the board
 */
class QuanserControllerShield {
public:
    /**
     * Controller for the motor actuation
     */
    Motor *motor;

    /**
     * Reader for decoder counting
     */
    Decoder *decoder;

    /**
     * Reader for micro switches
     */
    MicroSwitches *microSwitches;

    /**
     * Initializes all the components, opening and configuring necessary files
     */
    QuanserControllerShield();

    /**
     * Destroys all the components, configuring and closing necessary files
     */
    virtual ~QuanserControllerShield();

    /**
     * Runs the motor in one way until a switch is triggered
     * @return 0 if reached the default position, -1 if failed
     */
    int send_joint_to_reference_position();
};

#endif //QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H
