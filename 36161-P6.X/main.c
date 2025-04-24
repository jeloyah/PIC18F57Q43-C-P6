#include <xc.h>
#include "gpio.h"
#include "clock.h"
#include "ioc.h"
#include "pps.h"
#include "pwm1.h"
#include "pwm2.h"
#include "pwm3.h"

void main(void) {
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();
         
    /* Config IOC */
    IOC_Initialize();
        
    /* PWM1 Initialization */
	PWM1_Initialize();
    
    /* PWM2 Initialization */
	PWM2_Initialize();
    
    /* PWM3  Initialization */
	PWM3_Initialize();
    
    PPS_Initialize();
    
    /* Enable interrupts */
    ei();
    
    while(1)
    {

        
        
        
    } /* while */
    
    return;
} /* main */
