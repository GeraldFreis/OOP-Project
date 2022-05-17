#include "Risky_dealer.h"


void Risky_dealer::Move(){
    if(card_total == 21) {
        last_move = "stand";
    }
    else {
        last_move = "hit";
    }
}
