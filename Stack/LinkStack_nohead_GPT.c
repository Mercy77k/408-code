//
// Created by William on 2023/7/4.
//


#include <stdio.h>
#include <stdlib.h>

// 链栈结点结构定义
typedef struct Node {
    int data;           // 数据域
    struct Node* next;  // 指针域，指向下一个结点
} Node;

// 初始化链栈
void initializeStack(Node** top) {
    *top = NULL;
}

// 判断栈是否为空
int isEmpty(Node* top) {
    return top == NULL;
}

// 入栈操作
void push(Node** top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(*top)) {
        *top = newNode;
    } else {
        newNode->next = *top;
        *top = newNode;
    }

    printf("元素 %d 入栈成功\n", value);
}

// 出栈操作
void pop(Node** top) {
    if (isEmpty(*top)) {
        printf("栈为空，无法执行出栈操作\n");
        return;
    }

    int value = (*top)->data;
    Node* temp = *top;
    *top = (*top)->next;
    free(temp);

    printf("元素 %d 出栈成功\n", value);
}

// 获取栈顶元素
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("栈为空\n");
        return -1;
    }
    return top->data;
}

// 打印栈中的元素
void printStack(Node* top) {
    if (isEmpty(top)) {
        printf("栈为空\n");
        return;
    }

    Node* current = top;
    printf("栈中的元素为: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* top;
    initializeStack(&top);
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printStack(top);   // 输出：栈中的元素为: 30 20 10
    pop(&top);    // 输出：元素 30 出栈成功
    printf("栈顶元素为：%d\n", peek(top));  // 输出：栈顶元素为：20
    printStack(top);   // 输出：栈中的元素为: 20 10

    return 0;
}
