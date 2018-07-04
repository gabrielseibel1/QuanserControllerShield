cmake_minimum_required(VERSION 3.9)
project(QuanserControllerShield)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_library(QuanserControllerShield STATIC
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

set_target_properties(QuanserControllerShield PROPERTIES PUBLIC_HEADER include/QuanserControllerShield.h)

add_executable(testScript

        test/test.cpp
        include/PIDController.h
        src/PIDController.cpp
)

target_link_libraries(testScript QuanserControllerShield)