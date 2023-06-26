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

void Matrix::transferTetromino(Tetromino block) {
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
                matrix[xindex][yindex].belongsToTetro = false;
                matrix[xindex][yindex].draw();
            }
        }
    }
    
}

bool Matrix::validUpdate(Tetromino block, char dir) {
    bool valid = true;
    
    if (dir == 'r') {
        int pXIndex = convertIndex(block.shapes[block.currentShape][0][block.boundary[3]].x, x)+1; //predictedXIndex
        
        for (int i=0; i<4; i++) {
            if (pXIndex > cols - 1) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (block.shapes[block.currentShape][i][j].id != 'v') {
                        int yindex = convertIndex(block.shapes[block.currentShape][i][j].y, y);
                        int xindex = convertIndex(block.shapes[block.currentShape][i][j].x, x)+1;
                        if (matrix[xindex][yindex].id != 'v' && matrix[xindex][yindex].id != 'b' && !matrix[xindex][yindex].belongsToTetro) {
                            //if overlap with existing blocks in the matrix
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) {break;}
            }
        }
    }
    else if (dir == 'l') {
        int pXIndex = convertIndex(block.shapes[block.currentShape][0][block.boundary[2]].x, x)-1; //predictedXIndex
        
        for (int i=0; i<4; i++) {
            if (pXIndex < 0) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (block.shapes[block.currentShape][i][j].id != 'v') {
                        int yindex = convertIndex(block.shapes[block.currentShape][i][j].y, y);
                        int xindex = convertIndex(block.shapes[block.currentShape][i][j].x, x)-1;
                        if (matrix[xindex][yindex].id != 'v' && matrix[xindex][yindex].id != 'b' && !matrix[xindex][yindex].belongsToTetro) {
                            //if overlap with existing blocks in the matrix
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) {break;}
            }
        }

    }
    else if (dir == 'd') {
        int pYIndex = convertIndex(block.shapes[block.currentShape][block.boundary[1]][0].y, y)+1; //predictedXIndex
        
        for (int i=0; i<4; i++) {
            if (pYIndex > rows - 1) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (block.shapes[block.currentShape][i][j].id != 'v') {
                        int yindex = convertIndex(block.shapes[block.currentShape][i][j].y, y)+1;
                        int xindex = convertIndex(block.shapes[block.currentShape][i][j].x, x);
                        if (matrix[xindex][yindex].id != 'v' && matrix[xindex][yindex].id != 'b' && !matrix[xindex][yindex].belongsToTetro) {
                            //if overlap with existing blocks in the matrix
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) {break;}
            }
        }

    }
    else if (dir == 'u') {
        int pYIndex = convertIndex(block.shapes[block.currentShape][block.boundary[1]][0].y, y)-1; //predictedYIndex
        
        for (int i=0; i<4; i++) {
            if (pYIndex < 0) {
                valid = false;
                break;
            }
        }

        if (valid) {
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (block.shapes[block.currentShape][i][j].id != 'v') {
                        int yindex = convertIndex(block.shapes[block.currentShape][i][j].y, y)-1;
                        int xindex = convertIndex(block.shapes[block.currentShape][i][j].x, x);
                        if (matrix[xindex][yindex].id != 'v' && matrix[xindex][yindex].id != 'b' && !matrix[xindex][yindex].belongsToTetro) {
                            //if overlap with existing blocks in the matrix
                            valid = false;
                            break;
                        }
                    }
                }
                if (!valid) {break;}
            }
        }

    }
    else if (dir == 'o') {
        int shapeindex = block.currentShape +1;
        if (shapeindex == 4) {
            shapeindex = 0;
        }

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (block.shapes[shapeindex][i][j].id != 'v') {
                    int yindex = convertIndex(block.shapes[shapeindex][i][j].y, y);
                    int xindex = convertIndex(block.shapes[shapeindex][i][j].x, x);
                    if (yindex < 0 || yindex > rows-1 || xindex < 0 || xindex > cols-1) {
                        //if pass border
                        valid = false;
                        break;
                    }
                    else if (matrix[xindex][yindex].id != 'v' && matrix[xindex][yindex].id != 'b' && !matrix[xindex][yindex].belongsToTetro) {
                        //if overlap with existing blocks in the matrix
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) {break;}
        }
    }
    else {
        printf("wrong dir\n");
    }

    return valid;
}

bool Matrix::ifStopTetro(Tetromino block) {
    bool s = false;

    int yIndex = convertIndex(block.shapes[block.currentShape][block.boundary[1]][0].y, y);
    
    if (yIndex == rows - 1) { // will go out of bounds
        s = true;
    }
    else { // will any blocks in the tetro overlap with another block?
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                if (block.shapes[block.currentShape][i][j].belongsToTetro) {
                    int pYIndex = convertIndex(block.shapes[block.currentShape][i][j].y, y)+1;
                    int xIndex = convertIndex(block.shapes[block.currentShape][i][j].x, x);
                    if (matrix[xIndex][pYIndex].id != 'v' && matrix[xIndex][pYIndex].id != 'b' && !matrix[xIndex][pYIndex].belongsToTetro) {
                        //if the block below the current block of the tetro is filled
                        s = true;
                        break;
                    }
                }
            }
            if (s) {break;}
        }
    }

    return s;
}

int Matrix::convertIndex(int tpos, int mpos) {
    return (tpos - mpos/*starting position of matrix*/) / 20;
}