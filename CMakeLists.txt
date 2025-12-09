
cmake_minimum_required(VERSION 3.15)
project(set_library CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(setlib src/Set.cpp)
target_include_directories(setlib PUBLIC include)

add_executable(set_demo src/main.cpp)
target_link_libraries(set_demo PRIVATE setlib)

enable_testing()
add_executable(set_tests tests/test_set.cpp)
target_link_libraries(set_tests PRIVATE setlib)
add_test(NAME unit COMMAND set_tests)
