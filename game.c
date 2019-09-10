/*
 * File: game.c
 * Date: 19/10/2018
 * Description: The main module
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#include "symselect.h"
#include "determination.h"
#include "symbols.h"
#include "gameinit.h"

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "button.h"

#define IR_RATE 250
#define LOOP_RATE 500

/* Main game and its logical*/
int main(void)
{
    symbol a_symbol = EMPTY;         /* Used for the received symbol */
    symbol first_symbol = EMPTY;     /* The first player's symbol */
    symbol second_symbol = EMPTY;    /* The second player's symbol */

    char status = 0;               /* Initialise the game status */
    char symbol_sent = 0;          /* Initialise sent symbol */
    char symbol_received = 1;      /* Initialise received symbol*/
    char player_ready = 1;         /* Initialise player status */
    char result = 0;               /* Initialise result status */

    uint8_t ir_ticks = 0;          /* Initialise IR tick */

    game_init();

    /* Main game loop */
    while (1)
    {
        pacer_wait();
        navswitch_update();
        button_update();
        tinygl_update();

        /* A button to start the game */
        if (button_push_event_p (BUTTON1) && !status) {
            player_ready = 0;
            status = 1;
        }

        /* When the Player one is not ready */
        if (!player_ready) {
            first_symbol = symbol_selection(first_symbol);
            symbol_screen(first_symbol);
            /* Push a button to confirm their symbol */
            if (navswitch_push_event_p (NAVSWITCH_PUSH)) {
                if (first_symbol == EMPTY) {
                    first_symbol = ROCK;
                    player_ready = 0;
                } else {
                    tinygl_clear();
                    player_ready = 1;
                    symbol_received = 0;
                    symbol_sent = 1;
                }
            }
        } else {
             /* Awaits for the Player two to confirm their symbol */
            ir_ticks++;
            if (ir_ticks >= (LOOP_RATE / IR_RATE)) {
                if (ir_uart_read_ready_p ()) {
                    a_symbol = ir_uart_getc();
                    ir_uart_putc(first_symbol);
                    if ((a_symbol == ROCK || a_symbol == PAPER
                        || a_symbol == SCISSOR)) {
                        second_symbol = a_symbol;
                        symbol_received = 1;
                    }
                }
            }
        }

        /* Displays "\" while awaits for the Player two */
        if (!symbol_received) {
            symbol_screen(WAIT);
        }

        /* Determine the Player "VICTORY", "DEFEATED", or "TIED" */
        if (symbol_sent && symbol_received) {
            if (determination(first_symbol, second_symbol) == VICTORY) {
                /* Check if the result is not yet determined, then displays "VICTORY" */
                if (!result) {
                    tinygl_clear();
                    tinygl_text("VICTORY!");
                    result = 1;
                }
            } else if (determination(first_symbol, second_symbol) == DEFEATED) {
                /* Check if the result is not yet determined, then displays "DEFEATED" */
                if (!result) {
                    tinygl_clear();
                    tinygl_text("DEFEATED!");
                    result = 1;
                }
            } else{
                /* Check if the result is not yet determined, then displays "TIED" */
                if (!result) {
                    tinygl_clear();
                    tinygl_text("TIED!");
                    result = 1;
                }
            }

            /* Reset the game by press a button */
            if (result) {
                if (button_push_event_p (BUTTON1)) {
                    player_ready = 1;
                    first_symbol = EMPTY;
                    a_symbol = EMPTY;
                    symbol_sent = 0;
                    second_symbol = EMPTY;
                    symbol_received = 1;
                    status = 0;
                    result = 0;
                    ir_ticks = 0;
                    tinygl_clear();
                    game_init();
                }
            }
        }
    }

    return 0;
}
