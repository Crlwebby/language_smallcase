#include<stdio.h>
#include<limits.h>
#include<sys/time.h>
#include<stdlib.h>

#define SIZE 500000
void merge_sort_origin(int a[], int begin, int end);
void merge_sort_improve(int a[], int begin, int end);
void merge(int a[], int begin, int mid, int end);
void print_array(int a[], int len);
void insert_sort(int a[], int len);

int main(){
    int *a = (int*)malloc(sizeof(int) * SIZE);
    int *b = (int*)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < SIZE; i++){
        a[i] = rand();
        b[i] = a[i];
    }
    struct timeval start,end;
    int timeuse;
    gettimeofday(&start,NULL);
    merge_sort_origin(a,0,SIZE-1);
    gettimeofday(&end,NULL);
    timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    printf("原始方法消耗的时间为 %f\n",(double)timeuse/1000000);
    gettimeofday(&start,NULL);
    merge_sort_improve(b,0,SIZE-1);
    gettimeofday(&end,NULL);
    timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec;
    printf("改良方法消耗的时间为 %f\n",(double)timeuse/1000000);
    return 0;
}

void insert_sort(int a[], int len){
    for(int i = 1; i < len; i++){
        int key = a[i];
        int j = i - 1;
        while(j >=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void print_array(int a[], int len){
    for(int i = 0; i < len; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}
void merge_sort_origin(int a[], int begin, int end){
    if(begin >= end)
        return;
    int mid = (begin + end) / 2;
    merge_sort_origin(a,begin,mid);
    merge_sort_origin(a,mid+1,end);
    merge(a,begin,mid,end);
}

void merge_sort_improve(int a[], int begin, int end){
    if(begin >= end)
        return;
    else if((end - begin) <= 100){
        insert_sort(a+begin,end-begin + 1);
        return;
    }
    int mid = (begin + end) / 2;
    merge_sort_improve(a,begin,mid);
    merge_sort_improve(a,mid+1,end);
    merge(a,begin,mid,end);
}

void merge(int a[], int begin, int mid, int end){
    int len1= mid - begin + 1;
    //左半部分的长度包含mid
    int len2 = end - mid;
    //右半部分的长度不包含mid
    int left[len1 + 1],right[len2+1];
    for(int i = 0; i < len1; i++){
        left[i] = a[begin + i];
    }
    for(int i = 0; i < len2; i++){
        right[i] = a[mid + 1 + i];
    }
    left[len1] = INT_MAX;
    right[len2] = INT_MAX;
    //哨兵
    int left_tag=0,right_tag=0;
    for(int i = begin; i <= end; i++){
        if(left[left_tag] <= right[right_tag]){
            a[i] = left[left_tag++];
        }
        else{
            a[i] = right[right_tag++];
        }
    }
}
