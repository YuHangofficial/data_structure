#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
//宏定义#define之后是直接替换

typedef int ElemType; 
//数组式初始化
// typedef struct{ 
//     ElemType data[MAXSIZE];
//     int length;
// }Seqlist;


// void initlist(Seqlist *L)
// {
//     L->length = 0;
// }

//动态分配内存初始化
typedef struct{
    ElemType *data;
    int length;
}Seqlist;

Seqlist* initList()
{
    Seqlist *L = (Seqlist*)malloc(sizeof(Seqlist));
    //创建顺序线性表本身的指针
    L->data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    L->length = 0;
    return L;
}
/*
int appendList(Seqlist *L,ElemType e)
{
    if(L->length >= MAXSIZE){
        printf("顺序表已满");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
}
*/















int appendElem(Seqlist *L,ElemType e){
    if (L->length >= MAXSIZE){
        printf("顺序表已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

//插入元素
// void insertElem(Seqlist *L,ElemType e,ElemType a){
//     int num;
//     for(int i = 0;i < L->length;i++)
//     {
//         if(L->data[i] == a){
//             num = i;
//         }
//     }

//     for(int i = L->length; i >= num;i--)
//     {
//         L->data[i+1] = L->data[i];
//     }
//     L->data[num] = e;
//     L->length++;
// }

int insertElem(Seqlist *L, int pos, ElemType e)
{
    if(pos <= L->length)
    {
        for(int i = L->length-1; i >= pos - 1;i--)
        {
            L->data[i+1] = L->data[i];
        }
        L->data[pos-1] = e;
        L->length++;
    }
    return 1;
//顺序表插入的最好时间复杂度是什么  
//是O(1)
//最坏O(n) 第一个位置插入数据

}

//删除元素
int deleteElem(Seqlist *L,int pos,ElemType *e)
{

    if(L->length == 0)
    {
        printf("空表\n");
        return 0;
    }

    if (pos < 1 || pos > L->length)
    {
        printf("删除数据位置有误\n");
        return 0;
    }

    *e = L->data[pos-1] ;
    for(int i = pos;i <= L->length;i++){
        L->data[i-1] = L->data[i];
    }

    L->length--;
    return 1;
}

//查找
int findElem(Seqlist *L,ElemType e)
{
    for(int i = 0; i < L->length;i++)
    {
        if(L->data[i] == e)
        {
            return i+1;
        }
    }
}

//动态分配内存地址初始化



void listElem(Seqlist *L){
    for(int i = 0;i < L->length;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
int main(){
    //顺序表 用一组连续的内存单元一次存储线性表的
    //各个元素，也就是说，逻辑上相邻的元素，
    //实际的物理存储空间也是连续的
    Seqlist *list = initList();

    printf("初始化成功，目前长度占用%d\n",list->length);

    printf("目前占用内存%zu字节\n",sizeof(list->data));
    
    appendElem(list,88);
    
    appendElem(list,78);
    
    appendElem(list,16);

    appendElem(list,6);

    appendElem(list,35);

    appendElem(list,255);

    listElem(list);

    ElemType delData;
    deleteElem(list,2,&delData); 

    listElem(list);
    return 0;
}