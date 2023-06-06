#include "tetris.h"

Tetris::Tetris() {
    MyTimer = timer();
    PauseTimer = timer();

    paused = false;
    timeStamp = 0.0;
    timeElapsed = 0.0;

    drawBackground();
}

void Tetris::play() {
    while(1) {
        updateTime();
    }
}

void Tetris::drawBackground() {
    Brain.Screen.clearScreen(black);
    Brain.Screen.drawRectangle(20,20,200,200,black);
}

void Tetris::updateTime() {

    if (Controller1.ButtonL1.pressing()) {
        if (!paused) { //first time pausing the game
            paused = true;
            timeStamp += MyTimer.time(sec);
        }
    }
    else if (Controller1.ButtonR1.pressing()) {
        if (paused) { //need to resume the game
            paused = false;
            MyTimer.clear();
        }
    }

    if (!paused) { //normal gameplay
        timeElapsed = timeStamp + MyTimer.time(sec);
    }

    Brain.Screen.printAt(240,35,"Actual Timer: %f",timeElapsed);

}