#include "Safe_dealer.h"

Safe_dealer::Safe_dealer(){
    card_total = 0;;
    card_array = new card[5];
    last_move = "";
}



void Safe_dealer::Move(){
    
    if(card_total > 14) {
        last_move = "stand";
        // cout << last_move;
    }

    else {
        last_move = "hit";
        //  cout << last_move;
    }
}


Safe_dealer::~Safe_dealer(){
    delete [] card_array;
}
