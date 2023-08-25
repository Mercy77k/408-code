#include <stdio.h>
#include <stdlib.h>

/*定义双链表数据结构*/
typedef struct DNode {
    int data;
    struct DNode *next, *prior;
} DNode, *DLinkList;

void Print_DNode(DLinkList D);//打印双链表
int DNode_Insert_latter(DLinkList D, int i, int value);//在第i个节点后面插入一个节点
int DNode_Delete_latter(DLinkList D, int i );//删除第i个节点的后继节点

DLinkList Get_Ele(DLinkList D, int i);//按位查找节点
DLinkList Creat_DNode();//定义生产双链表的函数

int main() {
    DLinkList D = Creat_DNode();
//    DNode_Insert_latter(D,1,2);
//    DLinkList d = Get_Ele(D, 2);
    int m = DNode_Delete_latter(D,2);
    Print_DNode(D);
    printf("%d\n", m);
}

int DNode_Delete_latter(DLinkList D, int i ){
    /*其实需要考虑被删除节点后面是p空节点的问题，暂不考虑*/
    DLinkList p = Get_Ele(D,i);
    DLinkList q = p->next;
    int temp = q->data;
    q->next->prior = p;
    p->next = q->next;
    free(q);
    return temp;
}

DLinkList Get_Ele(DLinkList D, int i) {
    if (i < 1) {
        printf("输入错误\n");
        return 0;
    }
    DLinkList p = D->next;
    int counter = 1;
    while (counter != i && p != NULL) {
        p = p->next;
        counter++;
    }
    return p;
}

int DNode_Insert_latter(DLinkList D, int i, int value) {
    DLinkList p = Get_Ele(D, i);
    if (i < 1 || p == NULL) {
        printf("位置不合法");
        return 0;
    }
    DLinkList s = (DLinkList) malloc(sizeof(DNode));
    s->data = value;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return 1;
}

void Print_DNode(DLinkList D) {
    DLinkList p = D->next;
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
}

DLinkList Creat_DNode() {
    DLinkList DL = (DLinkList) malloc(sizeof(DNode));
    DLinkList p = DL;
    DL->next = NULL;
    DL->prior = NULL;
    DL->data = -1;
    int x = 0;
    scanf("%d", &x);
    while (x != 99999) {
        DLinkList s = (DLinkList) malloc(sizeof(DNode));
        s->data = x;
        s->next = NULL;
        s->prior = p;
        p->next = s;
        p = s;
        scanf("%d", &x);
    }
    return DL;
}