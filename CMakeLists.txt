cmake_minimum_required(VERSION 3.19)

project(ClockServiceTest CXX C)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-Wfatal-errors -pedantic -g -Wall -Wextra -Wformat=2 -Werror -Wno-missing-braces -std=c++17")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(BOOST_SYSTEM NAMES boost_system)
find_library(BOOST_FILESYSTEM NAMES boost_filesystem)
find_package(GTest CONFIG REQUIRED)

file(GLOB_RECURSE SOURCE_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} GTest::gtest)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    $<BUILD_INTERFACE:${${CMAKE_PROJECT_NAME}_SOURCE_DIR}/src>
)

