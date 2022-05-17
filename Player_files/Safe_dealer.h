#include <iostream>
#include "Dealer.h"
using namespace std;
#ifndef SAFE_DEALER_H
#define SAFE_DEALER_H

class Safe_dealer: public Dealer {
    private:
        int card_total;
        card *card_array;
        string last_move;
    public:
        Safe_dealer();

        void Move();

        ~Safe_dealer();
};

#endif