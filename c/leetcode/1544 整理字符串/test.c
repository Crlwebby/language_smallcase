#include<stdio.h>
#include<string.h>

int main(void){
    char *s = "hello world";
    printf("%d\n",strlen(s));
    printf("%d\n",sizeof(s));
    return 0;
}