cmake_minimum_required(VERSION 2.8)
set(-std=c++14 -Wall)
add_library(defaultik STATIC lib.h notlib.cpp)
