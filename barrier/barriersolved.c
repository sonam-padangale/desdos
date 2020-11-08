#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_barrier_t barr;

void *Serial(void *arg)
{
    printf("Serial initialization started\n");
    sleep(2);
    printf("Serial : initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("Serial : main functionality started\n");
}

void *Ethernet(void *arg)
{
    printf("Ethernt initialization started\n");
    sleep(10);
    printf("Ethernt: initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("Ethernet : main functionality started\n");
}

void *Lcd(void *arg)
{
    printf("Lcd initialization started\n");
    sleep(7);
    printf("Lcd : initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("Lcd : main functionality started\n");
}

void *Adc(void *arg)
{
    printf("Adc initialization started\n");
    sleep(3);
    printf("Adc : initialization completed\n");
    pthread_barrier_wait(&barr);
    printf("Adc : main functionality started\n");
}

int main(int argc, char const *argv[])
{
    pthread_t serial, ethernet, lcd, adc;
    pthread_barrier_init(&barr, NULL, 4);
    pthread_create(&serial, NULL, Serial, NULL);
    pthread_create(&ethernet, NULL, Ethernet, NULL);
    pthread_create(&lcd, NULL, Lcd, NULL);
    pthread_create(&adc, NULL, Adc, NULL);

    pthread_join(serial, NULL);
    pthread_join(ethernet, NULL);
    pthread_join(lcd, NULL);
    pthread_join(adc, NULL);

    pthread_barrier_destroy(&barr);

    return 0;
}
