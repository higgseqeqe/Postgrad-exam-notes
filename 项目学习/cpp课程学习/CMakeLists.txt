cmake_minimum_required(VERSION 4.3)
project(cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Each exercise with a main function is a separate executable.
add_executable(cpp test1.cpp)
add_executable(cout_demo "cout打印输出.cpp")
add_executable(linked_list "单链表.cpp")
add_executable(dynamic_search "动态分配  查找.cpp")
add_executable(sequence_list "顺序表.cpp")
add_executable(sequence_list_practice "顺序表练习.cpp")

# This exercise contains functions only, without a main function.
add_library(linked_list_practice OBJECT "单链表练习.cpp")