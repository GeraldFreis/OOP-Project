#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "deck.h"
#include "card.h"
using namespace std;

class Person {
    private:
        card *card_array;
        int card_total;
        string last_card;
        string last_move;
    
    public:
        Person();
        virtual void Move()=0;
        string getMove();
        int getCount();
        int addCard();
        string lastCard();
        void setMove(string move);
        //void hit();

        bool winGame();
        virtual ~Person();
};

#endif