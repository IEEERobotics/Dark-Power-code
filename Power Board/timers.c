/*
 * timers.c
 *
 *  Created on: Oct 13, 2015
 *      Author: Siddardha
 */



#include <msp430.h>
#include "ports.h"
#include "ADC.h"
#include "Macros.h"
#include "clocks.h"
#include "timers.h"

 /*

 timers.c
 I'm initing a timer in this, that is a 1000 ms timer.


 */


void init_timers (void) {
	Init_Timer_A0();

}

void turn_timers_on(); 
 //-----------------------------------------------------------------------------
// Init_Timer_A0(void)
// Global varibales used: none
// Local variables used: none
// Returns: null
// siddardha Boddapati
// 09/15/2014
//-----------------------------------------------------------------------------
void Init_Timer_A0 (void) {
    TA0CTL      = TASSEL_2;        				// SMCLK source - 100K Hz
    TA0CTL      |= TACLR;               		// Resets TA0R, clock divider, count direction
    TA0CTL      |= MC_2;       					// Continuous up
    TA0CTL      |= ID_2;               			// Divide clock by 4 = 25K Hz

    TA0CTL      &= ~TAIE;               		// Disable Overflow Interrupt
    TA0CTL      &= ~TAIFG;              		// Clear Overflow Interrupt flag
    TA0CCR0     =  FIVE_MS_INTERVAL_FOR_CC0;    // CCR0
    TA0CCTL0    &= ~ CCIE;                		// CCR0 enable interrupt.  interrupt


}
