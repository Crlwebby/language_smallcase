#include<stdio.h>

struct test1{
    unsigned char A:1;
    unsigned char F:1;
    unsigned short G:5;
    unsigned char C:1;
    unsigned short H:5;
    unsigned char D:1;
    unsigned short I:6;
    unsigned char E:1;
    //int B:32;
}data1;

struct  CC1 {
        int b1:1;
        int :2;			//空出2位，啥也没存
        int b3:3;		//b1~b5为同类型的变量，所以可以存储在连续的空间中，总共占4个字节
        int b4:2;
		int b5:3;
		short b6:4;		//b6和上面的类型不同，所以需要存储在新的单元中，总共占4个字节
		int b7:1;		//b7和上面的b6类型不同，所以需要存储在新的单元中，总共占4个字节
      
}CC;

int main(){
    printf("%d\n",sizeof(data1));
    printf("%d\n",sizeof(CC));
    return 0;
}