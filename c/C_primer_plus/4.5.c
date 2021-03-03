#include<stdio.h>


int main(void){
    printf("please input internet speed(Mb/s) and size of file(MB)\n");
    float download,filesize;
    scanf("%f %f",&download,&filesize);
    float time = filesize * 8/ download;
    printf("At %2.2f megabis per second, a file of %1.2f megabytes\n", download,filesize);
    printf("downloads in %.2f seconds.\n",time);

    return 0;
}