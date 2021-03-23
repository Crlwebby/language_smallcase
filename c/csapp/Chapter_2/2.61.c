#include<stdio.h>
#include<limits.h>

#define MASK1 0x00
#define MASK2 0xff
#define test(x) ( !(x ^ ~MASK1) || !(x ^ MASK1) || !((x & MASK2) ^ MASK2) || !(x >> ((sizeof(int)-1)<<3)))

int main(void){
    int x = 0xffffffff;
    int y = 0x00000000;
    int a = 0x123456ff;
    int b = 0x00123456;
    int l1 = 0xfeffffef;
    int l2 = 0x01000001;
    int l3 = 0x123444ef;
    int l4 = 0x01123456;
    printf("%d\t%d\t%d\t%d\n",test(x),test(y),test(a),test(b));
    printf("%d\t%d\t%d\t%d\n",test(l1),test(l2),test(l3),test(l4));
    return 0;
}                                                                                                                           