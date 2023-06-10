#include "vex.h"
#include "tetrostates.h"

using namespace vex;

int xP = 120, yP = 120;

Square Ishapes[4][4][4];

Square voidState[4][4] = {  {Square(xP,yP,'v'),   Square(xP+20,yP,'v'),   Square(xP+40,yP,'v'),   Square(xP+60,yP,'v')},
                         {Square(xP,yP+20,'v'),Square(xP+20,yP+20,'v'),Square(xP+40,yP+20,'v'),Square(xP+60,yP+20,'v')},
                         {Square(xP,yP+40,'v'),Square(xP+20,yP+40,'v'),Square(xP+40,yP+40,'v'),Square(xP+60,yP+40,'v')},
                         {Square(xP,yP+60,'v'),Square(xP+20,yP+60,'v'),Square(xP+40,yP+60,'v'),Square(xP+60,yP+60,'v')}  };

Square I0[4][4] = {  {Square(xP,yP,'I'),   Square(xP+20,yP,'I'),   Square(xP+40,yP,'I'),   Square(xP+60,yP,'I')},
                  {Square(xP,yP+20,'v'),Square(xP+20,yP+20,'v'),Square(xP+40,yP+20,'v'),Square(xP+60,yP+20,'v')},
                  {Square(xP,yP+40,'v'),Square(xP+20,yP+40,'v'),Square(xP+40,yP+40,'v'),Square(xP+60,yP+40,'v')},
                  {Square(xP,yP+60,'v'),Square(xP+20,yP+60,'v'),Square(xP+40,yP+60,'v'),Square(xP+60,yP+60,'v')}  };

Square I1[4][4] = {  {Square(xP,yP,'I'),   Square(xP+20,yP,'v'),   Square(xP+40,yP,'v'),   Square(xP+60,yP,'v')},
                  {Square(xP,yP+20,'I'),Square(xP+20,yP+20,'v'),Square(xP+40,yP+20,'v'),Square(xP+60,yP+20,'v')},
                  {Square(xP,yP+40,'I'),Square(xP+20,yP+40,'v'),Square(xP+40,yP+40,'v'),Square(xP+60,yP+40,'v')},
                  {Square(xP,yP+60,'I'),Square(xP+20,yP+60,'v'),Square(xP+40,yP+60,'v'),Square(xP+60,yP+60,'v')}  };

/**
 * helper function
 * set shape_ equal to sq
 */
void transfer(Square shape_[4][4], Square sq[4][4]) {
    for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                shape_[i][j] = sq[i][j];
            }
    }
}

/**
 * set the position of all the squares in the [4][4] matrix
 */
void setPos(Square sq[4][4], int x, int y) {
    for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                sq[i][j].x = x + 20*j;
                sq[i][j].y = y + 20*i;
            }
    }
}

/**
 * please call this function when initializing the game
 */
void initializeStates() {
    transfer(Ishapes[0],I0);
    transfer(Ishapes[1],I1);
    transfer(Ishapes[2],I0);
    transfer(Ishapes[3],I1);

}