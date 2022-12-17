#include <iostream>
#include <ctime>
#include <stdlib.h>

void merge_two_arrays(int* A,int start, int mid, int _end);

void merge_sort(int* A,int p,int q);

int main()
{
    int A[30];
    srand(time(0));
    for(int i=0;i<30;i++){
        A[i]=rand()%100;
        std::cout<<A[i]<<" ";
    }
    std::cout<<std::endl;
    merge_sort(A,0,29);
    for(int i=0;i<30;i++){
        std::cout<<A[i]<<" ";
    }
    return 0;
}

void merge_sort(int* A,int p,int q){
    if(p>=q)
        return;
    int t=(p+q)/2;
    merge_sort(A,p,t);
    merge_sort(A,t+1,q);
    merge_two_arrays(A,p,t,q);
}

void merge_two_arrays(int* A,int start, int mid, int _end){
    int *Left=new int(mid-start+2);
    int *Right=new int(_end-mid+1);
    for(int i=start;i<=mid;i++)
        Left[i-start]=A[i];
    for(int i=mid+1;i<=_end;i++)
        Right[i-mid-1]=A[i];
    Left[mid-start+1]=65535;
    Right[_end-mid]=65535;
    int i=0,j=0,num=start;
    while(num<=_end){
        A[num]=Left[i]<Right[j]?Left[i++]:Right[j++];
        num++;
    }
    delete Left;
    delete Right;
}
