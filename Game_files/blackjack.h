#include <iostream>
#include "window.h"
#include "bet.h"
#include <vector>

#ifndef BLACKJACK_H
#define BLACKJACK_H

class Blackjack: public Bet {
    private:
        int balance;
        int bet_amount;
        Window windowtools;
        Bet betting;
        std::vector<WINDOW *> array; 

    public:
        Blackjack();
        Blackjack(int _balance);
        
        std::vector<WINDOW *> game_template();
        std::vector<WINDOW *> start_game(); // returns a pointer to an array of windows
        std::vector<WINDOW *> hit();
        std::vector<WINDOW *> stand();
        int get_bet_amount(); // from Bet
};

#endif