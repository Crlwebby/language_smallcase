#include<stdio.h>
#include<limits.h>
#include "show_byte.h"

unsigned srl(unsigned x, int k);
int sra(int x, int k);
int main(void){
    
    return 0;
}

unsigned srl(unsigned x, int k){
    //Perform shift arithmetically;
    unsigned xsra = (int) x >> k;
    int t = INT_MAX;
    xsra = xsra & ~(t << (sizeof(int) << 3 - k));
    //算术右移改逻辑右移，只要把前k为置0即可，t为全1，左移N位使得前k位为1其余位位0，按位取反后再与
    return xsra;
}

int sra(int x, int k){
    //Perform shift logically;
    int xsrl = (unsigned) x >> k;
    return 0;
}