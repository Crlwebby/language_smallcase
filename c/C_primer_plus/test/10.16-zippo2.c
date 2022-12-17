#include<stdio.h>

int main(void){
    int zippo[4][2] = {{2,4}, {6,8}, {1,3}, {5,7}};
    int (*pz)[2];
    pz = zippo;
    int *pi[2];
    pi = zippo;

    return 0;
}