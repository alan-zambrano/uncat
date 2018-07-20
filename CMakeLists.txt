cmake_minimum_required(VERSION 2.6)

project(uncat)

add_definitions(-std=c++1z -g)

#Create Libraries
add_library(TreeLib tree.cpp node.cpp)

#Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests runTests.cpp)
target_link_libraries(runTests gtest)
target_link_libraries(runTests pthread)
target_link_libraries(runTests TreeLib)

#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
