#include<stdio.h>

int main(void){
    char a = 'A';
    for(int i = 0; i < 6; i++){
        for(int j = i; j <= 2 * i; j++)
            printf("%c",a++);
        printf("\n");
    }
    return 0;
}