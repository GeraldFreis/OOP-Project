#include <iostream>
#include "Dealer.h"
using namespace std;
#ifndef RISKY_DEALER_H
#define RISKY_DEALER_H

class Risky_dealer: public Dealer {
    private:
        int card_total;
        card *card_array;
        string last_move;
        
    public:
        Risky_dealer();

        void Move();

        ~Risky_dealer();
};

#endif