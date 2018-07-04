//
// Declarations for Quanser-Controller Shield (high level abstraction of the board)
//

#include <unistd.h>
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

int QuanserControllerShield::send_joint_to_reference_position() {
    //move slowly to one extreme of the trajectory
    motor->set_voltage(-1);

    //stop when a micro switch is triggered
    while (!microSwitches->is_end_of_trajectory(ELB1) ||
           !microSwitches->is_end_of_trajectory(ELB2));

    //move slightly away from the extremity, to not trigger the switch anymore
    motor->set_voltage(1);
    usleep(200);

    //stop the motor and reset the counting : we are in the reference position
    motor->set_voltage(0);
    decoder->reset_count();

    return 0;
}
