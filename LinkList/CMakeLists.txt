cmake_minimum_required(VERSION 3.24)
project(LinkList C)

set(CMAKE_C_STANDARD 11)

add_executable(LNode "LNode(单链表).c")
add_executable(DNode "DNode(双链表).c")
add_executable(CNode "CycleList(循环链表).c")
add_executable(SNode "SLinkList(静态链表).c")