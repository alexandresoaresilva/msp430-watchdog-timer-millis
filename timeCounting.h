/*
 * timeCounting.h
 *
 *  Created on: Dec 1, 2017
 *      Author: alexa
 */
//#include "msp430.h"
//#include <stdint.h>

#ifndef TIMECOUNTING_H_
#define TIMECOUNTING_H_


#ifndef __msp430
#include <msp430.h>
#endif

#ifndef _STDINT_H_
#include <stdint.h>
#endif
//uses Watchdog timer

//use this function to set up millis since start of execution
void initTimeCounting(void);

//uint32_t getSeconds(void);
uint32_t getMillis(void);
void watchdog_timer_ISR (void);
void setupWatchDogTimer(void);

#endif /* TIMECOUNTING_H_ */
