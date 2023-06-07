#include "tetromino.h"

void Tetromino::draw() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            shape[i][j].draw();
        }
    }
}

void Tetromino::moveRight() {
    for (int i=3; i>=0; i--) {
        for (int j=3; j>=0; j--) {
            shape[i][j].moveRight();
        }
    }
}

void Tetromino::moveLeft() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            shape[i][j].moveLeft();
        }
    }
}

void Tetromino::moveUp() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            shape[i][j].moveUp();
        }
    }
}

void Tetromino::moveDown() {
    for (int i=3; i>=0; i--) {
        for (int j=0; j<4; j++) {
            shape[i][j].moveDown();
        }
    }
}