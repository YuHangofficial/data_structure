#include<stdio.h>
#include<string.h>
struct book
{
    int isbn;
    char bookName[20];
    double price;
};


int main(int argc, char const *argv[]){
    struct book b;
    b.isbn = 767645;
    strcpy(b.bookName,"Java编程思想");
    b.price = 90;
    //信息的增删改查

    return 0;
}