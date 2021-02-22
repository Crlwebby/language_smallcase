#include <iostream>
#include<stdlib.h>
#include<ctime>
void quiksort(int *a,int p,int r);
void swap(int *a,int *b);
int main()
{
    int a[20];
    srand((unsigned)time(NULL));
    for(int i=0;i<20;i++){
        a[i]=rand()%1000;
    }
    for(int i=0;i<20;i++){
        std::cout<<a[i]<<"  ";
    }
    quiksort(a,0,19);
    std::cout<<std::endl;
    for(int i=0;i<20;i++){
        std::cout<<a[i]<<"  ";
    }
    return 0;
}

void quiksort(int *a,int p,int r){
    if(p>=r)
        return;
    int pivot=a[r];
    int i=p,j;
    for(j=p;j<r;j++){
        if(a[j]<pivot){
            swap(a+i,a+j);
            i++;
        }
    }
    swap(a+i,a+j);
    quiksort(a,p,i-1);
    quiksort(a,i+1,r);
}

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
