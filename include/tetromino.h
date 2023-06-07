#ifndef TETROMINO_H
#define TETROMINO_H

#include "square.h"

class Tetromino {
    public:

    int x, y;
    char id;

    Square shape[4][4];
    
    virtual void draw();

    virtual void moveRight();
};

#endif