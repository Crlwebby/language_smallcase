#include<stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float)); //line:data:show_bytes_amp2
}

int main(void){
    float x = 1e5;
    show_float(x);
    show_float(x+3.14);
    printf("%e\t%e\n",x,x+3.14);
    return 0;
}