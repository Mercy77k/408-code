//
// Created by William on 2023/7/5.
//
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 定义栈结构
struct Stack {
    struct Node* data[1000];
    int top;
};

// 创建新栈
struct Stack* createStack() {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));
    newStack->top = -1;
    return newStack;
}

// 入栈
void push(struct Stack* stack, struct Node* node) {
    stack->data[++stack->top] = node;
}

// 出栈
struct Node* pop(struct Stack* stack) {
    return stack->data[stack->top--];
}

// 栈是否为空
int isStackEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// 定义队列结构
struct Queue {
    struct Node* data[1000];
    int front;
    int rear;
};

// 创建新队列
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = -1;
    newQueue->rear = -1;
    return newQueue;
}

// 入队
void enqueue(struct Queue* queue, struct Node* node) {
    queue->data[++queue->rear] = node;
}

// 出队
struct Node* dequeue(struct Queue* queue) {
    return queue->data[++queue->front];
}

// 队列是否为空
int isQueueEmpty(struct Queue* queue) {
    return queue->front == queue->rear;
}

// 非递归先序遍历
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    struct Node* node;
    struct Stack* stack = createStack();
    push(stack, root);

    while (!isStackEmpty(stack)) {
        node = pop(stack);
        printf("%d ", node->data);

        if (node->right != NULL)
            push(stack, node->right);
        if (node->left != NULL)
            push(stack, node->left);
    }

    free(stack);
}

// 非递归中序遍历
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack = createStack();
    struct Node* current = root;

    while (current != NULL || !isStackEmpty(stack)) {
        if (current != NULL) {
            push(stack, current);
            current = current->left;
        } else{
            current = pop(stack);
            printf("%d ", current->data);

            current = current->right;
        }
    }

    free(stack);
}

// 非递归后序遍历
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(stack1, root);

    while (!isStackEmpty(stack1)) {
        struct Node* node = pop(stack1);
        push(stack2, node);

        if (node->left != NULL)
            push(stack1, node->left);
        if (node->right != NULL)
            push(stack1, node->right);
    }

    while (!isStackEmpty(stack2)) {
        struct Node* node = pop(stack2);
        printf("%d ", node->data);
    }

    free(stack1);
    free(stack2);
}

// 非递归层序遍历
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        struct Node* node = dequeue(queue);
        printf("%d ", node->data);

        if (node->left != NULL)
            enqueue(queue, node->left);
        if (node->right != NULL)
            enqueue(queue, node->right);
    }

    free(queue);
}

int main() {
    // 创建二叉树
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
