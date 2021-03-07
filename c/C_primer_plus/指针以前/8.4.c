#include<stdio.h>
#include<ctype.h>

int main(void){
    int ch,num = 0,sum = 0;
    while((ch = getchar()) != EOF){
        if(isalpha(ch))
            sum++;
        else
            num++;
    }
    printf("the average character nums of words if %.2f\n",(float)sum/num);
    return 0;
}