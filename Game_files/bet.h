#include <iostream>
#include <ncurses.h>
#include <form.h>
#include "window.h"
using std::string;

#ifndef BET_H
#define BET_H

/*
    Class Bet (creates a prompt to ask the user for the bet amount prior to starting the game)
        attrs:
            raw_bet_amount (holds the user_entered bet amount which is a string)
            bet_amount (holds the converted bet amount that the user enters (string -> int explicit conversion))
            balance (holds the user's balance)

            betamount_field (array of fields to enter the bet amount: required by the form.h library)

            Window_creation (object of Window class which has the methods to create the window)
            betting_window (WINDOW object of ncurses which is the window to ask for the bet amount)
        
        methods:
            private:
                bet_interface() // creates the window to interface w the user for the bet amount
                isvalid_bet_amount // checks if the user_entered bet amount is a number and if so concatenates to
                    // the raw_bet_amount data member
            
            public:
                Bet(int _balance);
                void set_bet_amount(); // uses bet_interface to create a window that asks the user to enter the bet amount
                int get_bet_amount(); // converts the raw_bet_amount to a string
                int get_balance(); // returns the balance
*/
class Bet {
    private:
        string raw_bet_amount; // string to hold the raw bet amount entered in the field
        // string copy;
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
        Bet(int _balance);
        void set_bet_amount(); // uses bet_interface to create a window that asks the user to enter the bet amount
        int get_bet_amount(); // converts the raw_bet_amount to a string
        int get_balance(); // returns the balance
};

#endif