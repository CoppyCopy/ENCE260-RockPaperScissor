/*
 * File: determination.c
 * Date: 19/10/2018
 * Description: Determines whether the player WIN, LOSE or TIE the game
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#include "determination.h"
#include "symbols.h"

#include "pacer.h"
#include "tinygl.h"

/* This condition is determining who will win in "Rock, Paper, and Scissor" game by return VICTORY, DEFEATED, or TIED */
determine determination(symbol first_symbol, symbol second_symbol)
{
    if ((first_symbol == ROCK && second_symbol == PAPER) || (first_symbol == PAPER && second_symbol == SCISSOR) || (first_symbol == SCISSOR && second_symbol == ROCK)) {
        return DEFEATED;
    } else if ((first_symbol == ROCK && second_symbol == SCISSOR) || (first_symbol == PAPER && second_symbol == ROCK) || (first_symbol == SCISSOR && second_symbol == PAPER)) {
        return VICTORY;
    } else {
        return TIED;
    }
}
