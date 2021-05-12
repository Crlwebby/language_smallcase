#include<stdio.h>

int quickMulti(int A, int B) {
    int ans = 0;
    for ( ; B; B >>= 1) {
        if (B & 1) {
            //如果B的某一位为1，就加上对应位权重*A
            ans += A;
        }
        //B的每一次右移，都会使得对应位相乘的A权重上升。
        //如B的第一位对应A，B的第二位对应A*2，B的第三位对应A*4这样
        A <<= 1;
    }
    return ans;
}

int main(void){
    printf("%d\n",quickMulti(2,3));
    return 0;
}