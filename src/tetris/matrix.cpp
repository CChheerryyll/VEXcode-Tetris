#include "matrix.h"

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
          matrix[i][j] = Square(x+j*20,y+i*20,'b');
      }
  }
  
}

Matrix::~Matrix() {
    //freeing dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    //delete[] matrix;
    
}

void Matrix::draw(bool border) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            matrix[i][j].draw();
        }
    }

    if (border) {
        int uprightx = matrix[0][cols-1].x+20;
        int uprighty = matrix[0][cols-1].y;
        int btrightx = matrix[rows-1][cols-1].x+20;
        int btrighty = matrix[rows-1][cols-1].y+20;
        int btleftx = matrix[rows-1][0].x;
        int btlefty = matrix[rows-1][0].y+20;

        Brain.Screen.drawLine(x,y,uprightx,uprighty);

        Brain.Screen.drawLine(uprightx,uprighty,btrightx,btrighty);

        Brain.Screen.drawLine(btleftx,btlefty,btrighty,btrighty);

        Brain.Screen.drawLine(x,y,btleftx,btrighty);
    }

}