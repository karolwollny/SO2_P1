//
// Created by karol on 03.03.19.
//

#ifndef SO2_P1_BALL_H
#define SO2_P1_BALL_H


class Ball {
private:
    int positionX, positionY; //współrzędne X oraz Y piłki
    int prevX, prevY; //poprzednie współrzędne X oraz Y piłki

    short vector;   //kierunek w jakim porusza się piłka (wartość 1-8)
    int speed;  //prędkość z jaką porusza się piłka
public:
    Ball(short vec, int speed);
    ~Ball();
    void mov();
    void drawBall();
    int getSpeed();
    int getX();
    int getY();
};


#endif //SO2_P1_BALL_H
