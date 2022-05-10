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

void card::newName(string new_name){
    name = new_name;
}
        
void card::newValue(int new_value){
    value = new_value;
}

string card::getName(){return name;}
        
int card::getValue(){return value;}

card::~card(){return;}
