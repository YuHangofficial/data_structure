// #include<stdio.h>
// #include <stdlib.h>

// typedef char Elemtype;

// typedef struct{
//     Elemtype *top;
//     Elemtype *base;

//     int stacksize;
// }Sqstack;

// int initiateStack(Sqstack *S){

// }

#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

typedef struct
{
    char data[MAXSIZE];
    int top;
} Stack;

void InitStack(Stack *S) {
    S->top = -1;
}

void Push(Stack *S,char x)
{
    S->top++;
    S->data[S->top] = x;//注意是先++再赋值
    printf("Push %c\n",x);
}

char Pop(Stack *S){
    if (S->top == -1){
        return '\0';
    }
    char x = S->data[S->top];
    S->top--;
    printf("Pop %c\n",x);
    return x;
}

int main(){
    char input[MAXSIZE];

    Stack s;
    InitStack(&s);

    if(scanf("%s",input) == EOF) return 0;

    int len = strlen(input);
    for(int i = 0;i < len;i++){
        if (input[i] == 'A'){
            Push(&s,'A');
            Pop(&s);
        } else if(input[i] == 'B'){
            Push(&s,'B');
        }
    }

    while(s.top != -1){
        Pop(&s);
    }

    return 0;
}