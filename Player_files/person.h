#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Dealer.h"
#include "Human.h"
using namespace std;

class person{
    public:
        person();

        
        virtual void Move()=0;
        int getMove();
        int getCount();
        void hit();

        bool winGame();
        ~person();


    private:
        // card *card array;
        // int CardTotal;
};
#endif

