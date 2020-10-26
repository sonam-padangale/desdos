#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread(void *arg)
{
printf("Thread\n");
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
 
    printf("before thread creation\n");
    pthread_create(&tid, NULL, thread, NULL);
    printf("after thread creation\n");

    sleep(1);
    printf("after sleep\n");
    return 0;
}