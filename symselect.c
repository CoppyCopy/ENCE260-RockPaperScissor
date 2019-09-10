/*
 * File: symselect.c
 * Date: 19/10/2018
 * Description: Let each player to select their symbol
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"
#include "symselect.h"
#include "symbols.h"

/* Displays a symbol on the screen */
void symbol_screen(symbol a_symbol)
{
    char symbol[2];
    symbol[0] = a_symbol;
    symbol[1] = '\0';              /* Prevent from unuse of char */
    tinygl_text(symbol);
}

/* The current symbol will be changes whenever NORTH or SOUTH is pressed */
symbol symbol_selection(symbol current_symbol)
{
    /* This is triggered when NORTH is pressed ROCK > PAPER > SCISSOR*/
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        if (current_symbol == ROCK) {
            current_symbol = PAPER;
        }
        else if (current_symbol == PAPER) {
            current_symbol = SCISSOR;
        }
        else {
            current_symbol = ROCK;
        }
    }

    /* This is triggered when SOUTH is pressed ROCK < PAPER < SCISSOR*/
    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        if (current_symbol == ROCK) {
            current_symbol = SCISSOR;
        }
        else if (current_symbol == PAPER) {
            current_symbol = ROCK;
        }
        else {
            current_symbol = PAPER;
        }
    }

    return current_symbol;
}
