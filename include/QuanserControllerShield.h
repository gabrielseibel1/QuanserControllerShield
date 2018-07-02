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
    Motor *motor;
    Decoder *decoder;
    MicroSwitches *microSwitches;

    /**
     * Initializes all the components, opening and configuring necessary files
     */
    QuanserControllerShield();

    /**
     * Destroys all the components, configuring and closing necessary files
     */
    virtual ~QuanserControllerShield();
};

#endif //QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H
