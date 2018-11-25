/*
 * timeCounting.c
 *
 *  Created on: Dec 1, 2017
 *      Author: alexa
 */

#include "timeCounting.h"

//create a  uint32_t millis variable to update your millis variable;


uint32_t millis;
//uint32_t seconds;

unsigned char oneMilliHasPassed;

void initTimeCounting(void){
    setupWatchDogTimer();
    oneMilliHasPassed = 0;
    millis = 0;
//    seconds = 0;
}

uint32_t getMillis(void){
    return millis;
}

//uint32_t getSeconds(void){
//    return seconds;
//}


void setupWatchDogTimer(void){
    WDTCTL = WDT_MDLY_0_5; //equivalent to
    IE1 |= WDTIE;                             // Enable WDT interrupt}
}

#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer_ISR(void)
//void __attribute__ ((interrupt(WDT_VECTOR))) watchdog_timer_ISR (void)
{
    oneMilliHasPassed ^=0x01; //toggles every .5 s

    if (oneMilliHasPassed)
        millis += 1;
//    if ( millis != 0  && !(millis % 1000) ) //not seconds = 0 and the remainder of millis/1000 is 0
//        seconds += 1;
}
