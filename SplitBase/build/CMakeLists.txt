cmake_minimum_required (VERSION 3.5.0)

project(FinalWork-SplitBase)

include_directories(../include)

set(SOURCES ../src/main.cpp)

set(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11 -Ofast -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH "../../")

add_executable(splitBase ${SOURCES})
