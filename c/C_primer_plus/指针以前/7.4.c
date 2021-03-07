#include<stdio.h>

int main(void){
    int index = 0;
    char ch;
    while((ch = getchar()) != '#'){
        if(ch == '.'){
            printf("!");
        }
        else if(ch == '!'){
            printf("!!");

        }
        else{
            printf("%c",ch);
            continue;
        }
        index++;
    }
    printf("\n replace times is %4d\n",index);
    return 0;
}