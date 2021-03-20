#include<stdio.h>

int main(void)
{
    int a = 0b00100011;
    int mask = 0b11111111;
    int b = 0b1110111011011010;
    printf("%x\t%x\t%x\n",a,mask,b);
    printf("%x\n",a&b);
    printf("%x\n",a&mask);
    printf("%x\n",a|b);
    printf("%x\n",a|mask);
    return 0;
}