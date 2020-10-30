#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int a, b;
int sum=0;
sem_t s1, s2;

void *input_thread(void *data)
{
    while (1)
    {
        printf("T1: signal from processing thread\n");
        sem_wait(&s1);
        printf("T1: enter inputs\n");
        scanf("%d\n",&a);
        scanf("%d\n",&b);
        printf("T1: got inputs\n");
        sem_post(&s2);
    }

}

void *processing_thread(void *data)
{
    while (1)
    {
        printf("T2: signal from input thread\n");
        sem_wait(&s2);
        printf("T2: starts processing inputs\n");
        sum=a+b;
        printf("T2:procesing done.... addition: %d\n",sum);
        sem_post(&s1);
    }

}
int main(int argc,char const *argv[])
{
    pthread_t input_id, processing_id;
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 0);
    pthread_create(&input_id, NULL, input_thread, NULL);
    pthread_create(&processing_id, NULL, processing_thread, NULL);

    pthread_join(input_id, NULL);
    pthread_join(processing_id, NULL);
    return 0;
}