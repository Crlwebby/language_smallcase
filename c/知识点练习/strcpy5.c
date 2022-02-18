#include<stdio.h>
#include<string.h>


int main(){
    char a[15];
    scanf("%s",a);
    char b[15];
    strcpy(b,a);
    printf("%s",b);
    return 0;
}