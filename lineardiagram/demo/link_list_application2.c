/*
假定用带头结点的单链表保存单词，当两个单词又相同的后缀时
则可共享相同的后缀存储空间

求出两个单词所指向两个链表共同后缀的起始位置

依旧快慢指针
先分别求出两个链表的长度
再用长的减去短的
那长度长的指针就是快指针
快指针先走m-n步
然后开始判断快慢指针是否相同
最后输出最先相同的后缀位置

*/
#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
}Node;

//初始化链表
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;//返回的是头指针
}

