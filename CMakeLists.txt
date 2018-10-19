cmake_minimum_required(VERSION 3.12)
project(Trabalho1_PC C)

set(CMAKE_C_STANDARD 99)

add_executable(Trabalho1_PC main.c)
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
