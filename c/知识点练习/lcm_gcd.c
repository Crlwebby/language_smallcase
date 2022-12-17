#include<stdio.h>

int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

int main(){
    printf("%d\n",gcd(48,36));
    return 0;
}

/*
a   b   a%b
48  36  12
36  12  0
12  0   0
*/