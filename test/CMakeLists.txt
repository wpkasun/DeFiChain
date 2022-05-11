cmake_minimum_required(VERSION 2.6)

project(DeFiChainTest)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ../include)
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests test.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)