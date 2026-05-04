#include <stdio.h>
#include <stdlib.h>


typedef int elementype;

typedef struct Node{
    elementype data;
    struct Node* next;
}Node;


Node *createNode(elementype value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("内存分配失败");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    
    return newNode;
}

void insertHead(Node **head,elementype value){
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void printlist(Node *head){
    Node* current = head;
    while(current != NULL){
        printf("%d\n",current->data);
        current =current->next;
    }
    printf("NULL\n");
}

void freeList(Node **head){
    Node *temp;
    while(*head != NULL){
        temp = *head;
        *head = (*head) -> next;
        free(temp);
    }
}

elementype GetDataByPosition(Node *head,int position){
    Node *current = head;
    if(head == NULL || position < 1)return -1;
    //假设表中不存-1

    //会偏移一位
    //每次循环都判断current是否为空
    for(int i = 1;i < position && current != NULL;i++){
        current = current->next;
    }
    if(current != NULL){
        return current->data;
    }else{
        return -1;
    }
    
}

int getLength(Node *head){
    int count = 0;
    Node *current = head;
    //区分头结点有无，上面是有头结点的写法
    //默认第一个结点是有效的

    while(current){
        count++;
        current = current->next;

    }
    return count;
}

int main(){
    Node *head = NULL;
    
    insertHead(&head,10);
    insertHead(&head,20);
    insertHead(&head,30);

    printlist(head);
    printf("%d\n",getLength(head));
    return 0;
}