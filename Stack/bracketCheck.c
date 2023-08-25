/*栈在括号匹配的应用，给一个括号序列，判断这个序列的括号是否能两两匹配*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct LinkNode {
    char data;
    struct LinkNode *next;
} LinkNode, *LinkStack;

int Push(LinkStack L, char value);//进栈操作
int Pop(LinkStack L, char *x);//出栈操作
int StackEmpty(LinkStack L);//判空
int GetElem(LinkStack L, char *x);//获取栈顶元素
LinkStack Creat_Stack();//创建链栈

int bracketCheck(char str[], int length);//
/*
 * 通过字符串数组传入一段括号字符串，通过strlen计算出字符串的总长度，然后for循环挨个遍历
 * 对每个括号进行判断，如果是左括号就入栈，如果是右括号，先判断栈是否为空，如果空栈则匹配失败
 * 栈不空则弹出栈顶左括号对比如果相同，则继续遍历，如果不同则匹配失败
 * 遍历结束后再检查一下是否是空栈，栈空则成功，栈内还有元素则匹配失败
 */


int main() {
    char str[] = "{()}";
    int m;
    m = bracketCheck(str, (int) strlen(str));
    printf("%d", m);
}

int bracketCheck(char str[], int length) {
    LinkStack s = Creat_Stack();
    for (int i = 0; i < length; ++i) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            Push(s, str[i]);
        } else{
            if(StackEmpty(s) == 1)
                return 0;
            char topElem;
            Pop(s,&topElem);
            if (str[i] == '{' && topElem != '}')
                return 0;
            if (str[i] == '{' && topElem != '}')
                return 0;
            if (str[i] == '{' && topElem != '}')
                return 0;
        }
    }
    return StackEmpty(s);
}


int GetElem(LinkStack L, char *x) {
    if (StackEmpty(L) == 1) {
        return 0;
    }
    LinkStack p = L->next;
    *x = p->data;
    return 1;
}

int Pop(LinkStack L, char *x) {
    if (StackEmpty(L) == 1) {
        return 0;
    }
    LinkStack p = L->next;
    *x = p->data;
    L->next = p->next;
    free(p);
    return 1;
}

int StackEmpty(LinkStack L) {
    if (L->next == NULL) {
        printf("当前栈为空\n");
        return 1;
    } else {
        return 0;
    }
}

int Push(LinkStack L, char value) {
    LinkStack s = (LinkStack) malloc(sizeof(LinkNode));
    s->data = value;
    s->next = L->next;
    L->next = s;
    return 1;
}

LinkStack Creat_Stack() {
    LinkStack L = (LinkStack) malloc(sizeof(LinkNode));
    L->next = NULL;
    L->data = 0;
    return L;
}