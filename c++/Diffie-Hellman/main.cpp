#include <iostream>
#include <time.h>
//#include<math.h>
using namespace std;

int pow(int a,int b){
    int t=1;
    for(int i=0;i<b;i++)
        t*=a;
    return t;
}

int squreMod(int base_num,int index,int divide){
    //base_num^(index) %divide ,���ƽ��ͬ�����⣬ΪDFЭ�����̵�
    if(index<=1)
        return base_num%divide;
    int twoIndex=1;
    //2��ָ�� Ϊ�˽�ԭָ���ֽ�Ϊ2��ָ��֮�ͣ����ҳ����ģ�������ֽ�
    while(index>pow(2,twoIndex))
        twoIndex++;
    //ȷ��indexС��2�Ķ��ٴη�
    int *a=new int[twoIndex]();
    int *b=new int[twoIndex]();
    int j=twoIndex-1;
    int final_num=1;
    while(index!=0){
        if(index>=pow(2,j)){
            a[j]++;
            index=index-pow(2,j);
        }
        j--;
    }
    //������2��ָ���ֽ�����������a��
    for(j=0;j<twoIndex;j++){
        if(j==0)
            b[j]=base_num%divide;
        else{
            b[j]=pow(b[j-1],2)%divide;
        }
    }
    j=0;
    while(j<twoIndex){
        if(a[j]!=0)
            final_num=b[j]*final_num%divide;
        j++;
    }
    return final_num;
}
int main()
{
    srand(int(time(0)));
    int p=2447,g=5;
    int xA=rand()%100000;
    int xB=rand()%100000;
    cout<<"g is  :"<<g<<endl;
    cout<<"p is  :"<<p<<endl;
    cout<<"pow(g,xA) mod p is:  "<<squreMod(g,xA,p)<<endl;
    cout<<"pow(g,xB) mod p is:  "<<squreMod(g,xB,p)<<endl;
    cout<<"pow(g,xA*xB) mod p is:  "<<squreMod(g,xA*xB,p)<<endl;
    cout<<"xA get information :  "<<squreMod(squreMod(g,xB,p),xA,p)<<endl;
    cout<<"xB get information :  "<<squreMod(squreMod(g,xA,p),xB,p)<<endl;
    return 0;
}
