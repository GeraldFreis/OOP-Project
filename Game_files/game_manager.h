#include <iostream>
#include <ncurses.h>
#include "../Player_files/Human.h"
#include "../Player_files/Dealer.h"
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

/*
Class to handle extraneous game class methods
    attrs:
        balance
*/
class Game_manager {
    private:
        int balance;
        bool draw;
    public:
        Game_manager(int _balance);
        Game_manager();
        void setbalance(int _balance);
        void calcbalance(int bet_amount, Human *h, Dealer *D);
        int getbalance();
        bool isdraw();
};

#endif