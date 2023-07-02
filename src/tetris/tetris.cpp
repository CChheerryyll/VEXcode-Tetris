#include "vex.h"
#include "tetris.h"

using namespace vex;

Tetris::Tetris() {
    
    gameboard = Matrix(10,10,20,20);

    paused = false, gameOver = false;
    timeStamp = 0.0;
    timeElapsed = 0.0;
    score = 0;

    initializeStates();
    drawBackground();

}

void Tetris::play() {
    Brain.Screen.printAt(250,35,"press Y to start");
    Brain.Screen.printAt(250,170,"Work in progress -");
    Brain.Screen.printAt(250,195, "does not represent");
    Brain.Screen.printAt(250,220, "final quality");
    while(!Controller1.ButtonY.pressing()) {
        wait(50,msec);
    }
    MyTimer = timer();

    Brain.Screen.setPenColor(black);
    Brain.Screen.drawRectangle(240,20,240,20,black);
    Brain.Screen.setPenColor(white);
    Brain.Screen.printAt(240,35,"score: %d ", score);

    //set a distinct seed based on time
    srand(time(NULL));
    
    while (1) { //a full tetro cycle
        
        //randomize an id
        int randomNumber = rand() % 7;
        int tetroStartingXPos = 20;
        block = Tetromino(tetroStartingXPos,20,idList[randomNumber],false);
        //gameboard.updateTetromino(block);

        if (gameboard.canFitTetro(block,tetroStartingXPos)) { //check whether there's enough space to fit a new tetro  
            gameboard.updateTetromino(block);
            
        }
        else {
            gameOver = true;
            //break;
        }
        /*else { //move the starting position to the right
            
            //if successfully creates tetro
            if (gameboard.canFitTetro(block,tetroStartingXPos)) {
                gameboard.updateTetromino(block);
            }
            else {
              //game over
              break;
            }

        }*/

        if (!gameOver) {
            while(1) {
                //buttons
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

                if (Controller1.ButtonY.pressing()) {
                    if (!leftPressing) {
                        if (gameboard.validUpdate(block, 'l')) {
                            block.moveLeft();
                            gameboard.updateTetromino(block);
                            gameboard.drawBorder();
                        }
                        leftPressing = true;
                    }
                }
                else {
                    leftPressing = false;
                }

                if (Controller1.ButtonB.pressing()) {
                    if (!downPressing) {
                        if (gameboard.validUpdate(block, 'd')) {
                            block.moveDown();
                            gameboard.updateTetromino(block);
                            gameboard.drawBorder();
                        }
                        downPressing = true;
                    }
                }
                else {
                    downPressing = false;
                }

                if (Controller1.ButtonUp.pressing()) {
                    if (!upPressing) {
                        if (gameboard.validUpdate(block, 'u')) {
                            block.moveUp();
                            gameboard.updateTetromino(block);
                            gameboard.drawBorder();
                        }
                        upPressing = true;
                    }
                }
                else {
                    upPressing = false;
                }

                if (Controller1.ButtonUp.pressing()) {
                    if (!upPressing) {
                        if (gameboard.validUpdate(block, 'u')) {
                            block.moveUp();
                            gameboard.updateTetromino(block);
                            gameboard.drawBorder();
                        }
                        upPressing = true;
                    }
                }
                else {
                    upPressing = false;
                }

                if (Controller1.ButtonX.pressing()) {
                    if (!rotatePressing) {
                        if (gameboard.validUpdate(block, 'o')) {
                            block.rotate();
                            gameboard.updateTetromino(block);
                            gameboard.drawBorder();
                        }
                        rotatePressing = true;
                    }
                }
                else {
                    rotatePressing = false;
                }

                if (Controller1.ButtonDown.pressing()) {
                    if (!dropPressing) {
                        while (gameboard.validUpdate(block, 'd')) {
                            block.moveDown();
                        }
                        gameboard.updateTetromino(block);
                        //gameboard.draw(true);
                        //gameboard.drawBorder();
                        //gameboard.printMatrix();
                        dropPressing = true;
                    }
                }
                else {
                    dropPressing = false;
                }
                
                //whether to stop the tetro and set up a new one
                if (gameboard.ifStopTetro(block)) {
                    gameboard.transferTetromino(block);
                    score+=5;
                    //check if any rows can be cleared
                    score+= 50*gameboard.scoreColumns();
                    Brain.Screen.printAt(240,35,"score: %d ", score);
                    gameboard.draw(true);
                    break;
                }

                wait(50,msec);
            }
        }
        else {
            Brain.Screen.printAt(240,60,"Game Over");
            while (1) { // make sure the game doesn't exit
                wait(50,msec);
            }
        }

        wait(50, msec);
    }

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