//
// Created by gabriel on 7/2/18.
//

#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "MicroSwitches.h"

MicroSwitches::MicroSwitches() {
    const char *elbow1_filename = "/sys/class/gpio/gpio62/value";
    const char *elbow2_filename = "/sys/class/gpio/gpio13/value";

    if ((elbow1_fd = open(elbow1_filename, O_RDONLY)) < 0) {
        fprintf(stderr, "Failed to open elbow 1 micro switch\n");
        exit(EXIT_FAILURE);
    }
    if ((elbow2_fd = open(elbow2_filename, O_RDONLY)) < 0) {
        fprintf(stderr, "Failed to open elbow 2 micro switch\n");
        exit(EXIT_FAILURE);
    }
}

MicroSwitches::~MicroSwitches() {
    if (close(elbow1_fd) < 0) {
        fprintf(stderr, "Failed to close elbow 1 micro switch\n");
        exit(EXIT_FAILURE);
    }
    if (close(elbow2_fd) < 0) {
        fprintf(stderr, "Failed to close elbow 2 micro switch\n");
        exit(EXIT_FAILURE);
    }
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
