#include "window.h"

Window::Window(){
    colour_grey_array = new int[3];
    colour_grey_array[0] = 128;
    colour_grey_array[1] = 128;
    colour_grey_array[2] = 128;
}

void Window::end_win(WINDOW *usingwin){ // closing the window
    wborder(usingwin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(usingwin);
    werase(usingwin);
};

WINDOW *Window::create_cards(int xpoint, int ypoint){ // creating the cards
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);

    wrefresh(card);
    return card;
};

WINDOW *Window::create_buttons(int xpoint, int ypoint){
    WINDOW *button; // initialising the buttons

    // initialising the colour of the border
    // start_color();
    // init_color(COLOR_BLACK, colour_grey_array[0], colour_grey_array[1], colour_grey_array[2]);
    // init_pair(1,COLOR_BLACK, COLOR_BLACK);
    // attron(COLOR_PAIR(1)); // turning the colour on

    // this button
    button = newwin(3,20, ypoint, xpoint);
    box(button, 0, 0);

    // attroff(COLOR_PAIR(1)); // turning the colour off
    
    wrefresh(button);
    return button;
};


// window that prompts the user to enter a bet amount, and lets them enter the bet amount
WINDOW *Window::bet_window(int size){ 
    WINDOW *betting_window;

    betting_window = newwin(200,200,0,0);
    wrefresh(betting_window);

    return betting_window;
};

Window::~Window(){
    delete colour_grey_array;
}