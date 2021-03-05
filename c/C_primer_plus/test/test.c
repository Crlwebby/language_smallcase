#include<stdio.h>
#define TEN 10

int main(void){
    char ch;
    ch = getchar();
    if(ch == '\n'){
        printf("yeeeeees!\n");
    }
    else{
        printf("??????\n");
    }
    printf("%d\n",ch);
    return 0;
}