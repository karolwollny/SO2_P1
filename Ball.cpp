//
// Created by karol on 03.03.19.
//
#include <ncurses.h>
#include "Ball.h"

Ball::Ball(short vec, int speed) {
    this->vector = vec;
    this->speed = speed;
    positionX = 28;
    positionY = 12;
}

void Ball::mov() {
    prevX = positionX;
    prevY = positionY;

    if(positionX > 2 && positionX < 51 && positionY > 1 && positionY < 22){

        if(vector == 1){

            positionX--;
        }
        else if(vector == 2){
            positionY--;
            positionX--;
        }
        else if(vector == 3){
            positionY--;
        }
        else if(vector == 4){
            positionX++;
            positionY--;
        }
        else if(vector == 5){
            positionX++;
        }
        else if(vector == 6){
            positionX++;
            positionY++;
        }
        else if(vector == 7){
            positionY++;
        }
        else if(vector == 8){
            positionX--;
            positionY++;
        }
    }

    else{
        if(positionX == 2){
            if(vector == 1){
                vector = 5;
                positionX++;
            }
            else if(vector == 2){
                vector = 4;
                positionY--;
                positionX++;
            }
            else if(vector == 8){
                vector = 6;
                positionX++;
                positionY++;
            }
        }
        else if(positionX == 51){
            if(vector == 4){
                vector = 2;
                positionX--;
                positionY--;
            }
            else if(vector == 5){
                vector = 1;
                positionX--;
            }
            else if(vector == 6){
                vector = 8;
                positionX--;
                positionY++;
            }
        }
        else if(positionY == 1){
            if(vector == 3){
                vector = 7;
                positionY++;
            }
            else if(vector == 4){
                vector = 6;
                positionX++;
                positionY++;
            }
            else if(vector == 2){
                vector = 8;
                positionX--;
                positionY++;
            }

        }
        else if(positionY == 22){
            if(vector == 7){
                vector = 3;
                positionY--;
            }
            else if(vector == 6){
                vector = 4;
                positionY--;
                positionX++;
            }
            else if(vector == 8){
                vector = 2;
                positionX--;
                positionY--;
            }
        }
    }

    //drawBall();
    speed = speed * 1.3;
}

void Ball::drawBall() {
    if(speed < 100){
    move(positionY,positionX);
    printw("o");
    move(prevY,prevX);
    printw(" ");
    }
    else {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        attron(COLOR_PAIR(1));
        move(prevY, prevX);
        printw("o");
        attroff(COLOR_PAIR(1));
    }
}

Ball::~Ball() {
    delete this;
}

int Ball::getSpeed() {
    return this->speed;
}
