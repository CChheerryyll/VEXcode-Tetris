#include "vex.h"
#include "matrix.h"

using namespace vex;

Matrix::Matrix() {

}

Matrix::Matrix(int r, int c, int x_, int y_) : rows(r), cols(c), x(x_), y(y_) {
    //dynamically allocating a 2d array
    matrix = new Square*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new Square[cols];
        
    }

    //setting up the squares in the matrix
    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j] = Square(x+j*20,y+i*20,'b', false);
        }
    }

    setBorder(); 
}

Matrix::~Matrix() {
    //freeing dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
}

void Matrix::draw(bool border) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j].draw();
        }
    }

    if (border) {
        drawBorder();
    }

}

void Matrix::drawBorder() {

    Brain.Screen.drawLine(x,y,uprightx,uprighty);

    Brain.Screen.drawLine(uprightx,uprighty,btrightx,btrighty);

    Brain.Screen.drawLine(btleftx,btlefty,btrighty,btrighty);

    Brain.Screen.drawLine(x,y,btleftx,btrighty);
}

void Matrix::setBorder() {
    uprightx = matrix[0][cols-1].x+20;
    uprighty = matrix[0][cols-1].y;
    btrightx = matrix[rows-1][cols-1].x+20;
    btrighty = matrix[rows-1][cols-1].y+20;
    btleftx = matrix[rows-1][0].x;
    btlefty = matrix[rows-1][0].y+20;
}

void Matrix::updateTetromino(Tetromino block) {
    //clear previous tetromino in the matrix
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (matrix[i][j].belongsToTetro) {
                matrix[i][j].setSquare('b');
                Brain.Screen.setPenColor(myGray);
                Brain.Screen.drawRectangle(matrix[i][j].x, matrix[i][j].y,20,20,black);
                Brain.Screen.setPenColor(white);
                //printf("%d, %d",matrix[i][j].x, matrix[i][j].y);
            }
        }
    }
    //update the new tetromino
    //convert tetromino squares position to position on matrix
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (block.shapes[block.currentShape][i][j].id != 'v') {
                int xindex = convertIndex(block.shapes[block.currentShape][i][j].x, x);
                if (xindex < 0 || xindex > rows-1) { //out of bounds (x)
                    continue;
                }

                int yindex = convertIndex(block.shapes[block.currentShape][i][j].y, y);
                if (yindex < 0 || xindex > rows-1) { //out of bounds (y)
                    continue;
                }

                matrix[xindex][yindex] = block.shapes[block.currentShape][i][j];
                matrix[xindex][yindex].belongsToTetro = true;
                matrix[xindex][yindex].draw();
            }
        }
    }
    
}

bool Matrix::validUpdate(Tetromino block, char dir) {
    bool valid = true;
    
    if (dir == 'r') {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (block.shapes[block.currentShape][i][j].id != 'v') {
                    int xindex = convertIndex(block.shapes[block.currentShape][i][j].x, x)+1;
                    //int yindex = convertIndex(block.shapes[block.currentShape][i][j].y, y);

                    //printf("%d, %d\n", xindex,yindex);

                    if (xindex > rows-1) {
                        //if pass border
                        //printf("%d > %d-1\n", xindex,rows);
                        valid = false;
                        break;
                    }
                    /*else if (matrix[xindex][yindex].id != 'v' || matrix[xindex][yindex].id != 'b') {
                        //if overlap with other nonvoid squares
                        valid = false;
                        printf("%d,%d, id=%c", xindex,yindex,matrix[xindex][yindex].id);
                        break;
                    }*/
                }
            }
            if (!valid) {break;}
        }

    }
    else if (dir == 'l') {

    }
    else if (dir == 'd') {

    }
    else {
        printf("wrong dir\n");
    }

    return valid;
}

int Matrix::convertIndex(int tpos, int mpos) {
    return (tpos - mpos/*starting position of matrix*/) / 20;
}