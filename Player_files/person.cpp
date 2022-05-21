#include "person.h" // include person header file

Person::Person(){ // intialize values for the constructor function
    card_array = new card[10]; // 10 cards since it has enough for 5 for the player and 5 for the dealer. more than this are not needed
    card_total = 0; // no cards have been drawn so total is 0
    lastcard = "";
    last_move = "";
    number_of_cards = 0;
}

string Person::getMove(){ // function to return the last move
    return last_move;
}

void Person::setMove(string move) {
    last_move = move; // setting the last move to be the move that has just taken place
}

string Person::lastCard(){ // function that retrieves the last card delt
    return lastcard;
}

int Person::getCount(){ // returns the card total
    return card_total;
}

card *Person::getCards(){ 
    return card_array; // returns an array of the cards 
}

void Person::setCount() {
    card_total = 0;  // intializing the total as 0
    for(int i=0; i<5; i++){  
        card_total = card_total + card_array[i].getValue(); // updating the card total to each value that is added
    }
}

void Person::addCard(card new_card) {
    for(int i=0; i<5; i++){
        if((card_array[i].getName()=="")&&(card_array[i].getValue()==0)){
            card_array[i] = new_card;
            break;
        }
    }
    number_of_cards += 1; // increasing the count of the number of cards
}

bool Person::under22() { // function to check if the game has been won or lost
    if(card_total > 21) { 
        return false; // if the total of the cards is over 21 then it is a loss, hence the false
    }
    return true; // anything under the number will be in play, hence true
}

Person::~Person(){
    delete [] card_array; // freeing the memory
}