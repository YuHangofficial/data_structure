/*
用单链表保存n个整数，节点的结构为[data][link],且|data|
<=n(n为正整数)。现要求设计一个时间复杂度尽可能高效的算法
，对于链表中data的绝对值相等的节点，基本保留第一次出现的节点
而删除其他的

设计思想：用空间换时间
先设计一个数组储存每个数是否出现
比如说数组为
head->21->-15->-15->->7->15->NULL
被输出节点后的head为
head->21->-15->-7->NULL
设计一个数组
0 1 2 ......7......15......21
0 0 0 ......1......1.......1
每次都检测对应的数组值是否为0
如果不为0
那就删除当前节点
注意释放
*/

/*删除绝对值相同的节点
void removeNode(Node *L,int n)
{
    Node *p = L;
    int index;//作为数组下标使用
    int *q = (int*)malloc(sizeof(int)*(n+1));
    //生成一个动态分配数组
    
    for(int i = 0; i < n+1; i++)
    {
        *(q + i) = 0;
    }
    
    while(*p->next != NULL)
    {
        index = abs(p->next->data);
        if(*(q+index) == 0)
        {
            *(q + index) = 1;
            p = p->next
        }
            
        //这种else的写法是错误的
        //释放的是新的p-next，而不是原本的
        else{
            p->next = p->next->next;
            free(p->next);
        }
    }
    //  释放的是原本的p->next
    //因为指向的是同一块内存，所以直接释放了

        else{
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    free(q);//数组用完了清理掉
}
 
*/