#include<stdio.h>

int main(void){
    printf("please input your message, put # to stop it\n");
    char ch;
    int i = 0;
    while((ch = getchar()) != '#'){
        printf("%4c%4d",ch,ch);
        i++;
        if(i % 8 == 0)
            printf("\n");
    }
    return 0;
}