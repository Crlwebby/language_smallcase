#include<stdio.h>
#include<stdlib.h>
#define TEN 10

int main(void){
    int *a = malloc(sizeof(int) * TEN);
    int b[10] = {0};
    int c = 0;
    char *d = malloc(sizeof(char));
    printf("%zd\n",sizeof(a));
    printf("%p\n",a);
    printf("%zd\n",sizeof(d));
    printf("%zd\n",sizeof(b));
    printf("%d\n",sizeof(c));
    free(a);
    return 0;
}

//sizeof(a[])/sizeof(int) 之所以能够求得数组的长度，是因为定义a[]本身就是数组，在执行分配内存的时候确定了a的长度
//例如int *a，这种方式定义的数组，虽然使用起来和a[]完全一样，但是定义的是指针，内存是在运行时动态分配的，就无法通过sizeof(a)/sizeof(int)求得数组长度