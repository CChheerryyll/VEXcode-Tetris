#ifndef MATRIX_H
#define MATRIX_H

#include "tetromino.h"

/**
 * a collection of squares which 
 * serves as a gameboard
 */
class Matrix {
    public:

    Square** matrix;
    int rows, cols, x, y;

    //the following are the coordinates of the border
    int uprightx, uprighty, btrightx, btrighty, btleftx, btlefty;

    Matrix();

    /** 
     * creates a collection of squares
     * with r rows and c columns
     * and position
     */
    Matrix(int r, int c, int x, int y);

    ~Matrix();

    /**
     * draw the matrix with or without border
     */
    void draw(bool border);

    /**
     * set the border coordinates of the matrix
     */
    void setBorder();

    /**
     * helper function to draw the border of the matrix
     */
    void drawBorder();

    /**
     * update the tetromino's position onto the matrix
     * only redraw enough squares to update the tetromino
     * assume the update is valid
     * call when the system or player moves the tetromino
     */
    void updateTetromino(Tetromino block);

    /**
     * determine whether the tetromino can move in this 
     * direction
     */
    bool validUpdate(Tetromino block, char dir);

    /**
     * a helper function
     * take a tetrosquare's positon on the screen
     * and convert it to an index in matrix 
     */
    int convertIndex(int tpos, int mpos);
};

#endif