project(Log VERSION 1.0 LANGUAGES CXX)

target_include_directories(Log PUBLIC ./include)

add_library(Log ./src/Console.cpp ./src/Log.cpp)