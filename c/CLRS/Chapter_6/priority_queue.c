#include<stdio.h>
#define PARENT(i) ((i - 1)/2)
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2

int heap_maximum(int a[]);
int heap_extract_max(int a[],int *heap_size);
void max_heapify(int a[], int heap_size, int i);
void increase_key(int a[], int x, int k);
void max_heap_insert(int a[], int key);
int main(){

    return 0;
}

void increase_key(int a[], int i, int key){
    if(a[i] >= key)
        return;
    a[i] = key;
    while(i > 1 && a[PARENT(i)] < a[i]){
        int temp = a[PARENT(i)];
        a[PARENT(i)] = a[i];
        a[i] = temp;
        i - PARENT(i);
    }
}
int heap_extract_max(int a[],int *heap_size){
    if(*heap_size < 1){
        printf("heap underflow");
        exit(-1);
    }
    int max = a[0];
    a[0] = a[*heap_size - 1];
    max_heapify(a,*heap_size - 1,0);
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