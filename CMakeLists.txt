cmake_minimum_required(VERSION 3.12)
project(SO2_P1)

set(CMAKE_CXX_STANDARD 14)


add_executable(SO2_P1 main.cpp Ball.cpp Ball.h Window.cpp Window.h)

target_link_libraries(${PROJECT_NAME} ncurses)
target_link_libraries(${PROJECT_NAME} pthread)