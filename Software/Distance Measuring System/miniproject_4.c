/*
 ============================================================================
 Name        : miniproject_4.c
 Author      : Ibrahim_Diab
 Description : System control fan speed based on the room temperature
 ============================================================================
 */

#include "avr/io.h" /* To use the SREG Register */
#include "util/delay.h"

#include "std_types.h"
#include "common_macros.h"

#include "gpio.h"
#include "lcd.h"
#include "timer.h"
#include "icu.h"
#include "ultrasonic.h"



int main(void) 
{

    Icu_ConfigType Icu_Config = {F_CPU_8,RISING};
    enable_ex_interrupt();
    
    LCD_init();                                     /* Initialize LCD driver */
    ultrasonic_init();                              /* Initialize ultrasonic driver */
    Icu_init(&Icu_Config);                          /* Initialize icu driver */

    /* Display this string "Temp =   C" only once on LCD at the second row*/
    LCD_moveCursor(0,0);
    LCD_displayString("distance =   cm");
    LCD_moveCursor(0,10);
    _delay_ms(40);
    /* Enable interrupts by setting I-bit */
        SREG |= (1 << 7);
    while (1) 
    {
         ultra_triger();
          _delay_ms(15);
    }
}

