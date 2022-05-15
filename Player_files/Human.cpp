#include <iostream>
#include <string>
#include "Human.h"
#include "card.h"
#include "deck.h"
#include "person.h"
using namespace std;


Human::Human(){
    card_array = new card[5];
    //choosen_move = "";
    card_total = 0;
    number_of_cards = 0;
}                       
        
void Human::addCardHuman(card new_card){
    for(int i=0; i<5; i++){
        if((card_array[i].getName()=="")&&(card_array[i].getValue()==0)){
            card_array[i] = new_card;
            break;
        }
    }
    number_of_cards += 1;
}


void Human::printCardHuman(int num){
    cout << card_array[num-1].getName() << " " << card_array[num-1].getValue() << endl;
}

int Human::getCountHuman(){
    card_total =0;  
    for(int i=0; i<5; i++){ 
        card_total = card_total + card_array[i].getValue();
    }
    return card_total;
}

card Human::getLastCard() {
    return card_array[number_of_cards];
}
// card Human::hit(card new_card){
// }

//void Human::playerMove(){}

// string Human::getMoves(){
//     return "human lol";
// } 
          
card *Human::getCards() {
    return card_array;
}

Human::~Human(){delete[] card_array;}