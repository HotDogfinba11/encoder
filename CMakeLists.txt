cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp
        encoder.h
        filehandling.h
        ShiftRegister.h)
