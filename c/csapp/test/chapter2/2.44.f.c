#include<stdio.h>
#include<limits.h>
int main(){
    int x = INT_MAX;
    int y = INT_MAX;

    unsigned ux = x;
    unsigned uy = y;
    printf("%d\t%u\n",x+y,ux+uy);
    if(x+y == ux + uy){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
}