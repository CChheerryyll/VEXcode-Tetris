#ifndef TETROMINO_H
#define TETROMINO_H

#include "square.h"

class Tetromino {
    public:

    int x, y;
    char id;

    Square shape[4][4];
    
    /**
     * draw the tetromino
     */
    virtual void draw();

    /**
     * move the tetromino right and draw
     */
    virtual void moveRight();

    /**
     * move the tetromino left and draw
     */
    virtual void moveLeft();

    /**
     * move the tetromino up and draw
     */
    virtual void moveUp();
    
    /**
     * move the tetromino down and draw
     */
    virtual void moveDown();

    //virtual void rotate();
};

#endif