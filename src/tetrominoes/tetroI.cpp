#include "tetroI.h"

TetroI::TetroI() {

}

TetroI::TetroI(int x_, int y_) {
    x = x_;
    y = y_;
    id = 'I';

    //set up shape
    shape[0][0] = Square(x,y,'I');
    shape[0][1] = Square(x+20,y,'I');
    shape[0][2] = Square(x+40,y,'I');
    shape[0][3] = Square(x+60,y,'I');

    shape[1][0] = Square(x,y+20,'v');
    shape[1][1] = Square(x+20,y+20,'v');
    shape[1][2] = Square(x+40,y+20,'v');
    shape[1][3] = Square(x+60,y+20,'v');

    shape[2][0] = Square(x,y+40,'v');
    shape[2][1] = Square(x+20,y+40,'v');
    shape[2][2] = Square(x+40,y+40,'v');
    shape[2][3] = Square(x+60,y+40,'v');

    shape[3][0] = Square(x,y+60,'v');
    shape[3][1] = Square(x+20,y+60,'v');
    shape[3][2] = Square(x+40,y+60,'v');
    shape[3][3] = Square(x+60,y+60,'v');

    draw();
}
