#include<stdio.h>

int main(void){
    int index = 0;
    char ch,before='!';
    while((ch = getchar()) != '#'){
        if(before == 'e' && ch == 'i')
            index++;
        before = ch;
    }
    printf("ei appears %4d times\n",index);
    return 0;
}