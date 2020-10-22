/**
* @file gyro-l3gd20h.cpp
* @brief Implementation of the L3GD20H gyro chip for ARM embed projects
* @author Jan-Willem Smaal <usenet@gispen.org>
* @date 7/9/2020 
*/


#include "gyro_l3gd20h.h"

Gyro::Gyro()
{
    x = 0; 
    y = 0; 
    z = 0; 
    temperature = 0; 
 
    i2c.start ();
    i2c.write(L3G_WRITE_PATTERN_SDO);
    i2c.write(CTRL_REG1);
    i2c.write(0x3F);
    //i2c.write()
    i2c.stop();

}


uint8_t Gyro::ReadRegister(enum l3g_register reg)
{
    uint8_t tmp;
    
    i2c.start();
    i2c.write(L3G_WRITE_PATTERN_SDO);
    i2c.write(reg);

    i2c.start();
    i2c.write(L3G_READ_PATTERN_SDO);
    tmp = i2c.read(0);
    i2c.stop();
    return tmp;
}

/**
* Read the register X and store in the class member. 
* @author Jan-Willem Smaal <usenet@gispen.org>
* @param void 
* @date 7/9/2020
*/
int16_t Gyro::ReadX(void)
{
    uint16_t tmp;
    
    tmp = Gyro::ReadRegister(OUT_X_L);
    tmp = tmp + (Gyro::ReadRegister(OUT_X_H)<<8);
    x = tmp;

    return tmp;
}


/**
* Read the register Y and store in the class member. 
* @author Jan-Willem Smaal <usenet@gispen.org>
* @param void 
* @date 7/9/2020
*/
int16_t Gyro::ReadY(void)
{
    int16_t tmp;
    
    tmp = Gyro::ReadRegister(OUT_Y_L);
    tmp = tmp + (Gyro::ReadRegister(OUT_Y_H)<<8);
    y = tmp;

    return tmp;
}


int16_t Gyro::ReadZ(void)
{
    int16_t tmp;
    
    tmp = Gyro::ReadRegister(OUT_Z_L);
    tmp = tmp + (Gyro::ReadRegister(OUT_Z_H)<<8);
    z = tmp;
    
    return tmp;
}


inline void Gyro::PowerUp(void)
{
        
}


inline void Gyro::PowerDown(void)
{
    
}


inline void Gyro::EnableX(void)
{
    
}


inline void Gyro::EnableY(void)
{
    
}


inline void Gyro::EnableZ(void)
{
    
}


int8_t Gyro::ReadTemp(void)
{
    int8_t temp;
    
    i2c.start();
    i2c.write(L3G_WRITE_PATTERN_SDO);
    i2c.write(OUT_TEMP);
    
    i2c.start();
    i2c.write(L3G_READ_PATTERN_SDO);
    temp = i2c.read(0);
    i2c.stop();

    temperature = temp; 

    return temp;
}

uint8_t Gyro::WhoAmI(void)
{
    uint8_t who;
    
    i2c.start();
    i2c.write(L3G_WRITE_PATTERN_SDO);
    i2c.write(WHO_AM_I);
    i2c.start();
    i2c.write(L3G_READ_PATTERN_SDO);
    who = i2c.read(0);
    i2c.stop();
    
    return who;
}

/* EOF  */