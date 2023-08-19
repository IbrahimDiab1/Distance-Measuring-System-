 /**************************************************************
 *  Source File: EF_PWM.c
 **************************************************************/
 
#include "timer.h"


/*********************************************************************
* Function    : timer0_init(void);
*
* DESCRIPTION : Initializes Timer0 with 1024 prescaler.
*
* PARAMETERS  : Nothing.
*
* Return Value: Nothing.
***********************************************************************/
void timer0_init(void)
{
    TCCR0 = DISABLE_MODULE_VALUE;   /* Disable Timer 0 */
    TCCR0 = (PRESCLR1_VALUE);       /* Setting prescaler */
    TCNT0 = ZER0_INITIALIZER;       /* Initializing the timer with zero */
    TIMSK |=(1<<TOIE0);             /* Timer overflow interrupt enable*/

    return;
}
