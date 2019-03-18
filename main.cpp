#include <ncurses.h>
#include <string>
#include <unistd.h>
#include "Window.h"
#include "Ball.h"
#include <thread>
#include <vector>

using namespace std;

Window *window;
vector<Ball*> balls;
bool finish = true;
vector<thread> threads;

void moveBall(Ball * b){
    while((b->getSpeed() < 1000) && finish == true) {
        b->mov();
        usleep(b->getSpeed() * 2000);
    }
}

void ballGenerator(){
    short tmpV;
    int tmpS;
    while(finish){

        tmpV = rand() % 5 + 1;
        tmpS = rand() % 10 + 20;
        Ball *ball = new Ball(tmpV,tmpS);
        balls.push_back(ball);

        threads.push_back(thread(moveBall,balls.back()));

        usleep(2000000);
    }
}

void windowRefresh(){


    while(finish) {
        for (int i = 0; i < balls.size(); i++) {
            balls[i]->drawBall();
        }
        refresh();
        usleep(100);
    }

}

void endProgram(){
    int c;
    while(finish){
        c = getch();
        if(c == 'e'){
            finish = false;
        }
    }
}



int main() {
    srand(time(NULL));
    window = new Window();

    start_color();
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(2));

    window->drawArea();


    thread ballGeneratorThread(ballGenerator);
    thread windowRefreshThread(windowRefresh);
    thread endProgramThread(endProgram);

    endProgramThread.join();
    ballGeneratorThread.join();
    windowRefreshThread.join();

    for(int i = 0; i<threads.size(); i++){
        threads[i].join();
    }
    attroff(COLOR_PAIR(2));

    for(int i =0; i<balls.size(); i++){
        delete balls[i];
    }
    delete window;
    return 0;
}