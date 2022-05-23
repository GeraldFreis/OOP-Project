#include <iostream>
#include <ncurses.h>
#include "../blackjack.h"
#define KEY_ESC 27

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

/*
Class to handle extraneous game class methods
    attrs:
        balance
        draw
        stage

    methods:
        bool initial_user_input(); {gets the users pregame input}
        void setbalance(int _balance); {sets the balance of this class}
        void calcbalance(int bet_amount, Blackjack *blackjack); {calculates the users balance based on their win or loss}
        int getbalance(); {returns the balance of the user}
        bool isdraw(); {returns if the game was a draw}
        int getstage(); {gets the current stage the game is in}
*/
class Game_manager {
    private:
        int balance;
        bool draw;
        int stage;
        bool test;

        WINDOW *dealer_card_1; // dealer card 1 
        WINDOW *dealer_card_2;  // dealer card 2
        WINDOW *dealer_card_3; // dealer card 3
        WINDOW *dealer_card_4; // dealer card 4
        WINDOW *dealer_card_5;

        // player cards
        WINDOW *player_card_1; // player card 1
        WINDOW *player_card_2; // player card 4
        WINDOW *player_card_3; // player card 3
        WINDOW *player_card_4; // player card 4;
        WINDOW *player_card_5;


    public:
        Game_manager(int _balance);
        Game_manager();

        bool initial_user_input();
        void setbalance(int _balance);
        void calcbalance(int bet_amount, Blackjack *blackjack);
        int getbalance();
        bool isdraw();
        int getstage();
        bool gettest();

        void endgame_interface(Game_manager *manager, Blackjack *blackjack, std::vector<WINDOW *> screen_objs);

};

#endif