#include "vex.h"
#include "tetromino.h"

using namespace vex;

Tetromino::Tetromino() {

}

Tetromino::Tetromino(int x_, int y_, char id_, bool show_) {
    x = x_; y = y_; id = id_; show = show_;
    currentShape = 0;
    if (id == 'I') {
        for (int i=0; i<4; i++) {
            setPos(Ishapes[i],x,y);
            transfer(shapes[i],Ishapes[i]);
        }
    }
    if(show) {
        draw();
    }
}

/*void Tetromino::transfer(Square shape_[4][4], Square sq[4][4]) {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            shape_[i][j] = sq[i][j];
        }
    }
}*/

void Tetromino::draw() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            shapes[currentShape][i][j].draw();
            /*if (shapes[currentShape][i][j].c == myCyan) {
            printf("%c ", shapes[currentShape][i][j].id);
            }
            else {printf("e ");}*/
        }
        //printf("\n");
    }
}

void Tetromino::moveRight() {
    for (int k=0; k<4; k++) {
      for (int i=3; i>=0; i--) {
          for (int j=3; j>=0; j--) {
              if (k == currentShape && show) {
                  shapes[k][i][j].moveRight();
              }
              else {
                  shapes[k][i][j].x += 20;
              }
          }
      }
    }
}

void Tetromino::moveLeft() {
    for (int k=0; k<4; k++) {
      for (int i=0; i<4; i++) {
          for (int j=0; j<4; j++) {
              if (k == currentShape && show) {
                  shapes[k][i][j].moveLeft();
              }
              else {
                  shapes[k][i][j].x -= 20;
              }
          }
      }
    }
}

void Tetromino::moveUp() {
    for (int k=0; k<4; k++) {
      for (int i=0; i<4; i++) {
          for (int j=0; j<4; j++) {
              if (k == currentShape && show) {
                  shapes[k][i][j].moveUp();
              }
              else {
                  shapes[k][i][j].y -= 20;
              }
          }
      }
    }
}

void Tetromino::moveDown() {
    for (int k=0; k<4; k++) {
      for (int i=3; i>=0; i--) {
          for (int j=0; j<4; j++) {
              if (k == currentShape && show) {
                  shapes[k][i][j].moveDown();
              }
              else {
                  shapes[k][i][j].y += 20;
              }
          }
      }
    }
}

void Tetromino::rotate() {
    if (show) {
      for (int i=0; i<4; i++) {
          for (int j=0; j<4; j++) {
              if (shapes[currentShape][i][j].id != 'v') {
                  Brain.Screen.setPenColor(myGray);
                  Brain.Screen.drawRectangle(shapes[currentShape][i][j].x,shapes[currentShape][i][j].y,20,20,black);
                  Brain.Screen.setPenColor(white);
              }
          }
      }
    }

    currentShape += 1;
    if (currentShape == 4) {
        currentShape = 0;
    }
    
    if (show) {
        draw();
    }
}