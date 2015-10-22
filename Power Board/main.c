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

extern unsigned int ADC_Power_Detector;
void check_vin_rail(void);
void power_down_voltage_rails(void);
volatile unsigned char v_in_is_less_than_twelve_volts = FALSE;
extern volatile unsigned char secondFlag;
void ADC_Process(void);

/******************************************************************/

/*
 * This function serves as an enternal low-power mode setter unless the adc finds something wrong with the
 * 		input voltage on on the VCC (v_in) rail.  If the rail drops to less than 12V reccommended minimum
 * 		range for the battery input, it cuts off the power to the supply rails.
 *
 *
 */
int main(void) {
	int delay;
	init_ports();
	init_clocks();
	init_timers();


	for (delay = 0; delay < 1000; delay++)
		;
	P1OUT |= RGB_GREEN;
	_enable_interrupts();
	P2OUT &= 	~POWER_EN;
	while (1) {

		if (secondFlag == TRUE) {
			secondFlag = FALSE;

			init_adc();
			ADC_Process();
		}
		if (v_in_is_less_than_twelve_volts == TRUE) {
			power_down_voltage_rails();
			continue;
		} else
			//_low_power_mode_3();
		{
			P2OUT &= ~POWER_EN;
		}

	}
}
void ADC_Process(void) {
	while (ADC10CTL1 & BUSY)
		; // Wait if ADC10 core is active
	ADC10CTL0 |= ENC;
	ADC10CTL0 |= ADC10SC; // Sampling and conversion start

}

void power_down_voltage_rails() {
	//set gpio pins that control the fets to low;
	P2OUT |= POWER_EN;		// turn off power.
	P2OUT |= BUZZ; 		// ENABLE THE BUZZER
	P1OUT &= ~RGB_GREEN; 		// turn OFF green led
	P1OUT |= RGB_RED; 		// turn on warning red led

}
