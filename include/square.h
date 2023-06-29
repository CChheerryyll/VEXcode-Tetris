#ifndef SQUARE_H
#define SQUARE_H

#include "colors.h"

using namespace vex;

/**
 * the basic unit of the game
 */
class Square {
    public:
    
    int x, y;
    bool belongsToTetro;
    
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
     * and whether the square belongs to a 
     * user-controlled tetromino
     */
    Square(int x_, int y_, char id_, bool t);

    /**
     * draw the square on the screen
     */
    void draw();

    /**
     * set the square status based on id
     * this square will not belong to a tetromino
     */
    void setSquare(char id_);

    void moveRight();

    void moveLeft();

    void moveUp();

    void moveDown();

    color getColor();
};

#endif