#include<stdio.h>
extern unsigned int rand0(void);

int main(void){
    int count;
    for(count = 0; count < 5; count++){
        printf("%d\n", rand0());
    }
    return 0;
}

//gcc -o 1.exe 12.8-r_drive0.c 12.7-rand0.c