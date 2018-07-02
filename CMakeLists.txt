cmake_minimum_required(VERSION 3.10)
project(QuanserControllerShield)

set(CMAKE_CXX_STANDARD 11)


add_executable(QuanserControllerShield

        main.cpp
        lib/galileo2io.c
        include/galileo2io.h
        src/Decoder.cpp
        src/Decoder.h
        src/MicroSwitches.cpp
        src/MicroSwitches.h
        src/Motor.cpp
        src/Motor.h
)