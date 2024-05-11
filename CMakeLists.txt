cmake_minimum_required(VERSION 3.26)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

file(GLOB APP_SOURCES *.cpp)
foreach(testsource ${APP_SOURCES})
    get_filename_component(testname ${testsource} NAME_WE)
    add_executable(${testname} ${testsource})
endforeach(testsource ${APP_SOURCES})
