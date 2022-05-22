#include "Dealer.h"

Dealer::Dealer(){                       
    card_array = new card[5];
    card_total = 0;
    string last_move;
}

void Dealer::addCardDealer(card new_card){
    for(int i=0; i<5; i++){
        if((card_array[i].getName()=="")&&(card_array[i].getValue()==0)){
            card_array[i] = new_card;
            break;
        }
    }
}

void Dealer::Move(){
    if(card_total > 15) {
        last_move = "stand";
    }
    else {
        last_move = "hit";
    }
}

void Dealer::printCardDealer(int num){
    cout << card_array[num-1].getName() << " " << card_array[num-1].getValue() << std::endl;
}

Dealer::~Dealer(){delete [] card_array;}