/*链栈,不带头节点的版本*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LinkStack;


int Push(LinkStack *S, int value);//进栈操作
int Pop(LinkStack *L, int *x);//出栈操作
int StackEmpty(LinkStack L);//判空
int GetElem(LinkStack L, int *x);//获取栈顶元素
LinkStack Creat_Stack();//创建链栈

int main() {
    int x = 0;
    LinkStack L = Creat_Stack();

    Push(&L,10);
    Pop(&L, &x);
    printf("%d\n", x);
//    GetElem(L, &x);
//    printf("%d\n", x);
}

int GetElem(LinkStack L, int *x) {
    if (StackEmpty(L) == 1) {
        return 0;
    }
    LinkStack p = L;
    *x = p->data;
    return 1;
}

int Pop(LinkStack* L, int *x) {
    if (StackEmpty(*L) == 1) {
        return 0;
    }
    LinkStack p = *L;
    *x = p->data;
    *L = p->next;
    free(p);
    return 1;
}

int StackEmpty(LinkStack L) {
    if (L == NULL) {
        printf("当前栈为空\n");
        return 1;
    } else {
        return 0;
    }
}

int Push(LinkStack *S, int value) {
    LinkStack Point;//定义一个指针
    Point = (LinkStack)malloc(sizeof(LinkNode));//创建一个结点
    Point->data = value;//结点赋值
    Point->next = *S;//新结点后继指针指向栈顶指针指向的结点
    *S = Point;// 栈顶指针指向新结点
    return 0;
}

LinkStack Creat_Stack() {
    LinkStack L;
    L = NULL;
    return L;
}