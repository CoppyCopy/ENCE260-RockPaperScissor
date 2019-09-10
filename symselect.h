/*
 * File: symselect.h
 * Date: 19/10/2018
 * Description: Let the player to choose their symbols
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#ifndef SYMSELECT_H
#define SYMSELECT_H

#include "symbols.h"

/* Retrieve The current symbol and it will be changes whenever NORTH or SOUTH is pressed */
symbol symbol_selection(symbol current_symbol);

/* Displays the symbol */
void symbol_screen(symbol a_symbol);

#endif // SYMSELECT.H
