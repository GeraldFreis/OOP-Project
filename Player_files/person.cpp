#include "person.h"

using namespace std;

    
Person::Person(){
    card_array = new card[10];
    card_total = 0;
    last_card = "";
    last_move = "";
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
    return this->card_total;
}

void Person::setCount() {
    this->card_total = 0;  
    for(int i=0; i<5; i++){ 
        this->card_total = this->card_total + this->card_array[i].getValue();
    }
}

//void person::hit(){
    // what will happen when someone hits?
    //
//}


bool Person::winGame(){
    if (this->card_total > 21){
        return true;
    }
    else {
        return false;
    }
}

Person::~Person(){
    delete [] card_array;
}