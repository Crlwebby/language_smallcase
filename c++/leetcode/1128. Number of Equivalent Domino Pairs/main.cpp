#include <iostream>
#include<string.h>

using namespace std;

int Summation(int i){
    long long int sum;
    if(i<0)
        i=0;
    sum=i*(i-1)/2;
    return sum;
}
int main()
{
    int dominoes[2][2];
    dominoes[0][0]=1;
    dominoes[0][1]=2;
    dominoes[1][0]=2;
    dominoes[1][1]=1;
    int total=0;
    int temp[10][10];
    memset(temp,0,sizeof(temp));
    for(int i=0;i<2;i++){
        if(dominoes[i][0]>dominoes[i][1])
            temp[dominoes[i][1]][dominoes[i][0]]++;
        else
            temp[dominoes[i][0]][dominoes[i][1]]++;
    }
    for (int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            total+=Summation(temp[i][j]);
        }
    }
    cout << total << endl;
    return 0;
}
