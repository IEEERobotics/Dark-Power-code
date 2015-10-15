/*
 * ADC.h
 *
 *  Created on: May 6, 2015
 *      Author: deathmonkey
 */

#ifndef ADC_H_
#define ADC_H_





#endif /* ADC_H_ */


/*********************extern variables used *********************************/

extern volatile unsigned char v_in_is_less_than_twelve_volts ;


/*********************extern variables used *********************************/


/*********************function declarations *********************************/
void init_adc(void);
void start_adc(void);

__interrupt void ADC10_ISR(void);
/*********************function declarations *********************************/
