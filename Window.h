//
// Created by karol on 07.03.19.
//

#ifndef SO2_P1_WINDOW_H
#define SO2_P1_WINDOW_H

#include <vector>
#include "Ball.h"

class Window {
public:
    Window();
    ~Window();

    void initWindow();
    void reload(std::vector<Ball> balls);
    void drawArea();
};


#endif //SO2_P1_WINDOW_H
