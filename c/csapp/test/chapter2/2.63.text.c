#include<stdio.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_unsigned(unsigned x);

int main(void){
    show_int(-100);
    show_int((unsigned)-100>>20);
    show_unsigned((unsigned)-100);
    show_unsigned((unsigned)-100>>20);
    int x = -1;
    return 0;
}
//测试用的代码
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

void show_unsigned(unsigned x) {
    show_bytes((byte_pointer) &x, sizeof(unsigned)); //line:data:show_bytes_amp1
}