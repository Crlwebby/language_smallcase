#include<stdlib.h>
typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y) {
    *dest = x * (int128_t) y;
}

/*
store_prod:
//128位乘法
// X_128 * Y_128 = (X_h * 2^64 + X_l) * （Y_h * 2^64 + Y_l) = (X_h * Y_h * 2^128) + (2^64 *(X_h * Y_l + X_l * Y_h)) + (X_l * Y_l)
//128位,因而第一部分全都是溢出的，直接忽略，关键就是第二部分和第三部分的计算。
//mul指令结果，低八字节在rax，高八字节在rdx
//因为题目是，x与y是64为有符号乘法，结果放在128位内。因而可以假设rdx为x,rsi为y
    movq    %rdx,%rax   //rax=x
    cqto                //初始化rdx为rax的符号位
    movq    $rsi,%rcx   //rcx=y
    sarq    $63, %rcx   //y = y >> 63(提取xh，因为是算术右移，保留符号位并填充)
    imulq   %rax,%rcx   //xh * yl
    imulq   %rsi,%rdx   //xl * y h
    addq    %rdx,%rcx   //
    mulq    %rsi
    addq    %rcx,%rdx
    movq    %rax,(%rdi)
    movq    %rdx,8(%rdi)
    ret

*/