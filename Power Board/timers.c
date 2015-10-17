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
 I'm initing a timer in this, that is a 250 ms timer.


 */

volatile unsigned int secondcounter; //switch 1 is inside debounce
 volatile unsigned char secondFlag;
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
	TA0CTL      = TASSEL_2;        // SMCLK source
	  TA0CTL |= TACLR ;               // Clear Timer A
	  TA0CTL |= MC_2;       // Continuous count mode
	  TA0CTL |= ID_2;                // divide clock by 2

	  TA0CTL &= ~TAIE;                // TimerA0 counter interrupt disable [overflow]
	  TA0CTL &= ~TAIFG;                // TimerA0 counter interrupt flag cleared
	  TA0CCR0 = TA0CCR0_INTERVAL_5;     // TA0CCR0 capture compare register
	  TA0CCTL0 |= CCIE;               // TA0CCR0 enable interrupt


}
//void Init_Timer_A02 (void) {
//    TA0CTL      = TASSEL_2;        				// SMCLK source - 100K Hz
//    TA0CTL      |= TACLR;               		// Resets TA0R, clock divider, count direction
//    TA0CTL      |= MC_2;       					// Continuous up
//    TA0CTL      |= ID_2;               			// Divide clock by 4 = 25K Hz
//
//    TA0CTL      &= ~TAIE;               		// Disable Overflow Interrupt
//    TA0CTL      &= ~TAIFG;              		// Clear Overflow Interrupt flag
//    TA0CCR0     =  FIVE_MS_INTERVAL_FOR_CC0;    // CCR0
//    TA0CCTL0    &= ~ CCIE;                		// CCR0 enable interrupt.  interrupt
//
//
//}

#pragma vector = TIMER0_A0_VECTOR

__interrupt void Timer0_A0_ISR(void){

  TA0CCR0 += TA0CCR0_INTERVAL_5;



  secondcounter++;



  if(secondcounter == 12){
	  secondcounter = 0;

	  secondFlag = TRUE;
  }
  }
