#include "func.c"

int main(int argc ,char **argv){
    char recvline[MAXLINE],sendline[MAXLINE];
    if(argc != 2){
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
        exit(0);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(6666);
    if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("inet_pton error for %s\n",argv[1]);
        exit(0);
    }

    int connfd = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    if(connfd < 0){
        printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }

    printf("please send message to server:\n");
    fgets(sendline,MAXLINE,stdin);
    if(send(sockfd,sendline,strlen(sendline),0)<0){
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }
    int confd;
    while(1){
	if con
	
    }

    close(sockfd);
    exit(0);
}