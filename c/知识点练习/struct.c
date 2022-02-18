#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
    int ID;
    char Name[100];
}type1,type2,type3;

typedef struct edgeitem
{
    double          weight;
}EDGE_ITEM, *pEDGE_ITEM;

int main(){
    type1 cby = {5,"cby"};
    type2 lzh = {6,"lzh"};
    type3 hel = {7,"hel"};
    printf("%d\t%s\n",cby.ID,cby.Name);
    printf("%d\t%s\n",lzh.ID,lzh.Name);
    printf("%d\t%s\n",hel.ID,hel.Name);

    EDGE_ITEM test1 = {3.0};
    pEDGE_ITEM p1;
    p1 = (pEDGE_ITEM)malloc(sizeof(EDGE_ITEM));
    p1->weight = 4.0;
    printf("%lf\n",test1.weight);
    printf("%lf\n",p1->weight);

    struct edgeitem * test2;
    test2 = p1;
    test2->weight = 5.0;
    printf("%lf\n",test2->weight);
    return 0;
}