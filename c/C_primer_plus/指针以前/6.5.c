#include<stdio.h>


int main(void){
    char a = 'A',input;
    printf("please input your letter\n");
    scanf("%c",&input);
    printf("this is what you want:\n");
    for(int i = 0; i <= input - 'A'; i++){
        a = 'A';
        for(int j = 0; j < input - 'A' - i; j++)
            printf(" ");
        for(int j = 0; j <= i; j++)
            printf("%c", a++);
        a--;
        for(int j = 0; j < i; j++)
            printf("%c", --a);
        printf("\n");
    }
    return 0;
}