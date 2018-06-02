/***************************************************************************
*
*
* CLS.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "CLS.h"


/////////////// Contact less temperature sensore ///////////////////

void AB_STEM_init_CLTS() // I2C pins P14 P15 
{
	celsius=0;
	ret1=0;ret2=0;ret3=0;

	setDirection(AB_P14,AB_OUTPUT);
	setDirection(AB_P15,AB_OUTPUT);
	
	setValue(AB_P14,AB_HIGH);
	setValue(AB_P15,AB_HIGH);
	
	i2cInitMaster();

}

int AB_STEM_Read_CLTS()
{
	i2cReadData(CL_ADDRESS, 0x07, AB_SIXTEEN_BIT_VALUE);

		
		// Process the data.
		double tempFactor=0.02;
		double tempData =0x0000;
		
		tempData=(double)((ret2 & 0x007F)<<8) + ret1;
		tempData=(tempData * tempFactor)-0.01;
		
		//celsius =((tempData - 273.15) * 100);
		celsius =((tempData - 273.15));
		return celsius;
		//lcd_integer(celsius,2,2,5);
		//lcd_string("Temp",2,0);
		//lcd_string("Deg C",2,8);
}


int main()
{
	int clsTemp=0;
	AB_STEM_init_CLTS();
	
	while(1)
	{
		clsTemp=AB_STEM_Read_CLTS()	;	///// Gives Teperature at the Pointed object
	}

		return 0;
}
