#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

void swap_int(int* a,int* b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

class Heap{
    private:
        int *a;
        int n;
        int nums;
    public:
        Heap(int capacity){
            a=new int(capacity+1);          //堆的首元素必须从1开始，否则无法利用完全二叉树的性质
            n=capacity;
            nums=0;
        }
        void insert_new(int data){
            if(nums>=n)
                return;
            a[++nums]=data;
            int i=nums;
            while(i/2>0&&a[i]>a[i/2]){
                swap_int(a+i,a+i/2);
                i=i/2;
            }
        }

        void Heapify(int* a,int n,int i){
            while(1){
                int Maxpos=i;
                if(2*i<=n&&a[2*i]>a[i]) Maxpos=2*i;
                if(2*i+1<=n&&a[2*i+1]>a[Maxpos]) Maxpos=2*i+1;
                if(Maxpos==i)
                    break;
                swap_int(a+Maxpos,a+i);
                i=Maxpos;
            }
        }
        void removeMax(){
            if(nums==0)
                return;
            a[1]=a[nums];
            nums--;
            Heapify(a,nums,1);
        }
        void BuildHeap(int* a,int n){
            for(int i=n/2;i>0;--i){
                Heapify(a,n,i);
            }
        }
        void Heapsort(){
            int k=n;
            while(k>0){
                swap_int(a+k,a+1);
                k--;
                Heapify(a,k,1);
            }
        }
        void HeapPrint(){
            for(int i=1;i<=nums;i++)
                cout<<a[i]<<" ";
        }
};
int main()
{
    Heap temp(10);
    int a[10];
    srand(time(0));
    for(int i=0;i<10;i++){
        a[i]=rand()%100;
        temp.insert_new(a[i]);
        cout<<a[i]<<" ";
    }
    cout<<endl;
    temp.Heapsort();
    temp.HeapPrint();
    return 0;
}
