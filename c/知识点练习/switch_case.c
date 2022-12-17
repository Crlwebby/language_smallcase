#include<stdio.h>


int main(){
    char a;
    scanf("%c",&a);
    while(a != '#'){
        printf("switch started\n");
        switch (a)
        {
        case 'a':
            printf("%c\n",a);
            break;
        case 'b':
            printf("%c\n",a);
            break;
        case 'n':
            continue;
        default:
            printf("continue default!\n");
            break;
        }
        printf("switch stopped!\n");
        scanf("%c\n",&a);
    }
    return 0;
}