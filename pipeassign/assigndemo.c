#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int r[128];
    pid_t id;
    int pfd1[2],pfd2[2];
    

    int arr[2];
    int i,sum=0;
    printf("enter nos.\n");
    for(i=0;i<2;i++)
    scanf("%d",&arr[i]);
   
        pipe(pfd1);
        id=fork();
        
        for(i=0;i<2;i++)
            {
         if (0 == id)
           {
           read(pfd1[0],&r[i],128);
           printf("received number : %d\n",r[i]);
           close(pfd1[0]);
           }
        else
        {
            write(pfd1[1],&arr[i],8);
            close(pfd1[1]);    
        }
        
    }
    
   pipe(pfd2);
    id=fork();
    
    {
        for ( i = 0; i < 2; i++)
        {
            sum=sum+r[i];
        } 

        if (0 == id)
        {
            read(pfd2[0],&sum,4);
            printf("addition of two numbers: %d\n",sum);
            close(pfd2[0]);
        }
        else
        {
              
            write(pfd2[1],&sum,4);
           //printf("addition in write: %d\n",sum);
            close(pfd2[1]);
        } 
    }

       return 0;
}