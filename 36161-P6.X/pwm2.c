#include <xc.h>
#include "pwm2.h"
#include "pps.h"

/* PWM Initialization */
void PWM2_Initialize(void) {  

    /* PWM2 Compare clock source = HFINTOSC */
	PWM2CLK = 0x03;  
    
    /* PWM2 Clock Prescale Value = 31 */
    PWM2CPRE = 0x1F;
    
    /* 100 clocks periods in the PWM period  */
    /* 100 * 500ns = 50 us (20 KHz) */
    PWM2PRH = 0x00;
    PWM2PRL = 0x64;
    
    /* PWM21 output is high true; PWM22 output is high-true. left-aligned mode */
    PWM2S1CFG = 00;
        
    /* Compare match occurs when PWM2 counter = 50dec (32h)*/
    /* 50 * 500ns = 25 us (d.c. = 25 us / 50 us = 50%) */
    PWM2S1P1H = 0x00;
    PWM2S1P1L = 0x32;
    
    /* Compare match occurs when PWM2 counter = 22dec (16h)*/
    /* 22 * 500ns = 11 us (d.c. = 11 us / 50 us = 22%) */
    PWM2S1P2H = 0x00;
    PWM2S1P2L = 0x16;
    
    /* PWMC is enabled; reload registers */
    PWM2CON = 0x84;
}
