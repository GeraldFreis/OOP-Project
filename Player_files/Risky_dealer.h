#include <iostream>
#include "Dealer.h"
using namespace std;
#ifndef RISKY_DEALER_H
#define RISKY_DEALER_H

class Risky_dealer: public Dealer {
    private:
        
    public:
        Risky_dealer();

        void Move();

        ~Risky_dealer();
};

#endif