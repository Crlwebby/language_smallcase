#include<stdio.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);
int main(void){
    
    return 0;
}

unsigned srl(unsigned x, int k){
    //Perform shift arithmetically;
    unsigned xsra = (int) x >> k;

    return 0;
}

int sra(int x, int k){
    //Perform shift logically;
    int xsrl = (unsigned) x >> k;

    return 0;
}