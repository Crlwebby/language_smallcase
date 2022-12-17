#include<stdio.h>

char *pr (char *str){
    char *pc;
    pc = str;
    while (*pc){
        putchar(*pc++);
    }
    do{
        pc -= 2;
        putchar(--*pc);
        printf("%p\n",pc);
    } while(pc - str);

    return pc;
}
int main()
{
    char *x;
    x = pr("Ho Ho Ho!");
    return 0;
}