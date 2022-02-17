#include<stdio.h>

struct a{
    char t[4];
    char k[4];
    unsigned short i:8;
    unsigned char *p;
    unsigned long m:3;
}test;
int main(){
    printf("%d\n",sizeof(test));
    return 0;
}