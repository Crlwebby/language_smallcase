#include<stdio.h>

struct case1
{
    char A;
    char B;
    char C;
    int D;
    int E;
    int F;
}data1;


int main(){
    //printf("%p, %p, %p, %p\n",&data1.A,&data1.B,&data1.C,&data1.D);
    //0x0040 7970 , 0x0040 7974
    printf("%d\n",sizeof(data1));
    //8
    return 0;
}