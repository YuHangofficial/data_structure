#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int SelemType;

/*后文中反复出现的status是什么*/

typedef int Status;
#define OK 1 //成功返回1
#define ERROR 0 //失败返回0
#define OVERFLOW -2 //溢出返回（比如malloc失败）-2


typedef struct {
    SelemType *top;
    SelemType *base;
    int stacksize;
}Sqstack;

/*base为什么是指针，为了动态分配空间
base指向连续数组的第0个位置

top为什么也是指针
在本教材中 top被设计为一个动态移动的指针

core：当栈不空的时候，top永远指向当前栈顶元素的下一个空闲位置
Q：那栈是空的时候呢？


stacksize 防止装的太多导致栈溢出
做安全检查
*/

//初始化
/*如何区分栈和指针
如果用箭头访问成员，如S->base S一定是个指针
如果用.访问成员，如S.base S一定是变量本身
*/
Status InitStack(Sqstack *S){
    S->base = (SelemType*)malloc(sizeof(SelemType)*MAXSIZE);
    if(S->base == NULL) return ERROR;

    S->top = S->base;
    S->stacksize = MAXSIZE;
    return OK;
}


Status Push(Sqstack *S,SelemType e){
    if(S->top - S->base == S->stacksize) return ERROR;

    *(S->top) = e;
    S->top++;
}

/*假设现在栈里已经有了两个元素10和20
数组的最大容量是100
此时 S->base指向的是栈底也就是elem[0]
也就是10所在的地址
S->top指向的是elem[2]
因为一共执行了两次push的代码
top经过两次++到达了elem[2]
但此时
elem[0] == 10
elem[1] == 20 
但是elem[2]是个空位置

当我调用Push(S,30)的时候
*(S->top) = e;
S->top里面存的是一个内存地址
通过解引用顺着这个地址找到具体的格子
于是
计算机把30放进了elem[2]这个空格子里

随后S->top++;
S->top指向elem[3]这个全新的空位
等待下一次push
*/

/*
缩写方法

*(S->top)++ = e;

后置++意味着先加后用

前置不行
*/

Status Pop(Sqstack *S,SelemType *e){
    //这里需要检验是不是空栈
    if(S->base == S->top) return ERROR;

    S->top--;
    *e = *(S->top);

    return OK;
}

/*
注意到出栈的顺序和入栈恰好是相反的

承接上面的场景

S->top指向的是elem[3](这是一个空位)
真正需要弹出的栈顶的元素是elem[2]
需要先S->top--
之后再获得*(S->top)的值传给*e

*/

/*考试时候的终极写法就是
*e = *--(S->top);

前置的++或者--是先加（减）再用

*/

/*总结
入栈(Push)是先赋值再++
出栈(Pop)是先--再弹出

本质只需要记住
S->top所指向的自始至终都是栈顶元素下一个的空位
*/

/*额外的思考
Pop后，内存里的30并没有消失
还在elem[3]的格子里
出栈知识让指针退到指向elem[3]

*/

//判空函数
