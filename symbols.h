/*
 * File: symbols.h
 * Date: 19/10/2018
 * Description: A file contains symbols, such as "Rock", "Paper", and "Scissor"
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#ifndef SYMBOLS_H
#define SYMBOLS_H

typedef enum {
    ROCK      = 'R',
    PAPER     = 'P',
    SCISSOR   = 'S',
    EMPTY     = 'E',
    WAIT      = 'X'
} symbol;

typedef enum {
    PLAYER1   = '1',
    PLAYER2   = '2',
    NAN
} player;

#endif // SYMBOLS_H
