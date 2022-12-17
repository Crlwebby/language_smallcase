#include "list.h"
#include <stdio.h>
void main(){
    LIST_HEAD(list);
    printf("%u\n%u\n%u\n",&list,list.prev,list.next)
}