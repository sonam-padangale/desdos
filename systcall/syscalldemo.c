#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char const *argv[])
{
    int fd;
   fd = open("desd.txt",O_WRONLY | O_CREAT); // int open(const char *pathname, int flags);
   
    if(-1 == fd)
    {
        perror("Error in open: \n");  //replace printf with perror 
        return -1;
    }

   write(fd,"cdac",4); //ssize_t write(int fd, const void *buf, size_t count);
    close(fd);
    return 0;
}