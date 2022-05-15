#include <iostream>
#include <string>
#include <ncurses.h>
#include "person.h"

using namespace std;

    
person::person(){
    card_array = new card[10];
    CardTotal = 0;
}

int person::getMove(){
    return 0;
}

int person::getCount(){
    return CardTotal;
}

//void person::hit(){
    // what will happen when someone hits?
    //
//}


bool person::winGame(){
    if (CardTotal > 21){
        return true;
    }
    else if (CardTotal <= 21){
        return false; 
    }
    else {
        return false;
    }
}

person::~person(){
    delete [] card_array;
}