#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "math.h"

int main()
{
	char iKey[32];
	char Key[32];
	char ID[32];
	int iID=0xabc1d3f;
	sprintf(Key,"%x",iID*8+123456);
    printf("%s\n",Key);
	printf("你的机器码是%x\n",iID);
	printf("请输入注册码:");
	gets(iKey);
	/*if (strcmp(Key,iKey)==0)
		MessageBoxA(0,"注册成功","",MB_OK);
	else
		MessageBoxA(0,"注册失败","",MB_OK);*/

    return 0;
}