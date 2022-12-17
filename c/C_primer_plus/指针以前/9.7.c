#include<stdio.h>

int place(char ch);

int main(void){
    int ch,index;
    while((ch = getchar()) != EOF){
        index = place((char)ch);
        if(index == -1)
            printf("%c is not an alpha\n",ch);
        else{
            printf("%c is an alpha and place is %d\n",ch,index);
        }
    }
    return 0;
}

int place(char ch){
    if(ch >= 'A' && ch <= 'Z'){
        return ch - 'A' + 1;
    }
    else if(ch >= 'a' && ch <= 'z'){
        return ch - 'a' + 1;
    }
    else return -1;
}