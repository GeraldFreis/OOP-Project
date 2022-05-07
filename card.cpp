#include <iostream>
#include <string>
#include "card.h"
using namespace std;


card::card(){
    name ="";
    value = 0;
}

card::card(string n_name, int n_value){
    name = n_name;
    value = n_value;
}

string card::getName(){return name;}
        
int card::getValue(){return value;}

card::~card(){return;}
