#include<stdio.h>

int main(void){
    int even_num = 0, odd_num = 0;
    float sum_even = 0, sum_odd = 0;
    int t;
    while(scanf("%d",&t),t!=0){
        if(t % 2 == 0){
            even_num++;
            sum_even += t;
        }
        else{
            odd_num++;
            sum_odd += t;
        }
    }
    printf("奇数的个数为%4d,奇数的平均值为%.2f\n",odd_num,sum_odd / odd_num);
    printf("偶数的个数为%4d,偶数的平均值为%.2fn",even_num,sum_even / even_num);
    return 0;
}