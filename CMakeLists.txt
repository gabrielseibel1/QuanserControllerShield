cmake_minimum_required(VERSION 3.9)
project(QuanserControllerShield)

set(CMAKE_CXX_STANDARD 11)

add_library(QuanserControllerShield
        include/galileo2io.h
        include/Motor.h
        include/Decoder.h
        include/MicroSwitches.h
        include/QuanserControllerShield.h
        lib/galileo2io.c
        lib/Motor.cpp
        lib/Decoder.cpp
        lib/MicroSwitches.cpp
        lib/QuanserControllerShield.cpp
)

add_executable(testScript

        test/test.cpp
)

target_link_libraries(testScript QuanserControllerShield)