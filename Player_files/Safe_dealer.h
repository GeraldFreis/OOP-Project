#include <iostream>
#include "Dealer.h"
using namespace std;
#ifndef SAFE_DEALER_H
#define SAFE_DEALER_H

/*
class Safe_dealer inherits public methods from Dealer which inherits public methods from Person
    has attrs:
        card_total (int) {relates to the sum of the values of the cards in hand}
        card_array (card*) {an array of card objects that the Dealer has been given}
        last_move (string) {a string "hit" or "stand" of the dealer's last move}
    
    has methods:
        Move() {move calculates what move the dealer is going to make}
            --> as it is Safe dealer if the card_total is less than 14 they are going to hit
*/
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