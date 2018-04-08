cmake_minimum_required(VERSION 3.1.3)

project(tp7 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11) # Use C++11

set(CMAKE_BUILD_TYPE Debug)

add_executable(tp7 tp7.cpp String.cpp String.h)

