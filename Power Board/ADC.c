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


void init_adc(){

	 ADC10CTL0 = ADC10SHT_2; // select clock speed of 16x
	    ADC10CTL0 |= ADC10ON;   // enable ADC10 (10bits, 0-1023)
	    ADC10CTL0 |= ADC10IE;   // interrupt enable
	    ADC10CTL1 = INCH_3;     // Channel 3
	    ADC10AE0 = VIN_REF;       // Pin 3
}


//void init_adc2(void){
//	ADC10CTL0 = CLEAR;
//	ADC10CTL0 |= ( ADC10ON | ADC10IE);				// turn adc on | turn on interrupts enable for conversion done ifg |
//	ADC10CTL1 |= CLEAR;
//	ADC10CTL1 |= (INCH_3 | ADC10SSEL_3);				// sellect input channel three and also select source lcock as sm_clk 100 kHZ
//	ADC10CTL1 |= CONSEQ_0;								// single channel single conversion
//	ADC10CTL1 |= SHS_2; 								// sample SHI (start conversion bit is form out output bit of timer out 0 ) instead of setting ADC10SC high.
//
//	ADC10AE0 = 	CLEAR;									// Set all pins to non adc mode
//	ADC10AE0 |= VIN_REF;								// Set pin 3 to ADC mode for VIN REF
//
//}

//void start_adc(void){
//
//	ADC10CTL0 |= ENC; 								// enables the conversion bit, so that the adc is ready to sample
//
//}



#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)  {


	/* __bis_SR_register_on_exit(CPUOFF + GIE);  */
	 ADC_Power_Detector = ADC10MEM;
		  if ( ADC_Power_Detector < Twelve_volts_Minimum_hex_adc_value)            //get conversion data from the adc mem register.
		        {
		       	 v_in_is_less_than_twelve_volts = TRUE;
		       	 //_low_power_mode_off_on_exit();								//
		        }

}
