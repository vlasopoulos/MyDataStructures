cmake_minimum_required(VERSION 3.20)
project(MyDataStructures)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyDataStructures main.cpp)

include_directories(MyDataStructures_lib)
add_subdirectory(MyDataStructures_lib)

target_link_libraries(MyDataStructures MyDataStructures_lib)

add_subdirectory(Google_tests)
