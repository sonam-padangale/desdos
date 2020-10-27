#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd,fd1;
    int sum=0;
    
    int arr[2];
    printf("enter nos.\n");
    for(int i=0;i<2;i++)
    scanf("%d",&arr[i]);
    
     for (i = 0; i < 2; i++)
    {
    fd=open("desd", O_WRONLY);
    write(fd, &arr, 8);
    //printf("%d\t",arr[i]);
    close(fd);
    }

    fd1=open("desd", O_RDONLY);
    read(fd1, &sum, 4);
    printf("addition is: %d \n", sum);
    close(fd1);

return 0;
}

