#include "vex.h"
#include "tetrostates.h"

using namespace vex;

int xP = 120, yP = 120;

Square Ishapes[4][4][4];


Square voidState[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                         {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                         {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                         {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square I0[4][4] = {  {Square(xP,yP,'I', false),   Square(xP+20,yP,'I', false),   Square(xP+40,yP,'I', false),   Square(xP+60,yP,'I', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', true), Square(xP+20,yP+60,'v', true), Square(xP+40,yP+60,'v', true), Square(xP+60,yP+60,'v', true)}  };

Square I1[4][4] = {  {Square(xP,yP,'I', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'I', true),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'I', true),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'I', true),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

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