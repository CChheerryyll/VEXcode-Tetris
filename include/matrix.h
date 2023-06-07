#ifndef MATRIX_H
#define MATRIX_H

#include "square.h"

/**
 * a collection of squares in which
 * exists = false
 */
class Matrix {
    public:

    Square** matrix;
    int rows, cols, x, y;

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
};

#endif