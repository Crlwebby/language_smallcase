#include<stdio.h>

int main(void){
    char a[26];
    for(int i = 0; i < 26; i++){
        a[i] = 'A' + i;
        printf("%3c",a[i]);
    }
    return 0;
}