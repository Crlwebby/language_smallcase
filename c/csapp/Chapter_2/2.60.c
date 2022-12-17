#include<stdio.h>

typedef unsigned char *byte_pointer;
int is_little_endian();
unsigned replace_byte (unsigned x, int i, unsigned char b);

int main(void){
    unsigned x = 0x12345678;
    replace_byte(x, 1, 0xff);
    return 0;
}

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

unsigned replace_byte (unsigned x, int i, unsigned char b){
    printf("%#x\n",x);
    byte_pointer t = (byte_pointer) &x;
    if(is_little_endian())
        t[i] = b;
    else
        t[4 - i - 1] = b;
    printf("%#x\n",x);

}