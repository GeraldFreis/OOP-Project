#include "person.h"

Person::Person(){
    card_array = new card[10];
    card_total = 0;
    last_card = "";
    last_move = "";
    number_of_cards = 0;
}

string Person::getMove(){
    return last_move;
}

void Person::setMove(string move) {
    last_move = move;
}

string Person::lastCard(){
    return last_card;
}

int Person::getCount(){
    return card_total;
}

card *Person::getCards(){
    return card_array;
}

void Person::setCount() {
    card_total = 0;  
    for(int i=0; i<5; i++){ 
        card_total = card_total + card_array[i].getValue();
    }
}

void Person::addCard(card new_card) {
    for(int i=0; i<5; i++){
        if((card_array[i].getName()=="")&&(card_array[i].getValue()==0)){
            card_array[i] = new_card;
            break;
        }
    }
    number_of_cards += 1;
}

Person::~Person(){
    delete [] card_array;
}