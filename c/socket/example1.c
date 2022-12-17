#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    const int port = htons(3000);
    struct sockaddr_in servaddr;
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=port;
    //servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
    int ret = bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    if(ret < 0){
        printf("bind\n");
        return -1;
    }

    struct  sockaddr_in cli;
    socklen_t len = sizeof(cli);
    {
        /* data */
    };
    
    while (1)
    {
        char buf = 0;
        recvfrom(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&cli,&len);
        printf("recv num = %hhd\n",buf);

        buf = 66;
        sendto(sockfd,&buf,sizeof(buf),0,(struct sockaddr*)&cli,len);
    }

    close(sockfd);
}