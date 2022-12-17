#include "func.c"

int main(){
    int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(sockfd < 0){
        printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }
    struct sockaddr_in serveaddr;
    struct sockaddr_in clientaddr;
    char recvline[MAXLINE],buf[MAXLINE];
    serveaddr.sin_port = htons(6666);
    serveaddr.sin_family = AF_INET;
    serveaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("my ip is:%s\tplease connect to this ip\n",inet_ntoa(serveaddr.sin_addr));
    if(bind(sockfd,(struct sockaddr*)&serveaddr,sizeof(serveaddr))==-1){
        printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }
    printf(" bind successfully\n");

    if( listen(sockfd, 10) < 0){
        printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
        exit(0);
    }
    printf("===============waiting message==============\n");
    int connfd;
    struct sockaddr receive_sock;
    while (1)
    {
        if(connfd=accept(sockfd,(struct sockaddr*)NULL,NULL) < 0){
            printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
            continue;
        }
        int n=recv(connfd,buf,MAXLINE,0);
        buf[n]='\0';
        printf("received message is:\t%s\n",buf);
	printf("please response message to client:\n");
        close(connfd);
    }
    close(sockfd);
    
}
