cmake_minimum_required(VERSION 3.16)
project(cuongcho C)

set(CMAKE_C_STANDARD 99)
#add_subdirectory(libfdr)
#include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/libfdr)
include_directories(include libfdr)
file(GLOB S "src/*.c" "libfdr/*.c")

add_executable(cuongcho main.c ${S} src/fileprocess.c)
#target_link_libraries(cuongcho fdr)