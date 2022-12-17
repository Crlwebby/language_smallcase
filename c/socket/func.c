#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 4096

void error_print(char * ptr){
    perror(ptr);
    exit(EXIT_FAILURE);
