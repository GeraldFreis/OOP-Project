#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "serializable.h"
using std::cout; using std::string;

#ifndef WALLET_H
#define WALLET_H

/*
Wallet class:
    attrs:
        int currentbalance
        int *previousamounts
        string filename
        int number_of_entries;
    
    methods:
        int getbalance()
        void printbalance()
        void retreivebalance()
        int *getpreviousbalances()
        void printpreviousbalances()
        void setbalance(int updated_balance)
*/
class Wallet: public Serializable{
    private:
        int currentbalance;
        int *previousbalances;
        string filename; // file from which the balances are read and updated to
        int number_of_entries;
    
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
        void read();
        void write();

        // destructor
        ~Wallet();
};

#endif
