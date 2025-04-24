#include <xc.h>
#include "pps.h"

void PPS_Initialize(void)
{
    /* sequence for unlock PPS */
    PPS_unlock();
               
    /* PWM1S1P1_OUT is connected to RC7 pin */
    RC6PPS = 0x18;
       
    /* PWM1S1P2_OUT is connected to RC6 pin */
    RC5PPS = 0x19;
    
    /* PWM2S1P1_OUT is connected to RB2 pin */
    RB2PPS = 0x1A;
    
    /* PWM2S1P2_OUT is connected to RB1 pin */
    RB1PPS = 0x1B;
        
     /* PWM3S1P1_OUT is connected to RD3 pin */
    RD3PPS = 0x1C;
    
    /* PWM3S1P2_OUT is connected to RD2 pin */
    RD2PPS = 0x1D;
    
    /* sequence for lock PPS */
    PPS_lock();
}

void PPS_lock(void) {
    /* Disable interrupts */
    di();
    
    /* Required sequence */
    PPSLOCK = 0x55;
    
    /* Required sequence */
    PPSLOCK = 0xAA;
    
    /* Set PPS locked bit*/
    PPSLOCK |= 0x01;
    
    /* Enable interrupts */
    ei();  
}

void PPS_unlock(void) {
    /* Disable interrupts */
    di();
    
    /* Required sequence */
    PPSLOCK = 0x55;
    
    /* Required sequence */
    PPSLOCK = 0xAA;
    
    /* Clear PPS locked bit*/
    PPSLOCK &= 0xFE;
    
    /* Enable interrupts */
    ei();  
}