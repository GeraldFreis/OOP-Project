#include "person.h" // include person header file

Person::Person(){ // intialize values for the constructor function
    card_array = new card[10]; // 10 cards since it has enough for 5 for the player and 5 for the dealer. more than this are not needed
    card_total = 0; // no cards have been drawn so total is 0
    lastcard = "";
    last_move = "";
    number_of_cards = 0;
}

string Person::getMove(){ // function to return the last move
    return this->last_move;
}

void Person::setMove(string move) {
    this->last_move = move; // setting the last move to be the move that has just taken place
}

string Person::lastCard(){ // function that retrieves the last card delt
    return lastcard;
}

int Person::getCount(){ // returns the card total
    return this->card_total;
}

card *Person::getCards(){ 
    return card_array; // returns an array of the cards 
}

void Person::setCount() {
    this->card_total = 0;  // intializing the total as 0
    for(int i=0; i<5; i++){  
        this->card_total = this->card_total + this->card_array[i].getValue(); // updating the card total to each value that is added
    }
}

void Person::addCard(card new_card) {
    for(int i=0; i<5; i++){
        if((this->card_array[i].getName()=="")&&(this->card_array[i].getValue()==0)){
            this->card_array[i] = new_card;
            break;
        }
    }
    this->number_of_cards += 1; // increasing the count of the number of cards
}

bool Person::winGame() { // function to check if the game has been won or lost
    if(this->card_total > 21) { 
        return true; // if the total of the cards is over 21 then it is a loss, hence the false
    }
    return false; // anything under the number will be in play, hence true
}

Person::~Person(){
    delete [] card_array; // freeing the memory
}