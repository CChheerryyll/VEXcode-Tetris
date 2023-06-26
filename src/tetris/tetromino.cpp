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
    
    //boundary[3] = 0;
    setBoundary();
    //printf("%d, %d, %d, %d\n",boundary[0],boundary[1],boundary[2],boundary[3]);
    //printf("0, 0, 0, 3  correct\n");
    //0,0,0,3
}

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

    setBoundary();
}

void Tetromino::setBoundary() {
    //upper boundary
    bool b = false; //break
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (shapes[currentShape][i][j].belongsToTetro) {
                boundary[0] = i;
                //printf("%d\n",boundary[0]);
                b = true;
                break;
            }
        }
        if (b) {
            break;
        }
    }
    
    //lower boundary
    b = false; //break
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (shapes[currentShape][3-i][j].belongsToTetro) {
                boundary[1] = 3-i;
                b = true;
                break;
            }
        }
        if (b) {
            break;
        }
    }

    //left boundary
    b = false; //break
    for (int j=0; j<4; j++) {
        for (int i=0; i<4; i++) {
            if (shapes[currentShape][i][j].belongsToTetro) {
                boundary[2] = j;
                b = true;
                break;
            }
        }
        if (b) {
            break;
        }
    }

    //right boundary
    b = false; //break
    for (int j=0; j<4; j--) {
        for (int i=0; i<4; i++) {
            if (shapes[currentShape][i][3-j].belongsToTetro) {
                boundary[3] = 3-j;
                //printf("%d\n",boundary[3]);
                b = true;
                break;
            }
        }
        if (b) {
            break;
        }
    }
}

void Tetromino::printTetro() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (shapes[currentShape][i][j].belongsToTetro) {
                printf("t ");
            }
            else {
                printf("f ");
            }
        }
        printf("\n");
    }
}