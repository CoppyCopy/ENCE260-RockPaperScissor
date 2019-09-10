/*
 * File: determination.h
 * Date: 19/10/2018
 * Description: Determines the player whether they WIN, LOSE or TIE the game.
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#ifndef DETERMINATION_H
#define DETERMINATION_H

#include "symbols.h"

/* The types of result of the game */
typedef enum {
    VICTORY,
    DEFEATED,
    TIED,
    UNDECIDED
} determine;

determine determination(symbol first_symbol, symbol second_symbol);

#endif // DETERMINATION.H
