cmake_minimum_required(VERSION 3.10)
project(QuanserControllerShield)

set(CMAKE_CXX_STANDARD 11)

add_executable(QuanserControllerShield

        main.cpp
        src/microswitch.c
        src/microswitch.h
)