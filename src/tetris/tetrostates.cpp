#include "vex.h"
#include "tetrostates.h"

using namespace vex;

int xP = 120, yP = 120;

Square Ishapes[4][4][4];
Square Oshapes[4][4][4];
Square Tshapes[4][4][4];
Square Jshapes[4][4][4];
Square Lshapes[4][4][4];
Square Sshapes[4][4][4];
Square Zshapes[4][4][4];

Square voidState[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                         {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                         {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                         {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square I0[4][4] = {  {Square(xP,yP,'I', true),   Square(xP+20,yP,'I', true),   Square(xP+40,yP,'I', true),   Square(xP+60,yP,'I', true)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false), Square(xP+20,yP+60,'v', false), Square(xP+40,yP+60,'v', false), Square(xP+60,yP+60,'v', false)}  };

Square I1[4][4] = {  {Square(xP,yP,'I', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'I', true),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'I', true),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'I', true),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square O0[4][4] = {  {Square(xP,yP,'O', true),   Square(xP+20,yP,'O', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'O', true),Square(xP+20,yP+20,'O', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square T0[4][4] = {  {Square(xP,yP,'T', true),   Square(xP+20,yP,'T', true),   Square(xP+40,yP,'T', true),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'T', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square T1[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'T', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'T', true),Square(xP+20,yP+20,'T', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'T', true),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square T2[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'T', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'T', true),Square(xP+20,yP+20,'T', true),Square(xP+40,yP+20,'T', true),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square T3[4][4] = {  {Square(xP,yP,'T', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'T', true),Square(xP+20,yP+20,'T', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'T', true),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square J0[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'J', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'J', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'J', true),Square(xP+20,yP+40,'J', true),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square J1[4][4] = {  {Square(xP,yP,'J', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'J', true),Square(xP+20,yP+20,'J', true),Square(xP+40,yP+20,'J', true),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square J2[4][4] = {  {Square(xP,yP,'J', true),   Square(xP+20,yP,'J', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'J', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'J', true),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square J3[4][4] = {  {Square(xP,yP,'J', true),   Square(xP+20,yP,'J', true),   Square(xP+40,yP,'J', true),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'J', true),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square L0[4][4] = {  {Square(xP,yP,'L', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'L', true),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'L', true),Square(xP+20,yP+40,'L', true),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square L1[4][4] = {  {Square(xP,yP,'L', true),   Square(xP+20,yP,'L', true),   Square(xP+40,yP,'L', true),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'L', true),Square(xP+20,yP+20,'v', false),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square L2[4][4] = {  {Square(xP,yP,'L', true),   Square(xP+20,yP,'L', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'L', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'L', true),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square L3[4][4] = {  {Square(xP,yP,'L', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'L', true),Square(xP+20,yP+20,'L', true),Square(xP+40,yP+20,'L', true),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square S0[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'S', true),   Square(xP+40,yP,'S', true),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'S', true),Square(xP+20,yP+20,'S', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square S1[4][4] = {  {Square(xP,yP,'S', true),   Square(xP+20,yP,'v', false),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'S', true),Square(xP+20,yP+20,'S', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'S', true),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square Z0[4][4] = {  {Square(xP,yP,'Z', true),   Square(xP+20,yP,'Z', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'v', false),Square(xP+20,yP+20,'Z', true),Square(xP+40,yP+20,'Z', true),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'v', false),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

Square Z1[4][4] = {  {Square(xP,yP,'v', false),   Square(xP+20,yP,'Z', true),   Square(xP+40,yP,'v', false),   Square(xP+60,yP,'v', false)},
                  {Square(xP,yP+20,'Z', true),Square(xP+20,yP+20,'Z', true),Square(xP+40,yP+20,'v', false),Square(xP+60,yP+20,'v', false)},
                  {Square(xP,yP+40,'Z', true),Square(xP+20,yP+40,'v', false),Square(xP+40,yP+40,'v', false),Square(xP+60,yP+40,'v', false)},
                  {Square(xP,yP+60,'v', false),Square(xP+20,yP+60,'v', false),Square(xP+40,yP+60,'v', false),Square(xP+60,yP+60,'v', false)}  };

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

    transfer(Oshapes[0],O0);
    transfer(Oshapes[1],O0);
    transfer(Oshapes[2],O0);
    transfer(Oshapes[3],O0);

    transfer(Tshapes[0],T0);
    transfer(Tshapes[1],T1);
    transfer(Tshapes[2],T2);
    transfer(Tshapes[3],T3);

    transfer(Jshapes[0],J0);
    transfer(Jshapes[1],J1);
    transfer(Jshapes[2],J2);
    transfer(Jshapes[3],J3);

    transfer(Lshapes[0],L0);
    transfer(Lshapes[1],L1);
    transfer(Lshapes[2],L2);
    transfer(Lshapes[3],L3);

    transfer(Sshapes[0],S0);
    transfer(Sshapes[1],S1);
    transfer(Sshapes[2],S0);
    transfer(Sshapes[3],S1);

    transfer(Zshapes[0],Z0);
    transfer(Zshapes[1],Z1);
    transfer(Zshapes[2],Z0);
    transfer(Zshapes[3],Z1);
}