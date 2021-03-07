#include<stdio.h>

void one_three(void);
void two(void);
void one_three(){
    printf("one\n");
    two();
    printf("three\n");
    return;
}

void two(){
    printf("two\n");
    return;
}
int main(){
    printf("starting now:\n");
    one_three();
    printf("done!\n");
    return 0;
}