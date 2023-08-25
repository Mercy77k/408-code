/*链栈,带头节点的版本*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode, *LinkStack;

int Push(LinkStack L, int value);//进栈操作
int Pop(LinkStack L, int *x);//出栈操作
int StackEmpty(LinkStack L);//判空
int GetElem(LinkStack L, int *x);//获取栈顶元素
int Creat_Stack(LinkNode* L);//创建链栈

int main(){
    int x = 0;
    LinkNode L;
    Creat_Stack(&L);
    Push(&L,10);
    Push(&L,11);
    Pop(&L,&x);
    printf("%d\n",x);
    GetElem(&L,&x);
    printf("%d\n",x);
}
int GetElem(LinkStack L, int *x){
    if (StackEmpty(L) == 1){
        return 0;
    }
    LinkStack p = L->next;
    *x = p->data;
    return 1;
}

int Pop(LinkStack L, int *x) {
    if (StackEmpty(L) == 1){
        return 0;
    }
    LinkStack p = L->next;
    *x = p->data;
    L->next =p->next;
    free(p);
    return 1;
}

int StackEmpty(LinkStack L){
    if (L->next == NULL){
        printf("当前栈为空\n");
        return 1;
    } else{
        return 0;
    }
}

int Push(LinkStack L, int value) {
    LinkStack s = (LinkStack) malloc(sizeof(LinkNode));
    s->data = value;
    s->next = L->next;
    L->next = s;
    return 1;
}

int Creat_Stack(LinkNode* L) {
    L->next = NULL;
    L->data = 0;
    return 0;
}