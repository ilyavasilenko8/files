cmake_minimum_required(VERSION 3.27)
project(laboratory_files C)

set(CMAKE_C_STANDARD 11)

add_executable(laboratory_files main.c
        Files/files.c
        Files/files.h)
