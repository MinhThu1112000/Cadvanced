cmake_minimum_required(VERSION 3.16)
project(StreetGraph C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(libfdr)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/libfdr)
include_directories(MyIgraph/include)
file(GLOB SOURCE "MyIgraph/src/*.c")
add_executable(StreetGrap ${SOURCE}  MyIgraph/main.c)
target_link_libraries(StreetGrap fdr)