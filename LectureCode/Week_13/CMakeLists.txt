cmake_minimum_required(VERSION 3.28)

project(Week13)

set(CMAKE_CXX_STANDARD 17)

file(GLOB EX2SRC exercise2/*.cpp exercise2/*.h)
file(GLOB EX4SRC exercise4/*.cpp exercise4/*.h)

add_executable(ex2 ${EX2SRC})
add_executable(ex4 ${EX4SRC})
