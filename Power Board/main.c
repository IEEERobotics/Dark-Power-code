#include <msp430.h> 
#include "ports.h"
#include "ADC.h"
#include "Macros.h"
#include "clocks.h"

/*
 * main.c
 */


int main(void) {
	int delay;
	init_ports();
	init_clocks();
	init_adc();
	for(delay = 0; delay < 1000; delay++);
	P1OUT |= 0x02;

    while(1);
//	return 0;
}
