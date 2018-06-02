/***************************************************************************
*
*
* CLS.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#ifndef __CLS_HEADER_H__
#define __CLS_HEADER_H__

#include "i2c.h"
#include "pins.h"

//// for Contact less temperature sensors
#define CL_ADDRESS 0X5A

char spi_ch;
char spi_recieve_buffer[50];
char flush_buffer;
long celsius;

char cl_buf[10];
char ret1,ret2,ret3;



///////////////////////// Contact less temperature ///////////////////////
void AB_STEM_init_CLTS(void);
int AB_STEM_Read_CLTS(void);

















#endif //__CLS_HEADER_H__