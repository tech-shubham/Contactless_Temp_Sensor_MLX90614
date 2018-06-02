/***************************************************************************
*
*
* i2c.c
*
* Created by Shubham Gupta 
* Copyright (c) Building blocks  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "i2c.h"



volatile char i2cRet1=0,i2cRet2=0,i2cRet3=0;



//////////////////////////// I2C Communication	/////////////////////////////////////////////////////////////


////////I2C Slave /////////////////////////////////////////////////////////////////////////////

uint8_t slaveData;

void i2cInitSlave(uint8_t address){
	// load address into TWI address register
	TWAR = (address<<1);
	// set the TWCR to enable address matching and enable TWI, clear TWINT, enable TWI interrupt
	TWCR = (1<<TWIE) | (1<<TWEA) | (1<<TWINT) | (1<<TWEN);
	sei();
}

void i2cStopSlave(void){
	// clear acknowledge and enable bits
	TWCR &= ~( (1<<TWEA) | (1<<TWEN) );
}

ISR(TWI_vect){
	
	// temporary stores the received slave_data
	
	// own address has been acknowledged
	if( ((TWSR & 0xF8) == TW_SR_SLA_ACK )){  
		bufferAddress = 0xFF;

		// clear TWI interrupt flag, prepare to receive next byte and acknowledge
		TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN); 
		
		
	}
	/*if( ((TWSR & 0xF8) == 0x10 )){  
		bufferAddress = 0xFF;
		// clear TWI interrupt flag, prepare to receive next byte and acknowledge
		TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN); 
		
	}*/
	
	
	else if( (TWSR & 0xF8) == TW_SR_DATA_ACK ){ // slave_data has been received in slave receiver mode
		
		// save the received byte inside slave_data 
		slaveData = TWDR;
		
		// check wether an address has already been transmitted or not
		if(bufferAddress == 0xFF){
			
			bufferAddress = slaveData; 
			// clear TWI interrupt flag, prepare to receive next byte and acknowledge
			TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN); 
			
		}
		else{ // if a slave_databyte has already been received
			
			// store the slave_data at the current address
			rxbuffer[bufferAddress] = slaveData;
			
			// increment the buffer address
			bufferAddress++;
			
			// if there is still enough space inside the buffer
			if(bufferAddress < 0xFF){
				// clear TWI interrupt flag, prepare to receive next byte and acknowledge
				TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN); 
			}
			else{
				// Don't acknowledge
				TWCR &= ~(1<<TWEA); 
				// clear TWI interrupt flag, prepare to receive last byte.
				TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEN); 
			}
		}
	}
	else if( (TWSR & 0xF8) == TW_ST_DATA_ACK ){ // device has been addressed to be a transmitter
		
		// copy slave_data from TWDR to the temporary memory
		slaveData = TWDR;
		
		// if no buffer read address has been sent yet
		if( bufferAddress == 0xFF ){
			bufferAddress = slaveData;
		}
		
		// copy the specified buffer address into the TWDR register for transmission
		TWDR = txbuffer[bufferAddress];
		// increment buffer read address
		bufferAddress++;
		PORTH|=(1<<PH4);
		// if there is another buffer address that can be sent
		if(bufferAddress < 0xFF){
			// clear TWI interrupt flag, prepare to send next byte and receive acknowledge
			TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEA) | (1<<TWEN); 
		}
		else{
			// Don't acknowledge
			TWCR &= ~(1<<TWEA); 
			// clear TWI interrupt flag, prepare to receive last byte.
			TWCR |= (1<<TWIE) | (1<<TWINT) | (1<<TWEN); 
		}
		
	}
	else{
		// if none of the above apply prepare TWI to be addressed again
		TWCR |= (1<<TWIE) | (1<<TWEA) | (1<<TWEN);
	} 
}




////////I2C MAster ///////////////////////////////////////////////////////////////////////////

void i2cInitMaster(void)
{
	TWBR = (uint8_t)TWBR_val;
}

uint8_t i2cStart(uint8_t address)
{
	// reset TWI control register
	TWCR = 0;
	// transmit START condition 
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	// check if the start condition was successfully transmitted
	if((TWSR & 0x08) != TW_START){ return 1; }
	
	// load slave address into data register
	TWDR = address;
	// start transmission of address
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	// check if the device has acknowledged the READ / WRITE mode
	uint8_t twst = TW_STATUS & 0xF8;
	if ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) ) return 1;
	
	return 0;
}




uint8_t i2cWrite(uint8_t data)
{
	// load data into data register
	TWDR = data;
	// start transmission of data
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	
	if( (TWSR & 0x28) != TW_MT_DATA_ACK ){ return 1; }
	
	return 0;
}

uint8_t i2cReadAck(void)
{
	
	// start TWI module and acknowledge data after reception
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA); 
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}

uint8_t i2cReadNack(void)
{
	
	// start receiving without acknowledging reception
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait for end of transmission
	while( !(TWCR & (1<<TWINT)) );
	// return received data from TWDR
	return TWDR;
}

uint8_t i2cTransmit(uint8_t address, uint8_t* data, uint16_t length)
{
	if (i2cStart((address<<1) | AB_I2C_WRITE)) return 1;
	
	for (uint16_t i = 0; i < length; i++)
	{
		if (i2cWrite(data[i])) return 1;
	}
	
	i2cStopMaster();
	
	return 0;
}

uint8_t i2cReceive(uint8_t address, uint8_t* data, uint16_t length)
{
	if (i2cStart((address<<1) | AB_I2C_READ)) return 1;
	
	for (uint16_t i = 0; i < (length-1); i++)
	{
		data[i] = i2cReadAck();
	}
	data[(length-1)] = i2cReadNack();
	
	i2cStopMaster();
	
	return 0;
}

uint8_t i2cWriteReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length)
{
	if (i2cStart(devaddr<<1)) return 1;
	i2cWrite(regaddr);

	for (uint16_t i = 0; i < length; i++)
	{
		if (i2cWrite(data[i])) return 1;
	}
	
	

	i2cStopMaster();

	return 0;
}

uint8_t i2cReadReg(uint8_t devaddr, uint8_t regaddr, uint8_t* data, uint16_t length)
{
	if (i2cStart(devaddr<<1)) return 1;

	i2cWrite(regaddr);
	
	if(i2cStart((devaddr<<1) | 0x01)) return 1;
	
		i2cReadAck();

	for (uint16_t i = 0; i < (length-1); i++)
	{
		data[i] = i2cReadAck();
	}
	
	data[(length-1)] = i2cReadNack();

	i2cStopMaster();

	return 0;
}

void i2cStopMaster(void)
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

char readStuff(uint8_t dev_addr,uint8_t reg_addr)
{
	
	char data;
	i2cStart(dev_addr);
	
	i2cWrite(reg_addr); // set pointer to X axis MSB
	
	
	i2cStart(dev_addr|0x01);

	data = i2cReadAck();

	data=i2cReadNack();
	
	i2cStopMaster();
	
	return data;
}






uint8_t i2cRepeatedStart(char read_address) /* I2C repeated start function */
{
    uint8_t status;		/* Declare variable */
    TWCR=(1<<TWSTA)|(1<<TWEN)|(1<<TWINT);/* Enable TWI, generate start */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    status=TWSR&0xF8;		/* Read TWI status register */
    if(status!=0x10)		/* Check for repeated start transmitted */
    return 0;			/* Return 0 for repeated start condition fail */
    TWDR=read_address;		/* Write SLA+R in TWI data register */
    TWCR=(1<<TWEN)|(1<<TWINT);	/* Enable TWI and clear interrupt flag */
    while(!(TWCR&(1<<TWINT)));	/* Wait until TWI finish its current job */
    status=TWSR&0xF8;		/* Read TWI status register */
    if(status==0x40)		/* Check for SLA+R transmitted &ack received */
    return 1;			/* Return 1 to indicate ack received */
    if(status==0x48)		/* Check for SLA+R transmitted &nack received */
    return 2;			/* Return 2 to indicate nack received */
    else
    return 3;			/* Else return 3 to indicate SLA+W failed */
}


uint8_t i2cReadData(uint8_t devaddr, uint8_t regaddr, uint16_t length)
{
	i2cStart(devaddr<<1);
	i2cWrite(regaddr);
	i2cStopMaster();
	i2cRepeatedStart((devaddr<<1)|0x01);
	
	if(length == AB_EIGHT_BIT_VALUE)
	{
		i2cRet1=i2cReadAck();
	}
	else
	{
		i2cRet1=i2cReadAck();
		i2cRet2=i2cReadAck();
	}
	i2cRet3=i2cReadNack();
	i2cStopMaster();
	
	return i2cRet1;
}


