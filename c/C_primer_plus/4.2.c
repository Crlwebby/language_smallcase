#include<stdio.h>
#include<string.h>
int main(void){
    printf("please input your first name and last name\n");
    char first_name[40],last_name[40];
    scanf("%s %s",first_name,last_name);
    printf("12345678901234567890123\n");
    printf("\"%s,%s\"\n",first_name,last_name);
    printf("\"%*s,%s\"\n",20-strlen(last_name)-1,first_name,last_name);
    printf("\"%s,%-*s\"\n",first_name,20-strlen(first_name)-strlen(last_name),last_name);
    printf("\"%*s,%s\"\n",strlen(first_name)+3,first_name,last_name);

    return 0;
}