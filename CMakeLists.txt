cmake_minimum_required(VERSION 3.9)
project(QuanserControllerShield)

set(CMAKE_CXX_STANDARD 11)

add_executable(QuanserControllerShield

        lib/galileo2io.c
        include/galileo2io.h
        lib/Decoder.cpp
        include/Decoder.h
        lib/MicroSwitches.cpp
        include/MicroSwitches.h
        lib/Motor.cpp
        include/Motor.h
        lib/QuanserControllerShield.cpp
        include/QuanserControllerShield.h
        test/test.cpp)