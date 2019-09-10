/*
 * File: gameinit.h
 * Date: 19/10/2018
 * Description: This is where a module initialises the other modules
 * Author: Suwijuk Nawaphanarat & Weizhe Qiu
 */

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "../fonts/font5x7_1.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "button.h"
#include <string.h>

#define LOOP_RATE 500

#define MESSAGE_RATE 15 /* Text scroll speed */

#ifndef GAMEINIT_H
#define GAMEINIT_H

player player_init(player current_player)
{

    /* This is triggered when NORTH is pressed */
    if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
        if (current_player == PLAYER1) {
            current_player = PLAYER2;
        } else {
            current_player = PLAYER1;
        }
    }

    /* This is triggered when SOUTH is pressed */
    if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
        if (current_player == PLAYER1) {
            current_player = PLAYER2;
        } else {
            current_player = PLAYER1;
        }
    }

    return current_player;

}

void game_init(void)
{

    /* Initialise the modules */
    system_init();
    tinygl_init(LOOP_RATE);
    tinygl_font_set(&font5x7_1);
    tinygl_text_speed_set(MESSAGE_RATE);
    tinygl_text_mode_set(TINYGL_TEXT_MODE_SCROLL);
    navswitch_init();
    button_init ();
    ir_uart_init();
    pacer_init(LOOP_RATE);

    tinygl_text("ROCK PAPER SCISSOR ReadMe Please");

}

#endif // GAMEINIT.H
