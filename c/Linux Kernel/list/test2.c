//#include <stdio.h>

#define MAX(x,y)({                  \
    typeof(x) _min1 = (x);          \
    typeof(y) _min2 = (y);          \
    (void) (&_min1 == &_min2);      \
    _min1 < _min2 ? _min1 : _min2; })
int main(){
    int x =5 , y = 10;
    MAX(x+100,y);
    //printf("hello world!\n");
}