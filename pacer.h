/*
 * File: pacer.h
 * Date: 19/10/2018
 * Description: A frequency module
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
*/

#ifndef PACER_H
#define PACER_H

#include "system.h"

/* Initialise the pacer module.  */
void pacer_init (uint16_t pacer_frequency);


/* Pace a while loop.  */
void pacer_wait (void);

#endif //PACER_H
