#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int count= 0;   
 

int main (int argc, char const *args[])
{
    pid_t id;
     printf("Before fork\n");
     
        
    id=fork();
    
    if(0 == id)
        { //child
            sleep(1);
             printf("count in child %d \n", count);
        }
        else 
        {
            count++;
            printf("count in parent %d \n", count);
        }

     return 0;
}