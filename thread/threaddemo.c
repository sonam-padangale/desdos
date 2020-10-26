#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count=0;

void *thread(void *arg)
{
    count++;
printf("Thread\n");
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    count++;
    printf("before thread creation\n");
    pthread_create(&tid, NULL, thread, NULL);
  
    return 0;
}