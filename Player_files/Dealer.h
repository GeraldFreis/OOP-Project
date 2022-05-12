#ifndef DEALER_H
#define DEALER_H
#include <iostream>
using std::cout; using std::string; using std::cin;
#include "Person.h"
#include "card.h"



class Dealer: public Person {
    private:
        int card_total;
        card *card_array;
        string choosen_move;
        

    public:
        Dealer();                       
        
        void dealerMove();

        string getMoves();    

        void hit();
    
        int getCount();
                                          
        ~Dealer();
};

#endif