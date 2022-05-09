#include <iostream>
#include <ncurses.h>
#ifndef WINDOW_H
#define WINDOW_H

class Window{
    public:
        void end_win(WINDOW *usingwin);
        WINDOW *create_cards(int xpoint, int ypoint);
        
};

#endif