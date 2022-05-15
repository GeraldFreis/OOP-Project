#include <iostream>
#include "Human.h"
#include "card.h"
#include "deck.h"
#include "person.h"

using namespace std;


Human::Human(){
    card_array = new card[5];
    choosen_move = "";
    card_total = 0;
}                       
        
void Human::addCardHuman(card new_card){
    for(int i=0; i<5; i++){
        if((card_array[i].getName()=="")&&(card_array[i].getValue()==0)){
            card_array[i] = new_card;
            break;
        }
    }
}

void Human::printCardHuman(int num){
    cout << card_array[num-1].getName() << " " << card_array[num-1].getValue() << endl;
}

// card Human::hit(card new_card){

// }

int Human::getCountHuman(){
    card_total =0;  
    for(int i=0; i<5; i++){ 
        card_total = card_total + card_array[i].getValue();
    }
    return card_total;
}

void Human::playerMove(){}

string Human::getMoves(){
    return "human lol";
} 




                                    
Human::~Human(){delete[] card_array;}