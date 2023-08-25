/*不带头节点的链队列*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct LinkQueue {
    LNode *front;
    LNode *rear;
} LinkQueue;

void InitQueue(LinkQueue *LQ);//初始化带头节点的链队列
int InQueue(LinkQueue *LQ, int value);//入队
int OutQueue(LinkQueue *LQ);//出队
int EmptyQueue(LinkQueue *LQ);//判空操作
int Get_length(LinkQueue *LQ);//获取队长
void Print_LQ(LinkQueue *LQ);// 打印队列

int main() {
    LinkQueue LQ;
    InitQueue(&LQ);
    InQueue(&LQ, 4);
    InQueue(&LQ, 4);
    InQueue(&LQ, 4);
    InQueue(&LQ, 4);
    OutQueue(&LQ);
    Print_LQ(&LQ);
    printf("%d", Get_length(&LQ));

}

void Print_LQ(LinkQueue *LQ) {
    LNode *p = LQ->front;
    int i = 0;
    while (p != NULL) {
        printf("%d\n", p->data);
        p = p->next;
        i++;
    }
}

int Get_length(LinkQueue *LQ) {
    LNode *p = LQ->front;
    int i = 0;
    while (p != NULL) {
        p = p->next;
        i++;
    }
    return i;
}

int OutQueue(LinkQueue *LQ) {
    if (EmptyQueue(LQ) == 1) {
        return 0;
    } else {
        int x = LQ->front->data;
        LNode *p = LQ->front;
        LQ->front = p->next;
        free(p);
        return x;
    }
}

int InQueue(LinkQueue *LQ, int value) {
    LNode *L = (LNode *) malloc(sizeof(LNode));
    L->data = value;
    L->next = NULL;
    if(LQ->rear == NULL){
        LQ->rear = L;
        LQ->front = L;
        return 0;
    }
    else{
        LQ->rear->next = L;
        LQ->rear = L;
        return 1;
    }
}


void InitQueue(LinkQueue *LQ) {
    LQ->front = NULL;
    LQ->rear = NULL;
}

int EmptyQueue(LinkQueue *LQ) {
    if (LQ->rear == NULL) {
        printf("当前队列为空\n");
        return 1;
    } else {
        return 0;
    }
}