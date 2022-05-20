#include "Dealer.h"

Dealer::Dealer(){                       
    card_array = new card[5];
    card_total = 0;
    last_move = "";
}

void Dealer::addCardDealer(card new_card){
    for(int i=0; i<5; i++){
        if((card_array[i].getName()=="")&&(card_array[i].getValue()==0)){
            card_array[i] = new_card;
            break;
        }
    }
}

void Dealer::printCardDealer(int num){
    cout << card_array[num-1].getName() << " " << card_array[num-1].getValue() << std::endl;
}

// int Dealer::getCountDealer(){
//     card_total =0;  
//     for(int i=0; i<5; i++){ 
//         card_total = card_total + card_array[i].getValue();
//     }
//     return card_total;
// }

// void Dealer::dealerMove(){                                       
// }


// void Dealer::hit(){
// }

Dealer::~Dealer(){delete [] card_array;}