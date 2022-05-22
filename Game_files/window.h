#include <iostream>
#include <ncurses.h>
#ifndef WINDOW_H
#define WINDOW_H
using std::string;

/*
Window
    attrs:
        colours:
            colour_grey
            
    methods:
        end_win (destroys a window / card)
        create_cards (takes x and y as parameters and creates a card at those points){returns a pointer to a window}
        create_buttons (takes x and y as parameters and creates a button at that point){returns a pointer to a window}
        bet_window() (takes size as parameter and creates the betting window) {returns a pointer to the window}
*/
class Window{
    private:
        int *colour_grey_array; 

    public:
        Window(); // default constructor
        void end_win(WINDOW *usingwin); // closes the window / object in the window
        WINDOW *create_cards(int xpoint, int ypoint, string cardtype); // creates a card in the window at point x and y
        WINDOW *create_cards(int xpoint, int ypoint);
        WINDOW *create_buttons(int xpoint, int ypoint, string buttonname); // creates a button in the window at point x and y
        WINDOW *bet_window(int size);
        WINDOW *winner_window();
        ~Window();
};

#endif