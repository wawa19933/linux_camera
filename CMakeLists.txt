cmake_minimum_required(VERSION 3.8)
project(linux_camera)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES camera-linux.c camera-linux.h)
add_library(linux_camera ${SOURCE_FILES})