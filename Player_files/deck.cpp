#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "card.h"
#include "deck.h"
using std::cout; using std::string; using std::endl;


deck::deck(){
    length = 312;
    array = new card[312];
    drawn_cards = new int[312];
    
}

void deck::fillDeck(){
    card c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13;
    c1 = card("Ace",11);
    c2 = card("Two",2);
    c3 = card("Three",3);
    c4 = card("Four",4);
    c5 = card("Five",5);
    c6 = card("Six",6);
    c7 = card("Seven",7);
    c8 = card("Eight",8);
    c9 = card("Nine",9);
    c10 = card("Ten",10);
    c11 = card("Jack",10);
    c12 = card("Queen",10);
    c13 = card("King",10);

    for(int j=0; j<24; j++){
        array[j+0] = c1;
        array[j+24] = c2;
        array[j+48] = c3;
        array[j+72] = c4;
        array[j+96] = c5;
        array[j+120] = c6;
        array[j+144] = c7;
        array[j+168] = c8;
        array[j+192] = c9;
        array[j+216] = c10;
        array[j+240] = c11;
        array[j+264] = c12;
        array[j+288] = c13;
    }

}

void deck::addCard(card new_card){
    for(int i=0; i<length; i++){
        if((array[i].getName()=="")&&(array[i].getValue()==0)){
            array[i] = new_card;
            break;
        }
    }
}

void deck::removeCard(int num){
    array[num].newName("");
    array[num].newValue(0);
}

void deck::removeLastCard(){
    int card_val;
    int i=0;
    card_val = drawn_cards[0];
    while(card_val!=0 && i<312){
        card_val = drawn_cards[i];
        i++;
    }
    card_val = drawn_cards[i-1];

    for(int j=0; j<312; j++){
        if(array[j].getValue() == card_val){
            array[j].newName("");
            array[j].newValue(0);
            break;
        }
    }

    // array[num].newName("");
    // array[num].newValue(0);
}

//This was used to check that the array initialised full of zeros 
void deck::printInt(){  
    for(int i=0; i<312; i++){
        cout << drawn_cards[i];
    }

}   




card deck::drawCard(){
    //srand ( time(NULL) );         need to fix this so it doesnt always use the same seed of rand numbers 
    int draw =0;
    draw = rand()%312;
    while(array[draw].getName()=="" && array[draw].getValue()==0){
        draw = rand()%312;
    }

    int i=0;
    int a=0;
    while(i<312 && a!=0){
        a = drawn_cards[i];
        i++;
    }
    drawn_cards[i-1]= array[draw].getValue();

    //cout << draw << endl;
    return array[draw];
}


void deck::printCard(int deck_num){
    cout << array[deck_num-1].getName() << " " << array[deck_num-1].getValue() << endl;
}


deck::~deck(){delete [] array; delete [] drawn_cards;}

