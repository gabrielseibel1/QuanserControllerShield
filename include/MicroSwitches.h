#ifndef QUANSERCONTROLLERSHIELD_MICROSWITCHES_H
#define QUANSERCONTROLLERSHIELD_MICROSWITCHES_H

#define ELB1 1
#define ELB2 2

/**
 * Micro switches that mark the end of trajectory of the arm
 */
class MicroSwitches {

private:
    int elbow1_fd;
    int elbow2_fd;

public:
    /**
     * Open files
     */
    MicroSwitches();

    /**
     * Close files
     */
    virtual ~MicroSwitches();

    /**
     * Returns whether the arm has reached the end of its trajectory
     * @param index What switch to be checked: ELB1 (elbow1) or ELB2 (elbow2)
     * @return 1 if switch is pressed, 0 if it is not
     */
    int is_end_of_trajectory(int index);
};


#endif //QUANSERCONTROLLERSHIELD_MICROSWITCHES_H
