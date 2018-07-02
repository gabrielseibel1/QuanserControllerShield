cmake_minimum_required(VERSION 3.10)
project(QuanserControllerShield)

set(CMAKE_CXX_STANDARD 11)


add_executable(QuanserControllerShield

        main.cpp
        lib/galileo2io.c
        include/galileo2io.h
        src/Decoder.cpp
        include/Decoder.h
        src/MicroSwitches.cpp
        include/MicroSwitches.h
        src/Motor.cpp
        include/Motor.h
)