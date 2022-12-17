#include<stdio.h>
#include<string.h>

void number(char *a){
    printf("%d\n",sizeof(a));//8
    printf("strlen is %d\n",strlen(a));//4
}
int main() {
    char a[16] = "abcd";
    int z[16];
    printf("%d\n",sizeof(a));//16
    number(a);//8
    printf("%d\n",strlen(a));//4
    printf("%d\n",sizeof("abcd"));//5
    printf("%d\t%d\t%d\n",sizeof(int),sizeof(long),sizeof(unsigned long));//4 4 4
    printf("%d\n",sizeof(long long));//8
    printf("%d\n",sizeof(z));//64
    printf("%d\n",strlen("abcd")); //4
    return 0;
}