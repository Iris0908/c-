cmake_minimum_required(VERSION 3.19)

project(ClockServiceTest CXX C)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wfatal-errors -pedantic -g -Wall -Wextra -Wformat=2 -Werror -Wno-missing-braces -std=c++17 ${CMAKE_CXX_FLAGS}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} test.cpp Service.cpp)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    $<BUILD_INTERFACE:${${CMAKE_PROJECT_NAME}_SOURCE_DIR}>
)

