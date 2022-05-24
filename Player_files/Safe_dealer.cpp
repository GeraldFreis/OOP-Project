#include "Safe_dealer.h"

Safe_dealer::Safe_dealer(){
    card_total = 0;;
    card_array = new card[5];
    last_move = "";
}
// calculates the safe dealer's move
void Safe_dealer::Move(){
    
    if(this->Person::card_total > 14) {
        this->Person::last_move = "stand";
    }

    else {
        this->Person::last_move = "hit";
    }
}

Safe_dealer::~Safe_dealer(){
    delete [] card_array;
}