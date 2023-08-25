cmake_minimum_required(VERSION 3.24)
project(Stack C)

set(CMAKE_C_STANDARD 11)

add_executable(Stack main.c)
add_executable(SqStack-1 SqStack_top-1.c)
add_executable(SqStack0 SqStack_top0.c)
add_executable(ShareStack ShareStack.c)
add_executable(LinkStack_withead LinkStack_withead.c)
add_executable(LinkStack_nohead LinkStack_nohead.c)
add_executable(AD bracketCheck.c)
add_executable(LinkStack_nohead_GPT LinkStack_nohead_GPT.c)

