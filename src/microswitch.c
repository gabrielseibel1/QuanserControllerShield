//
// Created by gabriel on 6/29/18.
//

#include "microswitch.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_end_of_trajectory(int index) {
    const char *elb1_filename = "/sys/class/gpio/gpio62/value";
    const char *elb2_filename = "/sys/class/gpio/gpio13/value";
    const char *elb_filename;

    switch (index) {
        case ELB1:
            elb_filename = elb1_filename;
            break;
        case ELB2:
            elb_filename = elb2_filename;
            break;
        default:
            fprintf(stderr, "Invalid switch selected\n");
            exit(EXIT_FAILURE);
    }

    int elb_fd, elb_read;

    elb_fd = open(elb_filename, O_RDONLY);

    lseek(elb_fd, 0, SEEK_SET);
    read(elb_fd, &elb_read, sizeof elb_read);
    usleep(100);
    close(elb_fd);

    return elb_read;
}

