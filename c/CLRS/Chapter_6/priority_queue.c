#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#define PARENT(i) ((i - 1)/2)
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

int heap_maximum(int a[]);
//获得队列中的最大值，但不出队
int heap_extract_max(int a[],int *heap_size);
//最大优先队列之出队，取出队列中的最大值
void max_heapify(int a[], int heap_size, int i);
//维持最大堆的性质
void increase_key(int a[], int position, int k);
//增加队列中某个元素的值，并维持优先队列
int *max_heap_insert(int a[], int *heap_size, int key);
//队列中新增元素
void build_max_heap(int a[], int heap_size);
//建堆

int main(){
    int *a;
    int permanent[] = {3,7,9,11,18,29,4};
    int len = sizeof(permanent)/sizeof(permanent[0]);
    printf("%d\n",len);
    a = permanent;
    build_max_heap(a,len);
    for(int i = 0; i < len; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    printf("%d\n",heap_extract_max(a,&len));
    for(int i = 0; i < len; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    a = max_heap_insert(a,&len,255);
    for(int i = 0; i < len; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    while(len > 0){
        printf("%d\t",heap_extract_max(a,&len));
    }
    printf("\n");
    return 0;
}

void build_max_heap(int a[], int heap_size){
    for(int i = heap_size/2; i >= 0; i--){
        max_heapify(a,heap_size,i);   
    }
}

int *max_heap_insert(int a[], int *heap_size, int key){
    int *temp = (int *)malloc(sizeof(int) * (*heap_size + 1));
    for(int i = 0; i < *heap_size; i++){
        temp[i] = a[i];
    }
    temp[*heap_size] = INT_MIN;
    (*heap_size)++;
    increase_key(temp,*heap_size-1,key);
    return temp;
}

void increase_key(int a[], int position, int key){
    if(a[position] >= key)
        return;
    a[position] = key;
    while(position > 0 && a[PARENT(position)] < a[position]){
        int temp = a[PARENT(position)];
        a[PARENT(position)] = a[position];
        a[position] = temp;
        position = PARENT(position);
    }
}
int heap_extract_max(int a[],int *heap_size){
    if(*heap_size < 1){
        printf("heap underflow!\n");
        exit(-1);
    }
    int max = a[0];
    (*heap_size)--;
    a[0] = a[*heap_size];
    max_heapify(a,*heap_size,0);
    return max;
}

void max_heapify(int a[], int heap_size, int i){
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest = i;
    if(l < heap_size && a[l] > a[i])
        largest = l;
    if(r < heap_size && a[r] > a[largest])
        largest = r;
    if(i != largest){
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        max_heapify(a,heap_size,largest);
    }    
}

int heap_maximum(int a[]){
    return a[0];
}