/*
 * File: pacer.h
 * Date: 19/10/2018
 * Description: A frequency module
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
*/

#include <avr/io.h>
#include "pacer.h"

#define F_CPU 8000000
#define TIMER1_PRESCALE 1024

static uint16_t pacer_period;

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency)
{
    TCNT1 = 0;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    TCCR1C = 0x00;

    pacer_period = (1000 / pacer_frequency);
}


/* Pace a while loop.  */
void pacer_wait (void)
{
    uint16_t ticks = 0;
    ticks = pacer_period * ((F_CPU / TIMER1_PRESCALE) / 1000);

    while (TCNT1 < ticks)
    {
        continue;
    }

    /* reset counter */
    TCNT1 = 0;

}
