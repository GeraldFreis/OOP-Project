#include "window.h"
#include <random>

// default constructor
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

// creating a card on the screen
WINDOW *Window::create_cards(int xpoint, int ypoint){ // creating the cards
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);
    mvwaddstr(card, 1, 1, " ");

    wrefresh(card);
    return card;
};

// creating a cards on the screen if given a card name
WINDOW *Window::create_cards(int xpoint, int ypoint, string cardname){ // creating the cards
    WINDOW *card; // initialising the cards

    // this card
    card = newwin(16,24, xpoint,ypoint);
    box(card, 0, 0);
    mvwaddstr(card, 4, 10, cardname.c_str()); // adding the cardname to the card

    // choosing a random suit for the card
    int randomint = 0 + (rand() % 4);
    Suits suits;
    if(randomint == 0){
        card = suits.drawclubs(card);
    }
    else if(randomint == 1){
        card = suits.drawspades(card);
    }
    else if(randomint == 2){
        card = suits.drawhearts(card);
    }
    else {
        card = suits.drawdiamonds(card);
    }

    wrefresh(card);
    return card;
};

// creating the buttons on the screen
WINDOW *Window::create_buttons(int xpoint, int ypoint, string buttonname){
    WINDOW *button; // initialising the buttons

    // this button
    button = newwin(3,20, ypoint, xpoint);
    box(button, 0, 0);

    if(buttonname != "Exit (ESC)" && buttonname != "Stand (3)"){
        mvwaddstr(button, 1, 7, buttonname.c_str()); // adding the buttonname to the button
    }
    else if(buttonname == "Exit (ESC)"){
        mvwaddstr(button, 1, 5, buttonname.c_str());
    }
    else {
        mvwaddstr(button, 1, 6, buttonname.c_str());
    }

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

// function to create the mainwindow 
WINDOW *Window::main_window(){
    WINDOW *mainwin;
    mainwin = newwin(200, 200, 0, 0);
    return mainwin;
}

Window::~Window(){
    delete colour_grey_array;
}
