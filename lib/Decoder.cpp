//
// Definitions for decoder
//

#include <unistd.h>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <cmath>
#include "../include/Decoder.h"

Decoder::Decoder() {
    uint8_t mode = SPI_MODE_0;
    uint8_t lsb = 0;
    uint8_t bpw = 8;
    uint32_t speed = SPI_FREQUENCY;
    unsigned char mode_register_0, mode_register_1;

    //open file descriptors

    if ((spi_fd = open(SPI_FILENAME, O_RDWR)) < 0) {
        fprintf(stderr, "Failed to open /dev/spidev1.0\n");
        exit(EXIT_FAILURE);
    }
    if ((_ss_fd = open(_SS_FILENAME, O_WRONLY)) < 0) {
        fprintf(stderr, "Failed to open /sys/class/gpio/gpio10/value\n");
        exit(EXIT_FAILURE);
    }

    //configure spi communication

    if (ioctl(spi_fd, SPI_IOC_WR_MODE, &mode) < 0) {
        fprintf(stderr, "Failed to set SPI write mode.\n");
        exit(EXIT_FAILURE);
    }

    if (ioctl(spi_fd, SPI_IOC_WR_LSB_FIRST, &lsb)) {
        fprintf(stderr, "Failed to set SPI LSB first.\n");
        exit(EXIT_FAILURE);
    }

    if (ioctl(spi_fd, SPI_IOC_WR_BITS_PER_WORD, &bpw)) {
        fprintf(stderr, "Failed to set SPI bits per word.\n");
        exit(EXIT_FAILURE);
    }

    if (ioctl(spi_fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed)) {
        fprintf(stderr, "Failed to set SPI max speed.\n");
        exit(EXIT_FAILURE);
    }

    //configure mode registers

    mode_register_0 = QUADRX4 | FREE_RUN | DISABLE_INDX | FILTER_2;
    mode_register_1 = BYTE_2 | EN_CNTR | NO_FLAGS;

    if (write_byte(WRITE_MDR0, mode_register_0) < 0) {
        fprintf(stderr, "Failed to configure mode register 0\n");
        exit(EXIT_FAILURE);
    }

    if (write_byte(WRITE_MDR1, mode_register_1) < 0) {
        fprintf(stderr, "Failed to configure mode register 1\n");
        exit(EXIT_FAILURE);
    }

    printf("MDR0: %c\n", read_byte(READ_MDR0));

    printf("MDR1: %c\n", read_byte(READ_MDR1));

    //clear counting register
    if (reset_count() < 0) exit(EXIT_FAILURE);
}


Decoder::~Decoder() {
    if (close(spi_fd) < 0) fprintf(stderr, "Failed to close SPI\n");
    if (close(_ss_fd) < 0) fprintf(stderr, "Failed to close #SS\n");
}

int Decoder::get_count() {
    int i;
    unsigned int count = 0;
    unsigned char byte = 0;
    char read_counter_op = READ_CNTR;

    if (_ss_high() < 0) exit(EXIT_FAILURE);
    if (_ss_low() < 0) exit(EXIT_FAILURE);

    //write spi op code to read counter to spi bus
    if (write(spi_fd, &read_counter_op, sizeof(read_counter_op)) <= 0) {
        fprintf(stderr, "Failed write read counter op code to SPI bus\n");
        exit(EXIT_FAILURE);
    }

    //read 16 bits (8 bytes)
    for (i = 0; i < 2; i++) {
        //shift 8 bits
        count = count << 8;

        //read a byte
        lseek(spi_fd, 0, SEEK_SET);
        while (read(spi_fd, &byte, sizeof(byte)) != sizeof(byte));

        //compose count from bytes by ORing
        count = count | byte;
    }

    if (_ss_high() < 0) exit(EXIT_FAILURE);

    return count;
}

int Decoder::reset_count() {
    unsigned char op_code = CLR_CNTR;

    if (_ss_high() < 0) return -1;
    if (_ss_low() < 0) return -1;

    //write spi op code to spi bus
    if (write(spi_fd, &op_code, sizeof(op_code)) <= 0) {
        fprintf(stderr, "Failed reset counter\n");
        return -1;
    }

    if (_ss_high() < 0) return -1;

    return 0;
}

int Decoder::write_byte(unsigned char op_code, unsigned char data) {
    int opcode_ok, data_ok;

    if (_ss_high() < 0) return -1;
    if (_ss_low() < 0) return -1;

    //write spi op code to spi bus
    opcode_ok = write(spi_fd, &op_code, sizeof(op_code));
    if (opcode_ok < 0) {
        fprintf(stderr, "Failed write op code to SPI\n");
        return -1;
    }

    // send data
    data_ok = write(spi_fd, &data, sizeof(data));
    if (data_ok < 0) {
        fprintf(stderr, "Failed write data to SPI\n");
        return -1;
    }

    printf("Opcode bytes: %d\n", opcode_ok);
    printf("Data bytes: %d\n", data_ok);

    if (_ss_high() < 0) return -1;

    return 0;
}

unsigned char Decoder::read_byte(unsigned char op_code) {
    int byte_ok;

    unsigned char byte;

    if (_ss_high() < 0) exit(EXIT_FAILURE);
    if (_ss_low() < 0) exit(EXIT_FAILURE);

    //write spi op code to spi bus
    byte_ok = write(spi_fd, &op_code, sizeof(op_code));
    if (byte_ok < 0) {
        fprintf(stderr, "Failed write op code to SPI\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Read %d bytes\n", byte_ok);
    }

    //read data from the spi bus when available
    lseek(spi_fd, 0, SEEK_SET);
    while (read(spi_fd, &byte, sizeof(byte)) != sizeof(byte));

    if (_ss_high() < 0) exit(EXIT_FAILURE);

    return byte;
}

int Decoder::_ss_low() {
    //go to beginning of file
    lseek(_ss_fd, 0, SEEK_SET);
    //write to file and check if success
    if (write(_ss_fd, "0", sizeof("0")) < 0) {
        fprintf(stderr, "Failed to set #SS to low\n");
        return -1;
    }
    return 0;
}

int Decoder::_ss_high() {
    //go to beginning of file
    lseek(_ss_fd, 0, SEEK_SET);
    //write to file and check if success
    if (write(_ss_fd, "1", sizeof("1")) < 0) {
        fprintf(stderr, "Failed to set #SS to high\n");
        return -1;
    }
    return 0;
}

float Decoder::get_position_radians() {
    int counting;

    //divide by 4 because we are using x4 mode of quadrature counting
    counting = get_count() / 4;

    //convert to radians
    return (float) (2 * M_PI * counting / COUNTS_PER_REVOLUTION);
}
