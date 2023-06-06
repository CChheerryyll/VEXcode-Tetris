#ifndef TETRIS_H
#define TETRIS_H

#include "vex.h"

/**
 * includes everything in tetris
 */
class Tetris {
    public:
    
    vex::timer MyTimer;
    vex::timer PauseTimer;

    double timeElapsed, timeStamp;

    bool paused;
    
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
     * update values such as timer and score
     * to the screen
     */
    void updateTime();
};

#endif