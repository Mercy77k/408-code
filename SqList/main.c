/* Sequence List */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int length;
} SqList;


void initial_SqList(SqList *L); //初始化线性表,覆盖内存中的值
void output_allEle_SqList(SqList *L);//输出表内所有元素
int is_full_SqList(SqList *L);//判断此时表内是否已满
int is_empty_SqList(SqList *L);//判断此时线性表是否为空
int find_SqList_length(SqList *L);//计算表长,返回表长
int find_value_SqList(SqList *L, int value);//按值查找，返回第一个值所在的位置
int find_position_SqList(SqList *L, int pos);//按位查找
int insert_element_SqList(SqList *L, int pos, int value);//按位插入
int delete_element_SqList(SqList *L, int pos);//按位删除，并返回并删除元素的值
int change_element_SqList(SqList *L, int pos, int value);//按位修改
SqList *creat_SqList();//按照输入顺序创建链表，输入999结束。

int main() {
    /* 测试 */
    SqList *L = creat_SqList();
//    insert_element_SqList(L, 1, 2);
//    insert_element_SqList(L, 1, 3);
//    insert_element_SqList(L, 1, 15);
//    insert_element_SqList(L, 1, 16);
//    insert_element_SqList(L, 1, 60);
//    insert_element_SqList(L, 1, 13);
//    delete_element_SqList(L, 6);
    printf("%d\n", find_value_SqList(L, 3));
    output_allEle_SqList(L);
    return 0;
}

int change_element_SqList(SqList *L, int pos, int value) {
    L->data[pos - 1] = value;
    return 1;
}

int delete_element_SqList(SqList *L, int pos) {
    if (is_empty_SqList(L) == 1) {
        printf("当前空表");
        return 0;
    }
    if (pos < 1 || pos > L->length) {
        printf("删除位置不合法");
        return 0;
    }
    int temp = L->data[pos - 1];
    for (int i = pos; i < L->length; ++i) {
        L->data[i - 1] = L->data[i];
    }
    L->length--;
    return temp;

}

int find_position_SqList(SqList *L, int pos) {
    return L->data[pos - 1];
}

int find_value_SqList(SqList *L, int value) {
    if (is_full_SqList(L) == 1) {
        return 0;
    }
    for (int i = 0; i < L->length; ++i) {
        if (value == L->data[i]) {
            return i + 1;
        }
    }
    return 0;
}

int find_SqList_length(SqList *L) {
    return L->length;
}

void initial_SqList(SqList *L) {
    L->length = 0;
    for (int i = 0; i < MaxSize; ++i) {
        L->data[i] = 0;
    }
}

void output_allEle_SqList(SqList *L) {
    for (int i = 0; i < L->length; ++i) {
        printf("%d\n", L->data[i]);
    }
}

int insert_element_SqList(SqList *L, int pos, int value) {
    if (is_full_SqList(L) == 1) {
        return 0;
    }
    if (pos < 1 || pos > L->length + 1) {
        printf("插入位置不合法");
        return 0;
    }
    for (int j = L->length; j >= pos; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[pos - 1] = value;
    L->length++;
    return 1;
}

int is_full_SqList(SqList *L) {
    if (L->length == MaxSize) {
        printf("表内已满");
        return 1;
    } else {
        return 0;
    }
}

int is_empty_SqList(SqList *L) {
    if (L->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

SqList *creat_SqList() {
    SqList *L = (SqList *) malloc(sizeof(SqList));
    initial_SqList(L);
    int x;
    scanf("%d", &x);
    while (x != 999) {
        insert_element_SqList(L, L->length + 1, x);
        scanf("%d", &x);
    }
    return L;
}
