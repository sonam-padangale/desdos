#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>

int *count;
int input;


int main(int argc, char const *argv[])
{
    int shmfd;
    
    shmfd = shm_open("/cdacshm", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    ftruncate(shmfd, sizeof(int));
    count = (int *) mmap(NULL, sizeof(int), PROT_READ |PROT_WRITE, MAP_SHARED, shmfd, 0);
    
    while (1)
    {
        scanf("%d", &input);
        *count = input;
    }
    
    shm_unlink("/cdacshm");
    return 0;
    }
