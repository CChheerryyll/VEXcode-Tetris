#include "vex.h"
#include "square.h"

using namespace vex;

Square::Square() {

}

Square::Square(int x_, int y_, char id_, bool t) : x(x_), y(y_), belongsToTetro(t), id(id_) {
    if (id == 'I') {
        c = color(102,204,204);
    }
    else if (id == 'O') {
        c = color(255,204,102);
    }
    else if (id == 'T') {
        c = color(255,192,203);
    }
    else if (id == 'J') {
        c = color(51,102,255);
    }
    else if (id == 'L') {
        c = color(255,153,51);
    }
    else if (id == 'S') {
        c = color(102,204,102);
    }
    else if (id == 'Z') {
        c = color(255,77,77);
    }
}

void Square::setSquare(char id_) {
    belongsToTetro = false;
    id = id_;
}

void Square::draw() {
    if (id != 'v') {
        if (id == 'b') {
            Brain.Screen.setPenColor(myGray);
            Brain.Screen.drawRectangle(x,y,20,20,black);
            Brain.Screen.setPenColor(white);
        }
        else {
            Brain.Screen.drawRectangle(x,y,20,20,c);
            /*if (c == myCyan) {
            printf("drew an I block\n");
            }*/
        }
    }
}

void Square::moveRight() {
    if (id != 'v') {
        Brain.Screen.setPenColor(myGray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        x+=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}

void Square::moveLeft() {
    if (id != 'v') {
        Brain.Screen.setPenColor(myGray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        x-=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}

void Square::moveUp() {
    if (id != 'v') {
        Brain.Screen.setPenColor(myGray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        y-=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}

void Square::moveDown() {
    if (id != 'v') {
        Brain.Screen.setPenColor(myGray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        y+=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}