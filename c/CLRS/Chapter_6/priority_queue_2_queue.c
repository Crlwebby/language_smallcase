#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define PARENT(i) ((i - 1)/2)
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2
int PRIORITY = INT_MAX;
//用优先队列实现队列，多加个优先级变量应该就可以了吧……

typedef struct {
    int val;
    int priority;
}data;

data heap_maximum(data a[]);
data heap_extract_max(data a[], int *heap_size);
void max_heapify(data a[], int heap_size, int position);
void exchange(data *a, data *b);
data *max_heap_insert(data *a, int *heap_size, data key);
void increase_key(data a[], int position, int key);
data *push(data *a, int *heap_size, int key);
data pop(data a[], int *heap_size);

int main(){
    data *a = (data *)malloc(sizeof(data));
    a->priority = 5;
    a->val = 20;
    int len = 1;
    a = push(a,&len,12);
    a = push(a,&len,18);
    a = push(a,&len,22);
    while(len){
        data temp = pop(a,&len);
        printf("%d\t%d\n",temp.priority,temp.val);
    }
    return 0;
}

data pop(data a[], int *heap_size){
    return heap_extract_max(a, heap_size);
}

data *push(data *a, int *heap_size, int key){
    data temp;
    temp.val = key;
    temp.priority = PRIORITY--;
    int len = *heap_size;
    data *b = max_heap_insert(a,&len,temp);
    *heap_size = len;
    return b;
}

data heap_extract_max(data a[], int *heap_size){
    if(*heap_size < 1){
        printf("heap underflow!\n");
        exit(-1);
    }
    data temp = a[0];
    (*heap_size)--;
    a[0] = a[*heap_size];
    max_heapify(a,*heap_size,0);
    return temp;
}

void increase_key(data a[], int position, int key){
    if(key < a[position].priority){
        printf("key is smaller than current value");
        return;
    }
    a[position].priority = key;
    while(position > 0 && a[PARENT(position)].priority < a[position].priority){
        exchange(&a[PARENT(position)],&a[position]);
        position = PARENT(position);
    }
}

data heap_maximum(data a[]){
    return a[0];
}

data *max_heap_insert(data *a, int *heap_size, data key){
    data *temp = (data *)malloc(sizeof(data) * (*heap_size + 1));
    for(int i = 0; i < *heap_size; i++){
        temp[i].val = a[i].val;
        temp[i].priority = a[i].priority;
    }
    free(a);
    temp[*heap_size].val = key.val;
    temp[*heap_size].priority = key.priority;
    (*heap_size)++;
    increase_key(temp,*heap_size-1,key.priority);
    return temp;
}

void exchange(data *a, data *b){
    data temp;
    temp.val = a->val;
    temp.priority = a->priority;
    a->val = b->val;
    a->priority = b->priority;
    b->val = temp.val;
    b->priority = temp.priority;

}

void max_heapify(data a[], int heap_size, int position){
    int l = LEFT(position);
    int r = RIGHT(position);
    int max = position;
    if(l < heap_size && a[l].priority > a[position].priority){
        max = l;
    }
    if(r < heap_size && a[r].priority > a[max].priority){
        max = r;
    }
    if(max != position){
        exchange(&a[position],&a[max]);
        max_heapify(a,heap_size,max);
    }
}
