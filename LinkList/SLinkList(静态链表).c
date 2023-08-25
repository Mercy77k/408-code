#define MaxSize 5

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int next;
} SLinkList[MaxSize];

int Seek_empty_pos(); //找一个空闲节点
void Print_SLinkList();//输出所有节点的值
void Init_SLinkList(); //初始化静态链表，并把list[0]作为头节点，并用头节点中的data代表链表的长度
int Insert_latter(int i, int value);//在静态表的位置i处后插入一个值
int Insert_former(int i, int value);//在静态表的位置i处前插一个值，等同于在i-1处后插一个值，但需要考虑在第一个位置前插元素的情况
int Delete_Elem_SLinkList(int i);//删除指定位置的元素
int Find_pos(int i);//找到第i个元素的物理位置
SLinkList list;

int main() {
//    SLinkList *SL = (SLinkList *) malloc(sizeof(SLinkList));
    Init_SLinkList();
    Insert_former(1, 1);
    Delete_Elem_SLinkList(2);
//    Delete_Elem_SLinkList(1);
//    Delete_Elem_SLinkList(1);
    //printf("%d\n", list[2].data);
    Print_SLinkList();
    printf("\n");
    for (int i = 0; i < MaxSize; ++i) {
        printf("%d\n", list[i].next);
    }
    printf("\n");
    for (int i = 0; i < MaxSize; ++i) {
        printf("%d\n", list[i].data);
    }
}

int Find_pos(int i) {
    int j = 1, p = list[0].next;//找到i的物理位置p
    while (j != i) {
        p = list[p].next;
        j++;
    }
    return j;
}

int Delete_Elem_SLinkList(int i) {
    if (i < 1 || i > list[0].data) {
        printf("删除位置不合法\n");
        return 0;
    }
    if (i == 1) {
        int p = list[0].next, temp = list[p].data;
        list[0].next = list[p].next;
        list[p].next = -2;
        list[0].data--;
        return temp;
    }
    int j = Find_pos(i - 1);
    int p = list[j].next,temp = list[j].data;
    list[j].next = list[p].next;
    list[p].next = -2;
    list[0].data--;
    return temp;
}

int Insert_former(int i, int value) {
    if (list[0].data == MaxSize) {
        printf("当前的静态链表已经满了");
        return 0;
    }
    if (i < 1 || i > list[0].data + 1) {
        printf("插入位置不合法\n");
        return 0;
    }
    if (i == 1) {
        int empty = Seek_empty_pos();
        list[empty].data = value;
        list[empty].next = list[0].next;
        list[0].next = empty;
        list[0].data++;
        return 1;
    }
    Insert_latter(i - 1, value);
    return 1;
}

int Insert_latter(int i, int value) {
    if (list[0].data == MaxSize) {
        printf("当前的静态链表已经满了");
        return 0;
    }
    if (i < 1 || i > list[0].data) {
        printf("插入位置不合法");
        return 0;
    }
    int j = Find_pos(i);//找到存放i的物理位置
    int empty = Seek_empty_pos();//找到一个空的位置
    list[empty].data = value;
    list[empty].next = list[j].next;
    list[j].next = empty;
    list[0].data++;
    return 1;
}

void Print_SLinkList() {//完美的输出函数
    int i = list[0].next;
    while (i != -1) {
        printf("%d\n", list[i].data);
        i = list[i].next;
    }

}

void Init_SLinkList() {
    list[0].next = -1; //声明头节点的游标为-1,-1代表静态链表中最后一个节点
    list[0].data = 1; //头节点的data域用于存放链表当前的长度，默认为1（包括头节点）
    for (int i = 1; i < MaxSize; ++i) { //将所有的空节点的游标都置为-2
        list[i].next = -2;
        list[i].data = 0;
    }
    int x, p = 0; //定义p指针指向尾节点
    scanf("%d", &x);
    while (x != 99999 && list[0].data < MaxSize) {
        int s = p + 1;
        list[s].data = x;
        list[p].next = s;
        list[s].next = -1;
        p = s;
        list[0].data++;
        scanf("%d", &x);
    }
}


int Seek_empty_pos() {
    int i = 0;
    while (i < MaxSize && list[i].next != -2) {
        i++;
    }
    return i;
}
