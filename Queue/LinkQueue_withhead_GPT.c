//
// Created by William on 2023/7/4.
//

#include <stdio.h>
#include <stdlib.h>

// 链队列结点结构定义
typedef struct Node {
    int data;           // 数据域
    struct Node* next;  // 指针域，指向下一个结点
} Node;

// 链队列定义
typedef struct {
    Node* front;  // 队头指针
    Node* rear;   // 队尾指针
} Queue;

// 初始化链队列
void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// 判断队列是否为空
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// 入队操作
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("元素 %d 入队成功\n", value);
}

// 出队操作
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空，无法执行出队操作\n");
        return;
    }

    int value = queue->front->data;
    Node* temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        queue->front = temp->next;
    }

    free(temp);

    printf("元素 %d 出队成功\n", value);
}

// 获取队头元素
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空\n");
        return -1;
    }
    return queue->front->data;
}

// 打印队列中的元素
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("队列为空\n");
        return;
    }

    Node* current = queue->front;
    printf("队列中的元素为: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    printQueue(&queue);   // 输出：队列中的元素为: 10 20 30
    dequeue(&queue);      // 输出：元素 10 出队成功
    printf("队头元素为：%d\n", peek(&queue));  // 输出：队头元素为：20
    printQueue(&queue);   // 输出：队列中的元素为: 20 30

    return 0;
}
