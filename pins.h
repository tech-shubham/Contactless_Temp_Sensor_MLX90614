/***************************************************************************
*
*
* pins.h
*
* Created by Shubham Gupta 
* Copyright (c) shubhamgupta.org  and/or its affiliates.
* All rights reserved.
***************************************************************************/

#ifndef __PINS_HEADER_H__
#define __PINS_HEADER_H__

#include "avrCommon.h"


#define AB_P0 "PH_0"
#define AB_P1 "PH_1"
#define AB_P2 "PD_6"
#define AB_P3 "PD_2"
#define AB_P4 "PG_4"
#define AB_P5 "PG_3"
#define AB_P6 "PH_3"
#define AB_P7 "PH_4"
#define AB_P8 "PH_5"
#define AB_P9 "PL_3"

#define AB_P10 "PJ_2"
#define AB_P11 "PB_2"
#define AB_P12 "PB_3"
#define AB_P13 "PB_1"
#define AB_P14 "PD_1"
#define AB_P15 "PD_0"
#define AB_P16 "PC_0"
#define AB_P17 "PC_1"
#define AB_P18 "PC_2"
#define AB_P19 "PC_3"

#define AB_P24 "PC_5"
#define AB_P25 "PC_4"
#define AB_P26 "PC_7"
#define AB_P27 "PC_6"
#define AB_P48 "PD_4"
#define AB_P49 "PD_5"

#define AB_P50 	"PG_0"
#define AB_A0	"PF_2"
#define AB_A1	"PF_3"
#define AB_A2	"PF_5"
#define AB_A3	"PF_6"

/////////////////////////////////New Macros Numbers ///////////////////////////////

#define AB_P51 "PE_1"
#define AB_P52 "PJ_2"
#define AB_P53 "PG_0"
#define AB_P54 "PH_6"
#define AB_P55 "PB_6"
#define AB_P56 "PG_2"
#define AB_P57 "PJ_5"
#define AB_P58 "PE_7"
#define AB_P59 "PE_5"
#define AB_P60 "PA_3"
#define AB_P61 "PA_4"
#define AB_P62 "PD_7"
#define AB_P63 "PE_7"
#define AB_P64 "PL_2"
#define AB_P65 "PE_6"
#define AB_P66 "PB_4"
#define AB_P67 "PB_0"
#define AB_P68 "PJ_6"
#define AB_P69 "PE_2"
#define AB_P70 "PJ_7"
#define AB_P71 "PB_7"
#define AB_P72 "PG_5"
#define AB_P73 "PB_5"
#define AB_P74 "PE_3"
#define AB_P75 "PE_4"
#define AB_P76 "PL_4"
#define AB_P77 "PL_5"






//////////////////////////////// NEW Macros ///////////////////////////////////////

/* Pins of Motor1  */

#define AB_MOTOR1_PIN1   "PC_4"  				// Motor Port1 Pin 1
#define AB_MOTOR1_PIN2   "PC_5"				// Motor Port1 Pin 2

/* Pins of Motor2  */

#define AB_MOTOR2_PIN1   "PC_6"  				// Motor Port2 Pin 1
#define AB_MOTOR2_PIN2   "PC_7"				// Motor Port2 Pin 2

/* Pins of Motor3  */

#define AB_MOTOR3_PIN1   "PC_0" 				// Motor Port3 Pin 1
#define AB_MOTOR3_PIN2   "PC_1"				// Motor Port3 Pin 2

/* Pins of Motor4  */

#define AB_MOTOR4_PIN1   "PC_2"  				// Motor Port4 Pin 1
#define AB_MOTOR4_PIN2   "PC_3"				// Motor Port4 Pin 2



#define AB_MOTORPORT		PORTC		// Motor Port on MicroController

#define AB_CW    	'2'	   // Clockwise Direction of Motor
#define AB_ACW	  	'1'	  // Anti - Clockwise Direction of Motor
#define AB_STOP  	'0'	 // To Stop Motor

#define AB_MOTORPORT1		'1'		// Motor Port 1
#define AB_MOTORPORT2		'2'		// Motor Port 2
#define AB_MOTORPORT3		'3'		// Motor Port 3
#define AB_MOTORPORT4		'4'		// Motor Port 4

#define AB_MOTORSPEED_SLOW     '1'			  // To Move motor at Slow Speed
#define AB_MOTORSPEED_MEDIUM	'2'			 // To Move motor at Medium Speed
#define AB_MOTORSPEED_FAST		'3'			// To Move motor at Fast Speed

#define AB_MOTORPORT2_PWMPIN   OCR4A			  // PWM Pin of Motor at Port 2
#define AB_MOTORPORT3_PWMPIN   OCR4C			 // PWM Pin of Motor at Port 3
#define AB_MOTORPORT4_PWMPIN   OCR4B			// PWM Pin of Motor at Port 4

#define AB_SLOWPWM_VALUE  170				  // PWM Value for Slow Movement
#define AB_MEDPWM_VALUE   200				 // PWM Value for Medium Movement
#define AB_FASTPWM_VALUE  255				// PWM Value for Fast Movement
#define	AB_MOTOR_PORT_INTERRUPT_GPIO	DDRD			// Gpio (Pin Direction) For motor Port Interrupt
#define	AB_MOTOR_PORT_READ				PIND			// Reading Motor Port value


#define AB_MOTOR_PORT_GPIO	DDRC							// Gpio (PIN Direction) for MOtor Port
#define AB_L293DD_GPIO	DDRD								// Gpio (PIN Direction) for L293D
#define	AB_L293DD_PORT	PORTD								// POrt for MOtor Port
#define AB_MOTOR_SHIELD_CONTROL1_GPIO	DDRJ				// Gpio (PIN Direction) for MOtor Shield1 Connectivity
#define AB_MOTOR_SHIELD_CONTROL1_PORT	PORTJ				// Port for Motor Shield1 Connrctivity
#define AB_RESET_SD_CARD_GPIO	DDRB
#define AB_RESET_SD_CARD_PORT	PORTB
#define	AB_RESET_LCD_GPIO	DDRH
#define	AB_RESET_LCD_PORT	PORTH
#define	AB_MOTOR_SHIELD_CONTROL2_GPIO	DDRG				// Gpio (PIN Direction) for MOtor Shield2 Connectivity
#define	AB_MOTOR_SHIELD_CONTROL2_PORT	PORTG				// Port for Motor Shield2 Connrctivity


// PWM Pins

#define 	AB_PWM_PIN_PORT2 "PH_3"							// PWM pin at Port2 for varying Motor Speed 
#define		AB_PWM_PIN_PORT4 "PH_4"							// PWM pin at Port4 for varying Motor Speed
#define 	AB_PWM_PIN_PORT3 "PH_5"							// PWM pin at Port3 for varying Motor Speed

#define 	AB_L293DD1_VCC					"PD_4"				// Pin which provides power to L293DD 1st IC
#define		AB_L293DD2_VCC					"PD_5"				// Pin which provides power to L293DD 2nd IC


#define 	AB_FT232_RXD					"PE_1"

#define 	AB_MOTOR_SHIELD_CONTROL1		"PJ_2"				// Its checks the connectivity of Motor Shield with the Brain
#define 	AB_MOTOR_SHIELD_CONTROL2		"PG_0"				

	
#define 	AB_RESET_LCD					"PH_6"				// Rseset Pin for Lcd
#define		AB_RESET_SD_CARD				"PB_6"				// Reset Pin for SD Card

#define		AB_POWER_LED					"PG_2"				// Power Led Pin (Red)
#define		AB_GREEN_LED					"PJ_5"				//	Remote attached Led Pin (Green)


#define 	AB_MOTOR_PORT4_INTERRUPT		"PD_0"				// INterrupt at Motor Port4 for counting rotations
#define 	AB_MOTOR_PORT3_INTERRUPT		"PD_1"				// INterrupt at Motor Port3 for counting rotations
#define		AB_MOTOR_PORT2_INTERRUPT		"PD_2"				// INterrupt at Motor Port2 for counting rotations


#define AB_COLORPORT3_PIN_S3  "PE_7"         // S3 PIN OF COLOR SENSOR AT PORT3  timer 0 pd7  INT7
#define AB_COLORPORT4_PIN_S3  "PE_4"         // S3 PIN OF COLOR SENSOR AT PORT4  timer 5 pl2  INT4
#define AB_COLORPORT5_PIN_S3  "PE_5"         // S3 PIN OF COLOR SENSOR AT PORT5  timer 3 pe6  INT5


#define AB_SENSOR_SHIELD_CONNECTIVITY1 "PA_3"			// Sensor shield connectivity1 Pin
#define AB_SENSOR_SHIELD_CONNECTIVITY2 "PA_4"			// Sensor shield connectivity2 Pin

// Ultra sonic Sensor Interrupts PINS

#define AB_SENSOR_PORT4_INTERRUPT "PE_4" 				// Sensor Port4 Interrupt Pin
#define AB_SENSOR_PORT5_INTERRUPT "PE_5"				// Sensor Port5 Interrupt Pin
#define AB_SENSOR_PORT3_INTERRUPT "PE_7"				// Sensor Port3 Interrupt Pin

#define AB_COLOR_SENSOR3_READ_PIN	"PD_7"				// Colour Sensor port3 read input frequency pin
#define AB_COLOR_SENSOR4_READ_PIN	"PL_2"				// Colour Sensor port4 read input frequency pin
#define AB_COLOR_SENSOR5_READ_PIN	"PE_6"				// Colour Sensor port5 read input frequency pin

//	Colour Sensor Input Pins and Port

#define AB_SENSOR_PORT3_INPUT_PIN	"PD_7"
#define AB_SENSOR_PORT4_INPUT_PIN	"PL_2"
#define AB_SENSOR_PORT5_INPUT_PIN	"PE_6"


//	Temperature and Humidity Sensors

#define	AB_TEMPERATURE_CHIP_SELECT_PIN		"PB_4"

#define AB_SD_CHIP_SELECT_PIN	"PB_0"



#define AB_DIN_1 		setValue(AB_P11, AB_HIGH);
#define AB_DIN_0 		setValue(AB_P11, AB_LOW);// data in	->	MOSI
#define AB_CLK_1 		setValue(AB_P13, AB_HIGH);
#define AB_CLK_0 		setValue(AB_P13, AB_LOW); // clocking the data to the LCD ->	SCLK
#define AB_CS_1 		setValue(AB_P66, AB_HIGH);
#define AB_CS_0 		setValue(AB_P66, AB_LOW); // chip enable, active low	->	SS
#define AB_RS_1 		setValue(AB_P55, AB_HIGH);
#define AB_RS_0 		setValue(AB_P55, AB_LOW); // data (high)/character(low)
#define AB_RESET_1 	setValue(AB_P54, AB_HIGH);setValue(AB_P0, AB_HIGH); 
#define AB_RESET_0 	setValue(AB_P54, AB_LOW); // reset pin

#define 	AB_POWER_LED_ON		setDirection(AB_P56, AB_OUTPUT);    setValue(AB_P56, AB_HIGH);
#define 	AB_POWER_LED_OFF		setValue(AB_P56, AB_LOW);  setDirection(AB_P56, AB_INPUT)

#define 	AB_POWER_GREEN_LED_OFF		setValue(AB_P57, AB_LOW);
#define 	AB_BLUELCD_LED_ON		setDirection(AB_P68, AB_OUTPUT);    setValue(AB_P68, AB_HIGH);
#define 	AB_BLUELCD_LED_OFF		setDirection(AB_P56,AB_INPUT);    setValue(AB_P68, AB_LOW);

#define 	AB_LCD_BACK_LED_ON		setDirection(AB_P70, AB_OUTPUT);    setValue(AB_P70, AB_HIGH);
#define 	AB_LCD_BACK_LED_OFF	setDirection(AB_P70,AB_INPUT);    setValue(AB_P70, AB_LOW);

#define	AB_LCD_GND_PIN				"PE_2"			// Lcd GND via transistor
#define AB_LCD_CHIP_SELECT_PIN		"PB_4"			//Lcd Chip select Pin
#define	AB_LCD_REG_PIN				"PH_0"			// Lcd register select pin


#define AB_SD_CARD_RESET_PIN	"PB_6"				// Reset Pin for SD card
#define	AB_POWER_LED_PIN	"PG_2"


#define	AB_SPI_CS_PIN		"PB_0"
#define	AB_SPI_SCK_PIN		"PB_1"
#define	AB_SPI_MOSI_PIN	"PB_2"

#define	AB_WIFI_ON_PIN		"PA_5"						// Power to WiFi Module via transistor

#define	AB_GREEN_LED_PIN	"PJ_5"

#define	AB_POWER_LED_PIN	"PG_2"

#define AB_INPUT 0
#define AB_OUTPUT 1

#define AB_HIGH 1
#define AB_LOW 0



void setValue(char *str, unsigned int p_value);
void setDirection(char *str, unsigned int p_direction);
int digitalRead(char *str);



#endif //__PINS_HEADER_H__


