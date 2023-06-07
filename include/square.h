#ifndef SQUARE_H
#define SQUARE_H

#include "vex.h"

/**
 * the basic unit of the game
 */
class Square {
    public:
    
    int x, y;
    color c;
    
    /**
     * b: background
     * v: void
     * I
     * O
     * T
     * J
     * L
     * S
     * Z
     */
    char id;
    
    Square();
    
    /**
     * creates a square with position and id
     * constant size 20 pixels
     */
    Square(int x_, int y_, char id_);

    /**
     * draw the square on the screen
     */
    void draw();

    void moveRight();

    void moveLeft();

    void moveUp();

    void moveDown();
};

#endif