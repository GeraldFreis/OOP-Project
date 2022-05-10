#include <iostream>

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

/*
Interface class Serializable will have pure virtual read and write methods
These will read and write to the text file users_balances.txt
*/
class Serializable {
    public:
        virtual void read() = 0;
        virtual void write() = 0;
};

#endif