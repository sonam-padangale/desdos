#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t count_mutex;
pthread_mutexattr_t count_mutex_attr;

int count=0;
void *inc_thread(void *arg)
{
    while (1)
    {
       
    pthread_mutex_lock(&count_mutex); //lock
    count++;
    printf("Inc Thread:%d \n",count); 
    pthread_mutex_unlock(&count_mutex);//unlock
    }
}

void *dec_thread(void *arg)
{
    while (1)
    {
    pthread_mutex_lock(&count_mutex);//lock
    pthread_mutex_lock(&count_mutex);//lock
    count--;
    printf("Dec Thread:%d \n",count);
    pthread_mutex_unlock(&count_mutex);//   //unlock
    }
}
int main(int argc, char const *argv[])
{
    pthread_t tid_inc, tid_dec;
    pthread_mutexattr_init(&count_mutex_attr);

    pthread_mutex_init(&count_mutex,NULL);
    pthread_create(&tid_inc, NULL, inc_thread, NULL);
    pthread_create(&tid_dec, NULL, dec_thread, NULL);

    pthread_join(tid_inc, NULL);
    pthread_join(tid_dec, NULL);
    pthread_mutex_destroy(&count_mutex);
    pthread_mutexattr_destroy(&count_mutex_attr);
      
    return 0;
}