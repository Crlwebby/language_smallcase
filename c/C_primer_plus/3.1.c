#include<stdio.h>
#include "math.h"
int main(){
    unsigned short big = 65535;
    printf("original big is %u\n",big);
    big++;
    printf("later big is %u\n",big);
    float toobig = 3.4E38 * 100.0;
    printf("float infinity is %f\n",toobig);
    //#INF表示浮点数溢出
    float toosmall = 0.1234567;
    printf("toosmall is %f\n",toosmall);
    toosmall = toosmall * 0.01;
    printf("toosmall is %f\n",toosmall);

    /*printf("1.#INF00表示正无穷或正溢出，%d",1/0);
    printf("-1.#INF00表示正无穷或正溢出，%d",-1/0);
    printf("-1.#IND00表示正无穷或正溢出，%f",log(-1));*/
    //直接除零好像会爆bug，所以只能测试到1.#INF00啦

    return 0;
}