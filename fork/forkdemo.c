#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main (int argc, char const *args[])
{
    pid_t id;
     printf("Before fork\n");
     //waiting  incoming
        
    id=fork();
    
    if(0 == id)
        { //child
        printf("Inside child= PID=%d \t PPID=%d \n", getpid(),getppid());  // for new client
        }
        else 
        {
            printf("Inside parent= PID=%d \t PPID=%d \n", getpid(),getppid()); // licens incoming
        }

     return 0;
}