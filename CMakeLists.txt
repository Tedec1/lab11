cmake_minimum_required(VERSION 3.20)
project(lab11)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab11
        Queue.h
        test_no_template.h
        test_with_template.h
        tests.cpp)
