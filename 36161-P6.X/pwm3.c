#include <xc.h>
#include "pwm3.h"
#include "pps.h"

/* PWM Initialization */
void PWM3_Initialize(void) {  
          
    /* PWM3 Compare clock source = HFINTOSC */
	PWM3CLK = 0x03;  
    
    /* PWM3 Clock Prescale Value = 1 */
    PWM3CPRE = 0x01;
    
    /* 6400 clocks period in the PWM period  */
    /* 6400 * 31.25ns = 200 us (~5 KHz) */
    PWM3PRH = 0x19;
    PWM3PRL = 0x00;
    
    /* PWM31 output is high true; PWM32 output is high-true. left-aligned mode */
    PWM3S1CFG = 00;
        
    /* Compare match occurs when PWM3 counter = 2496dec (9C0h)*/
    /* 2496 * 31.25ns = 78 us (d.c. = 78 us / 200 us = ~39%) */
    PWM3S1P1H = 0x09;
    PWM3S1P1L = 0xC0;
    
    /* Compare match occurs when PWM3 counter = 4288dec (10C0h)*/
    /* 4288 * 31.25ns =  134 us (d.c. = 134 us / 200 us = ~67%) */
    PWM3S1P2H = 0x10;
    PWM3S1P2L = 0xC0;
    
    /* PWMC is enabled; reload registers */
    PWM3CON = 0x84;
}
