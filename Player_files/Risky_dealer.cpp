#include "Risky_dealer.h"

Risky_dealer::Risky_dealer(){
    card_total = 0;
    card_array = new card[5];
    last_move = "";
}

void Risky_dealer::Move(){
    if(this->card_total == 21) {
        this->Person::last_move = "stand";
    }
    else {
        this->Person::last_move = "hit";
    }
}


Risky_dealer::~Risky_dealer(){
    delete [] card_array;
}