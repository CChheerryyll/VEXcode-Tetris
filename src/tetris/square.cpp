#include "square.h"
#include "colors.h"

Square::Square() {

}

Square::Square(int x_, int y_, char id_) : x(x_), y(y_), id(id_) {
    if (id == 'I') {
        c = myCyan;
    }
}

void Square::draw() {
    if (id != 'v') {
        if (id == 'b') {
            Brain.Screen.setPenColor(gray);
            Brain.Screen.drawRectangle(x,y,20,20,black);
            Brain.Screen.setPenColor(white);
        }
        else if (id == 'I') {
            Brain.Screen.drawRectangle(x,y,20,20,c);
        }
    }
}

void Square::moveRight() {
    if (id != 'v') {
        Brain.Screen.setPenColor(gray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        x+=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}

void Square::moveLeft() {
    if (id != 'v') {
        Brain.Screen.setPenColor(gray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        x-=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}

void Square::moveUp() {
    if (id != 'v') {
        Brain.Screen.setPenColor(gray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        y-=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}

void Square::moveDown() {
    if (id != 'v') {
        Brain.Screen.setPenColor(gray);
        Brain.Screen.drawRectangle(x,y,20,20,black);
        Brain.Screen.setPenColor(white);
        y+=20;
        Brain.Screen.drawRectangle(x,y,20,20,c);
    }
}