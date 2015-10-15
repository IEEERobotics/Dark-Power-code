/*
 * ports.c
 *
 *  Created on: May 6, 2015
 *      Author: deathmonkey
 */

#include "ports.h"
#include "Macros.h"
#include <msp430.h>

void init_ports(void){
	init_port1();										// Initialize Port 1
	init_port2();										// Initialize Port 2

}

void init_port1(void){
	P1DIR = 	CLEAR;									// Set all pins to input direction
	P1DIR |= 	(RGB_RED | RGB_GREEN | RGB_BLUE);		// Set to output direction for rgb leds
	P1SEL = 	CLEAR;									// Set all pins to GPIO
	P1OUT = 	CLEAR;									// Set all pins to Low

}

void init_port2(void){
	P2DIR = 	CLEAR;									// Set all pins to input direction
	P2DIR |= 	(BUZZ | POWER_EN);						// Set to output mode for buzzer and power enable
	P2SEL = 	CLEAR;									// Set all pins to GPIO
	P2OUT = 	CLEAR;									// Set to output to low power mode
	P2OUT |= 	POWER_EN;								// Turn off power to system
}

