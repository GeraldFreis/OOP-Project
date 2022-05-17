#include "Dealer.h"

Dealer::Dealer(){   // dealer constructor class which sets the card total to zero                    
    card_array = new card[5]; // sets 5 spots for cards for the dealer
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
    if(card_total >= 17) { // if the dealers cards are at 17 or greater than they would stand
        last_move = "stand";
    }
    else {
        last_move = "hit"; // if they are less than 17, they woudld hit
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

// string Dealer::getMoves(){                              
//     return "lol";
// }

// void Dealer::hit(){
// }

Dealer::~Dealer(){delete [] card_array;} // clear contents of dealers cards to be ready for next round