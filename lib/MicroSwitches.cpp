//
// Definitions for micro switches reading
//

#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "../include/MicroSwitches.h"

MicroSwitches::MicroSwitches() {
    if ((elbow1_fd = open(ELBOW1_FILENAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Failed to open elbow 1 micro switch\n");
        exit(EXIT_FAILURE);
    }
    if ((elbow2_fd = open(ELBOW2_FILENAME, O_RDONLY)) < 0) {
        fprintf(stderr, "Failed to open elbow 2 micro switch\n");
        exit(EXIT_FAILURE);
    }
}

MicroSwitches::~MicroSwitches() {
    if (close(elbow1_fd) < 0) fprintf(stderr, "Failed to close elbow 1 micro switch\n");
    if (close(elbow2_fd) < 0) fprintf(stderr, "Failed to close elbow 2 micro switch\n");
}

int MicroSwitches::is_end_of_trajectory(int index) {
    int elbow_fd;
    char elb_read;

    switch (index) {
        case ELB1:
            elbow_fd = elbow1_fd;
            break;
        case ELB2:
            elbow_fd = elbow2_fd;
            break;
        default:
            fprintf(stderr, "Invalid switch selected\n");
            exit(EXIT_FAILURE);
    }

    lseek(elbow_fd, 0, SEEK_SET);
    read(elbow_fd, &elb_read, sizeof elb_read);
    usleep(100);

    return elb_read == '1'; //TODO check if '1' really means end
}
