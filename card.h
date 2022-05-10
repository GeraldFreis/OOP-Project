#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using std::cout; using std::string;

class card{
    private:
        string name;
        int value;

    public:
        card();

        card(string n_name, int n_value);

        void newName(string new_name);

        void newValue(int new_value);

        string getName();

        int getValue();

        ~card();

};
#endif