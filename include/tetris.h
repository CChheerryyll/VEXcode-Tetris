#ifndef TETRIS_H
#define TETRIS_H

#include "matrix.h"
#include "tetromino.h"
//#include "colors.h"

using namespace vex;

/**
 * includes everything in tetris
 */
class Tetris {
    public:
    
    timer MyTimer;

    Matrix gameboard, field;

    Tetromino block;

    double timeElapsed, timeStamp;

    bool paused, rightPressing, leftPressing, upPressing, downPressing;
    
    /**
     * creates a tetris game to play with
     */
    Tetris();

    /**
     * main function of the game to keep the
     * game running
     */
    void play();
    
    /**
     * draws the background of the game screen
     */
    void drawBackground();

    /**
     * update the timer to the screen
     * and determine when to pause and
     * resume the game
     */
    void updateTime();
};

#endif