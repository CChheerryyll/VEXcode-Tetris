#ifndef TETROMINO_H
#define TETROMINO_H

#include "square.h"
#include "tetrostates.h"

using namespace vex;

class Tetromino {
    public:

        int x, y;
        char id;
        bool show;

        Square shapes[4][4][4];
        int currentShape;
        int boundary[4] = {0,0,0,0};
        //up, down, left, right

        Tetromino();

        Tetromino(int x_, int y_, char id_, bool show_);

        /** 
        * change shape_ to the tetrostate
        * stored in sq 
        */
        //void transfer(Square shape_[4][4], Square sq[4][4]);
        
        /**
        * draw the tetromino
        */
        void draw();

        /**
        * move the tetromino right and draw
        */
        void moveRight();

        /**
        * move the tetromino left and draw
        */
        void moveLeft();

        /**
        * move the tetromino up and draw
        */
        void moveUp();
        
        /**
        * move the tetromino down and draw
        */
        void moveDown();

        /**
         * rotate the tetromino and draw
         */
        void rotate();

        /**
         * set the boundary of the tetromino in its 4x4 matrix
         */
        void setBoundary();

        /**
         * a test function to print the tetro's status in terminal
         */
        void printTetro();

};

#endif