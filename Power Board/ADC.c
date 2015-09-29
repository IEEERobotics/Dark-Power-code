/*
 * ADC.c
 *
 *  Created on: May 6, 2015
 *      Author: deathmonkey
 */

#include "ADC.h"
#include "msp430.h"
#include "Macros.h"

void init_adc(void){
	ADC10CTL0 = CLEAR;
	ADC10CTL0 |= (MSC | ADC10ON | ADC10IE| ENC);

	ADC10CTL1 |= CLEAR;
	ADC10CTL1 |= (INCH_3 | ADC10SSEL_3);
	ADC10CTL1 |= CONSEQ_2;

	ADC10AE0 = 	CLEAR;									// Set all pins to non adc mode
	ADC10AE0 |= VIN_REF;								// Set pin 3 to ADC mode for VIN REF

}

void start_adc(void){
	ADC10CTL0 |= ADC10SC;
}



