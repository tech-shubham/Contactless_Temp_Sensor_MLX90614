/***************************************************************************
*
*
* avrCommon.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#ifndef __AVR_COMMON_H__
#define __AVR_COMMON_H__

#define ATMEGA2560
#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */
#include <stdio.h>			/* Include Std. i/p o/p file */
#include <string.h>			/* Include String header file */
#include <avr/interrupt.h>
#include<inttypes.h>
#include <stdlib.h>
#include <util/twi.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>

#define F_CPU 16000000UL			/* Define CPU Frequency 8MHz */

#endif //__AVR_COMMON_H__
