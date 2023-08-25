#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void List_Print(LinkList L);//输出链表中所有节点的值，适用于带头节点的链表（会跳过头节点)
void List_Print_Nh(LinkList L);//打印无头节点的链表
int List_GetLength(LinkList L);//求表长
int List_Delete(LinkList L, int i);//将i节点从链表中删除
int List_Insert_form(LinkList L, int i);//前插操作，将一个节点插入到第i个节点的前面
int List_Insert_form2(LinkList L, int i);//通过直接后插来实现的前插方式，先将节点插入到第i个节点的后面，再将两个i节点中的数据与插入节点中互换，则不需要知道i的前驱节点也能完成前插
int List_Insert_latter(LinkList L, int i);//后插操作，将一个节点插入到单链表第i个节点的后面，实际上等同于将一个节点插入到第i+1个节点的前面
int List_Insert_form_NH(LinkList *L, int i);//无头节点的前插操作，这里要注意在插入第一个位置和其他位置，插入空表和非空表时的操作是不一样的
LinkList is_NULL(LinkList);//判断指针是否为空指针
LinkList List_HeadInsert();//头插法创建单链表，新的元素每次都插入到头节点后面，带头节点
LinkList List_TailInsert();//尾插法创建单链表，新的元素每次都插入到尾节点后面，带头节点
LinkList List_HeadInsert_Nh();//无头节点的头插法创建单链表
LinkList List_TailInsert_Nh();//要考虑无头节点的问题，较麻烦
LinkList List_initial_Head();//初始一个头节点并返回
LinkList GetElem(LinkList L, int i);//按位查找元素,返回所找位置元素节点的指针，只用于带头节点
LinkList GetElem_NH(LinkList L, int i);//按位查找元素,返回所找位置元素节点的指针，只用于不带头节点
LinkList LocateElem(LinkList L, int value);//按值查找，返回与所给值相等的第一个位置节点的指针


int main() {
    LinkList L = NULL;
//    L = List_TailInsert();
//    List_Delete(L, 1);
//    List_Insert_form2(L, 1);
//    LinkList m = LocateElem(L, 3);
//    is_NULL(m);
//    List_Print(L);
//    int m = List_GetLength(L);
//    printf("%d", m);

    L = List_TailInsert_Nh();
    List_Print_Nh(L);
    List_Insert_form_NH(&L, 1);
    List_Print_Nh(L);

}

LinkList List_TailInsert_Nh() {
    LinkList r, L = NULL;
    int x = 0;
    scanf("%d", &x);
    if (x != 99999) {
        LinkList s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        L = s;
        r = s;
        scanf("%d", &x);
    }

    while (x != 99999) {
        LinkList s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        s->next = NULL;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}

void List_Print_Nh(LinkList L) {
    if (L == NULL) {
        printf("当前为空表\n");
    } else {
        LinkList p = L;
        while (p != NULL) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}

LinkList GetElem_NH(LinkList L, int i) {
    if (i < 1) {
        printf("查找位置非法");
        return NULL;
    }
    LinkList p = L;
    int j = 1;
    while (j < i && p != NULL) {
        p = p->next;
        j++;
    }
    return p;
}

/*
 * 从这个函数就能看出头节点的重要性，如果没有头节点，对链表的操作要考虑两个问题
 * 一个是空表问题引起的操作逻辑问题，还有一个是对第一个位置的元素和其他位置元素操作逻辑不同的问题
 * 这会导致出现很多的分支语句
 * */
int List_Insert_form_NH(LinkList *L, int i) { //
    LinkList s = (LinkList) malloc(sizeof(LNode));
    if (i < 1) {
        printf("查找位置非法");
        return 0;
    }
    if (*L == NULL) {
        if (i == 1) {
            scanf("%d", &s->data);
            s->next = *L;
            *L = s;
        } else {
            printf("当前空表，无法在所给位置插入\n");
            return 0;
        }
    } else {
        if (i == 1) {
            scanf("%d", &s->data);
            s->next = *L;
            *L = s;
        } else {
            LinkList p = GetElem_NH(L, i - 1);
            if (p == NULL) {
                printf("未找到待插位置/n");
            }
            scanf("%d", &s->data);
            s->next = p->next;
            p->next = s;
        }
    }
}

int List_GetLength(LinkList L) {
    LinkList p = L->next;
    int count = 0;
    while (p != NULL) {
        p = p->next;
        count++;
    }
    return count;
}

int List_Delete(LinkList L, int i) {
    /* 两种方式实现
     * 一种是找到第i-1个节点，将i-1个节点和第i+1个节点链接，释放第i个节点的空间
     * 第二种是找到第i个节点，将第i个节点中的数据元素与第i+1个节点的元素互换，然后将第i个节点与第i+2个节点相连，释放第i+1个节点
     * 这里使用第二种方式，第一种方式要考虑头节点，需要重写GetElem函数，第二种不需要
     * 第二种方式也有一个问题，那就是链表的长度不能小于3，否则就找不到i+2个节点，可以添加个判断语句修正一下
     */
    LinkList p = GetElem(L, i);
    LinkList q = p->next;
    int value = p->data;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return value;
}

int List_Insert_form2(LinkList L, int i) {
    List_Insert_latter(L, i); //先后插
    LinkList p = GetElem(L, i);
    int temp = p->data;
    p->data = p->next->data;
    p->next->data = temp;
    return 1;
}

int List_Insert_latter(LinkList L, int i) {
    //List_Insert_form(L,i+1); //对i节点进行后插等同于对i+1进行前插
    /*直接后插*/
    LinkList p = GetElem(L, i);
    if (p == NULL) {
        return 0;
    } else {
        LinkList s = (LinkList) malloc(sizeof(LNode));
        scanf("%d", &s->data);
        s->next = p->next;
        p->next = s;
    }
    return 1;
}

int List_Insert_form(LinkList L, int i) {
    LinkList s = (LinkList) malloc(sizeof(LNode));
    scanf("%d", &s->data);
    LinkList p = GetElem(L, i - 1);;
    s->next = p->next;
    p->next = s;
    return 1;
}

LinkList is_NULL(LinkList L) {
    if (L == NULL) {
        printf("当前为空指针\n");
        return NULL;
    } else {
        printf("非空指针，地址为%p\n", &L);
        return L;
    }
}

LinkList LocateElem(LinkList L, int value) {
    LinkList p = L->next;
    while (p != NULL && p->data != value) {
        p = p->next;
    }
    return p;
}

LinkList GetElem(LinkList L, int i) {
    if (i == 0) {
        return L;
    }
    if (i < 1) {
        printf("查找位置非法");
        return NULL;
    }
    LinkList p = L->next;
    int j = 1;
    while (j < i && p != NULL) {
        p = p->next;
        j++;
    }
    return p;
}

LinkList List_HeadInsert_Nh() {
    LinkList s = NULL;
    LinkList L = NULL;
    int x = 0;
    scanf("%d", &x);
    while (x != 99999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        s->next = L;
        L = s;
        scanf("%d", &x);
    }
    return L;
}


LinkList List_TailInsert() {
    LinkList s, r, L;
    L = List_initial_Head();
    r = L;//尾节点指针指向L
    int x = 0;
    scanf("%d", &x);
    while (x != 99999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_HeadInsert() {
    LinkList L, s;
    L = List_initial_Head();
    int x = 0;
    scanf("%d", &x);
    while (x != 99999) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

void List_Print(LinkList L) {
    LinkList temp = L->next;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

LinkList List_initial_Head() {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->next = NULL;
    L->data = -1;
    return L;
}

