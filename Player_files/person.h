#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Dealer.h"
#include "Human.h"
#include "deck.h"
#include "card.h"
using namespace std;

class person {
    private:
        card *card_array;
        int CardTotal;
    
    public:
        person();
        virtual void Move()=0;
        int getMove();
        int getCount();
        int addCard();
        string lastCard();
        //void hit();

        bool winGame();
        ~person();


};
#endif