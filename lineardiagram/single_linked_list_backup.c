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
<<<<<<< HEAD
void*insertHead(Node* L,ElemType e)
=======
Node*insertHead(Node* L,ElemType e)
>>>>>>> e3259513e09fc46aaeffe7f7981b7158ddfab382
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    //先让新节点指向旧的第一个节点
    //然后再让头节点指向新节点
    //顺序调换的话关系就断了
    L->next = p;
}

<<<<<<< HEAD
//尾插法
//自己写的，问题在一定要给新节点分配空间
//否则会出现野指针
/*void insertTail(Node*L,ElemType e)
{
    Node *q;//这行出问题了
    q->next = NULL;
    q->data = e;
    Node *p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}*/

//尾节点获取
Node* get_tail(Node *L)
{
    Node *p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

//修正版本
void insertTail(Node*L,ElemType e)
{
    Node *q = (Node*)malloc(sizeof(Node));
    q->next = NULL;
    q->data = e;
    Node *p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

//在指定位置插入数据
int insertLink(Node* L,int pos,ElemType e)
{
    //用来保存插入位置的前驱节点
    Node *p = L;
    //遍历链表找到插入位置的前驱
    for(int i = 0; i < pos-1;i++)
    {
        p = p->next;
        if(p == NULL)
        {
            return 0;
        }
    }
    Node *q = (Node*)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 1;
}

//删除节点
void deleteNode(Node* L,int pos)
{
    if(pos < 1) return;//基础检查

    Node *p = L;
    //寻找待删节点的前驱节点（第pos-1个）
    for(int i = 0;i < pos-1;i++)
    {
        p = p->next;
        if(p==NULL){
            return;
        }
    }

    //检查，前驱节点不能为空，
    //且待删除节点的p->next也不能为空
    if(p = NULL || p->next == NULL)
    {
        printf("删除位置不合法\n");
        return;
    }

    //开始删除逻辑
    Node *q = p->next;
    p->next = q->next;
    //q->next = NULL;
    //应该把q释放
    free(q);
    printf("节点释放成功");
}

//获取链表长度
int listLength(Node *L)
{
    Node *p = L;
    int len = 0;
    while(p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

//释放链表
void freeList(Node *L)
{
    Node *p = L->next;
    Node *q;
    
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

=======
>>>>>>> e3259513e09fc46aaeffe7f7981b7158ddfab382
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
<<<<<<< HEAD
    insertHead(list,30);
    insertHead(list,10);
    insertHead(list,20);
    listNode(list);
    insertLink(list,2,15);
    listNode(list);
    return 0;
}
=======
    insertHead(list,10);
    insertHead(list,20);
    listNode(list);
    return 1;
}
>>>>>>> e3259513e09fc46aaeffe7f7981b7158ddfab382
