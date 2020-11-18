#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<linux/in.h>


int cfd;

struct sockaddr_in saddr;

int len;
unsigned char buff[1024];

int main(int argc,char const *argv[])
{
    cfd = socket(AF_INET, SOCK_STREAM, 0);
    
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    saddr.sin_port= htons(5678); //host to network
    
    connect(cfd, (struct sockaddr *)&saddr, sizeof(struct sockaddr));
    read(cfd, buff, 1024);
    printf("server sent: %s\n", buff);

    write(cfd, "Hello clnt\n", 11);
    close(cfd);
  
}