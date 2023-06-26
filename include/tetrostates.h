#include "square.h"

using namespace vex;

extern int xP, yP;

extern Square Ishapes[4][4][4];
extern Square Oshapes[4][4][4];
extern Square Tshapes[4][4][4];
extern Square Jshapes[4][4][4];
extern Square Lshapes[4][4][4];
extern Square Sshapes[4][4][4];
extern Square Zshapes[4][4][4];
extern Square voidState[4][4];
extern Square I0[4][4];
extern Square I1[4][4];

void transfer(Square shape_[4][4], Square sq[4][4]);
void setPos(Square sq[4][4], int x, int y);
void initializeStates();