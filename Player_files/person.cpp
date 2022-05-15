#include <iostream>
#include <string>
#include <ncurses.h>
#include "person.h"
#include "Dealer.h"
#include "Human.h"
#include "deck.h"
#include "card.h"
using namespace std;


    // card *card array;
    // int CardTotal;
    
person::person(){
    //card = [];
   // CardTotal=0;
}



int person::getMove(){
    // retrieve the move of 
    return 6;
}

int person::getCount(){
    //return CardTotal;
    return 7;

}


void person::hit(){
    // what will happen when someone hits?
    //
}

bool person::winGame(){
    return true;
}

person::~person(){

}