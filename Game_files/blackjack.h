#include <iostream>
#include "window.h"
#include "bet.h"
#include <vector>

#ifndef BLACKJACK_H
#define BLACKJACK_H

/*
    Blackjack class:
        attrs:
            private:
                balance (int of the balance that the user has initialised)
                bet_amount (int of the bet amount, initially zero, that the user sets when they start game);
                windowtools (Window from window.h, allows the production of the required cards)
                betting (Bet from bet.h, allows the game to request the bet amount and ensure that it is less than the balance)
                array (vector <WINDOW *>, ncurses type that enables the returning and storage of the buttons and cards for the screen)
        
        methods:
            public:
                std::vector<WINDOW *> game_template(); // returns the template of the cards in the window
                std::vector<WINDOW *> start_game(); // returns a an array of WINDOW types, which are composed of cards and buttons
                std::vector<WINDOW *> hit(); // returns the user's cards and the dealers cards if they hit
                std::vector<WINDOW *> stand(); // returns the dealers cards if they hit

                int get_bet_amount(); // from Bet
*/
class Blackjack {
    private:
        int balance;
        int bet_amount;
        Window windowtools;
        Bet *betting;
        std::vector<WINDOW *> array; 

    public:
        Blackjack();
        Blackjack(int _balance);
        
        std::vector<WINDOW *> game_template();
        std::vector<WINDOW *> start_game(); // returns a pointer to an array of windows
        std::vector<WINDOW *> hit(int hit_number);
        std::vector<WINDOW *> stand();

        int get_bet_amount(); // from Bet
        ~Blackjack();
};

#endif