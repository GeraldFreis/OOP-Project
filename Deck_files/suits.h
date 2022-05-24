#include <iostream>
#include <ncurses.h>

#ifndef SUITS_H
#define SUITS_H

// class for drawing a suit onto a card
/*
Class has no data members only public
-> All functions take in a WINDOW * as a parameter and draw their respective suit onto this card

    drawclubs {draws a club onto the window}
    drawspades {draws a spade onto the window}
    drawdiamonds {draws a diamond onto the window}
    drawhearts {draws a diamond onto the window}
*/
class Suits {
    public:
        Suits();
        WINDOW *drawclubs(WINDOW * canvas);
        WINDOW *drawspades(WINDOW * canvas);
        WINDOW *drawdiamonds(WINDOW * canvas);
        WINDOW *drawhearts(WINDOW * canvas);
};

#endif 