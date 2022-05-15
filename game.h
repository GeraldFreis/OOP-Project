#include <iostream>
#include <ncurses.h>
#include <form.h>
#include <vector>

#include "Game_files/window.h"
#include "Game_files/bet.h"
#include "blackjack.h"
#include "Player_files/Dealer.h"
#include "Player_files/Human.h"

using std::string; using std::cout;

#ifndef GAME_H
#define GAME_H

/*
    class Game:
        attrs: all non public:
            -> balance
            -> betamount
            -> game has begun
            -> hit counter

            cards (1-8) {4 cards for both the user and dealer}

            userwindow (Window object that enables creation of the cards onto the window)

            buttons (hit, stand, double, start) {all created on screen by userwindow object}
*/
class Game: public Blackjack {
    private:
        int balance;
        int bet_amount;
        bool game_has_begun;
        int hit_counter;

        // initialising the cards for the screen
        // dealer cards
        WINDOW *dealer_card_1; // dealer card 1 
        WINDOW *dealer_card_2;  // dealer card 2
        WINDOW *dealer_card_3; // dealer card 3
        WINDOW *dealer_card_4; // dealer card 4

        // player cards
        WINDOW *player_card_1; // player card 1
        WINDOW *player_card_2; // player card 4
        WINDOW *player_card_3; // player card 3
        WINDOW *player_card_4; // player card 4;

        // initialising the window object to create the cards, destroy the cards, and create the buttons
        Window window_tools;

        // initialising the blackjack object to handle the start, hit, stand, double and other functions
        Blackjack blackjack;

        // initialising the buttons for the game options
        WINDOW *hit_button;
        WINDOW *stand_button;
        WINDOW *double_button;
        WINDOW *start_button;
        
        // initialising the betting window:
        WINDOW *betting_window;

        WINDOW *winner;



    public:
        // constructors
        Game();
        Game(int balance);

        // methods
        void mainscreen();

        ~Game();


};
#endif