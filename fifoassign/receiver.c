#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd,fd1;
    int r[128];
    int i;

 fd=open("desd", O_RDONLY);
 
    for (i = 0; i < 2; i++)
    {
     read(fd, &r[i], 128);
     printf("number%d: %d \n", i+1, r[i]);
    }
 close(fd);

int sum=0;
  for (i = 0; i < 2; i++)
    {
        sum=sum+r[i];
    }
    fd1=open("desd", O_WRONLY);
    write(fd1, &sum, 4);
    //printf("%d\t",arr[i]);
    close(fd1);
    

return 0;
}

