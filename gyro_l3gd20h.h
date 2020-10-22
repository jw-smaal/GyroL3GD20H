#ifndef __jwsTWI_gyro_l3gd20hpp__
#define __jwsTWI_gyro_l3gd20hpp__
/**
* @file gyro-l3gd20h.h
* @brief Implementation of the L3GD20H gyro chip for ARM embed projects
* @author Jan-Willem Smaal  <usenet@gispen.org>
* @date 7/9/2020 
*/


#include "mbed.h"
#include "platform/mbed_thread.h"

// Not sure if this can be placed inside of the class.  
static I2C i2c(I2C_SDA0, I2C_SCL0);
 
/** 
 * Adresses
 */
// I2C address (SDO0 == 1)
#define L3G_I2C_SLAVE_ADDRESS   0x6B

#define L3G_READ_PATTERN        0xD5
#define L3G_WRITE_PATTERN       0xD4
//  The Populo board has SD0 set to 1.
#define L3G_READ_PATTERN_SDO    0xD7
#define L3G_WRITE_PATTERN_SDO   0xD6


/**
 * Registers
 */
#define L3G_WHO_AM_I        0x0F

#define L3G_CTRL_REG1       0x20
#define YEN 0U
#define XEN 1U
#define ZEN 2U
#define PD  3U
#define BW0 4U
#define BW1 5U
#define BW1 5U
#define DR0 6U
#define DR1 7U
#define POWERUPALL ((1<<PD)|(1<<XEN)|(1<<YEN)|(1<<ZEN)|(1<BW1)|(1<<BW0))


/**
 * register mapping
 */
enum l3g_register {
    WHO_AM_I      = 0x0F,
    CTRL_REG1     = 0x20,
    CTRL_REG2     = 0x21,
    CTRL_REG3     = 0x22,
    CTRL_REG4     = 0x23,
    CTRL_REG5     = 0x24,
    REFERENCE     = 0x25,
    OUT_TEMP      = 0x26,
    STATUS_REG    = 0x27,
    OUT_X_L       = 0x28,
    OUT_X_H       = 0x29,
    OUT_Y_L       = 0x2A,
    OUT_Y_H       = 0x2B,
    OUT_Z_L       = 0x2C,
    OUT_Z_H       = 0x2D,
    FIFO_CTRL_REG = 0x2E,
    FIFO_SRC_REG  = 0x2F,
    INT1_CFG      = 0x30,
    INT1_SRC      = 0x31,
    INT1_THS_XH   = 0x32,
    INT1_THS_XL   = 0x33,
    INT1_THS_YH   = 0x34,
    INT1_THS_YL   = 0x35,
    INT1_THS_ZH   = 0x36,
    INT1_THS_ZL   = 0x37,
    INT1_DURATION = 0x38,
    LOW_ODR       = 0x39
};



/** 
 * Gyro class for the L3GD20H chip 
 * @author Jan-Willem Smaal <usenet@gispen.org>
 * @param void 
 * @date 7/9/2020
 */ 
class Gyro 
{
    public:
        Gyro(); // Constructor 
        // Getters 
        int16_t x;
        int16_t y; 
        int16_t z; 
        int8_t temperature; 

        int16_t ReadX(void);
        int16_t ReadY(void);
        int16_t ReadZ(void);
        int8_t ReadTemp(void);
        void PowerUp(void);
        void PowerDown(void);
        void EnableX(void);
        void EnableY(void);
        void EnableZ(void);
        uint8_t WhoAmI(void);
    private: 
        uint8_t ReadRegister(enum l3g_register reg);
};


#endif /* defined(__jwsTWI_MCP4725__gyro_l3gd20h__) */