#include "suits.h"

Suits::Suits(){

};

// drawing a club onto a window
WINDOW *Suits::drawclubs(WINDOW *canvas){
    // drawing onto the card
    mvwaddstr(canvas, 7, 11, "0");
    mvwaddstr(canvas, 8, 10, "000");
    mvwaddstr(canvas, 9, 9, "00000");
    mvwaddstr(canvas, 10, 10, "/ \\");
    /*      0
    //     000
    //    00000
           / \ 
    */
    return canvas;
};

// drawing a spade onto a window
WINDOW *Suits::drawspades(WINDOW *canvas){
    mvwaddstr(canvas, 7, 11, "/\\");
    mvwaddstr(canvas, 8, 10, "/00\\");
    mvwaddstr(canvas, 9, 9, "00--00");
    mvwaddstr(canvas, 10, 11, "||");
    /*   /\ 
        /00\ 
       00--00
         ||
    */
    return canvas;
}

// drawing a heart onto a window
WINDOW *Suits::drawhearts(WINDOW *canvas){
    mvwaddstr(canvas, 6, 9, " _  _");
    mvwaddstr(canvas, 7, 9, "/ \\/ \\");
    mvwaddstr(canvas, 8, 9, "\\    /");
    mvwaddstr(canvas, 9, 10, "\\  /");
    mvwaddstr(canvas, 10, 11, "\\/");
    //    _  _
    //   / \/ \ /
    //   \   /
    //    \/

    return canvas;
}

// drawing a diamond onto a window
WINDOW *Suits::drawdiamonds(WINDOW *canvas){
    mvwaddstr(canvas, 7, 11, "/\\");
    mvwaddstr(canvas, 8, 10, "/  \\");
    mvwaddstr(canvas, 9, 10, "\\  /");
    mvwaddstr(canvas, 10, 11, "\\/");
    return canvas;
}