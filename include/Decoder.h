//
// Headers for decoder
//

#ifndef QUANSERCONTROLLERSHIELD_DECODER_H
#define QUANSERCONTROLLERSHIELD_DECODER_H

class Decoder {
public:

    /**
     * Opens files and configures SPI communication
     */
    Decoder();

    /**
     * Close open files and end SPI
     */
    virtual ~Decoder();

    /**
     * Reads counting and converts to radians, indicating position of the joint
     * @return position of the joint in radians
     */
    float get_position_radians();

private:

    /**
     * Read counting from SPI
     * @return value of CNTR register
     */
    int get_count();

    /**
     * File descriptor for SPI
     */
    int spi_fd;

    /**
     * File descriptor for #SS
     */
    int _ss_fd;

    /**
     * Write an op code than a byte of data to the decoder
     * @param op_code the op code to define the register and the operation
     * @param data the data to be transmitted
     * @return 0 if success, -1 if failed
     */
    int write_byte(unsigned char op_code, unsigned char data);

    /**
     * Write an op code than wait for the decoder to read byte data from the SPI bus
     * @param op_code the op code to define the register and the operation
     * @return a byte transmitted by the decoder
     */
    unsigned char read_byte(unsigned char op_code);

    /**
     * Set #SS to high
     * @return 0 if success, -1 if failed
     */
    int _ss_high();

    /**
     * Set #SS to low
     * @return 0 if success, -1 if failed
     */
    int _ss_low();

    /**
     * Clear contents of CNTR register
     */
    int reset_count();
};


/*
 * MDR0 configuration data - the configuration byte is formed with
 * single segments taken from each group and ORing all together.
 */

//Count modes
#define NQUAD 0x00          //non-quadrature mode
#define QUADRX1 0x01        //X1 quadrature mode
#define QUADRX2 0x02        //X2 quadrature mode
#define QUADRX4 0x03        //X4 quadrature mode

//Running modes
#define FREE_RUN 0x00
#define SINGE_CYCLE 0x04
#define RANGE_LIMIT 0x08
#define MODULO_N 0x0C

//Index modes
#define DISABLE_INDX 0x00   //index_disabled
#define INDX_LOADC 0x10     //index_load_CNTR
#define INDX_RESETC 0x20    //index_rest_CNTR
#define INDX_LOADO 0x30     //index_load_OL
#define ASYNCH_INDX 0x00    //asynchronous index
#define SYNCH_INDX 0x80     //synchronous index

//Clock filter modes
#define FILTER_1 0x00       //filter clock frequncy division factor 1
#define FILTER_2 0x80       //filter clock frequncy division factor 2

/*
 * MDR1 configuration data; any of these
 * data segments can be ORed together
 */

//Flag modes
#define NO_FLAGS 0x00       //all flags disabled
#define IDX_FLAG 0x10       //IDX flag
#define CMP_FLAG 0x20       //CMP flag
#define BW_FLAG 0x40        //BW flag
#define CY_FLAG 0x80        //CY flag

//1 to 4 bytes data-width
#define BYTE_4 0x00         //four byte mode
#define BYTE_3 0x01         //three byte mode
#define BYTE_2 0x02         //two byte mode
#define BYTE_1 0x03         //one byte mode
//Enable/disable counter
#define EN_CNTR 0x00        //counting enabled
#define DIS_CNTR 0x04       //counting disabled

/*
 * LS7366R op-code list
 */

#define CLR_MDR0 0x08
#define CLR_MDR1 0x10
#define CLR_CNTR 0x20
#define CLR_STR 0x30
#define READ_MDR0 0x48
#define READ_MDR1 0x50
#define READ_CNTR 0x60
#define READ_OTR 0x68
#define READ_STR 0x70
#define WRITE_MDR1 0x90
#define WRITE_MDR0 0x88
#define WRITE_DTR 0x98
#define LOAD_CNTR 0xE0
#define LOAD_OTR 0xE4

#define SPI_FREQUENCY 5000000
#define COUNTS_PER_REVOLUTION 4096

#endif //QUANSERCONTROLLERSHIELD_DECODER_H
