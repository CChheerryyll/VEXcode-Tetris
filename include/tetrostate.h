#include "square.h"

int xP, yP;

Square Void[4][4] = {};

Square I0[4][4] = {  {Square(xP,yP,'I'),Square(xP+20,yP,'I'),Square(xP+40,yP,'I'),Square(xP+60,yP,'I')},
                     {Square(xP,yP+20,'v'),Square(xP+20,yP+20,'v'),Square(xP+40,yP+20,'v'),Square(xP+60,yP+20,'v')},
                     {Square(xP,yP+40,'v'),Square(xP+20,yP+40,'v'),Square(xP+40,yP+40,'v'),Square(xP+60,yP+40,'v')},
                     {Square(xP,yP+60,'v'),Square(xP+20,yP+60,'v'),Square(xP+40,yP+60,'v'),Square(xP+60,yP+60,'v')},  };
Square I1[4][4];

void transferData() {
    
}