#include<stdio.h>

int main(){
    int a[1001];
    for(int i = 0; i < 1001; i++)
        a[i] = 1;
    for(int i = 2; i < 500; i++){
        for(int j = 2; i*j < 1001; j++)
            a[i*j] = 0;
    }
    
    for(int i = 2; i < 1001; i++){
        if(a[i]){
            int first = i % 100;
            int second = (i%100)/10;
            int third = i/100;
            if((first + second + third) % 2 == 0)
                printf("%d\n",i);
        }
    }
    return 0;
}