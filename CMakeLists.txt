cmake_minimum_required(VERSION 3.15)
project(aoc-25)
include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB DAYS "src/day*.cpp")

foreach(DAY ${DAYS})
    get_filename_component(NAME ${DAY} NAME_WE)
    add_executable(${NAME} ${DAY})
endforeach()
