#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct buffer{
    int len;
    int b[0];
};
int main(){
    /*int a[0];
    char b[0];
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(struct buffer));
    printf("%d\n",strlen(b));
    printf("%d\n",strlen(""));*/

    struct buffer *buf;
    buf = (struct buffer *) malloc(sizeof(struct buffer) + 20);
    buf->len = 20;
    strcpy(buf->b,"nsnl,I love you!\n");
    puts(buf->b);
    printf("hello?\n");
    free(buf);
    return 0;
}