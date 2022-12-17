#include<stdio.h>

int main(void){
    printf("please input your input\n");
    int space_num = 0, new_line_num = 0, other_num = 0;
    char ch;
    while((ch = getchar()) != '#'){
        if(ch == ' '){
            space_num++;
        }
        else if(ch == '\n'){
            new_line_num++;
        }
        else{
            other_num++;
        }
    }
    printf("%4d%4d%4d",space_num,new_line_num,other_num);
    return 0;
}