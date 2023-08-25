#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by William on 2023/7/5.
//

#include <stdio.h>
#include <stdlib.h>

// 二叉树节点定义
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// 函数声明
void preorderTraversal(struct Node* root);
void inorderTraversal(struct Node* root);
void postorderTraversal(struct Node* root);
void levelOrderTraversal(struct Node* root);
void printGivenLevel(struct Node* root, int level);
int getHeight(struct Node* root);

// 创建新节点
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 先序遍历（递归）
void preorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 中序遍历（递归）
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// 后序遍历（递归）
void postorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// 层序遍历
void levelOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printGivenLevel(root, i);
    }
}

// 打印给定层级的节点值
void printGivenLevel(struct Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// 获取树的高度
int getHeight(struct Node* root) {
    if (root == NULL)
        return 0;
    else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// 测试用例
int main() {
    // 构造二叉树
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 先序遍历
    printf("先序遍历结果：");
    preorderTraversal(root);
    printf("\n");

    // 中序遍历
    printf("中序遍历结果：");
    inorderTraversal(root);
    printf("\n");

    // 后序遍历
    printf("后序遍历结果：");
    postorderTraversal(root);
    printf("\n");

    // 层序遍历
    printf("层序遍历结果：");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}


