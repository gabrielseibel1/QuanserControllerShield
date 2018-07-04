//
// Declarations for Quanser-Controller Shield (high level abstraction of the board)
//

#include "../include/QuanserControllerShield.h"

QuanserControllerShield::QuanserControllerShield() {
    motor = new Motor();
    decoder = new Decoder();
    microSwitches = new MicroSwitches();
}

QuanserControllerShield::~QuanserControllerShield() {
    delete motor;
    delete decoder;
    delete microSwitches;
}
