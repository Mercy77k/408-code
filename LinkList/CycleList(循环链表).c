#include <stdio.h>
#include <stdlib.h>

/*循环单链表*/
typedef struct CSNode { //定义方式和单链表一样
    int data;
    struct CSNode *next;
} CSNode;

/*循环双链表*/
typedef struct CDNode { //定义方式和双链表一样
    int data;
    struct CDNode *next, *prior;
} CDNode;

CSNode *Creat_CSNode(); //创建循环单链表,采用尾插法
CDNode *Creat_CDNode();//创建循环双链表，采用尾插法

int main() {
//    Creat_CDNode();
    Creat_CSNode();
}

CDNode *Creat_CDNode() {
    CDNode *CD = (CDNode *) malloc(sizeof(CDNode));
    CD->next = CD;
    CD->prior = CD;
    CD->data = 0;
    CDNode *p; //定义尾指针
    p = CD;
    int x = 0;
    scanf("%d", &x);
    while (x != 99999) {
        CDNode *s = (CDNode *) malloc(sizeof(CDNode));
        s->data = x;
        s->prior = p;
        s->next = CD;
        p->next = s;
        CD->prior = s;
        p = s;
        scanf("%d", &x);
    }
    return CD;
}

CSNode *Creat_CSNode() {
    CSNode *CS = (CSNode *) malloc(sizeof(CSNode));
    CSNode *p; //定义尾指针
    CS->next = CS;
    CS->data = 0;
    p = CS;
    int x = 0;
    scanf("%d", &x);
    while (x != 99999) {
        CSNode *s = (CSNode *) malloc(sizeof(CSNode));
        s->data = x;
        s->next = CS;
        p->next = s;
        p = s;
        scanf("%d", &x);
    }
    return CS;
}