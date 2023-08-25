/*共享栈*/
#include <stdio.h>

#define MaxSize 10
typedef struct {
    int data[MaxSize];
    int top1;
    int top2;
} ShareStack;

int Push1(ShareStack *ShS, int value);//进栈1
int Pop1(ShareStack *ShS, int *x);//出栈1
int Get_ele1(ShareStack *ShS, int *x);//获取栈1顶元素
int Push2(ShareStack *ShS, int value);//进栈2
int Pop2(ShareStack *ShS, int *x);//出栈2
int Get_ele2(ShareStack *ShS, int *x);//获取栈2顶元素
int StackEmpty1(ShareStack *ShS);//判空栈1
int StackEmpty2(ShareStack *ShS);//判空栈2
int StackFull(ShareStack *ShS);//判满

int main() {

}

int StackFull(ShareStack *ShS) {
    if (ShS->top1 - ShS->top2 == -1) {
        printf("此时栈已满\n");
        return 1;
    } else {
        return 0;
    }
}

int Push1(ShareStack *ShS, int value) {
    if (StackFull(ShS) == 1) {
        return 0;
    }
    ShS->top1++;
    ShS->data[ShS->top1] = value; //ShS->data[ShS->top++]
    return 1;
}

int Push2(ShareStack *ShS, int value) {
    if (StackFull(ShS) == 1) {
        return 0;
    }
    ShS->top1--;
    ShS->data[ShS->top2] = value; //ShS->data[ShS->top++]
    return 1;
}

int StackEmpty1(ShareStack *ShS) {
    if (ShS->top1 == 0) {
        printf("此时空栈");
        return 1;
    } else {
        return 0;
    }
}

int StackEmpty2(ShareStack *ShS) {
    if (ShS->top2 == MaxSize + 1) {
        printf("此时空栈");
        return 1;
    } else {
        return 0;
    }
}

int Pop1(ShareStack *ShS, int *x) {
    if (StackEmpty1(ShS) == 1) {
        return 0;
    }
    *x = ShS->data[ShS->top1];//*x = ShS->data[ShS->top--];
    ShS->top1--;
    return 1;
}

int Pop2(ShareStack *ShS, int *x) {
    if (StackEmpty2(ShS) == 1) {
        return 0;
    }
    *x = ShS->data[ShS->top2];//*x = ShS->data[ShS->top--];
    ShS->top1++;
    return 1;
}

int initStack(ShareStack *ShS) {
    ShS->top1 = -1;
    ShS->top2 = MaxSize + 1;
    return 1;
}

int Get_ele1(ShareStack *ShS, int *x) {
    if (StackEmpty1(ShS) == 1) {
        return 0;
    }
    *x = ShS->data[ShS->top1];
    return 1;
}

int Get_ele2(ShareStack *ShS, int *x) {
    if (StackEmpty2(ShS) == 1) {
        return 0;
    }
    *x = ShS->data[ShS->top2];
    return 1;
}