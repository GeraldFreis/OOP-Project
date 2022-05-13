#include <iostream>
#include <ncurses.h>
#include <form.h>
#include "window.h"
using std::string;

#ifndef BET_H
#define BET_H

class Bet {
    private:
        string raw_bet_amount; // string to hold the raw bet amount entered in the field
        int bet_amount;
        int balance;

        FIELD *betamount_field[2]; // initialising the field to hold the bet amount
            // must be a double pointer
        FORM *betting_form; // initialising the form to hold the bet amount
        Window window_creation;
        WINDOW *betting_window;
        string bet_interface(); // creates a window to interface w the user and retrieve the raw bet amount
        bool isvalid_bet_amount(char betting_input);
        
    public:
        Bet();
        Bet(int _balance);
        void set_bet_amount(); // uses bet_interface to create a window that asks the user to enter the bet amount
        int get_bet_amount(); // converts the raw_bet_amount to a string

};

#endif