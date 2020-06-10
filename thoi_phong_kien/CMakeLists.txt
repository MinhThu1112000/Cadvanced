cmake_minimum_required(VERSION 3.16)
project(thoi_phong_kien)

set(CMAKE_CXX_STANDARD 14)
include_directories(libfdr MyIgraph/include)
file(GLOB S "libfdr/*.c" "MyIgraph/src/*.c")
add_executable(thoi_phong_kien MyIgraph/main.c ${S})