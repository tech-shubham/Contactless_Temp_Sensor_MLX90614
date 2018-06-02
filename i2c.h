/***************************************************************************
*
*
* i2c.h
*
* Created by Shubham Gupta 
* Copyright (c) Building blocks  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#ifndef __I2C_HEADER_H__
#define __I2C_HEADER_H__

#include "avrCommon.h"

#define F_SCL 100000UL 														// SCL frequency
#define Prescaler 1															// Prescale Division by 1
#define TWBR_val ((((F_CPU / F_SCL) / Prescaler) - 16 ) / 2)				// Bit Rate value


////////////////////// I2C Communication ///////////////////////

#define AB_I2C_READ 0x01
#define AB_I2C_WRITE 0x00

#define AB_EIGHT_BIT_VALUE 1
#define AB_SIXTEEN_BIT_VALUE 2


extern volatile char i2cRet1,i2cRet2,i2cRet3;								// Reads/Stores  the vlaue from I2C 

////////////////////// I2C Communication ///////////////////////

volatile uint8_t bufferAddress;
volatile uint8_t txbuffer[0xFF];
volatile uint8_t rxbuffer[0xFF];

void i2cInitSlave(uint8_t address);
void i2cStopSlave(void);
ISR(TWI_vect);


void i2cInitMaster(void);
uint8_t i2cStart(uint8_t address);
uint8_t i2cWrite(uint8_t data);
uint8_t i2cReadAck(void);
uint8_t i2cReadNack(void);
uint8_t i2cTransmit(uint8_t address, uint8_t* data, uint16_t length);
uint8_t i2cReceive(uint8_t address, uint8_t* data, uint16_t length);
uint8_t i2cWriteReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
uint8_t i2cReadReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length);
void i2cStopMaster(void);
char readStuff(uint8_t dev_addr,uint8_t reg_addr);
uint8_t i2cRepeatedStart(char read_address);
uint8_t i2cReadData(uint8_t devaddr, uint8_t regaddr, uint16_t length);


#endif //__I2C_HEADER_H__

