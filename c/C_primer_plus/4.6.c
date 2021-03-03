#include<stdio.h>
#include<string.h>

int main(void){
    char first_name[40],last_name[40];
    printf("please input your first_name\n");
    scanf("%s",first_name);
    printf("please input your last_name\n");
    scanf("%s",last_name);
    printf("%s %s\n",first_name,last_name);
    int x = strlen(first_name);
    int y = strlen(last_name);
    printf("%*d %*d\n",x,x,y,y);
    printf("%s %s\n",first_name,last_name);
    printf("%-*d %-*d\n",x,x,y,y);

    return 0;
}