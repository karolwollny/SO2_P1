//
// Created by karol on 07.03.19.
//

#include "Window.h"
#include <ncurses.h>

Window::Window() {
    initWindow();
}

Window::~Window() {
    endwin();    // zakończenie trybu ncurses
}

void Window::initWindow() {
    initscr();  // rozpoczęcie trybu curses
    noecho();   //wyłącz efekt echa
    curs_set(FALSE);    //wyłącz kursor
    clear();     //wyczysczenie ekranu
    refresh();  // wypisanie na rzeczywistym ekranie
}

void Window::reload(std::vector<Ball> balls) {

}

void Window::drawArea() {
    //Wyrysowanie ramki:



    for(int i = 2; i <=51; i++)
    {
        move(0,i);
        printw("_");
        move(23,i);
        printw("-");
    }

    for(int i = 1; i <=22; i++)
    {
        move(i,1);
        printw("|");
        move(i,52);
        printw("|");
    }

    refresh();
}

