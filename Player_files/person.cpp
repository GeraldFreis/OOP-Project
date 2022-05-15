#include <iostream>
#include <string>
#include "person.h"
using namespace std;


    // card *card array;
    // int CardTotal;
    
person::Person(){
    card = [];
    CardTotal=0;
}

int person::getMove(){
    // retrieve the move of 
}

int person::getCount(){
    return CardTotal;
}

//void person::hit(){
    // what will happen when someone hits?
    //
//}


bool person::winGame(){
    if (cardTotal>21){
        return false;
    else if (cardTotal < 21)
        return true; 
    }
}

person::~Person(){

}