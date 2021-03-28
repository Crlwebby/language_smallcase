#include<stdio.h>
#include<limits.h>
#include "show_byte.h"

unsigned srl(unsigned x, int k);
int sra(int x, int k);
int main(void){
    unsigned x = 0xf2345678;
    int t = (int) x;
    printf("原始的无符号数x\n");
    show_unsigned((x));
    show_unsigned(srl(x,8));
    printf("原始的int t\n");
    show_int((t));
    show_int(sra(t,8));
    return 0;
}

int w = sizeof(int) << 3;
unsigned srl(unsigned x, int k){
    //用算术右移实现逻辑右移
    //Perform shift arithmetically;
    unsigned xsra = (int) x >> k;
    printf("算术右移后的无符号数x\n");
    show_unsigned((xsra));
    xsra = xsra & ~(-1 << w - k);
    //sizeof(int)返回字节数，左移3位表示int的总位数
    //由于前面xsra右移了k位，所以现在要左移N-k位，由此确保前K位为1
    //将t左移这么多位，使得t的前k位为1
    //将t按位取反，前k位为0，后k位为1
    //因而实现了将xsra前面置0，后面不变的操作
    printf("实现逻辑右移后的无符号数x\n");
    return xsra;
}

int sra(int x, int k){
    //用逻辑右移实现算术右移
    //Perform shift logically;
    int xsrl = (unsigned) x >> k;
    printf("逻辑右移后的int t\n");
    show_int(xsrl);
    int set = 1 << (w - 1); //首位为1的数
    int msb = set & x;      //用set获取x的首位，正数为0，负数为1
    int t = -1 << (w - k); //前k位为1的数
    int mask = ((!msb) - 1) & t; //如果是正数，前k位置0，负数前k位置1；对应到t，就是整数前k位与0，负数前k位与1
    //msb只有首位为0或1，要通过与-1的运算，使得为0时每一位为0，为1时每一位为1；
    //!msb正数为1，负数为0
    //!msb - 1正数为0000000，负数为11111111
    printf("实现算术右移后的int t\n");
    return xsrl | mask;
}