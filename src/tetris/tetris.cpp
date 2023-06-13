#include "vex.h"
#include "tetris.h"

using namespace vex;

Tetris::Tetris() {
    
    gameboard = Matrix(10,10,20,20);

    paused = false, rightPressing = false;
    timeStamp = 0.0;
    timeElapsed = 0.0;

    initializeStates();
    drawBackground();

    //test
    //testBlock = Tetromino(60,60,'I', true);
}

void Tetris::play() {
    Brain.Screen.printAt(240,35,"press down to start");
    while(!Controller1.ButtonDown.pressing()) {
        wait(50,msec);
    }
    MyTimer = timer();

    //create a block
    block = Tetromino(20,20,'I',false);
    gameboard.updateTetromino(block);

    /*for(int i=0; i<gameboard.rows; i++) {
        for (int j=0; j<gameboard.rows; j++) {
            if (gameboard.matrix[i][j].belongsToTetro) {
                printf("t ");
            }
            else {
                printf("f ");
            }
            //printf("%c ",gameboard.matrix[i][j].id);
        }
        printf("\n");
    }*/

    Brain.Screen.setPenColor(black);
    Brain.Screen.drawRectangle(240,20,240,20,black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(240,35,"timer: ");
    
    while(1) {

        if (Controller1.ButtonA.pressing()) {
            if (!rightPressing) {
                if (gameboard.validUpdate(block, 'r')) {
                    block.moveRight();
                    gameboard.updateTetromino(block);
                    gameboard.drawBorder();
                }
                rightPressing = true;
            }
        }
        else {
            rightPressing = false;
        }
        wait(50,msec);}

    /*
    while(1) {
        updateTime();
        //buttons
        if (Controller1.ButtonA.pressing()) {
            if (!rightPressing) {
                block.moveRight();
                rightPressing = true;
            }
        }
        else {
            rightPressing = false;
        }

        if (Controller1.ButtonB.pressing()) {
            if (!downPressing) {
                block.moveDown();
                downPressing = true;
            }
        }
        else {
            downPressing = false;
        }

        if (Controller1.ButtonY.pressing()) {
            if (!leftPressing) {
                block.moveLeft();
                leftPressing = true;
            }
        }
        else {
            leftPressing = false;
        }

        if (Controller1.ButtonX.pressing()) {
            if (!upPressing) {
                //testBlock.moveUp();
                block.rotate();
                upPressing = true;
            }
        }
        else {
            upPressing = false;
        }
    }*/

}

void Tetris::drawBackground() {
    gameboard.draw(true);
    //printf("drew background\n");
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

    Brain.Screen.printAt(240,35,"Timer: %f",timeElapsed);

}