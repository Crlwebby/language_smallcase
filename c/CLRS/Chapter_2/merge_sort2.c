//不使用哨兵的版本
#include<stdio.h>

void merge_sort(int a[], int begin, int end);
void merge(int a[], int begin, int mid, int end);
void print_array(int a[], int len);

int main(){
    int a[]={3,7,9,11,18,29,4,24,15,18,16,19,52,63,99,54,32,43,12,58,29};
    int len = sizeof(a) / sizeof(int);
    print_array(a,len);
    merge_sort(a,0,len-1);
    print_array(a,len);
    return 0;
}

void merge(int a[], int begin, int mid, int end){
    int len1 = mid - begin + 1;
    int len2 = end - mid;
    int left[len1],right[len2];
    for(int i = 0; i < len1; i++){
        left[i] = a[begin + i];
    }
    for(int i = 0; i < len2; i++){
        right[i] = a[mid + 1 + i];
    }
    int left_tag=0,right_tag=0;
    for(int i = begin; i <= end; i++){
        if(left_tag == len1){
            a[i] = right[right_tag++];
        }
        else if(right_tag == len2){
            a[i] = left[left_tag++];
        }
        else{
            if(left[left_tag] <= right[right_tag]){
                a[i] = left[left_tag++];
            }
            else{
                a[i] = right[right_tag++];
            }
        }
    }
}
void merge_sort(int a[], int begin, int end){
    if(begin >= end)
        return;
    int mid = (begin + end) / 2;
    merge_sort(a,begin,mid);
    merge_sort(a,mid+1,end);
    merge(a,begin,mid,end);
}

void print_array(int a[], int len){
    for(int i = 0; i < len; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}