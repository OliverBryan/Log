project(Log VERSION 1.0 LANGUAGES CXX)

add_library(Log ./src/Console.cpp ./src/Log.cpp)

target_include_directories(Log PUBLIC ./include)