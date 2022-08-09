cmake_minimum_required(VERSION 3.15)
project(polynomial)

set(CMAKE_CXX_STANDARD 11)

add_executable(polynomial main.cpp test.h poly.h poly.cpp)