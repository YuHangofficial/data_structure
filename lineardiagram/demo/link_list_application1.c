 /*
带有表头节点的单链表
节点结构为 data link
假设该链表只给了头节点list，在不改变链表的前提下
设计一个尽可能高效的算法，查找倒数第k个位置上的节点
（k为正整数）若查找成功，输出data的值并返回1
否则返回0

1）描述算法的基本思想
快慢指针（双指针）：
比如说要找倒数第三个
快指针就先走三步
走完三步之后
快慢指针共同再走
一直走到快指针变成NULL了
此时的慢指针也就是倒数的了


2)详细实现步骤

3）代码实现
*/

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

int findNodeFS(Node *L,int k)
{
    Node *fast = L->next;
    Node *slow = L->next;
    for(int i = 0;i < k;i++)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    printf("倒数第%d个指针节点值为：%d\n",k,slow->data);
}


