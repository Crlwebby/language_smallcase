#include<stdio.h>

int main(void){
    int index = 0;
    int ch;
    while((ch = getchar()) != EOF){
        index++;
    }
    printf("the num of character is %d\n",index);
    return 0;
}