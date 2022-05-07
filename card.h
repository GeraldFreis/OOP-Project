#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class card{
    private:
        string name;
        int value;

    public:
        card();

        card(string n_name, int n_value);

        string getName();

        int getValue();

        ~card();

};
#endif