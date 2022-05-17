#include <iostream>
#include <string>
#include "card.h"
using std::cout; using std::string;

// default constructor
card::card(){ 
    name ="";
    value = 0;
}

// parameterized constructor
card::card(string n_name, int n_value){
    name = n_name;
    value = n_value;
}

// newName takes a string for params and makes that the name of the card
void card::newName(string new_name){
    name = new_name;
}

 // newValue takes an int for params and makes that the value of the card       
void card::newValue(int new_value){
    value = new_value;
}

// returning the name of the card
string card::getName(){return name;}
        
// returning the value of the card
int card::getValue(){return value;}

card::~card(){return;}
