#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
using std::cout; using std::string; using std::cin;
#include "Person.h"
#include "card.h"



class Human: public Person {
    private:
        int card_total;
        card *card_array;
        string choosen_move;
        

    public:
        Human();                       
        
        void playerMove();

        string getMoves();    

        void hit();
    
        int getCount();
                                          
        ~Human();
};

#endif