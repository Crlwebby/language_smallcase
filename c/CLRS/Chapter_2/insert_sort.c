#include<stdio.h>

void insert_sort(int a[], int len);
void print_array(int a[], int len);

int main(){
    int a[]={3,7,9,11,18,29,4,24,15,18,16,19,52,63,99,54,32,43,12,58,29};
    int len = sizeof(a) / sizeof(int);
    print_array(a,len);
    insert_sort(a,len);
    print_array(a,len);
    return 0;
}

void insert_sort(int a[], int len){
    for(int i = 1; i < len; i++){
        int key = a[i];
        int j = i - 1;
        while(j >0 && a[j] > key){
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