#include <iostream>
#include <string>
#include "card.h"
using std::cout; using std::string;


card::card(){
    name ="";
    value = 0;
}

card::card(string n_name, int n_value){
    name = n_name;
    value = n_value;
}

// reassigning the name of the card
void card::newName(string new_name){
    name = new_name;
}

// assigning a new value to the card
void card::newValue(int new_value){
    value = new_value;
}

//getting the name of the card
string card::getName(){return name;}

// getting the value of the card
int card::getValue(){return value;}

card::~card(){return;}
