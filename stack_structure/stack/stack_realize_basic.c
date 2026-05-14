/*栈是一个限定仅在表尾进行插入或删除操作的线性表
因此对栈来说，表尾部有特殊意义
称为栈顶（top）
相应的表头部被称为栈底（bottom）
不含元素的空表成为空栈
后进先出
先进后出
LIFO（Last In First Out）的线性表

进栈
退栈

栈是限制插入和删除操作只能在一个位置进行的表，
该位置是表的末尾
叫做栈顶
对栈的基本操作有
进栈
和
出栈

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct s{
    ElemType data[MAXSIZE];
    int top;
}Stack;

void initStack(Stack *s)//初始化
{
    s->top = -1;
}

/*
Status Push(Sqstack &S,Elemtype e)
*/

int isEmpty(Stack *s){
    if(s->top == -1)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//进栈、压栈
int push(Stack *s,ElemType e)
{
    if(s->top >= MAXSIZE - 1)
    {
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}

int pop(Stack *s,ElemType *e)
{
    if(s->top == -1)
    {
        printf("空的\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

int main()
{
    return 0;
}