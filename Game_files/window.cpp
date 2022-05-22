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
    mvwaddstr(card, 1, 1, "hello");

    wrefresh(card);
    return card;
};

WINDOW *Window::create_cards(int xpoint, int ypoint, string cardname){ // creating the cards
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);
    mvwaddstr(card, 1, 1, cardname.c_str());
    wrefresh(card);
    return card;
};

WINDOW *Window::create_buttons(int xpoint, int ypoint){
    WINDOW *button; // initialising the buttons

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

WINDOW *Window::winner_window(){
    WINDOW *winner_win;

    winner_win = newwin(200, 200, 0, 0);
    // wrefresh(winner_win);

    return winner_win;
}

Window::~Window(){
    delete colour_grey_array;
}