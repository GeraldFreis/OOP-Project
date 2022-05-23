#include <iostream>
#include <ncurses.h>

#ifndef SUITS_H
#define SUITS_H

class Suits {
    public:
        Suits();
        WINDOW *drawclubs(WINDOW * canvas);
        WINDOW *drawspades(WINDOW * canvas);
        WINDOW *drawdiamonds(WINDOW * canvas);
        WINDOW *drawhearts(WINDOW * canvas);
};

#endif 