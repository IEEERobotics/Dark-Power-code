#include <msp430.h>
#include "ports.h"
#include "ADC.h"
#include "Macros.h"
#include "clocks.h"
#include "timers.h"
/*
 * main.c
 */

/*******************************************************************/

#define Twelve_volts_Minimum_hex_adc_value (0x2FF)

void check_vin_rail(void);
void power_down_voltage_rails(void);
volatile unsigned int v_in = 0;



/******************************************************************/

int main(void) {
    int delay;
    init_ports();
    init_clocks();
    init_adc();
    init_timers();
    for(delay = 0; delay < 1000; delay++);
    P1OUT |= 0x02;
    _enable_interrupts();


    while(1) {


        /*
        if ( v_in < Twelve_volts_Minimum_hex_adc_value ) {
             power_down_voltage_rails();
             continue;
		 }
		 else
		 __bis_SR_register(CPUOFF + GIE);
         */
    }
//    return 0;
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)  {
      __bis_SR_register_on_exit(CPUOFF + GIE);
     ADC10CTL0 &= ~ENC;         //disable ADC conversion unit
     v_in = ADC10MEM;             //get conversion data from the adc mem register.
     ADC10CTL0 |= ENC | ADC10SC;    //re-enable conversions AND set start conversion bit


}

void power_down_voltage_rails () {
    //set gpio pins that control the fets to low;
}
