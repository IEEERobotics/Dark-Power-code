/*
 * clocks.c
 *
 *  Created on: May 6, 2015
 *      Author: deathmonkey
 */

#include "clocks.h"
#include "Macros.h"
#include "msp430.h"

void init_clocks(void)
  //------------------------------------------------------------------------------
// Clock Configurtaions
// This is the clock initialization for the program.
//
// Initial clock configuration, runs immediately after boot.
// Disables 1ms watchdog timer,
//      configure MCLK to 100kHz
//      configure SMCLK to 100kHz.
//      ACLK  Not used.
// Since the X1 oscillator is not currently connected,
// X1CLK is an unknown speed (probably ~10kHz).
//------------------------------------------------------------------------------
{
  WDTCTL = WDTPW | WDTHOLD;            	// Disable watchdog
// Clocks:
  DCOCTL = 0;                          // Select lowest DCOx and MODx settings
  BCSCTL1 = CLEAR;					   // Select lowest RSEL settings

//-------------------------------------------------------
}


