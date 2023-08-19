/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.h
 *
 * Description: Header file for ultrasonic
 *
 *******************************************************************************/

#ifndef _ULTRA_H_
#define _ULTRA_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include "timer.h"


#define   TRIGER_DDR    DDRB
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTB
#define   ECHO_PULLUP   PORTD
#define   TRIGER        5
#define   ECHO          6

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init    (void);
void enable_ex_interrupt(void);
void ultra_triger       (void);

#endif
