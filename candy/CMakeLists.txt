cmake_minimum_required(VERSION 3.13)
project(assumptionTest)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(candy-kingdom)
include_directories(candy-kingdom/src)

add_executable(assumptionTest main.cpp)

target_link_libraries(assumptionTest candylib)