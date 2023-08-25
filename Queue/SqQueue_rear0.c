/*循环队列,rear初始指向0*/
#include <stdio.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;

int InitSqQueue(SqQueue *SqQ); //初始化队列
int EmptySqQueue(SqQueue *SqQ);//判空
int NumOfSqQueue(SqQueue *SqQ);//计算队内元素数
int FullSqQueue(SqQueue *SqQ);//判满
int InSqQueue(SqQueue *SqQ, int value);//进队
int OutSqQueue(SqQueue *SqQ);//出队
int GetHead(SqQueue *SqQ);//获取队列头
int Print(SqQueue *SqQ) ;//遍历队列，并打印

int main() {
    SqQueue SqQ;
    InitSqQueue(&SqQ);
    for (int i = 0; i < 10; ++i) {
        InSqQueue(&SqQ,i);
    }

    Print(&SqQ);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",OutSqQueue(&SqQ));;
    }

}

int Print(SqQueue *SqQ) {
    int p = SqQ->front;
    while (p != SqQ->rear){
        printf("%d\n",SqQ->data[p]);
        p = (p+1)%MaxSize;
    }
    return 1;
}

int GetHead(SqQueue *SqQ) {
    if (EmptySqQueue(SqQ) == 1) {
        return 0;
    } else {
        int x = SqQ->data[SqQ->front];
        return x;
    }
}

int OutSqQueue(SqQueue *SqQ) {
    if (EmptySqQueue(SqQ) == 1) {
        return 0;
    } else {
        int x = SqQ->data[SqQ->front];
        SqQ->front = (SqQ->front + 1) % MaxSize;
        return x;
    }
}

int NumOfSqQueue(SqQueue *SqQ) {
    /*当rear的值超出数组的边界的时候会通过取模运算重置回开始位置
     * 在计算长度的时候要加回一个MaxSize进行作差，作差之后再对Maxsize取模就能得到队内的元素数
     * */
    int x = (SqQ->rear + MaxSize - SqQ->front) % MaxSize;
    return x;
}

int InSqQueue(SqQueue *SqQ, int value) {
    if (FullSqQueue(SqQ) == 1) {
        return 0;
    } else {
        SqQ->data[SqQ->rear] = value;
        SqQ->rear = (SqQ->rear + 1) % MaxSize;
        return 1;
    }
}

int FullSqQueue(SqQueue *SqQ) {
    if (NumOfSqQueue(SqQ) == MaxSize - 1) { //(SqQ->rear+1)%MaxSize == SqQ->front
        printf("当前队列已满\n");
        return 1;
    } else {
        return 0;
    }
}

int InitSqQueue(SqQueue *SqQ) {
    SqQ->front = 0;
    SqQ->rear = 0;
    return 1;
}

int EmptySqQueue(SqQueue *SqQ) {
    if (SqQ->front == SqQ->rear) {
        printf("队列为空\n");
        return 1;
    } else {
        return 0;
    }
}