#include<stdio.h>

#define MASK 0xff
int main(){
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    int t = (x & MASK) + (y & ~MASK);
    printf("%x\n",x);
    printf("%x\n",y);
    printf("%x\n",t);
    return 0;
}

//C语言没学好……这应该是C primer plus里位运算最基础的内容