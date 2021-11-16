#include<stdio.h>

struct a{
    int a;
    char b;
}test;
int main(){
    printf("%d\n",sizeof(test));
    char c[] = "abcde";
    printf("%d\n",sizeof(c));
    return 0;
}