#include<stdio.h>

int main(void){
    int index = 0;
    char ch;
    while((ch = getchar()) != '#'){
        switch (ch){
            case '.':
                printf("!");
                break;
            case '!':
                printf("!!");
                break;
            default:
                printf("%c",ch);
                continue;
        }
        index++;
    }
    printf("\n replace times is %4d\n",index);
    return 0;
}