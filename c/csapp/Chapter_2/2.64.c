#include<stdio.h>
#include "show_byte.h"

int any_odd_one(unsigned x);

int main(void){
    unsigned test_number = 0x77777777;
    show_unsigned(test_number);
    printf("if any odd bit of test_number:%#x equals 1? %d\n", test_number,any_odd_one(test_number));
    return 0;
}

int any_odd_one(unsigned x){
    unsigned mask = 0x55555555;
    //假设最低位为第一个bit
    return (mask&x) == mask;

}