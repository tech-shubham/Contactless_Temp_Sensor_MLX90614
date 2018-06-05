/***************************************************************************
*
*
* pins.c
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#include "pins.h"


void setDirection(char *str, unsigned int pDirection)
{
	if(str[1]=='A')
	{
		if(pDirection == AB_INPUT)
		{
			DDRA &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRA |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='B')
	{
		if(pDirection == AB_INPUT)
		{
			DDRB &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRB |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='C')
	{
		if(pDirection == AB_INPUT)
		{
			DDRC &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRC |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='D')
	{
		if(pDirection == AB_INPUT)
		{
			DDRD &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRD |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='E')
	{
		if(pDirection == AB_INPUT)
		{
			DDRE &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRE |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='F')
	{
		if(pDirection == AB_INPUT)
		{
			DDRF &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRF |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='G')
	{
		if(pDirection == AB_INPUT)
		{
			DDRG &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRG |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='H')
	{
		if(pDirection == AB_INPUT)
		{
			DDRH &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRH |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='J')
	{
		if(pDirection == AB_INPUT)
		{
			DDRJ &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRJ |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='K')
	{
		if(pDirection == AB_INPUT)
		{
			DDRK &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRK |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='L')
	{
		if(pDirection == AB_INPUT)
		{
			DDRL &=~(1<<(str[3]-48));
		}
		else if(pDirection == AB_OUTPUT)
		{
			DDRL |=(1<<(str[3]-48));
		}
	}
}

void setValue(char *str, unsigned int pValue)
{
	if(str[1]=='A')
	{
		if(pValue == AB_LOW)
		{
			PORTA &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTA |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='B')
	{
		if(pValue == AB_LOW)
		{
			PORTB &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTB |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='C')
	{
		if(pValue == AB_LOW)
		{
			PORTC &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTC |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='D')
	{
		if(pValue == AB_LOW)
		{
			PORTD &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTD |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='E')
	{
		if(pValue == AB_LOW)
		{
			PORTE &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTE |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='F')
	{
		if(pValue == AB_LOW)
		{
			PORTF &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTF |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='G')
	{
		if(pValue == AB_LOW)
		{
			PORTG &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTG |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='H')
	{
		if(pValue == AB_LOW)
		{
			PORTH &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTH |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='J')
	{
		if(pValue == AB_LOW)
		{
			PORTJ &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTJ |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='K')
	{
		if(pValue == AB_LOW)
		{
			PORTK &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTK |=(1<<(str[3]-48));
		}
	}
	
	else if(str[1]=='L')
	{
		if(pValue == AB_LOW)
		{
			PORTL &=~(1<<(str[3]-48));
		}
		else if(pValue == AB_HIGH)
		{
			PORTL |=(1<<(str[3]-48));
		}
	}
	
	

}

int digitalRead(char *str)
{
	if(str[1]=='A')
	{
		return(PINA&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='B')
	{
		return(PINB&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='C')
	{
		return(PINC&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='D')
	{
		return(PIND&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='E')
	{
		return(PINE&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='F')
	{
		return(PINF&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='G')
	{
		return(PING&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='H')
	{
		return(PINH&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='J')
	{
		return(PINJ&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='K')
	{
		return(PINK&(1<<(str[3]-48)));
	}
	
	else if(str[1]=='L')
	{
		return(PINL&(1<<(str[3]-48)));
	}
	
	return 0;
}




	
	
	
	