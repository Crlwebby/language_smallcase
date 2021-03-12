#include<stdio.h>
#include<string.h>
#define TIMES 20
char *s_gets(char *ch, int n){
    int t = 0;
    while((ch[t] = getchar()) && t < n - 1)
        t++;
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