#include<stdio.h>

#define PARENT(i) (i/2)
#define LEFT(i) 2*i + 1
#define RIGHT(i) 2*i + 2
//两个宏与书上的不一样，是因为数组下标从0开始，不能简单的2*i和2*i+1获取子树位置，要分别再额外+1才行

void max_heapify(int a[], int heap_size, int i);
void build_max_heap(int a[], int heap_size);
void heap_sort(int a[], int heap_size);
int main(){
    int a[]={3,7,9,11,18,29,4,24,15,18,16,19,52,63,99,54,32,43,12,58,29};
    int b[] = {5,13,2,25,7,17,20,8,4};
    int length = sizeof(b) / sizeof(int);
    //获取数组长度
    heap_sort(b,length);
    for(int i = 0; i < length; i++)
        printf("%d\t",b[i]);
    printf("\n");
    build_max_heap(b,length);
    for(int i = 0; i < length; i++)
        printf("%d\t",b[i]);
    printf("\n");
    return 0;
}

void heap_sort(int a[],int heap_size){
    int len = heap_size;
    build_max_heap(a,len);
    while(len>1){
        //len代表堆的结点个数，有两个还能再运算一次，只有一个元素必然是有序的，就不需要再循环了
        int temp = a[0];
        a[0] = a[len-1];
        a[len-1] = temp;
        len--;
        max_heapify(a,len,0);
    }
}

void build_max_heap(int a[], int heap_size){
    for(int i = heap_size/2; i >= 0; i--){
        max_heapify(a,heap_size,i);   
    }
}

void max_heapify(int a[], int heap_size, int i){
    int l = LEFT(i);
    int r = RIGHT(i);
    int max = i;
    //与书上不一样的是，heap_size是数组的长度，但是不能直接a[heap_size]，都需要减1
    //因此这里循环判断的条件都是<而不是<=
    if(l < heap_size && a[l] > a[i])
        max = l;
    if(r < heap_size && a[r] > a[max]){
        max = r;
    }
    if(max != i){
        int temp = a[i];
        a[i] = a[max];
        a[max] = temp;
        max_heapify(a, heap_size, max);
    }
}