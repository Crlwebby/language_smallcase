#include<stdio.h>

double power(double n, int p);

int main(void){
    double x, xpow;
    int exp;

    printf("please enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");

    while(scanf("%lf%d",&x,&exp) == 2){
        xpow = power(x,exp);
        printf("%.3f to the power %d is %.5f\n",x,exp,xpow);
        printf("Enter next pair of numbers or q to quit.\n");
    }
    printf("Hope you enjoyed this power trip --bye!\n");
    return 0;
}

double power(double n, int p){
    if(0 == n && 0 == p){
        printf("0 to the 0 undefined, using 1 as the value.\n");
        return 1;
    }
    if(n == 0){
        return 0;
    }
    if(p == 0){
        return 1;
    }
    double result = 1;
    if(p > 0){
        result = n * power(n, p - 1);
    }
    else{
        for(int i = 0; i > p; i--)
            result = 1/n * power(n, p + 1);
    }
    return result;

}