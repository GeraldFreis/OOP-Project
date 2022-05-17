#include "Safe_dealer.h"


void Safe_dealer::Move(){
    if(card_total > 14) {
        last_move = "stand";
    }
    else {
        last_move = "hit";
    }
}