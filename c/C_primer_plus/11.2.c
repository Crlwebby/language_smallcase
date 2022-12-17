#include<stdio.h>
#include<string.h>
#define TIMES 20
char *s_gets(char *ch, int n){
    int t = 0;
    char temp;
    while( (temp = getchar()) && temp != ' ' && temp != '\n' && temp != '\t' && t < n - 1){
        ch[t] = temp;
        t++;
    }
    ch[t] = '\0';
    return ch;
}
int main(void){
    char temp[40];
    s_gets(temp,TIMES);
    puts(temp);
    for(int i = 0; i < TIMES; i++)
        printf("%4d",temp[i]);
    return 0;
}

//我是傻逼……temp = getchar()就是懒不加个括号，殊不知赋值运算优先级低于关系运算，然后temp一直是0，还debug不出来错误，真的傻逼