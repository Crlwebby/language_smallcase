#include<stdio.h>

struct test
{
    int a;
    int b;
}my_test;

int main(){
    printf("%p\n%p\n",&my_test,&(my_test.a));
    return 0;
}