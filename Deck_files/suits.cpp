#include "suits.h"

Suits::Suits(){

};

// drawing a club onto a window
WINDOW *Suits::drawclubs(WINDOW *canvas){
    // drawing onto the card
    mvwaddstr(canvas, 7, 10, "0");
    mvwaddstr(canvas, 8, 9, "000");
    mvwaddstr(canvas, 9, 8, "00000");
    mvwaddstr(canvas, 10, 9, "/ \\");
    /*      0
    //     000
    //    00000
           / \ 
    */
    return canvas;
};

// drawing a spade onto a window
WINDOW *Suits::drawspades(WINDOW *canvas){
    mvwaddstr(canvas, 7, 10, "/\\");
    mvwaddstr(canvas, 8, 9, "/00\\");
    mvwaddstr(canvas, 9, 8, "00--00");
    mvwaddstr(canvas, 10, 10, "||");
    /*   /\ 
        /00\ 
       00--00
         ||
    */
    return canvas;
}

// drawing a heart onto a window
WINDOW *Suits::drawhearts(WINDOW *canvas){
    mvwaddstr(canvas, 6, 8, " _  _");
    mvwaddstr(canvas, 7, 8, "/ \\/ \\");
    mvwaddstr(canvas, 8, 8, "\\    /");
    mvwaddstr(canvas, 9, 9, "\\  /");
    mvwaddstr(canvas, 10, 10, "\\/");
    //    _  _
    //   / \/ \ /
    //   \   /
    //    \/

    return canvas;
}

// drawing a diamond onto a window
WINDOW *Suits::drawdiamonds(WINDOW *canvas){
    mvwaddstr(canvas, 7, 10, "/\\");
    mvwaddstr(canvas, 8, 9, "/  \\");
    mvwaddstr(canvas, 9, 9, "\\  /");
    mvwaddstr(canvas, 10, 10, "\\/");
    return canvas;
}