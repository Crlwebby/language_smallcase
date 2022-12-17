#include<stdio.h>

typedef unsigned char *byte_pointer;
int is_little_endian(){
    int x = 255;
    byte_pointer s = (byte_pointer) &x;
    if(s[0] != 0){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){

    printf("%d\n",is_little_endian());
    return 0;
}