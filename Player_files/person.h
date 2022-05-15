#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "dealer.h"
#include "human.h"
using namespace std;

class person{
    public:
        Person();
        virtual void Move()=0;
        int getMove();
        int getCount();
        int addCard();
        string lastCard();
        //void hit();

        bool winGame();
        ~Person();


    private:
        card *card array;
        int CardTotal;
};
#endif

