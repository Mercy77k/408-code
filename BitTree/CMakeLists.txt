cmake_minimum_required(VERSION 3.24)
project(BitTree C)

set(CMAKE_C_STANDARD 11)

add_executable(BitTree main.c )
add_executable(bit BitTree_IterativeTraversal.c)
add_executable(bit2 BitTree_RecursiveTraversa.c)
add_executable(test1 test.c)