#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
using namespace std;


        // card *array;
        // int length;


deck::deck(){
    length = 52;
    array = new card[52];
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

    for(int j=0; j<4; j++){
        array[j+0] = c1;
        array[j+4] = c2;
        array[j+8] = c3;
        array[j+12] = c4;
        array[j+16] = c5;
        array[j+20] = c6;
        array[j+24] = c7;
        array[j+28] = c8;
        array[j+32] = c9;
        array[j+36] = c10;
        array[j+40] = c11;
        array[j+44] = c12;
        array[j+48] = c13;
    }

}

void deck::addcard(card new_card){
    for(int i=0; i<length; i++){
        if((array[i].getName()=="")&&(array[i].getValue()==0)){
            array[i] = new_card;
            break;
        }
    }
}

void deck::printCard(int deck_num){
    cout << array[deck_num-1].getName() << " " << array[deck_num-1].getValue() << endl;
}


deck::~deck(){delete[] array;}

