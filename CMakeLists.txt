cmake_minimum_required(VERSION 3.8)
project(wordCount)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(wordCount ${SOURCE_FILES})