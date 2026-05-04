#include <stdio.h>
#include <stdlib.h>

//单链表指的是单个方向的链表
typedef int ElemType;

typedef struct node{
    ElemType data;
    struct node *next;
}Node;
//节点包括两个域，其中存储数据元素信息的叫做数据域
//指针域是指节点中用来存储下一个节点地址（指针）的字段

//初始化
Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//插入数据
//头插法
Node*insertHead(Node* L,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    //先让新节点指向旧的第一个节点
    //然后再让头节点指向新节点
    //顺序调换的话关系就断了
    L->next = p;
}

//遍历链表
void listNode(Node *L)
{
    Node *p = L->next;
    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
    Node *list = initList();
    insertHead(list,10);
    insertHead(list,20);
    listNode(list);
    return 1;
}