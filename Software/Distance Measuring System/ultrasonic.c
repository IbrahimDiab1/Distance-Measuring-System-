/******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for ultrasonic
 *
 *******************************************************************************/

#include "common_macros.h"
#include "ultrasonic.h"
#include "lcd.h"
#include "std_types.h"


uint8 sensor_working = 0, rising_edge = 0;
uint32 timer_counter = 0, distance;


void ultrasonic_init(void) 
{

    SET_BIT(TRIGER_DDR, TRIGER);
    CLEAR_BIT(ECHO_DDR, ECHO);
    SET_BIT(ECHO_PULLUP, ECHO);
    enable_ex_interrupt();
    timer0_init();
    return;
}

void enable_ex_interrupt(void) 
{

    MCUCR |= (1 << ISC10);          // Trigger INT1 on any logic change.
    GICR  |= (1 << INT1);           // Enable INT1 interrupts.

    return;
}

void ultra_triger(void) 
{
    if (!sensor_working) 
    {
        TRIGER_PORT |= (1 << TRIGER);
        _delay_us(15);
        TRIGER_PORT &= ~(1 << TRIGER);
        sensor_working = 1;
    }
}

ISR(INT1_vect)
{
    if (sensor_working == 1) 
    {
        if (rising_edge == 0)
        {
            TCNT0 = 0x00;
            rising_edge = 1;
            timer_counter = 0;
        } 
        else
        {
            distance = (timer_counter * 256 + TCNT0) / 466;

            LCD_moveCursor(0, 10);
            LCD_intgerToString(distance);
            _delay_ms(40);
            timer_counter = 0;
            rising_edge = 0;
        }
    }
}

ISR(TIMER0_OVF_vect)
{
    timer_counter++;
    if (timer_counter > 730) 
    {
        TCNT0 = 0x00;
        sensor_working = 0;
        rising_edge = 0;
        timer_counter = 0;
    }
}
