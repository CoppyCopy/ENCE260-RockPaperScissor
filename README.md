# ENCE260-RockPaperScissor

=============================================================================================================================

How to play the "Rock, Paper, and Scissor" game:

=============================================================================================================================


1. Once you get into the game, you will see the message "ROCK PAPER SCISSOR", the title of its game, then you press a "white" button[1]
   that closest to the Maxtrix LEDs (MAXT. LEDS) to start the game, see figure 1. You will see a letter 'E' on the displays, it is because 
   each player did not choose their symbols yet.


2. For each player, you use the navswitch(NAV) to choose ROCK('R'), PAPER('P'), SCISSOR('S') in the following, figure 1:

    ___________[USB]__
   | UC FUNKIT 4      |   At [1]: A "white" button, the start button.
   |                  |      [2]: A "white" button, the program terminator button.
   |                  |    [NAV]: A Navigator Switch, for controlling NORTH and SOUTH buttons.
   |               [2]|    [USB]: An USB port, the port to connect between your FunKit and computer.
   |                  |
   |    ______        |
   |   |      |       |
   |   | MAXT.|   ___ |
   |[1]| LED  |  |NAV||
   |   |______|  |___||
   |__________________| 
    Figure 1: FunKit

    NORTH button: Push this button to changes your current symbol forwards, e.g. 'R'>'P'>'S'>'R'>'P'>'S'>... and so on.
    SOUTH button: Push this button to changes your current symbol backwards, e.g. 'R'>'S'>'P'>'R'>'S'>'P'>... and so on.


3. Once you get your symbol, then you push the "center" button on navswitch[NAV] to confirm. Make sure you put 2 FunKits' IR transmitter/receiver near each other or else it would not 
   transmitting/receiving properly and also try to avoid from exposes to any lights. E.g. Light bulbs. The most efficient way is to play with lights around you.


4. You will see "\" on the screen, that is indicating that one of the players has yet to confirm their symbol. If both players are confirmed their symbols, then the message 
   "VICTORY", "DEFEATED", or "TIED" appears on their screens, it depends on the following conditions:
    
   Game conditions:
     - If the Player one has a ROCK('R') on their screen and the Player two's screen has a PAPER('P'), then it is a "VICTORY" for Player one and it is a "DEFEATED" for Player two. 
     - If the Player one has a PAPER('P') on their screen and the Player two's screen has a SCISSOR('S'), then it is a "VICTORY" for Player one and it is a "DEFEATED" for Player two. 
     - If the Player one has a SCISSOR('S') on their screen and the Player two's screen has a ROCK('R'), then it is a "VICTORY" for Player one and it is a "DEFEATED" for Player two. 
     - If the Player one has a ROCK('R') on their screen as well as on the Player two's screen, then it is a "TIED" for both of them. Also the same as PAPER('P') and SCISSOR('S').

5. You can be able to reset the game after both players received their determination message ("VICTORY", "DEFEATED", "TIED"). You are unable to reset the game while it is not at 
   the determination part. Except, if you pressed a "white" button [2], it will shutdown your FunKit.

=============================================================================================================================


                                                                                     Made by Suwijuk Nawaphanarat and Wei
                                                                                              Date: 19/10/2018

               Disclaimer: There is some part that we take it from the "premade" codings in "ence260-ucfk4" resources and used for our project and we do acknowledged that it is not our codes. 
                                                                                    *Therefore, it is all credits to its owner.*


=============================================================================================================================
