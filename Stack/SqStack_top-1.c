/*顺序栈，top指针初始为-1*/
#include <stdio.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize]; //栈内元素节点
    int top; //栈顶指针
} SqStack;

int initStack(SqStack *Sqs);//初始化栈
int Push(SqStack *Sqs, int value);//进栈
int Pop(SqStack *Sqs, int *x);//出栈
int StackEmpty(SqStack *Sqs);//判空
int StackFull(SqStack *Sqs);//判满
int Get_ele(SqStack *Sqs, int *x);//获取栈顶元素

int main() {
    SqStack SqS;
    SqStack *s = &SqS;
    int x = 0;
    int *p = &x;
    initStack(s);
    for (int i = 0; i < MaxSize; ++i) {
        Push(s, i);
    }
//    Push(s, 100);
    for (int i = 0; i < MaxSize; ++i) {
        Pop(s,p);
        printf("%d\n",x);
    }
}

int Get_ele(SqStack *Sqs, int *x) {
    if (StackEmpty(Sqs) == 1) {
        return 0;
    }
    *x = Sqs->data[Sqs->top];
    return 1;
}

int Pop(SqStack *Sqs, int *x) {
    if (StackEmpty(Sqs) == 1) {
        return 0;
    }
    *x = Sqs->data[Sqs->top];//*x = Sqs->data[Sqs->top--];
    Sqs->top--;
    return 1;
}

int initStack(SqStack *Sqs) {
    Sqs->top = -1;//栈顶元素指向-1，表示空栈
    return 1;
}

int StackEmpty(SqStack *Sqs) {
    if (Sqs->top == -1) {
        printf("此时空栈");
        return 1;
    } else {
        return 0;
    }
}

int StackFull(SqStack *Sqs) {
    if (Sqs->top == MaxSize - 1) {
        printf("此时栈满");
        return 1;
    } else {
        return 0;
    }
}


int Push(SqStack *Sqs, int value) {
    if (StackFull(Sqs) == 1) {
        return 0;
    }
    Sqs->top++;
    Sqs->data[Sqs->top] = value; //Sqs->data[++Sqs->top]
    return 1;
}