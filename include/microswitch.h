//
// Created by gabriel on 6/29/18.
//

#ifndef QUANSERCONTROLLERSHIELD_MICROSWITCH_H
#define QUANSERCONTROLLERSHIELD_MICROSWITCH_H

#define ELB1 1
#define ELB2 2

/**
 * Returns whether the arm has reached the end of its trajectory
 * @param index What switch to be checked: ELB1 (elbow1) or ELB2 (elbow2)
 * @return 1 if switch is pressed, 0 if it is not
 */
int is_end_of_trajectory(int index);

#endif //QUANSERCONTROLLERSHIELD_MICROSWITCH_H
