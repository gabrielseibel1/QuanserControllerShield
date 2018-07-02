//
// Declarations for Quanser-Controller Shield (high level abstraction of the board)
//

#ifndef QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H
#define QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H

#include "../include/Motor.h"
#include "../include/Decoder.h"
#include "../include/MicroSwitches.h"

class QuanserControllerShield {
public:
    Motor *motor;
    Decoder *decoder;
    MicroSwitches *microSwitches;

    QuanserControllerShield();

    virtual ~QuanserControllerShield();
};

#endif //QUANSERCONTROLLERSHIELD_QUANSERCONTROLLERSHIELD_H
