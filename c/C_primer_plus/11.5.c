#include<stdio.h>
#define MES "Hello,cby.Long time no see~ I dont' know what to say, but hello."
char *my_strchr(char *des, char ch){
    int i = 0;
    while(des[i] != '\0'){
        if(des[i] == ch)
            return des + i;
        i++;
    }
    return NULL;
}
int main(void){
    char ch;
    while((ch = getchar()) != 'q'){
        puts(my_strchr(MES,ch));
    }
    return 0;
}