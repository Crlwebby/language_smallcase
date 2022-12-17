#include<stdio.h>

int main(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    
    printf("%ld %ld %ld %ld\n",n1,n2,n3,n4);
    printf("%zd %d %d",sizeof(double),sizeof(long),sizeof(int));
    return 0;
}