#include "tetris.h"

Tetris::Tetris() {
    MyTimer = timer();
    PauseTimer = timer();
    
    gameboard = Matrix(10,10,20,20);

    paused = false;
    timeStamp = 0.0;
    timeElapsed = 0.0;

    drawBackground();

    //test
    TetroI testBlock = TetroI(60,60);
}

void Tetris::play() {
    while(1) {
        updateTime();
    }
}

void Tetris::drawBackground() {
    gameboard.draw(true);
}

void Tetris::updateTime() {

    if (Controller1.ButtonL1.pressing()) {
        if (!paused) { //first time pausing the game
            paused = true;
            timeStamp += MyTimer.time(sec);
            Brain.Screen.printAt(240,55,"Game Paused");
        }
    }
    else if (Controller1.ButtonR1.pressing()) {
        if (paused) { //need to resume the game
            paused = false;
            MyTimer.clear();
            Brain.Screen.setPenColor(black);
            Brain.Screen.drawRectangle(240,35,120,20,black);
            Brain.Screen.setPenColor(white);
        }
    }

    if (!paused) { //normal gameplay
        timeElapsed = timeStamp + MyTimer.time(sec);
    }

    Brain.Screen.printAt(240,35,"Actual Timer: %f",timeElapsed);

}