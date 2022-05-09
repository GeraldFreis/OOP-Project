#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using std::cout; using std::string;

#ifndef WALLET_H
#define WALLET_H

/*
Wallet class:
    attrs:
        int currentbalance
        int *previousamounts
        string filename
    
    methods:
        int getbalance()
        void printbalance()
        void retreivebalance()
        int *getpreviousbalances()
        void printpreviousbalances()
        void setbalance(int updated_balance)
*/
class Wallet{
    private:
        int currentbalance;
        int *previousbalances;
        string filename; // file from which the balances are read and updated to
    
    public:
        // constructors
        Wallet(); // default constructor
        Wallet(string filename); // parameterized constructor

        // methods
        int getbalance(); // returns the current balance
        void printbalance(); // prints the current balance
        void retreivebalance(); // finds the current balance from a csv file
        int *getpreviousbalances(); // returns a pointer to the previous balances
        void printpreviousbalances(); // prints the previous balances
        void setbalance(int updated_balance); // sets the balance of the object

        // destructor
        ~Wallet();
};

#endif
