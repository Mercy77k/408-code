cmake_minimum_required(VERSION 3.24)
project(Queue C)

set(CMAKE_C_STANDARD 11)

add_executable(Queue1 SqQueue_rear0.c)
add_executable(Queue2 SqQueue_rear-1.c)
add_executable(Queue3 SqQueue_withTag.c)
add_executable(Queue4 SqQueue_withNum.c)
add_executable(Queue5 LinkQueue_withhead.c)
add_executable(Queue6 LinkQueue_nohead.c)
add_executable(Queue8 LinkQueue_withhead_GPT.c)
