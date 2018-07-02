//
// Created by gabriel on 7/2/18.
//

#ifndef QUANSERCONTROLLERSHIELD_MICROSWITCHES_H
#define QUANSERCONTROLLERSHIELD_MICROSWITCHES_H

#define ELB1 1
#define ELB2 2

class MicroSwitches {
private:
    int elbow1_fd;
    int elbow2_fd;
public:
    MicroSwitches();

    virtual ~MicroSwitches();

    /**
     * Returns whether the arm has reached the end of its trajectory
     * @param index What switch to be checked: ELB1 (elbow1) or ELB2 (elbow2)
     * @return 1 if switch is pressed, 0 if it is not
     */
    int is_end_of_trajectory(int index);
};


#endif //QUANSERCONTROLLERSHIELD_MICROSWITCHES_H