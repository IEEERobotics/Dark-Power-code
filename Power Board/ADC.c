/*
 * ADC.c
 *
 *  Created on: May 6, 2015
 *      Author: deathmonkey
 */

#include "ADC.h"
#include "msp430.h"
#include "Macros.h"

unsigned int ADC_Power_Detector;

void init_adc() {

	ADC10CTL0 = ADC10SHT_2; // select clock speed of 16x
	ADC10CTL0 |= ADC10ON;   // enable ADC10 (10bits, 0-1023)
	ADC10CTL0 |= ADC10IE;   // interrupt enable
	ADC10CTL1 = INCH_3;     // Channel 3
	ADC10AE0 = VIN_REF;       // Pin 3
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {

	ADC_Power_Detector = ADC10MEM;
	if (ADC_Power_Detector < Twelve_volts_Minimum_hex_adc_value) //get conversion data from the adc mem register.
	{
		v_in_is_less_than_twelve_volts = TRUE;
		//_low_power_mode_off_on_exit();
	}
	else
	{
		v_in_is_less_than_twelve_volts = FALSE;
	}
	}
